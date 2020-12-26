#include "proposition.h"

void display_proposition(Proposition * p){

	  printf("Element : %s \n",p->contenu_proposition);
		return NULL;

}

void delete_proposition(Proposition * p){

	free(p->contenu_proposition);
  free(p);
	return NULL;
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
  return NULL;
}

void print_bool(bool b){
  if (b != false){
    printf("true");
  } else {
		printf("false");
	}
  return NULL;
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

//TODO: verifier si le stdin doit etre flush
char * input(){
	char inp[100]; //on limite arbitrairement a 100 les inputs
	fgets(inp,sizeof(inp),stdin);
	return tolower(inp);
}

Proposition * create_proposition(char * c){
	Proposition * newel = (Proposition*)malloc(sizeof(Proposition));
	newel->contenu_proposition=c;
	newel->is_true=false;
	return newel;
}

void tolower(char * c) {
	if (c!=NULL){
		int i=0;
		while (c+i!='\0') {
		  if (c+i>='A' && c+i<='Z') {
		     c+i= c+i + 32;
		  }
		  i++;
		}
	}
	return 0;
}
