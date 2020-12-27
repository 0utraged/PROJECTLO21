#ifndef PROPOSITION
#define PROPOSITION

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_structs.h"

Proposition * display_proposition(Proposition * p); //affiche le contenu

void delete_proposition(Proposition * p);

void set_bool(Proposition * p, bool b);

char * create_str(char * input);

char * input();

Proposition * create_proposition(char * c);

//lowers the case, allows for more permissive checks when searching/comparing strings
char * c str_tolower(char * c);

#endif
