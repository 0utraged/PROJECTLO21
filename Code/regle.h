#ifndef REGLE
#define REGLE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_structs.h"
#include "premisse.h"
#include "proposition.h"

Regle * ajout_premisse_queue(Regle * r, char * c );

Regle * ajout_conclusion(Regle * r, char * c);

//Tester si une proposition appartient à la prémisse d’une règle, de manière récursive:
bool is_in_premisse(const char *c, Regle * r);

bool is_empty_premisse(Regle * r);

Premisse * search_prop(const char * c, Premisse * p);

void display_regle(Regle* r); //(uses display_premisse), on print simplement la conclusion en plus

Regle * remove_head_premisse(Regle * r);

void remove_conclusion(Regle * r);

void link_regle(Regle* r, int iddel);

#endif
