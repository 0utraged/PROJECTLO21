#include "engine.h"

void marks_true_fact(BC b, char* c){
  if (b->next!=NULL){
    marks_true_fact(b->next);
  }
  Premisse * p=search_prop(c,p);
  if(p!=NULL){
    set_bool(p->contenu_premisse, true);
  }
  return NULL;
}

bool conclusion_check(Regle * r){
  bool something_changed=false;
  if(check_premisse(r->premisse_regle)==true){
    set_bool(r->conclusion,true);
    something_changed=true;
  }
  return something_changed;
}

bool check_premisse (Premisse * p){
  if (p==NULL){
    return true;
  } else {
    if (p->contenu_premisse->is_true==false){
      return false;
    } else if (p->next==NULL){
      return true;
    } else {
      return check_premisse(p->next);
    }
  }
}

void conclusion_check_global (BC b, BC origin_point){
  if (b->next!=NULL){
    conclusion_check_global(b->next,origin_point);
  }
  if (b->conclusion!=NULL && b->conclusion->is_true==false){
    //les conclusions vides ou deja verifiees sont triees ici
    bool check = conclusion_check(b);
    if (check == true){
      printf("%s\n",b->conclusion->contenu_proposition);
      marks_true_fact(origin_point,b->conclusion->contenu_proposition);
      conclusion_check_global(b->next,origin_point);
      //pas besoin de recheck la conclusion actuelle, on recommence a la suite
    }
  }
  return NULL;
}

void reinit_bool(BC b){
  if (b!=NULL){
    if (b->next!=NULL){
      reinit_bool(b->next);
    }
    if(b->conclusion!=NULL){
      set_bool(b->conclusion, false);
    }
    reinit_premisse(b->premisse_regle);
  }
  return NULL;
}

void reinit_premisse(Premisse * p){
  if(p!=NULL){
    if(p->next!=NULL){
      reinit_premisse(p->next);
    }
    set_bool(p->contenu_premisse,false);
  }
  return NULL;
}

void engine(BC b){
  //TODO: voir comment on gere base de faits pour appeler marks_true_fact suffisamment de fois
  printf("The possible conclusions are:\n");
  conclusion_check_global(b,b);
  reinit_bool(b);
  return NULL;
}
