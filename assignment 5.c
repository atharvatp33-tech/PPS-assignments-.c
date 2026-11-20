/* Simple menu-driven program for string operations */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Read a string (with spaces) and remove the newline */
void input(char *msg, char *str)
{
    printf("%s", msg);
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
}

int main()
{
    char s1[100], s2[100], temp[200];
    int choice, i, n;

    do {
        printf("\n----- STRING OPERATIONS MENU -----\n");
        printf("1. Length          (strlen)\n");
        printf("2. Copy            (strcpy)\n");
        printf("3. Concatenate     (strcat)\n");
        printf("4. Lowercase       (tolower)\n");
        printf("5. Uppercase       (toupper)\n");
        printf("6. Compare         (strcmp)\n");
        printf("7. Reverse         (strrev logic)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();                      /* remove leftover newline */

        switch (choice) {
        case 1:
            input("Enter a string: ", s1);
            printf("Length = %d\n", (int)strlen(s1));
            break;

        case 2:
            input("Enter a string: ", s1);
            strcpy(s2, s1);
            printf("Copied string = %s\n", s2);
            break;

        case 3:
            input("Enter first string : ", s1);
            input("Enter second string: ", s2);
            strcpy(temp, s1);
            strcat(temp, s2);
            printf("Joined string = %s\n", temp);
            break;

        case 4:
            input("Enter a string: ", s1);
            for (i = 0; s1[i] != '\0'; i++)
                s1[i] = tolower(s1[i]);
            printf("Lowercase = %s\n", s1);
            break;

        case 5:
            input("Enter a string: ", s1);
            for (i = 0; s1[i] != '\0'; i++)
                s1[i] = toupper(s1[i]);
            printf("Uppercase = %s\n", s1);
            break;

        case 6:
            input("Enter first string : ", s1);
            input("Enter second string: ", s2);
            if (strcmp(s1, s2) == 0)
                printf("Strings are equal\n");
            else
                printf("Strings are not equal\n");
            break;

        case 7:
            input("Enter a string: ", s1);
            n = strlen(s1);
            for (i = 0; i < n; i++)
                temp[i] = s1[n - 1 - i];
            temp[n] = '\0';
            printf("Reversed string = %s\n", temp);
            break;

        case 0:
            printf("Exiting program. Good luck!\n");
            break;

        default:
            printf("Invalid choice, try again.\n");
        }
    } while (choice != 0);

    return 0;
}
