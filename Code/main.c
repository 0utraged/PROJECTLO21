#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proposition.h"
#include "premisse.h"
#include "regle.h"
#include "baseconnaissance.h"
#include "engine.h"
#include "list_structs.h"
#include "fileio.h"
#if defined POSIX
  #define CLS system ( "clear" )
#elif defined MSDOS || defined WIN32
  #define CLS system ( "cls" )
#endif


int main(){
  printf("Disclaimer: this program is NOT case sensitive.\n");
  BC b=create_base();
  //TODO: fonction initialisation de la base
  int menu = 0;
  int tempid;
  char * c[101];
  Regle * temp = NULL;
  bool boolean = false;
  do{

    printf("What do you want to do? Enter the proper number:\n 1:Create a new empty knowledge base.\n 2:Delete the knowledge base.\n 3:Display the entire knowledge base.\n 4:Add a new empty rule.\n 5:Display a rule thanks to its ID.\n 6:Delete a rule thanks to its ID.\n 7:Delete the premise of a rule thanks to its ID.\n 8:Add a proposition to the premise of a rule thanks to its ID.\n 9:Add or change the conclusion of a rule thanks to its ID.\n 10:Check if a proposition is in the premise of a rule thanks to its ID.\n 11:Check if the premise of a rule is empty thanks to its ID.\n 12:Display the conclusion of a rule thanks to its ID.\n 13:Display the premise of a rule thanks to its ID.\n 14:Delete a proposition from the premise of a rule thanks to its ID.\n 15:Display the first proposition of a premise thanks to the ID of the rule.\n 16:Start the engine and begin to give facts.\n 17:Save your changes to the knowledge base.\n 18:Exit program.\n ");
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
          b=create_regle(b);
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
            boolean = is_in_premisse(c, temp);
          }
          print_bool(boolean);
        break;

        case 11:
          temp = recherche_id(b,id_input());
          if(temp!=NULL){
            boolean = is_empty_premisse(temp);
          }
          print_bool(boolean);
        break;

        case 12:
          temp = recherche_id(b,id_input());
          if (temp!=NULL){
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
          if (temp!=NULL){
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
          if(confirmation()==true){
            printf("Exiting program.\n");
            menu = 99;
          }
        break;

        default:
          menu = 0;
          printf("Please enter a valid option!\n");
      }
  } while(menu!=99);
  return EXIT_SUCCESS;
}
