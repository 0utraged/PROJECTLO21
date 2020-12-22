#include "regle.h"


Proposition * ajout_premisse_queue(Regle * r, Proposition * p ){

}

Proposition * ajout_conclusion_queue(Regle * r, Proposition * p ){

}

bool is_in_premisse(Regle * r){

}

bool is_empty_premisse(Regle * r){

}

Proposition * get_conclusion(Regle r){

}

void search_remove_prop(Proposition * p, Regle * r){

}

Regle * display_regle(Regle * r){

  display_premisse(r);
  printf("%s",r->conclusion->contenu_proposition);

}

void display_premisse(Regle * r){

}

Regle * remove_head_premisse(Regle * r){

	Premisse * p = r->premisse_regle;

	if (p != NULL){

		r->premisse_regle=p->next;
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
		free(r);

	}
	return p;

}
