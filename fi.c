#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *infos;
    char str[50];

    // Open the file in read mode
    infos = fopen("informations.txt", "r");

    // Check if file opened successfully
    if (infos == NULL) {
        printf("Error: cannot open the file.\n");
        return 1;
    }

    // Read and print the file line by line
    while (fgets(str, 50, infos) != NULL) {
        printf("%s", str);
    }

    fclose(infos);

    return 0;
}