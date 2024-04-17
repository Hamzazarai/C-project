#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED
struct element{
char* name;
struct element* next;};
struct liste{
int dim;
struct element* first;
struct element* last;};
struct liste* initialisation();
void add_empty_list(struct liste*,char*);
void add_first_list(struct liste*,char*);
void add_last_list(struct liste*,char*);
void add_to_pos_in_list(struct liste*,char*,int);
void supp_first(struct liste*);
void supp_dans_liste(struct liste*,int);
void supp_liste(struct liste*);
void affiche(struct liste*);
void fichier(struct liste*);

#endif // LISTE_H_INCLUDED
