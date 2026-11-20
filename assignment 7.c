#include <stdio.h>

#define MAX_STUDENTS 50
#define NUM_SUBJECTS 3

struct Student {
    int roll_no;
    char name[50];
    float marks[NUM_SUBJECTS];
    float total;
    float percentage;
    char grade;
    char result[5];   // "Pass" or "Fail"
};

int main() {
    struct Student s[MAX_STUDENTS];
    int n, i, j;

    printf("Enter number of students (max %d): ", MAX_STUDENTS);
    scanf("%d", &n);

    if (n < 1 || n > MAX_STUDENTS) {
        printf("Invalid number of students.\n");
        return 1;
    }

    /* Accept student details */
    for (i = 0; i < n; i++) {
        printf("\n--- Enter details of student %d ---\n", i + 1);

        printf("Roll number: ");
        scanf("%d", &s[i].roll_no);

        printf("Name: ");
        scanf(" %49[^\n]", s[i].name);   // reads name with spaces

        s[i].total = 0;
        int failed = 0;

        for (j = 0; j < NUM_SUBJECTS; j++) {
            printf("Marks in subject %d (out of 100): ", j + 1);
            scanf("%f", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
            if (s[i].marks[j] < 40)
                failed = 1;
        }

        s[i].percentage = s[i].total / NUM_SUBJECTS;

        /* Determine result and grade */
        if (failed) {
            sprintf(s[i].result, "Fail");
            s[i].grade = 'F';
        } else {
            sprintf(s[i].result, "Pass");
            if (s[i].percentage >= 75)
                s[i].grade = 'A';
            else if (s[i].percentage >= 60)
                s[i].grade = 'B';
            else if (s[i].percentage >= 50)
                s[i].grade = 'C';
            else
                s[i].grade = 'D';
        }
    }

    /* Display results */
    printf("\n\n=========================== STUDENT RESULTS ===========================\n");
    printf("%-6s %-20s %-8s %-8s %-8s %-6s %-6s\n",
           "Roll", "Name", "Total", "Percent", "Grade", "Result", "");
    printf("-----------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-6d %-20s %-8.2f %-8.2f %-8c %-6s\n",
               s[i].roll_no,
               s[i].name,
               s[i].total,
               s[i].percentage,
               s[i].grade,
               s[i].result);
    }
    printf("=======================================================================\n");

    return 0;
}
