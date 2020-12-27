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
/*La structure Regle (List of Lists) est une liste d'adresses vers des listes d'éléments de structure ListElement*/

//Prototypes de fonctions:
void read_from_file(BC * b);

void write_to_file(BC * b);

#endif
