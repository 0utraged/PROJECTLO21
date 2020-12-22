#ifndef PROPOSITION
#define PROPOSITION

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_structs.h"

/*TODO: GENERAL PROJECT: 1. fonctions 2. moteur 3. boucle main = menu 4. reprendre une BC (init) puis sauvergarde si voulu (exit) */

/*La structure Regle (List of Lists) est une liste d'adresses vers des listes d'éléments de structure ListElement*/

//Une règle se lit de la manière suivante : si la prémisse est vraie alors on déduit que la
//conclusion est vraie.
//On considère une règle comme une liste de propositions, dont le dernier élément est la
//conclusion de la règle.

Proposition * display_proposition(Proposition * p); //affiche le contenu

void delete_proposition(Proposition * p);  //récursif

void set_bool(Proposition * p, bool b);

char * create_str(char * input);

#endif
/*

imposees:
Créer une règle vide,
o Ajouter une proposition à la prémisse d’une règle, l’ajout se fait en queue
o Créer la conclusion d’une règle
o Tester si une proposition appartient à la prémisse d’une règle, de manière récursive
o Supprimer une proposition de la prémisse d’une règle
o Tester si la prémisse d’une règle est vide
o Accéder à la proposition se trouvant en tête d’une prémisse
o Accéder à la conclusion d’une règle
o Créer une base vide
o Ajouter une règle à une base, l’ajout peut se faire en queue
o Accéder à la règle se trouvant en tête de la base

List recherche(List l, int c) {

    prod *tmp=l;
    while(tmp != NULL)
    {
        if(tmp->codeP == c)
        { Si l'élément a la valeur recherchée, on renvoie son adresse
	tmp->next=NULL;

	return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

Dl_List insert_head(Dl_List l, char* w)
{
	Dl_List newel;
	newel=(DListElement *)malloc(sizeof(DListElement));
	newel->word=malloc(strlen(w)+1);
	strcpy(newel->word, w);
	newel->next=l;
	newel->prev=NULL;
	if(l!= NULL){
		l->prev=newel;
	}

	return newel;
}


Dl_List insert_tail(Dl_List l, char* w)
{

	Dl_List newel;
	Dl_List p=NULL;
	newel=(DListElement *)malloc(sizeof(DListElement));
	newel->word=malloc(strlen(w)+1);
	strcpy(newel->word, w);
	newel->next=NULL;
	newel->prev=NULL;
	if(l == NULL)
	{
		l=newel;
	}
	else
	{

		p= l;

		while (p->next !=NULL)
		{
			p=p->next;
		}

		p->next=newel;
		newel->prev=p;
	}
	return l;
}


Dl_List remove_head(Dl_List l)
{
	Dl_List p;
	if (l == NULL)
	{
		p=NULL;
	}
	else
	{
		p=l->next;
		if(p!=NULL){
			p->prev=NULL;
		}
		free(l);
	}
	return p;
}

Dl_List remove_tail(Dl_List l)
{
	if (l != NULL){

		if (l->next == NULL)
		{
			free(l);
			l=NULL;
		}
		else
		{
			Dl_List p=l;

			while (p->next->next !=NULL)
			{
				p=p->next;
			}

			free(p->next);
			p->next=NULL;
		}

	}


	return l;

}

void print_list(Dl_List l)
{

	if( is_empty(l) )
	{
		printf(" *** EMPTY LIST *** \n");
	}
	else
	{
		Dl_List p=l;

		printf ("[ " );
		while (p->next !=NULL)
		{
			printf("%s ", p->word);
			p=p->next;
		}
		printf ("%s ]\n",p->word);
	}
}
*/
