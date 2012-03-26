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
#include <stdio.h>
#include "arbre.h"
#include "pile.h"

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

void infixe (typeNoeud *noeud)
{
   if (noeud->gauche == NULL)
   {
        /* On a une feuille */
        printf ("%d", noeud->data.val);
   }
   else
   {
       /* Noeud */
       printf("(");
       infixe(noeud->gauche);
       printf("%c", noeud->data.oper);
       infixe (noeud->droit);
       printf(")");
   }
}

void prefixe (typeNoeud *noeud)
{
    if(noeud != NULL)
    {
        if(noeud->gauche == NULL)
        {
            printf("%d ",noeud->data.val);

        }
        else
        {
            printf("%c ", noeud->data.oper);
        }
        prefixe(noeud->gauche);
        prefixe(noeud->droit);

    }
}
int eval(typeNoeud *noeud)
{
    int res;
    int valg, vald;

    if (noeud->droit == NULL && noeud->gauche == NULL)
    {
        res = noeud->data.val;
    }
    else
    {
        valg = eval (noeud->gauche);
        vald = eval (noeud->droit);
        switch (noeud->data.oper)
        {
            case '+' :
                res = valg + vald;
                break;
            case '-':
                res = valg -vald;
                break;
            case '*':
                res = valg * vald;
                break;
            case '/':
                res = valg / vald;

        }
    }
    return res;
}
