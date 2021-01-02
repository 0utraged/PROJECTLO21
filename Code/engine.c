#include "engine.h"

void marks_true_fact(BC b, char* c){
  Premisse * p = search_prop(c,b->premisse_regle);
  if(p!=NULL){
    set_bool(p->contenu_premisse, true);
  }
    if (b->next!=NULL){
    marks_true_fact(b->next,c);
  }
  return;
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
        if (b->next!=NULL){
            conclusion_check_global(b->next,origin_point);
        }
      //pas besoin de recheck la conclusion actuelle, on recommence a la suite
    }
  }
  return;
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
  return;
}

void reinit_premisse(Premisse * p){
  if(p!=NULL){
    if(p->next!=NULL){
      reinit_premisse(p->next);
    }
    set_bool(p->contenu_premisse,false);
  }
  return;
}

bool confirmation(){
  char c;
  do{
    printf("Are you sure you want to do this? Y/N:\n");
    scanf(" %c",&c);
    if (c!='y'&&c!='Y'&&c!='n'&&c!='N'&&c!='\0'){
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
  int men=0;
  do {
    printf("What do you want to do? Enter the proper number:\n 1:Enter a fact.\n 2:Launch the engine, get all possible conclusions from your facts and exit engine.\n 3:Exit engine now.\n ");
      scanf("%d",&men);
      switch(men){
        case 1: printf("Please enter your fact (max 100 characters):\n");
        input();
        char * temp_input = create_str(input());
        printf("Your fact is: %s\n",temp_input);
        marks_true_fact(b, temp_input);
        break;

        case 2: if(confirmation()==true){
          printf("The possible conclusions are:\n");
          conclusion_check_global(b,b);
          men = 99;
        }
        break;

        case 3: if(confirmation()==true){
          printf("Exiting engine.\n");
          men = 99;
        }
        break;

        default: men= 0;
        printf("Please enter a valid option!\n");
      }
  } while (men!=99);
  reinit_bool(b);
  return;
}

int menu_bf(){
    BC b=create_base();
    int menu = 0;
    int tempid;
    char * c[101];
    Regle * temp = NULL;
    bool boolean = false;
    while(menu!=99){
        if (b==NULL){
            b=create_regle(b);

        }
        printf("\n What do you want to do? Enter the proper number:\n 1:Create a new empty knowledge base.\n 2:Delete the knowledge base.\n 3:Display the entire knowledge base.\n 4:Add a new empty rule.\n 5:Display a rule thanks to its ID.\n 6:Delete a rule thanks to its ID.\n 7:Delete the premise of a rule thanks to its ID.\n 8:Add a proposition to the premise of a rule thanks to its ID.\n 9:Add or change the conclusion of a rule thanks to its ID.\n 10:Check if a proposition is in the premise of a rule thanks to its ID.\n 11:Check if the premise of a rule is empty thanks to its ID.\n 12:Display the conclusion of a rule thanks to its ID.\n 13:Display the premise of a rule thanks to its ID.\n 14:Delete a proposition from the premise of a rule thanks to its ID.\n 15:Display the first proposition of a premise thanks to the ID of the rule.\n 16:Start the engine and begin to give facts.\n 17:Save your changes to the knowledge base.\n 18:Read from database file.\n 19:Exit program.\n 20:Display head rule of database \n");
      scanf("%d",&menu);
       //TODO: IF BASE EMPTY THEN FORCE CREATE IT
      switch(menu){
        case 1:
          if(confirmation()==true){
            delete_bc(b);
            b = create_base();
            printf("New base created.\n");
          }
        break;

        case 2:
          if(confirmation()==true){
            delete_bc(b);
            b=NULL;
            printf("Base deleted, please create a new one!\n");
          }
        break;

        case 3:
          display_bc(b);
        break;

        case 4:
          create_regle(b);
          printf("Empty rule created.\n");
        break;

        case 5:
          printf("Rule:\n");
          display_regle(recherche_id(b,id_input()));
        break;

        case 6: //TODO: FIX THIS
          tempid = id_input();
          if(tempid==b->id){
                temp=b;
                b=b->next;
                delete_regle(temp);
          } else{
            link_regle(b,tempid);
          }
          printf("Rule deleted!\n");
        break;

        case 7:
          temp = recherche_id(b,id_input());
          delete_premisse_regle(temp->premisse_regle);
          temp->premisse_regle=NULL;
          printf("Premise deleted!\n");
        break;

        case 8:
          temp = recherche_id(b,id_input());
          if (temp!=NULL){
            memset(c, '\0', 101);
            input();
            c[0] = input();
            ajout_premisse_queue(temp,c[0]);
          }
        break;

        case 9:
          temp = recherche_id(b,id_input());
          if(temp!=NULL){
            memset(c, '\0', 101);
            input();
            c[0] = input();
            ajout_conclusion(temp,c[0]);
          }
        break;

        case 10:
          temp = recherche_id(b,id_input());
          if(temp!=NULL){
            memset(c, '\0', 101);
            input();
            c[0] = input();
            boolean = is_in_premisse(c[0], temp);
          }
          print_bool(boolean);
        break;

        case 11:
          temp = recherche_id(b,id_input());
          if(temp!=NULL){
            print_bool(is_empty_premisse(temp));
          }else{
            printf("\nNot Assigned\n");
          }

        break;

        case 12:
          temp = recherche_id(b,id_input());
          if (temp!=NULL&&temp->conclusion!=NULL){
            printf("Conclusion: %s\n",temp->conclusion->contenu_proposition);
          }
        break;

        case 13:
          display_premisse(recherche_id(b,id_input())->premisse_regle);
        break;

        case 14:
          temp = recherche_id(b,id_input());
          if (temp!=NULL){
            memset(c, '\0', 101);
            input();
            c[0] = input();
            link_premisse(temp,c[0]);
          }
        break;

        case 15:
          temp = recherche_id(b,id_input());
          if (temp!=NULL&&temp->premisse_regle!=NULL){
            display_proposition(temp->premisse_regle->contenu_premisse);
          }
        break;

        case 16:
          if(confirmation()==true){
            engine(b);
          }
        break;

        case 17:
            write_to_file(b);
        break;

        case 18:
            delete_bc(b);
            b = create_base();
            b = read_from_file(b);

        break;
        case 19:
            if(confirmation()==true){
                printf("Exiting program.\n");
                menu = 99;
            }
        break;
        case 20:
            display_regle(b);
        break;
        default:

          printf("Please enter a valid option!\n");
          menu = 0;
      }

    }
    return NULL;
}
