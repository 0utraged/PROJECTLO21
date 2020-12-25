#ifndef REGLE
#define REGLE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_structs.h"
#include "premisse.h"
#include "proposition.h"

Regle * ajout_premisse_queue(Regle * r, Proposition * p );

Regle * ajout_conclusion(Regle * r, Proposition * p );

//Tester si une proposition appartient à la prémisse d’une règle, de manière récursive:
bool is_in_premisse(const char *c, Regle * r);

bool is_empty_premisse(Regle * r);

Proposition * get_conclusion(Regle r); // should print

Premisse * search_prop(Proposition * p, Regle * r);

void display_regle(Regle * r); //(uses display_premisse), on print simplement la conclusion en plus

Regle * remove_head_premisse(Regle * r);

void remove_conclusion(Regle * r);

#endif
