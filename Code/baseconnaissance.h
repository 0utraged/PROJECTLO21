#ifndef BASEC
#define BASEC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_structs.h"
#include "proposition.h"
#include "premisse.h"
#include "regle.h"

/** renvoie un pointeur nul
*/
BC create_base();

/** alloue l'espace nécesaire à une règle vide, crée une règle vide,
    et lie cette règle à la dernière règle de la base de connaissances après l'avoir trouvée
*/
Regle * create_regle(BC b);

/** récursif, supprime toutes les règles de la liste chainée BC avec delete_regle()
*/
void delete_bc(BC b);

/** supprime la prémisse de r, supprime la conclusion avec delete_proposition(), puis utilise delete_premisse_regle() avant de libérer la règle
*/
void delete_regle(Regle * r);

/** récursif, supprime tous les éléments de la prémisse p en commençant par celui là, utilise delete_premisse()
*/
void delete_premisse_regle(Premisse * p);

/** récursif, affiche le contenu du pointeur de règle BC puis si son pointeur next est non nul, l'affiche aussi.
    si le pointeur b est nul, affiche "empty base!"
*/
void display_bc(BC b);

/** renvoie le pointeur vers la regle cherchée, après avoir comparé l'id de chaque règle.
    Si l'id est trop grand, affiche le message "ID too big!", si il est trop petit ou a été supprimé, affiche "ID unavailable!"
*/
Regle * recherche_id(BC b,int id);

/** Renvoie le nombre entré par l'utilisateur
*/
int id_input();

#endif
