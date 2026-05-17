#include <stdio.h>

typedef struct Time
{
    int hour;
    int minute;
} Time;
typedef struct Date
{
    int day, month, year;
}Date;
typedef struct Consultation
{
    int id;
    char name[50];
    Date dateCons;
    Time timeCons;
    int duration;
}Consultation;

void ReadConsultation(){
    FILE *f;
    int n = 0 , i;
    Consultation tab[100];

    f = fopen("consultation.txt", "r");

    if (f == NULL)
    {
        printf("error opening file");
        return;
    }

     while (fscanf(f, "%d %s %d %d %d %d %d %d",
                  &tab[n].id,
                  tab[n].name,
                  &tab[n].dateCons.day,
                  &tab[n].dateCons.month,
                  &tab[n].dateCons.year,
                  &tab[n].timeCons.hour,
                  &tab[n].timeCons.minute,
                  &tab[n].duration) == 8)
    {
        n = n + 1;
    }

    fclose(f);
     for (i = 0; i < n; i++)
    {
        printf("\nConsultation %d\n", i + 1);

        printf("ID       : %d\n", tab[i].id);
        printf("Name     : %s\n", tab[i].name);

        printf("Date     : %02d/%02d/%d\n", tab[i].dateCons.day, tab[i].dateCons.month, tab[i].dateCons.year);

        printf("Time     : %02d:%02d\n", tab[i].timeCons.hour, tab[i].timeCons.minute);

        printf("Duration : %d minutes\n", tab[i].duration);
    }
}



int main(){

    ReadConsultation();
    return 0;
}