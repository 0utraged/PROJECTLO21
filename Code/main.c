#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proposition.h"
#include "premisse.h"
#include "regle.h"
#include "baseconnaissance.h"
#include "engine.h"
#include "list_structs.h"

int main(){
  printf("Disclaimer: this programm is NOT case sensitive.\n");
  BC b;
  //TODO: fonction initialisation de la base
  int menu = 0;
  do{
    printf("What do you want to do? Enter the proper number:\n
      1:Create a new empty knowledge base.\n
      2:Delete the knowledge base.\n
      3:Display the entire knowledge base.\n
      4:Add a new empty rule.\n
      5:Display a rule thanks to its ID.\n
      6:Delete a rule thanks to its ID.\n
      7:Delete the premise of a rule thanks to its ID.\n
      8:Add a proposition to the premise of a rule thanks to its ID.\n
      9:Add or change the conclusion of a rule thanks to its ID.\n
      10:Check if a proposition is in the premise of a rule thanks to its ID.\n
      11:Check if the premise of a rule is empty thanks to its ID.\n
      12:Display the conclusion of a rule thanks to its ID.\n
      13:Display the premise of a rule thanks to its ID.\n
      14:Delete a proposition from the premise of a rule thanks to its ID.\n
      15:Display the first proposition of a premise thanks to the ID of the rule.\n
      16:Start the engine and begin to give facts.\n
      17:Save your changes to the knowledge base.\n
      18:Exit program.\n
      ");
      scanf("%d",&menu);
      switch(menu){
        case 1:
        break;

        case 2:
        break;

        case 3:
        break;

        case 4:
        break;

        case 5:
        break;

        case 6:
        break;

        case 7:
        break;

        case 8:
        break;

        case 9:
        break;

        case 10:
        break;

        case 11:
        break;

        case 12:
        break;

        case 13:
        break;

        case 14:
        break;

        case 15:
        break;

        case 16:
        break;

        case 17:
        break;

        case 18:
          menu=99;
        break;

        default:
          menu = 0;
          printf("Please enter a valid option!\n");
      }
  } while(menu!=99);
  return EXIT_SUCCESS;
}
