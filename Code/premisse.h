#ifndef PREMISSE
#define PREMISSE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_structs.h"
#include "proposition.h"
/*La structure Regle (List of Lists) est une liste d'adresses vers des listes d'éléments de structure ListElement*/

//Prototypes de fonctions:
void display_premisse(Premisse * p);// récursif, utilise display_proposition

void delete_premisse(Premisse * p);

#endif
