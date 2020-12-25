#ifndef BASEC
#define BASEC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_structs.h"
#include "proposition.h"
#include "premisse.h"
#include "regle.h"
/*La structure Regle (List of Lists) est une liste d'adresses vers des listes d'éléments de structure ListElement*/

BC create_base();

Regle * create_regle(BC b);

void delete_bc(BC b); //récursif

void delete_regle(Regle * r);

void delete_premisse_regle(Premisse * p); //récursif

void display_bc(BC b); //(uses display_regle), récursif

Regle * recherche_id(BC b,int id);//recursif, retrouve la regle voulue, pas de verif de base vide (fait en main)

#endif
