#include "list_structs.h"

Proposition * display_proposition(Proposition * p){

}

void delete_proposition(Proposition * p){

}

Proposition * create_proposition(char * c){
  Proposition * p_new = (Proposition *)malloc(sizeof(Proposition));
  p_new -> is_true = false;
  p_new -> contenu_proposition = c ;
  return p_new;
}

void set_bool(Proposition * p, bool b){
  if (p != NULL){
    p->is_true = b;
  }
  return 0;
}

char * create_str(char * input)
{
  int size_loop;
  size_loop = strlen(input);
  char *str = (char *)malloc(sizeof(char)*(size_loop+1));
  for(int i=0; i <= size_loop ; i++){
    *(str + i) = *(input + i) ;
  }
   return str;
}
