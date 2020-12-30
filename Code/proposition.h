#ifndef PROPOSITION
#define PROPOSITION

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_structs.h"

/** Cette fonction affiche le contenu de la chaine de caractères contenu dans la proposition
*/
void display_proposition(Proposition * p);

/** Cette fonction free le contenu  de la chaine de caractères contenu dans la proposition
    puis la proposition elle même
*/
void delete_proposition(Proposition * p);

/**alloue l'espace nécessaire à la nouvelle proposition (chaîne de caractères et boolean)
   et copie le contenu de la chaîne de caractères c dans la nouvelle.
   La fonction renvoie l'adresse de la nouvelle proposition pour l'inclure dans la prémisse ou la conclusion
*/
Proposition * create_proposition(char * c);

/** permet de changer le boolean d'une proposition si elle n'est pas vide
*/
void set_bool(Proposition * p, bool b);

/** affiche true ou false en fonction du boolean
*/
void print_bool(bool b);

/** alloue l'espace nécessaire à une nouvelle chaine de caractères et copie inp dedans
*/
char * create_str(char * inp);

/** alloue l'espace nécessaire à une nouvelle chaine de caractères
    et convertit le string en lowercase avec str_tolower() (et enlève le newline ajouté par fgets())
    après avoir copié la chaîne de caractères entrée par l'utilisateur
*/
char * input();

/** utilise tolower() pour chaque caractère d'un string,
    permet à l'utilisateur d'entrer un texte proche de celui cherché à la taille de caractère près
*/
char * str_tolower(char * c);

#endif
