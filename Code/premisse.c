#include "premisse.h"

/*recursif pour gagner en efficacite, affiche l'ensemble des premisses d'une regle*/
void display_premisse(Premisse_elem * p){

  display_proposition(p->contenu_premisse);
  Premisse_elem * next_p;
  if(next_p != NULL){

    next_p = p->next;
    display_premisse(next_p);

  }
  return NULL;
}

void delete_premisse(Premisse_elem * p) {
  delete_proposition(p->contenu_premisse);

  return NULL;
}
