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

Proposition * ajout_premisse_queue(Regle * r, char * c){

}

Proposition * ajout_conclusion_queue(Regle * r, Proposition * p ){

}

bool is_in_premisse(const char *c, Regle * r){

}

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
			Premisse * prem = r->next;
			search_remove_prop(c, prem)
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
