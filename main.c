#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "arbre.h"
#include "pile.h"

#define TAILLEMAX 80   
#define TAILLEPILE 50 

void main () {
	typePile *pile;
	char expr [TAILLEMAX];
	int val;
	char *ptexpr;
	typeNoeud *feuille, *noeud, *droit, *gauche;
	typeNoeud *racine;

	pile = initpile (TAILLEPILE); 
	ptexpr = expr;
	printf ("Entrer une expression postfixee\n");
	fgets (expr, TAILLEMAX, stdin);

	while (*ptexpr == ' ') ptexpr++;
	while ( *ptexpr != '=' && *ptexpr != '\n' ) {
		if (!isdigit (*ptexpr)) {
			droit = depiler(pile); 
			gauche = depiler(pile);
			noeud = creerNoeud (*ptexpr, gauche, droit);  
			empiler (pile, noeud);
			ptexpr++;
		} else {
			sscanf (ptexpr, "%d", &val);
			while (isdigit(*ptexpr)) ptexpr++;
			feuille = creerFeuille (val);     
			empiler (pile, feuille); 
		}
		while (*ptexpr == ' ') ptexpr++;
	}
	racine = depiler(pile);  

	printf ("\nExpression infixee : \n");
	infixe (racine); 
	printf ("\n\n");
	printf ("Expression prefixee : \n");
	prefixe (racine);
	printf ("\n\n");
	printf ("Valeur de l'expression : %d\n", eval (racine));
}
