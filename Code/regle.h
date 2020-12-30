#ifndef REGLE
#define REGLE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_structs.h"
#include "premisse.h"
#include "proposition.h"

/** Crée un nouvel élément de prémisse en appelant create_proposition(),
    puis cherche l'élément de la prémisse d'une règle pour lequel next est vide
    et associe cet élément au nouveau.
*/
Regle * ajout_premisse_queue(Regle * r, char * c );


/** Supprime la conclusion de la règle si il y en a déjà une,
    puis crée une nouvelle proposition en appelant create_proposition(),
    et l'élément conclusion de r y est associé.
*/
Regle * ajout_conclusion(Regle * r, char * c);

/**Teste si une proposition appartient à la prémisse d’une règle,
   en comparant les chaînes de caractères de c et de la proposition des éléments de la prémisse
   de manière récursive (search_prop()) et renvoie true (si search_prop renvoie un pointeur non vide) ou false.
*/
bool is_in_premisse(const char *c, Regle * r);

/**Teste si une prémisse et vide et renvoie true (si l'élément premisse_regle de r renvoie un pointeur vide) ou false.
*/
bool is_empty_premisse(Regle * r);

/** compare chaque élément de la prémisse (récursif) à la chaîne de caractères c et renvoie l'adresse de l'élément
    pour lequel la proposition associée contient la chaîne correspondante.
    Si il n'y a pas d'élément correspondant, un pointeur vide est renvoyé
*/
Premisse * search_prop(const char * c, Premisse * p);

/** Si r est un pointeur non vide, utilise display_premisse()
    avec le premier élément de la prémisse, puis display_proposition pour la conclusion
*/
void display_regle(Regle* r);

/** associe le pointeur premisse_regle de r au deuxième élément de sa premisse
    après avoir libéré le premier élément avec delete_premisse().
*/
Regle * remove_head_premisse(Regle * r);

/** appelle la fonction delete_proposition sur la conclusion de la règle r
*/
void remove_conclusion(Regle * r);

/** récursif, va de règle en règle jusqu'à ce que le pointeur next de r mène à la règle d'id égal à iddel
    puis associe le pointeur next de r à la règle suivant celle à supprimer après l'avoir supprimé avec delete_regle()
    Cas particulier si la première règle de la base est celle à supprimer, le pointeur BC est lié à la deuxième règle
    après avoir supprimé la première.
*/
void link_regle(Regle* r, int iddel);

#endif
