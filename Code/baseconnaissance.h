#ifndef BASEC
#define BASEC
/*TODO: GENERAL PROJECT: 1. fonctions 2. moteur 3. boucle main = menu 4. reprendre une BC (init) puis sauvergarde si voulu (exit) */

/*La structure Regle (List of Lists) est une liste d'adresses vers des listes d'éléments de structure ListElement*/

typedef struct ruleset {

  Regle * premisse_regle ;
  struct regle * next ;

} Ruleset ;

typedef Ruleset * BC;

BC create_base()

Regle * create_regle(BC b)

void delete_bc(BC * b) //récursif

void delete_regle(Regle * r, BC b)  //récursif

BC display_db(BC) //(uses display_regle), récursif

#endif
