#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
#include<assert.h>
#include"liste.h"
void invalide()
{
    printf("Votre choix n'est pas valide !!!\n");
    printf("Tapez une touche pour revenir au menu.\n");
    getch();
}

char* saisie_nom()
{
    char* nom;
    nom=(char*)malloc(50);
    assert(nom);
    printf("Donnez le nom de l'éudiant:");
    scanf("%s",nom);
    printf("Tapez une touche du clavier");
    getch();
    printf("\n");
    return nom;
}
int saisie_pos(struct liste*l)
{
    int i;
do{
printf("Donnez la position dans la liste.");
scanf("%d",&i);}while((i<=1)&&(i>=l->dim));
return i;
}

void menu(struct liste* l)
{
int c;
while(1)
{
 if(l==NULL)
   {
           printf("\n         *******      Gestion des étudiants      ******* \n\n");
                   printf("          ============================================= \n\n");
           printf("     <0>.  Initialiser la liste.--------------------------------- \n");
           printf("     <1>.  Quitter.---------------------------------------------- \n");
           printf("Entrez votre choix : ");
           scanf("%d",&c);
           printf("\n\n");
           switch(c)
           {
               case 0:{ l=initialisation();printf("La liste a été crée.");break;}
               case 1: exit(0);break;
               default : {invalide();
                          menu(l);
                        }

           }

}
 /*else*/ if(l->dim==0)
{
    printf("\n        *******      Gestion des étudiants      ******* \n\n");
            printf("          ============================================= \n\n");
                              printf("  Total des étudiants : %d\n\n",l->dim);
            printf("     <0>.  Afficher la liste.----------------------------------- \n");
            printf("     <1>.  Ajouter un étudiant.--------------------------------- \n");
            printf("     <2>.  Supprimer un étudiant.------------------------------- \n");
            printf("     <3>.  Quitter.--------------------------------------------- \n");
            printf("Entrez votre choix : ");
            scanf("%d",&c);
            printf("\n\n");
            switch(c)
            {
               case 0: printf("La liste est vide!\n");break;
               case 1: {add_empty_list(l,saisie_nom());printf("l'étudiant est ajouté.\n");break;}
               case 2: printf("La liste est vide!\n");break;
               case 3: exit(0);break;
               default : {invalide();
                          menu(l);
                         }
           }
}
/*else*/ if (l->dim==1)
{
    printf("\n        *******      Gestion des étudiants      ******* \n\n");
            printf("          ============================================= \n\n");
                              printf("  Total des étudiants : %d\n\n",l->dim);
            printf("     <0>.  Afficher la liste.----------------------------------- \n");
            printf("     <1>.  Ajouter un étudiant.--------------------------------- \n");
            printf("     <2>.  Supprimer un étudiant de la liste.------------------- \n");
            printf("     <3>.  Enregistrer la liste dans un fichier.---------------- \n");
            printf("     <4>.  Quitter.--------------------------------------------- \n");
            printf("Entrez votre choix : ");
            scanf("%d",&c);
            printf("\n\n");
           switch(c)
           {
               case 0: affiche(l);break;
               case 1:{
                    printf("     <0>.  Ajouter au début de la liste.---------------- \n");
                    printf("     <1>.  Ajouter à la fin de la liste.---------------- \n");
                    printf("Entrez votre choix : ");
                    scanf("%d",&c);
                    printf("\n\n");
                    switch(c){
                        case 0: add_first_list(l,saisie_nom());break;
                        case 1: add_last_list(l,saisie_nom());break;
                        default : {invalide();
                          menu(l);
                                  }
                             }
                    break;}
               case 2: supp_liste(l);break;
               case 3: fichier(l);break;
               case 4: exit(0);break;
               default : {invalide();
                          menu(l);
                         }
            }
}

/*else */if(l->dim==2)/* la liste contient 2 etudiants*/
{
          printf("\n        *******      Gestion des étudiants      ******* \n\n");
            printf("          ============================================= \n\n");
                              printf("  Total des étudiants : %d\n\n",l->dim);
            printf("     <0>.  Afficher la liste.----------------------------------- \n");
            printf("     <1>.  Ajouter un étudiant.--------------------------------- \n");
            printf("     <2>.  Supprimer un étudiant de la liste.------------------- \n");
            printf("     <3>.  Supprimer toute la liste.---------------------------- \n");
            printf("     <4>.  Enregistrer la liste dans un fichier.---------------- \n");
            printf("     <5>.  Quitter.--------------------------------------------- \n");
            printf("Entrez votre choix : ");
           scanf("%d",&c);
           printf("\n\n");
            switch(c)
           {
               case 0:affiche(l) ;break;
               case 1:{
            printf("     <0>.  Ajouter au début de la liste.------------------------ \n");
            printf("     <1>.  Ajouter à la fin dela liste.------------------------- \n");
            printf("     <2>.  Ajouter au milieu de la liste.----------------------- \n");
            printf("     <3>.  Quitter.--------------------------------------------- \n");
            printf("Entrez votre choix : ");
            scanf("%d",&c);
            printf("\n\n");
            switch(c){
               case 0: add_first_list(l,saisie_nom());break;
               case 1: add_last_list(l,saisie_nom());break;
               case 2: add_to_pos_in_list(l,saisie_nom(),2);break;
               case 3: exit(0);break;
               default : {invalide();
                          menu(l);
                         }
                      }
                 break;}
               case 2:{
            printf("     <0>.  Supprimer du début de la liste.---------------------- \n");
            printf("     <1>.  Supprimer de la fin de la liste.--------------------- \n");
            printf("     <2>.  Quitter.--------------------------------------------- \n");
            printf("Entrez votre choix : ");
            scanf("%d",&c);
            printf("\n\n");
            switch(c){
               case 0: supp_first(l);break;
               case 1: supp_dans_liste(l,2);break;
               case 2: exit(0);break;
               default : {invalide();
                          menu(l);
                         }
                      }
                 break;}
               case 3: supp_liste(l);break;
               case 4: fichier(l);break;
               case 5: exit(0);break;
               default : {invalide();
                          menu(l);
                         }
            }

}
/*else*/if(l->dim>2)/*la liste contient plusieurs étudiants >2*/
{
  printf("\n        *******      Gestion des étudiants      ******* \n\n");
            printf("          ============================================= \n\n");
                              printf("  Total des étudiants : %d\n\n",l->dim);
            printf("     <0>.  Afficher la liste.----------------------------------- \n");
            printf("     <1>.  Ajouter un étudiant.--------------------------------- \n");
            printf("     <2>.  Supprimer un étudiant de la liste.------------------- \n");
            printf("     <3>.  Supprimer toute la liste.---------------------------- \n");
            printf("     <4>.  Enregistrer la liste dans un fichier.---------------- \n");
            printf("     <5>.  Quitter.--------------------------------------------- \n");
            printf("Entrez votre choix : ");
           scanf("%d",&c);
           printf("\n\n");
            switch(c)
           {
               case 0:affiche(l) ;break;
               case 1:{
            printf("     <0>.  Ajouter au début de la liste.------------------------ \n");
            printf("     <1>.  Ajouter à la fin de la liste.------------------------ \n");
            printf("     <2>.  Ajouter à une position de la liste.------------------ \n");
            printf("     <3>.  Quitter.--------------------------------------------- \n");
            printf("Entrez votre choix : ");
            scanf("%d",&c);
            printf("\n\n");
            switch(c){
               case 0: add_first_list(l,saisie_nom());break;
               case 1: add_last_list(l,saisie_nom());break;
               case 2: add_to_pos_in_list(l,saisie_nom(),saisie_pos(l));break;
               case 3: exit(0);break;
               default : {invalide();
                          menu(l);
                         }
                      }
                 break;}
               case 2:{
            printf("     <0>.  Supprimer du début de la liste.---------------------- \n");
            printf("     <1>.  Supprimer de la fin de la liste.--------------------- \n");
            printf("     <2>.  Supprimer d'une position de la liste.---------------- \n");
            printf("     <3>.  Quitter.--------------------------------------------- \n");
            printf("Entrez votre choix : ");
            scanf("%d",&c);
            printf("\n\n");
            switch(c){
               case 0: supp_first(l);break;
               case 1: supp_dans_liste(l,l->dim);break;
               case 2: supp_dans_liste(l,saisie_pos(l));break;
               case 3: exit(0);break;
               default : {invalide();
                          menu(l);
                         }
                      }
                 break;}
               case 3: supp_liste(l);break;
               case 4: fichier(l);break;
               case 5: exit(0);break;
               default : {invalide();
                          menu(l);
                         }
            }


}
}
}

void main()
{
static struct liste* list;
 list=NULL;

        menu(list);
}
