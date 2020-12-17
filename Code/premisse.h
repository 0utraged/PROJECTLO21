#ifndef PREMISSE
#define PREMISSE
/*TODO: GENERAL PROJECT: 1. fonctions 2. moteur 3. boucle main = menu 4. reprendre une BC (init) puis sauvergarde si voulu (exit) */

/*La structure Regle (List of Lists) est une liste d'adresses vers des listes d'éléments de structure ListElement*/

typedef struct proposition {

  char * contenu_proposition;
  bool is_true;

} Proposition;

typedef struct premisse_elem {

  Proposition * contenu_premisse;
  struct premisse_elem * next ;

} Premisse_elem ;

//Prototypes de fonctions:
Premisse_elem * display_premisse(Premisse_elem * p);// récursif, utilise display_proposition

Proposition * display_proposition(Proposition * p); //affiche le contenu et le boolean

void delete_premisse(Premisse_elem * p,Premisse_elem * conclusion);  //récursif, use with while different than conclusion, link previous to next

bool is_in_premisse(Proposition * search, Premisse_elem * p);// use with while different than conclusion

#endif
