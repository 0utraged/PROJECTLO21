#ifndef LIST_STRUCTS
#define LIST_STRUCTS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {
	false,
	true
} bool;

/** cette structure est utilisée pour les éléments de la prémisse ainsi que pour la conclusion
		le boolean est utilisé lors de l'entrée de nouveau faits par l'utilisateur,
		et permet d'eliminer les premisses et conclusions vraies
		le contenu_proposition sert à contenir la proposition
*/
typedef struct proposition {

  char * contenu_proposition;
  bool is_true;

} Proposition;

/** un élément de prémisse est caractérisé par son contenu, une proposition, et son emplacement dans la prémisse.
 		Ici son emplacement est déterminé à partir de l'élément qui le suit.
		L'élément next du dernier élément de la prémisse sera vide.
		On a donc choisi de représenter une premisse comme une liste chaînée.
*/
typedef struct premisse_elem {

  Proposition * contenu_premisse;
  struct premisse_elem * next;

} Premisse;

/** Une règle contient une prémisse (composée de 0, 1 ou plusieurs éléments) ainsi qu'une conclusion (composée d'un seul élément).
		Dans une base de connaissances il peut y avoir plusieurs règles,
		nous avons donc choisi de les représenter sous forme de liste chaînée.
		Chaque règle possède un id qui lui est propre.
*/
typedef struct regle {

  Premisse * premisse_regle ;
  struct regle * next;
  Proposition * conclusion ;
	int id;

} Regle;

/** Le type BC (base de connaissances) est un pointeur menant
		vers le premier élément de la liste chaînée de règles.
*/
typedef Regle* BC;

#endif
