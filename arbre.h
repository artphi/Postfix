/* 
* Arbres.h
* Prototypes des fonctions de création et de parcours
* d'arbres binaires représentant une expression arithmétique
*/
typedef union {
	int val;
	char oper;
} typeDonnee;

typedef struct n {
	/* La donnee est un entier (opérande) ou un charactère (opérateur) */
	typeDonnee data;
	struct n *gauche; /* Fils gauche */
	struct n *droit;  /* Fils droit  */
} typeNoeud;

/* Résultat : pointeur sur un noeud feuille contenant val */
typeNoeud *creerFeuille (int val);

/* Résultat : pointeur sur un noeud contenant la donnée oper */
/* et les fils gauche et droit                               */
typeNoeud *creerNoeud (char oper, typeNoeud *gauche, typeNoeud *droit);

/* Impression infixée des noeuds de l'arbre binaire */
void infixe (typeNoeud *racine);

/* Impression préfixée des noeuds de l'arbre binaire */
void prefixe (typeNoeud *racine);

/* Evaluation de l'expression */
int eval (typeNoeud *noeud);
