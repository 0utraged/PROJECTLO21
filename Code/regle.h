#ifndef REGLE
#define REGLE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_structs.h"

Regle * ajout_premisse_queue(Regle * r, Proposition * p );

Regle * ajout_conclusion(Regle * r, Proposition * p );

//Tester si une proposition appartient à la prémisse d’une règle, de manière récursive:
bool is_in_premisse(Proposition * search, Premisse_elem * prem);

bool is_empty_premisse(Regle * r);

Proposition * get_conclusion(Regle r); // should print

Premisse * search_prop(Proposition * p, Regle * r);

Regle * display_regle(Regle * r); //(uses display_premisse), on print simplement la conclusion en plus

#endif
