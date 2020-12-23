#include "regle.h"

/*TODO : Write ajout_premisse_queue()
Dl_List newel;
Dl_List p=NULL;
newel=(DListElement *)malloc(sizeof(DListElement));
newel->word=malloc(strlen(w)+1);
strcpy(newel->word, w);
newel->next=NULL;
while
if(l == NULL){
  l=newel;
}
else{

  p= l;

  while (p->next !=NULL){
    p=p->next;
  }

  p->next=newel;
  newel->prev=p;
}
return l;*/

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
  Proposition * temp = r->conclusion;
  if (temp!=NULL){
    delete_proposition(temp);
  }
  temp = create_proposition(c);
  return r;
}

bool is_in_premisse(const char *c, Regle * r){
  return (search_prop(c,r->premisse_regle)!=NULL);
}
//TODO: bool est un enum on peut pasa juste return comme ca, sinon faut faire bool avec des define true 1 false 0 et typedef int bool
bool is_empty_premisse(Regle * r){
  return (r->premisse_regle==NULL);
}

Proposition * get_conclusion(Regle r){
  if(r!=NULL && r->conclusion){
    return r->conclusion;
  } else {
    return NULL;
  }

}
//TODO: contenu premisse plutot que premisse regle non?
Premisse * search_prop(const char * c, Premisse * r){
	if (r==NULL){
    return NULL;
	} else {
    int len=strlen(r->premisse_regle->contenu_proposition);
		int i = 0;
    while(c+i==r->premisse_regle->contenu_proposition+i && r->premisse_regle->contenu_proposition+i!='\0'){
      i++;
    }
    if (i==len){
      return r;
    } else {
			search_remove_prop(c, r->next)
    }
  }
}

void display_regle(Regle * r){

  display_premisse(r->premisse_regle); //récursif, s'arrête à NULL (dernier élément de la prémisse)
  printf("Conclusion : %s",r->conclusion->contenu_proposition);
  return NULL;

}

Regle * remove_head_premisse(Regle * r){

	Premisse * p = r->premisse_regle;

	if (p != NULL){

		r->premisse_regle=p->next;
    delete_proposition( p-> contenu_premisse);
    free(p);

	}
	return p;

}

Regle * remove_conclusion(Regle * r){

	Premisse * p = r->next;

	if (p != NULL){

		r->premisse_regle=p->next;
		if(p!=NULL){

			r->prev=NULL;

		}

		free(p);

	}
	return p;

}
