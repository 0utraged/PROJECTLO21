#ifndef LIST_STRUCTS
#define LIST_STRUCTS

typedef enum {
	false,
	true
} Bool;

typedef struct proposition {

  char * contenu_proposition;
  bool is_true;

} Proposition;

typedef struct premisse_elem {

  Proposition * contenu_premisse;
  struct premisse_elem * next ;

} Premisse_elem ;

/*List est un pointeur vers une liste d'éléments de structure ListElement*/
typedef Premisse_elem  * Premisse ;

typedef struct regle {

  Premisse premisse_regle ;
  struct regle * next ;
  Proposition * conclusion ;

} Regle ;

typedef Regle * BC;

#endif
