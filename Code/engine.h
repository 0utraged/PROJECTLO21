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


/** récursif, Si la proposition cherchée est dans la prémisse de la règle b,
    son bool passe en true, sinon on fait la recherche pour la règle suivante.
*/
void marks_true_fact(BC b, char* c);

/**recursif, utilise check_premisse() pour passer conclusion en true si tous les éléments sont true, return bool
pour savoir qu'il y a eu un changement*/
bool conclusion_check(Regle * r);

/**recursif, verifie si le boolean de chaque élément de la premisse est vrai, sinon renvoie false au premier élément faux
*/
bool check_premisse (Premisse * p);

/** recursif, verifie l'ensemble des conclusions et print la liste de conclusions
    origin_point sert a changer les conclusions vraies en faits dans toute la base
    et devrait donc toujours etre identique a b quand la fonction est appelee
    pour la 1ere fois
*/
void conclusion_check_global (BC b, BC origin_point);

/** récursif, réinitialise les booleans de la conclusion de chaque règle
    ainsi que tous les élements de prémisse de chaque règle avec reinit_premisse()
    tant que b est non nul.
*/

void reinit_bool(BC b);

/** récursif, réinitialise le boolean de chaque élément de la prémisse
    tant que p est non nul.
*/
void reinit_premisse(Premisse * p);

/**demande une confirmation de la part de l'utilisateur*/
bool confirmation();

/** menu avec trois options, entrer des faits, obtenir les conclusions possibles
    et quitter la base de faits (ce qui la réinitialise)
*/
void engine(BC b);

/** menu avec toutes les fonctions possibles, corps du programme
*/
int menu_bf();

#endif
