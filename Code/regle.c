#include "regle.h"


Regle * ajout_premisse_queue(Regle * r, char * c){
  Premisse * newel = (Premisse *)malloc(sizeof(Premisse));
  newel->contenu_premisse = create_proposition(c);
  newel->next = NULL;
  Premisse * p = r->premisse_regle;
  if (r->premisse_regle==NULL){
    r->premisse_regle = newel;
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
    r->conclusion=temp;
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
        if(strcmp(c,p->contenu_premisse->contenu_proposition)==0){
            return p;
        }
        else {
            search_prop(c, p->next);
    }
  }
}

void display_regle(Regle * r){
  if(r!=NULL){
    printf("Rule ID: %d\n",r->id);
    printf("Premise:\n");
    display_premisse(r->premisse_regle); //récursif, s'arrête à NULL (dernier élément de la prémisse)
    if (r->conclusion!=NULL){

      printf("Conclusion: ");
      display_proposition (r->conclusion);
    }
  } else {
    printf("Empty rule!\n");
  }
  return;
}

void link_regle(Regle* r,int iddel){
    if(r==NULL){
        return;
    }
    if (r->next==NULL && r!=NULL){
        printf("ID too big!\n");
    } else {
        if (r->next->id==iddel){
            Regle* rnext = r->next->next;
            delete_regle(r->next);
            r->next = rnext;
            printf("Done!\n");
        }else{
            link_regle(r->next,iddel);
        }
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
  return;
}
