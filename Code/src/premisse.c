#include "premisse.h"

/*recursif pour gagner en efficacite, affiche l'ensemble des premisses d'une regle*/
void display_premisse(Premisse * p){
  if (p==NULL){
    printf("Empty premise!\n");
  } else {
    printf("Element: ");
    display_proposition(p->contenu_premisse);
    if(p->next != NULL){
      display_premisse(p->next);
    }
  }
  return;
}

void delete_premisse(Premisse * p) {
  delete_proposition(p->contenu_premisse);
  free(p);
  return;
}

//TODO: si premier element est le bon, marche pas
void link_premisse(Regle * r ,const char * c){

    Premisse * pnext = r->premisse_regle;
    Premisse * p = r->premisse_regle;
    Premisse * plast = search_prop(c,r->premisse_regle);
    if (plast==NULL){
        printf("The premise is empty or no match was found !\n");
        return;
    }

    if (r->premisse_regle==plast){

        pnext = r->premisse_regle->next;
        delete_premisse(r->premisse_regle);
        printf("Proposition deleted!\n");
        r->premisse_regle = pnext;

    } else {

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
    }
    return;
}
