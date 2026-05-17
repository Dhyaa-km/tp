#include <stdio.h>
#include <string.h>

typedef struct
{
    int numero;
    char nom[50];
    char poste[50];
} joueur;

// Function that returns one joueur
joueur remplirInfos()
{
    joueur j;

    printf("Enter numero: ");
    scanf("%d", &j.numero);

    printf("Enter nom: ");
    scanf("%s", j.nom);

    printf("Enter poste: ");
    scanf("%s", j.poste);

    return j;
}

int main()
{
    int n, i;

    printf("Give the number of joueurs: ");
    scanf("%d", &n);

    // Array of joueurs
    joueur j[n];

    // Fill the array using the function
    for (i = 0; i < n; i++)
    {
        printf("\n--- Joueur %d ---\n", i + 1);

        j[i] = remplirInfos();
    }

    // Display all joueurs
    printf("\n===== LIST OF JOUEURS =====\n");

    for (i = 0; i < n; i++)
    {
        printf("\nJoueur %d\n", i + 1);
        printf("Numero : %d\n", j[i].numero);
        printf("Nom    : %s\n", j[i].nom);
        printf("Poste  : %s\n", j[i].poste);
    }

    return 0;
}