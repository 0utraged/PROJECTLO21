#ifndef FILEIO
#define FILEIO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_structs.h"
#include "proposition.h"
#include "premisse.h"
#include "regle.h"
#include "baseconnaissance.h"

/** lit le contenu d'un fichier caractère par caractère. Lorsqu'un '/' est lu, une nouvelle règle (active) est créée, lorsqu'un '&' est lu, le mot est ajouté à la prémisse de la règle active
    lorsqu'un ':' est lu, le mot devient la conclusion de la règle active.
*/
BC read_from_file(BC b);

/** Copie le contenu de la base de connaissances dans un fixhier texte. Lorsqu'on qu'on passe à la règle suivante, un '/' est écrit dans le fichier,
    le contenu de l'élément et un '&' sont écrit dans le fichier
    Si la règle possède une conclusion, le contenu de la conclusion et un ':' sont écrit dans le fichier
*/
void write_to_file(BC * b);

#endif
