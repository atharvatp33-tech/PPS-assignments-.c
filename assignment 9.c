#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *src, *dest;
    char srcName[100], destName[100];
    int ch;

    printf("Enter source file name: ");
    scanf("%99s", srcName);

    printf("Enter destination file name: ");
    scanf("%99s", destName);

    src = fopen(srcName, "r");
    if (src == NULL) {
        printf("Error: cannot open source file '%s'.\n", srcName);
        return 1;
    }

    dest = fopen(destName, "w");
    if (dest == NULL) {
        printf("Error: cannot create destination file '%s'.\n", destName);
        fclose(src);
        return 1;
    }

    /* Copy character by character until end of file */
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    printf("File copied successfully.\n");

    fclose(src);
    fclose(dest);

    return 0;
}
