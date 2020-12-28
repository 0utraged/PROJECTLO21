#include "fileio.h"

BC read_from_file(BC b)
{
  int i=0,n=0;

  char tempc[101];
  Regle * tempr;
  Regle * firstrule;
  FILE * fp;
  fp = fopen("database.txt", "a+");
  if (fp != NULL) {
    while(fscanf(fp,"%c", &tempc[n] ) != EOF ){
      if(tempc[n]=='/'){
        if(b==NULL){
            b=create_regle(b);
            tempr=b;
            firstrule=tempr;
        } else {
            b=create_regle(b);
            tempr=tempr->next;
        }
        memset(tempc,'\0',101);
        n=-1;
        printf("Rule %d",tempr->id);
      }
      if(tempc[n]=='&'){
        tempc[n]='\0';
        ajout_premisse_queue(tempr,tempc);
        printf("  PE %s",tempc);
        memset(tempc,'\0',101);
        n=-1;

      }
      if(tempc[n]==':'){
        tempc[n]='\0';
        ajout_conclusion(tempr,tempc);
        printf("  C %s\n",tempc);
        memset(tempc,'\0',101);
        n=-1;
      }
      n++;
    }
  }
  else {
    perror("fopen");
    create_regle(b);
  }
  display_bc(b);
  fclose(fp);
  return b;
}

void write_to_file(BC * b)
{
  Regle * r = b;
  Premisse * tempp;
  FILE * fp;
  fp = fopen("database.txt", "w");
  if (fp != NULL) {

      while(r!=NULL){

        fprintf(fp,"%c",'/');
        tempp=r->premisse_regle;
        if(r->premisse_regle!=NULL){

          while(tempp!=NULL){

            fprintf(fp,"%s%c",tempp->contenu_premisse->contenu_proposition,'&');
            tempp=tempp->next;

          }

        }
        if(r->conclusion!=NULL){
          fprintf(fp,"%s%c",r->conclusion->contenu_proposition,':');
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
