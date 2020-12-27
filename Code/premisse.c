#include "premisse.h"

/*recursif pour gagner en efficacite, affiche l'ensemble des premisses d'une regle*/
void display_premisse(Premisse * p){
  if (p==NULL){
    printf("Empty premise!\n");
  } else {
    display_proposition(p->contenu_premisse);
    if(p->next != NULL){
      display_premisse(p->next);
    }
  }
  return NULL;
}

void delete_premisse(Premisse * p) {
  delete_proposition(p->contenu_premisse);
  free(p);
  return NULL;
}

//TODO: si premier element est le bon, marche pas
void link_premisse(Premisse * p ,const char * c){
  Premisse * pnext = p;
  Premisse * plast = search_prop(c,p);
  while (pnext->next !=NULL && plast != NULL){
    if (pnext->next==plast){
      pnext = p->next->next;
      delete_premisse(p->next);
      printf("Proposition deleted!\n");
      p->next = pnext;
      plast = NULL;
    }
    pnext=pnext->next;
  }
  return NULL;
}
