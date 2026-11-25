
#include <stdio.h>
#include <string.h>
#include "project.h"
#include "question.h"

void adminLogin()
{
    char username[20], password[20];
    int choice;

    printf("\nUsername: ");
    scanf("%19s", username);

    printf("Password: ");
    scanf("%19s", password);

    if(strcmp(username, "admin") == 0 &&
       strcmp(password, "1234") == 0)
    {
        do
        {
            printf("\n===== ADMIN DASHBOARD =====");
            printf("\n1. Add Question");
            printf("\n2. View Questions");
            printf("\n3. Search Question");
            printf("\n4. Delete Question");
            printf("\n5. Sort Questions A-Z");
            printf("\n6. View Student Results");
            printf("\n7. Admin Dashboard");
            printf("\n8. Logout");
            printf("\nEnter choice: ");
            scanf("%d", &choice);

            switch(choice)
            {
                case 1: addQuestion(); break;
                case 2: viewQuestions(); break;
                case 3: searchQuestion(); break;
                case 4: deleteQuestion(); break;
                case 5: sortQuestions();break;
                case 6: viewResults();break;
                case 7: adminDashboard();break;
                case 8:printf("\nLogout Successful!\n");break;
                default: printf("\nInvalid Choice!\n");
            }

        } while(choice != 8);
    }
    else
        printf("\nInvalid Login!\n");
}
