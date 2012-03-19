/*
 * =====================================================================================
 *
 *       Filename:  arbre.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19. 03. 12 19:11:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Olivier Francillon (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <arbres.h>
#include <pile.h>

typeNoeud *creerFeuille (int val)
{
    typeNoeud *noeud;
    noeud = (typeNoeud *)malloc (sizeof (typeNoeud));
    if (noeud != NULL)
        {
            noeud->data.val = val;
            noeud->gauche = NULL;
            noeud->droit = NULL;
        }
        return (noeud);

}

typeNoeud *creerNoeud (char oper, typeNoeud *gauche, typeNoeud *droit)
{
    typeNoeud *noeud;
    noeud = (typeNoeud *)malloc (sizeof (typeNoeud));
    if (noeud != NULL)
        {
            noeud->data.val = oper;
            noeud->gauche = gauche;
            noeud->droit = droit;
        }
        return (noeud);


}

void infixe (typeNoeud *racine)
{
    
}

