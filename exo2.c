#include <stdio.h>
#include <stdlib.h>



int main(){
    FILE *f , *f2 , *temp;
    int x, n, i;

    printf("give N: ");
    scanf("%d", &n);

    f = fopen("Integer1.dat", "wb");
     if (f == NULL)
    {
        printf("error opening file");
        return 1;
    }

    for ( i = 0; i < n; i++)
    {
        printf("give an integer X: ");
        scanf("%d", &x);
        fwrite(&x, sizeof(int), 1, f);
    }
    fclose(f);

    f = fopen("Integer1.dat", "rb");
    f2 = fopen("Integer2.dat", "wb");
    temp = fopen("temp.dat", "wb");
    if (f == NULL || f2 == NULL || temp == NULL) {
        printf("error opening file(s)\n");
        return 1;
    }

    printf("the content of Integer1(original): ");
    for ( i = 0; i < n; i++)
    {
        fread(&x, sizeof(int), 1, f);
        printf("%d ", x);

        if (x % 2 == 0)
        {
            fwrite(&x, sizeof(int), 1, f2);
        }else
        {
            fwrite(&x, sizeof(int), 1, temp);
        }
    }
    fclose(f);
    fclose(f2);
    fclose(temp);

    remove("Integer1.dat");
    rename("temp.dat", "Integer1.dat");

    f2 = fopen("Integer2.dat", "rb");
    if (f2 == NULL)
    {
        printf("error opening file");
        return 1;
    }

    printf("\n");
    printf("content of Integer2: ");

    while (fread(&x, sizeof(int), 1, f2) == 1)
    {
        printf("%d ", x);
    }
    
    fclose(f2);

    return 0;
}