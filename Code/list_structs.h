#ifndef LIST_STRUCTS
#define LIST_STRUCTS

typedef struct elem {

  int value ;
  struct elem * next ;
  struct elem * prev ;

} ListElement ;

/*List est un pointeur vers une liste d'éléments de structure ListElement*/
typedef ListElement * List ;

/*La structure LOL (List of Lists) est une liste d'adresses vers des listes d'éléments de structure ListElement*/
typedef struct listoflists {

  List Listptr;
  struct listoflists* next ;
  struct listoflists* prev ;

} LOL ;

typedef LOL * LOLptr ;

#endif
/*TODO: test */
