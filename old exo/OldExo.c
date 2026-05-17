#include <stdio.h> 
#include <stdlib.h> 
 
void fill_file() 
{
    FILE *f1;
    int n, i, x;
    f1 = fopen("entier.txt", "w");

    printf("give n: ");
    scanf("%d", &n);

    if (f1 == NULL)
    {
        printf("error openning file");
        return;
    }

    for ( i = 0; i < n; i++)
    {
        printf("give x: ");
        scanf("%d", &x);
        fprintf(f1, "%d ", x);
    }
    fclose(f1);
} 
 
 
int minimum () 
{ 
    FILE *f1;
    int n, min, x;
    f1 = fopen("entier.txt", "r");

    if (f1 == NULL)
    {
        printf("error openning file");
        return 1;
    }
    fscanf(f1, "%d", &x);
    min = x;

    while (fscanf(f1, "%d", &x) == 1)
    {
        if (x < min)
        {
            min = x;
        }
        
    }
    fclose(f1);
    return min;
} 
 

float average(){
    float moy , som = 0;
    int cpt = 0, x;


    FILE *f1;
    f1 = fopen("entier.txt", "r");

    if (f1 == NULL)
    {
        printf("error openning file");
        return 1;
    }

    while (fscanf(f1, "%d", &x) == 1)
    {
        som += x;
        cpt++;
    }
    if (cpt != 0)
    {
        moy = som / cpt;
    }else
    {
        moy = 0;
    }
    
    
    fclose(f1);

    return moy;
}
 
 
void fill_admis() 
{
    FILE *f1, *f2;
    int x;

    f1 = fopen("entier.txt", "r");
    f2 = fopen("Moyenne.txt", "w");

    if (f1 == NULL || f2 == NULL)
    {
        printf("error openning file");
        return;
    }
    float moy = average();

    while (fscanf(f1, "%d", &x) == 1)
    {
        if (x > moy)
        {
            fprintf(f2, "%d ", x);
        }
    }
    fclose(f1);
    fclose(f2);
} 
 
 
void display_file() 
{
    int cpt = 0, x;
      FILE *f2;

    f2 = fopen("Moyenne.txt", "r");

    if (f2 == NULL)
    {
        printf("error openning file");
        return;
    }
    printf("les elements de Moyenne.txt : ");
    while (fscanf(f2, "%d", &x ) == 1)
    {
        printf("%d ", x);
        cpt = cpt + 1;
    }
    printf("\n");
    printf("le nombre des elements de Moyenne.txt : %d", cpt);

    fclose(f2);
} 
 
 
int main() 

{ 
    fill_file(); 
 
    int min = minimum(); 
 
    printf("The minimum Value of the file == : %d\n", min); 
 
    float moy =average(); 
    printf("The average of elements == %.2f \n", moy); 
 
    fill_admis(); 
 
    display_file(); 
 
    return 0; 
}
