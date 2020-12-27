#include "baseconnaissance.h"

BC create_base(){
  BC newel=NULL;
  return newel;
}

Regle * create_regle(BC b){
  Regle * newel = (Regle*)calloc(sizeof(Regle));
  newel->premisse_regle=NULL;
  newel->next=NULL;
  newel->conclusion=NULL;
  if (b==NULL){
    newel->id=1;
    b=newel;
  } else{
    Regle * temp = b;
    while (temp->next!=NULL){
      temp=temp->next
    }
    newel->id = temp->id+1;
    temp->next = newel;
  }
  return b;
}

void delete_bc(BC b){
  if (b!=NULL){
    if(b->next!=NULL){
      delete_bc(b->next);
    }
    delete_regle(b);
  }
  return NULL;
}

void delete_regle(Regle * r){
  if (r!=NULL){
    delete_proposition(r->conclusion);
    delete_premisse_regle(r->premisse_regle);
    free(r);
  }
  return NULL;
}

void delete_premisse_regle(Premisse * p){
  if (p!=NULL){
    if(p->next!=NULL){
      delete_premisse_regle(p->next);
    }
    delete_premisse(p);
  }
  return NULL;
}

void display_bc(BC b){
  if (b!=NULL){
    display_regle(b);
    printf("\n");
    if(b->next!=NULL){
      display_bc(b->next);
    }
  } else {
    printf("Empty base!\n");
  }
  return NULL;
}

Regle * recherche_id(BC b,int id){ //bien verif que b est pas NULL
  if (id<1){
    printf("ID unavailable!\n"); //id de 0 ou negative impossible
    return NULL;
  } else {
    Regle * temp = b;
    while(temp->id!=id && temp->next!=NULL){
      temp=temp->next;
    }
    if (temp->id==id){
      return temp;
    } else {
      printf("ID too big!\n"); //ara ara
      return NULL;
    }
  }
}

int id_input(){
  int temp;
  printf("ID?\n");
  scanf("%d", &temp);
  return temp;
}
