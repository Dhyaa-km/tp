#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *filles, *filles2;

    int n, x, i;
    float som = 0, moy;
    printf("give an integer N: ");
    scanf("%d", &n);

    filles = fopen("filles.bin", "wb");
    if (filles == NULL)
    {
        printf("error opening file");
        return 1;
    }

    for ( i = 0; i < n; i++)
    {
        printf("give an integer X %d:", i + 1);
        scanf("%d", &x);
        fwrite(&x, sizeof(int), 1,filles);
    }
    fclose(filles);


    

    filles = fopen("filles.bin", "rb");
    if (filles == NULL)
    {
        printf("error opening file");
        return 1;
    }
    
    for ( i = 0; i < n; i++)
    {
        fread(&x, sizeof(int), 1, filles);
        som += x;
    }

    fclose(filles);


    moy = som / n;

    printf("The sum is: %.2f\n", som);
    printf("The average is: %.2f\n", moy);

    filles = fopen("filles.bin", "rb");
    filles2 = fopen("average.bin", "wb");

    if (filles == NULL || filles2 == NULL)
    {
        printf("error opening file");
        return 1;
        
    }

    for ( i = 0; i < n; i++)
    {
        fread(&x, sizeof(int), 1, filles);
        if (x > moy)
        {
            fwrite(&x, sizeof(int), 1, filles2);
        }
    }
    fclose(filles);
    fclose(filles2);

    filles2 = fopen("average.bin", "rb");

    if (filles2 == NULL)
    {
        printf("error opening file2");
        return 1;
    }

    printf("The numbers that are > average are: ");
    while (fread(&x, sizeof(int), 1, filles2) == 1)
    {
        printf("%d ", x);
    }
    printf("\n");

    fclose(filles2);

    printf("Numbers greater than the average were saved in average.bin\n");


    return 0;
}