#ifndef LIST_STRUCTS
#define LIST_STRUCTS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {
	false,
	true
} Bool;

typedef struct proposition {

  char * contenu_proposition;
  bool is_true;

} Proposition;

/* aussi utilise pour la conclusion qui sera differenciee par son indication
dnas la structure regle*/
typedef struct premisse_elem {

  Proposition * contenu_premisse;
  struct premisse_elem * next ;

} Premisse_elem ;

/*List est un pointeur vers une liste d'éléments de structure ListElement*/
typedef Premisse_elem  * Premisse ;

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
