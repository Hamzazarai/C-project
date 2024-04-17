#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"liste.h"

struct liste* initialisation()
{
    struct liste* l;
    l=(struct liste*)malloc(sizeof(struct liste));
    l->first=NULL;
    l->last=NULL;
    l->dim=0;

}
void add_empty_list(struct liste* l,char* name)
{
  struct element* p;
  p=(struct element*)malloc(sizeof(struct element));
  assert(p);
 strcpy(p->name,name);
  p->next=NULL;
  l->first=p;
  l->last=p;
  l->dim++;
}
void add_first_list(struct liste*l,char*name)
{
  struct element* p;
  p=(struct element*)malloc(sizeof(struct element));
  assert(p);
  strcpy(p->name,name);
  p->next=l->first;
  l->first=p;
  l->dim++;
}
void add_last_list(struct liste* l,char* name)
{
  struct element* p;
  p=(struct element*)malloc(sizeof(struct element));
  assert(p);
  strcpy(p->name,name);
  p->next=NULL;
  l->last->next=p;
  l->last=p;
  l->dim++;
}
void add_to_pos_in_list(struct liste*l,char*name,int pos)
{
  struct element* p;
  struct element* e;/*pour parcourir la liste jusqu'à la position pos */
  int i;
  p=(struct element*)malloc(sizeof(struct element));
  assert(p);
  e=l->first;/* e pointe sur la 1ère position de la liste*/
  for(i=1;i<pos;i++)
   {e=e->next;}
  /* e pointe sur l'element de position pos dans la liste */
 *p=*e;
 e->next=p;
 strcpy(e->name,name);
  l->dim++;
}
void supp_first(struct liste*l)
{
     struct element* p;
     p=l->first;
     l->first=p->next;
     free(p);
     l->dim--;
}
void supp_dans_liste(struct liste* l,int pos)
{
    struct element* p;
    struct element* e;
    int i;
    if(pos<l->dim)/* (pos est saisie >1:sinon on supprime le premier) && (pos< l->dim) */
    {
     e=l->first;/* e pointe sur la 1ère position de la liste*/
     for(i=1;i<pos-1;i++)
      e=e->next;
     /* e pointe sur l'element de position pos-1 dans la liste */
     p=e->next;
     e->next=p->next;
     free(p);
     l->dim--;
    }
    else/*pos==l->dim :l'element à supprimer est le dernier */
    {
        p=l->last;
        e=l->first;
        while(e->next!=l->last)
            e=e->next;
        e->next=NULL;
        l->last=e;
        free(p);
        l->dim--;
    }
}
void supp_liste(struct liste* l)
{
struct element* p;
p=l->first;
l->first=NULL;
l->last=NULL;
l->dim=0;
free(p);
}
void affiche(struct liste*l)
{
    struct element* p;
    int i=1;
    p=l->first;
    printf("\n");
    while(p)
    {
      printf("%d) %s.\n",i,p->name);
      p=p->next;
      i++;
    }
}
void fichier(struct liste*l)
{
    struct element* p;
    int i=1;
    FILE* fic;
    char* nomfic;
    printf("donner le nom du fichier \n ");
    scanf("%s",nomfic);
    p=l->first;
    fic=fopen(nomfic,"w");
    if(!fic)
    {
        printf("le fichier n'a pas été crée !");
        exit(-1);
    }
    while(p)
    {
        fprintf(fic,"%d)\t%s\n",i,p->name);
        i++;
        p=p->next;
    }
    fclose(fic);
    printf("\n");

}
