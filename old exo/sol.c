#include <stdio.h> 
#include <stdlib.h> 
 
void fill_file() 
{ 
    FILE * f = fopen("entier.txt", "w"); 
 
    int n,x , i ; 
 
    if(f==NULL) 
    { 
      printf("error in opening our file \n"); 
    } 
 
 
    printf("Enter the number of elements to enter: \n "); 
    scanf("%d", &n); 
 
    for(i=0; i<=n-1; i++) 
    { 
        printf("Enter an integer : \n"); 
        scanf("%d", &x); 
 
        fprintf(f, "%d ", x); 
    } 
 
    fclose(f); 
 
} 
 
 
 
 
 
int minimum () 
{ 
    FILE * f =fopen("entier.txt", "r"); 
 
    int min,x; 
 
    fscanf(f, "%d", &x); 
    min=x; 
 
    while(fscanf(f, "%d", &x)==1 ) 
    { 
        if (x < min) 
            min =x; 
    } 
 
    fclose(f); 
 
    return min; 
 
} 
 
 
 
 
float average() 
{ 
    FILE * f= fopen("entier.txt", "r"); 
    float avg; 
    int x; 
    int sum, cpt; 
    sum=0; 
    cpt=0; 
 
    while(fscanf(f, "%d", &x)==1) 
    { 
        sum= sum + x; 
        cpt = cpt+1; 
    } 
    avg= (float) sum/cpt; 
    fclose(f); 
    return avg; 
} 
 
 
 
 
void fill_admis() 
{ 
    FILE * f1 = fopen("moyenne.txt", "w"); 
    FILE * f2= fopen("entier.txt", "r"); 
 
    int x; 
    float avg = average(); 
 
    while(fscanf(f2, "%d", &x) ==1) 
    { 
        if(x > avg) 
        { 
            fprintf(f1, "%d ", x); 
        } 
    } 
    fclose(f1); 
    fclose(f2); 
 
} 
 
 
 
void display_file() 
{ 
    FILE * f= fopen ("moyenne.txt", "r"); 
 
    int x, cpt; 
    cpt=0; 
    while(fscanf(f, "%d", &x) ==1) 
    { 
        cpt= cpt+1; 
        printf("Value Number%d == %d \n", cpt, x); 
    } 
 
    printf(" The number of elments of the file Moyenne.txt == %d  \n", cpt); 
    fclose(f); 
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