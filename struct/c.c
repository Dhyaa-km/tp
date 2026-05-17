#include <stdio.h>

typedef struct
{
    int id;
    char name[20];
    float note;
} Student;

int main()
{
    FILE *f;
    int n, i;

    // Number of students
    printf("Enter number of students: ");
    scanf("%d", &n);

    Student tab[n];

    // =========================
    // WRITE INTO BINARY FILE
    // =========================

    f = fopen("students.dat", "wb");

    if(f == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    // Input data
    for(i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &tab[i].id);

        printf("Enter Name: ");
        scanf("%s", tab[i].name);

        printf("Enter Note: ");
        scanf("%f", &tab[i].note);

        fwrite(&tab[i], sizeof(Student), 1, f);
    }

    fclose(f);

    printf("\nData written successfully.\n");

    // =========================
    // READ FROM BINARY FILE
    // =========================

    // Open file in read binary mode
    f = fopen("students.dat", "rb");

    if(f == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // Read structs from file
    fread(tab, sizeof(Student), n, f);

    fclose(f);

    // Display data
    printf("\n--- Students Data ---\n");

    for(i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("ID   : %d\n", tab[i].id);
        printf("Name : %s\n", tab[i].name);
        printf("Note : %.2f\n", tab[i].note);
    }

    return 0;
}