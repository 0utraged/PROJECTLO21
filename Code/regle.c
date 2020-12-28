#include "regle.h"


Regle * ajout_premisse_queue(Regle * r, char * c){

  Premisse * newel = (Premisse *)malloc(sizeof(Premisse));
  newel->contenu_premisse = create_proposition(c);
  newel->next = NULL;
  Premisse * p = r->premisse_regle;
  if (p==NULL){
    p = newel;
  } else {
    while (p->next != NULL) {
      p=p->next;
    }
    p->next = newel;
  }
  return r;
}

/*aussi utilise pour modifier une conclusion existante*/
Regle * ajout_conclusion(Regle * r, char * c){
  if(r!=NULL){
    Proposition * temp = r->conclusion;
    if (temp!=NULL){
      remove_conclusion(r);
    }
    temp = create_proposition(c);
  }
  return r;
}

bool is_in_premisse(const char *c, Regle * r){
  return (search_prop(c,r->premisse_regle)!=NULL);
}

bool is_empty_premisse(Regle * r){
  return (r->premisse_regle==NULL);
}

//remplacé, plus lisible
Premisse * search_prop(const char * c, Premisse * p){
	if (p==NULL){
    return NULL;
	} else {
    int len=strlen(p->contenu_premisse->contenu_proposition);
		int i = 0;
    while(c+i==p->contenu_premisse->contenu_proposition+i &&
      p->contenu_premisse->contenu_proposition+i!='\0'){
      i++;
    }
    if (i==len){
      return p;
    } else {
        search_prop(c, p->next);
    }
  }
}

void display_regle(Regle * r){
  if(r!=NULL){
    printf("Premise:\n");
    if(r->premisse_regle!=NULL){
        display_premisse(r->premisse_regle); //récursif, s'arrête à NULL (dernier élément de la prémisse)
    }
    if (r->conclusion!=NULL){
      printf("Conclusion :\n%s\n",r->conclusion->contenu_proposition);
    }
  } else {
    printf("Empty rule!\n");
  }
  return NULL;
}

void link_regle(Regle* r){
  if (r->next==NULL && r!=NULL){
    printf("ID too big!\n");
  } else {
    Regle* rnext = r->next->next;
    delete_regle(r->next);
    printf("Rule deleted!\n");
    r->next = rnext;
  }
}


Regle * remove_head_premisse(Regle * r){
	Premisse * p = r->premisse_regle;
	if (p != NULL){
		r->premisse_regle=p->next;
    delete_proposition( p-> contenu_premisse);
    free(p);
	}
	return r;
}

void remove_conclusion(Regle * r){
  delete_proposition(r->conclusion);
  return NULL;
}
