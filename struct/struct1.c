#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct 
{
    int numero;
    char nom[50];
    char poste[50];
} joueur;





    int main(){
      

        int n;
        do
        {
            printf("give the size of joueur: ");
            scanf("%d", &n);
        } while (n <= 0);
        joueur j[n];

        printf("fill the informations of the joueur:\n ");
       for (int i = 0; i < n; i++)
       {
           printf("enter the number of joueur: ");
           scanf("%d", &j[i].numero);

           printf("enter the name of joueur: ");
           scanf("%s", &j[i].nom);

           printf("enter the post of joueur: ");
           scanf("%s", &j[i].poste);
       }

       printf("\n===== Players Information =====\n");

        for (int i = 0; i < n; i++)
        {
            printf("\nJoueur %d\n", i + 1);
            printf("Numero : %d\n", j[i].numero);
            printf("Nom    : %s\n", j[i].nom);
            printf("Poste  : %s\n", j[i].poste);
        }
       
        


        return 0;
}