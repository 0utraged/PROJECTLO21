#ifndef PREMISSE
#define PREMISSE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_structs.h"
/*TODO: GENERAL PROJECT: 1. fonctions 2. moteur 3. boucle main = menu 4. reprendre une BC (init) puis sauvergarde si voulu (exit) */

/*La structure Regle (List of Lists) est une liste d'adresses vers des listes d'éléments de structure ListElement*/

//Prototypes de fonctions:
Premisse_elem * display_premisse(Premisse_elem * p);// récursif, utilise display_proposition

Proposition * display_proposition(Proposition * p); //affiche le contenu et le boolean

void delete_premisse(Premisse_elem * p,Premisse_elem * conclusion);  //récursif, use with while different than conclusion, link previous to next

#endif
