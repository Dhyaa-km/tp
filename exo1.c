#include <stdio.h>

typedef struct{
    char name[20];
    int age;
} etudiant;

int main(){
    etudiant e1, etudNbr[3];
    FILE *f1, *f2;
    int name = 2;
    char str[50];

    f1 = fopen("fichier.txt", "r");
    if (f1 = NULL)
    {
        printf("invalid opning file");
        return 1;
    }
        //   fwrite(&e1, sizeof(etudiant), 1, f1);
        // fread(&etudNbr, sizeof(etudiant), 3, f1);
    while (fgets(str, 50, f1 ) != NULL)
    {
        printf("%s", str);
    }
    
    
    
    fclose(f1);
    

    return 0;
}