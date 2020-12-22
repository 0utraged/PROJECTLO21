#ifndef LIST_STRUCTS
#define LIST_STRUCTS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
	false,
	true
} bool;

/* aussi utilise pour la conclusion*/
typedef struct proposition {

  char * contenu_proposition;
  bool is_true;

} Proposition;

/* Lier le next de l'élément en queue à NULL; NE PAS LE LINK A CONCLUSION */
typedef struct premisse_elem {

  Proposition * contenu_premisse;
  struct premisse_elem * next ;

} Premisse ;

/*List est un pointeur vers une liste d'éléments de structure ListElement*/

typedef struct regle {

  Premisse * premisse_regle ;
  struct regle * next ;
  Proposition * conclusion ;
	bool is_true;

} Regle ;

/*Liste chainee de listes chainees (premisse_regle de Regle) pour contenir
 les differentes regles*/
typedef Regle * BC;

#endif
