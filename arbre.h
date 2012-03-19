/* 
* Arbres.h
* Prototypes des fonctions de cr�ation et de parcours
* d'arbres binaires repr�sentant une expression arithm�tique
*/
typedef union {
	int val;
	char oper;
} typeDonnee;

typedef struct n {
	/* La donnee est un entier (op�rande) ou un charact�re (op�rateur) */
	typeDonnee data;
	struct n *gauche; /* Fils gauche */
	struct n *droit;  /* Fils droit  */
} typeNoeud;

/* R�sultat : pointeur sur un noeud feuille contenant val */
typeNoeud *creerFeuille (int val);

/* R�sultat : pointeur sur un noeud contenant la donn�e oper */
/* et les fils gauche et droit                               */
typeNoeud *creerNoeud (char oper, typeNoeud *gauche, typeNoeud *droit);

/* Impression infix�e des noeuds de l'arbre binaire */
void infixe (typeNoeud *racine);

/* Impression pr�fix�e des noeuds de l'arbre binaire */
void prefixe (typeNoeud *racine);

/* Evaluation de l'expression */
int eval (typeNoeud *noeud);
