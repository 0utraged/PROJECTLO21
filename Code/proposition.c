#include "proposition.h"

void display_proposition (Proposition * p){
    printf("%s\n",p->contenu_proposition);
}

void delete_proposition(Proposition * p){
    if(p==NULL){
        return;
    }
    free(p->contenu_proposition);
    free(p);
	return;
}

Proposition * create_proposition(char * c){
  Proposition * p_new = (Proposition *)malloc(sizeof(Proposition));
  p_new->contenu_proposition = (char *)malloc(101*sizeof(char));
  p_new->is_true = false;
  memcpy(p_new->contenu_proposition,c,101);
  return p_new;
}

void set_bool(Proposition * p, bool b){
  if (p != NULL){
    p->is_true = b;
  }
  return;
}

void print_bool(bool b){
  if (b != false){
    printf("true\n");
  } else {
		printf("false\n");
	}
  return;
}


char * create_str(char * inp)
{
  int size_loop;
  size_loop = strlen(inp);
  char *str = (char *)malloc(sizeof(char)*(size_loop+1));
  for(int i=0; i <= size_loop ; i++){
  *(str + i) = *(inp + i) ;
  }
   return str;
}

char * input(){
  char * inp = (char*) malloc((101)*sizeof(char));
  fgets(inp,100,stdin);
  str_tolower(inp);
  strtok(inp, "\n");
  return inp;
}

char * str_tolower(char * c) {
	if (c!=NULL){
		int i=0;
		while (*(c+i)!='\0') {
		  *(c+i)=tolower(*(c+i));
		  i++;
		}
	}
	return c;
}
