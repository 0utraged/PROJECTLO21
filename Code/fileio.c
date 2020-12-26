#include "fileio.h"

void read_from_file(BC * b)
{
  int i=0,n=0;
  char tempc[101];
  Regle * tempr;
  FILE * fp;
  fp = fopen("database.txt", "a+");
  if (fp != NULL) {
    fscanf(fp, "%c", &tempc[n] );
    while(fscanf(fp, "%c", &tempc[n] ) != EOF ){

      if(&tempc[n]=='/'){
        tempr = create_regle(b);
        memset(tempc,'\0',101);
        n=0;
      }

      if(&tempc[n]=='&'){
        &tempc[n]='\0';
        ajout_premisse_queue(tempr,tempc);
        memset(tempc,'\0',101);
        n=0;
      }
      if([&tempc[n]==':'){
        &tempc[n]='\0';
        ajout_conclusion(tempr,tempc);
        memset(tempc,'\0',101);
        n=0;
      }
      n++;
      i++;
    }
  }
  else {
    perror("fopen");
    create_regle(b);
  }
  fclose(fp);
  return NULL;
}

void write_to_file(BC * b)
{
  Regle * r = b;
  Premisse * tempp;
  FILE * fp;
  fp = fopen("database.txt", "w");
  if (fp != NULL) {

      while(r!=NULL && r->next!=NULL){

        fprintf(fp, "%c", '/');
        tempp=r->premisse_regle;
        if(r->premisse_regle!=NULL){

          while(tempp!=NULL){

            fprintf(fp, "%c",tempp->contenu_proposition);
            fprintf(fp, "%c", '&');
            tempp=tempp->next;

          }

        }
        if(r->conclusion!=NULL){
          fprintf(fp, "%c",r->conclusion->contenu_proposition);
          fprintf(fp, "%c", ':');
          n=0;
        }
        r=r->next;
      }
  }
  else {
    perror("fopen");
  }
  fclose(fp);
  return NULL;
}
