#ifndef REGLE
#define REGLE

typedef struct regle {

  Premisse premisse_regle ;
  Proposition * conclusion ;

} Regle ;

Proposition * ajout_premisse_queue(Regle * r, Proposition * p )

Proposition * ajout_conclusion_queue(Regle * r, Proposition * p )

//Tester si une proposition appartient à la prémisse d’une règle, de manière récursive:
bool is_in_premisse(Proposition * search, Premisse_elem * prem)

bool is_empty_premisse(Regle * r)

Proposition * get_conclusion(Regle r) // should print

void search_remove_prop(Proposition * p, Regle * r)

bool is_empty_premisse(Regle * r)

Regle * display_regle(Regle * r) //(uses display_premisse), on print simplement la conclusion en plus

void display_premisse(Regle * r) // récursif, utilise display_proposition


#endif
