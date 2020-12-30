#ifndef ENGINE
#define ENGINE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proposition.h"
#include "premisse.h"
#include "regle.h"
#include "baseconnaissance.h"
#include "list_structs.h"


//reccursif, verifie la presence d'un fait et passe is_true en true
//pas de check de b vide car fait par la fonction engine
void marks_true_fact(BC b, char* c);

/*reccursif, check des premisses pour passer conclusion vraie, return bool
pour savoir qu'il y a eu un changement*/
bool conclusion_check(Regle * r);

//reccursif, verifie si toutes les premisses sont vraies
bool check_premisse (Premisse * p);

/*reccursif, verifie l'ensemble des conclusions et print la liste de conclusions
origin_point sert a changer les conclusions vraies en faits dans toute la base
et devrait donc toujours etre identique a b quand la fonction est appelee
pour la 1ere fois*/
void conclusion_check_global (BC b, BC origin_point);

void reinit_bool(BC b); //reccursif

void reinit_premisse(Premisse * p);//reccursif

//simple confirmation avant les etapes importantes entrainant des changements irreversibles
bool confirmation();

void engine(BC b);

int menu_bf();

#endif
