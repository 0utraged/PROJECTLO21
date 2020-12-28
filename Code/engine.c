#include "engine.h"

void marks_true_fact(BC b, char* c){
  if (b->next!=NULL){
    marks_true_fact(b->next,c);
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

bool confirmation(){
  char c;
  do{
    printf("Are you sure you want to do this? Y/N:\n");
    scanf("%c",&c);
    if (c!='y'&&c!='Y'&&c!='n'&&c!='N'){
      printf("Enter a valid answer please!\n");
    }
  } while (c!='y'&&c!='Y'&&c!='n'&&c!='N');
  if (c=='y'||c=='Y'){
    return true;
  } else {
    return false;
  }
}

void engine(BC b){
  int menu=0;
  do {
    printf("What do you want to do? Enter the proper number:\n 1:Enter a fact.\n 2:Launch the engine, get all possible conclusions from your facts and exit engine.\n 3:Exit engine now.\n ");
      scanf("%d",&menu);
      switch(menu){
        case 1: printf("Please enter your fact (max 100 characters):\n");
        char * temp_input = create_str(input());
        printf("Your fact is: %s\n",temp_input);
        if(confirmation()==true){
          marks_true_fact(b, temp_input);
        }
        break;

        case 2: if(confirmation()==true){
          printf("The possible conclusions are:\n");
          conclusion_check_global(b,b);
          menu = 9;
        }
        break;

        case 3: if(confirmation()==true){
          printf("Exiting engine.\n");
          menu = 9;
        }
        break;

        default: menu = 0;
        printf("Please enter a valid option!\n");
      }
  } while (menu!=9);
  reinit_bool(b);
  return NULL;
}
