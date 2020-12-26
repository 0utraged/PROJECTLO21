#include "premisse.h"

/*recursif pour gagner en efficacite, affiche l'ensemble des premisses d'une regle*/
void display_premisse(Premisse * p){

  display_proposition(p->contenu_premisse);
  Premisse_elem * next_p;
  if(next_p != NULL){
    next_p = p->next;
    display_premisse(next_p);
  }
  return NULL;
}

void delete_premisse(Premisse * p) {
  delete_proposition(p->contenu_premisse);
  free(p);
  return NULL;
}

void link_premisse(Premisse * p ,const char * c){
  Premisse * pnext = p;
  Premisse * plast = search_prop(c,p);
  while (pnext->next !=NULL && plast != NULL){
    if (pnext->next==plast){
      pnext = p->next->next;
      delete_premisse(p->next);
      printf("Proposition deleted!\n");
      p->next = pnext;
      return NULL;
    }
    pnext=pnext->next;
  }
  return NULL;
}
