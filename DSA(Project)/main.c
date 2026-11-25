
#include <stdio.h>
#include "project.h"

int main()
{
    int choice;
    loadQuestions();
    do
    {
        printf("\n====================================");
        printf("\n ONLINE EXAM QUESTION MANAGEMENT");
        printf("\n====================================");
        printf("\n1. Admin Login");
        printf("\n2. Student Login");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                adminLogin();
                break;

            case 2:
                studentLogin();
                break;

            case 3:
{
    char confirm;

    printf("\nAre you sure you want to exit? (Y/N): ");
    scanf(" %c", &confirm);

    if(confirm == 'Y' || confirm == 'y')
    {
        printf("\nThank You for Using Our System!\n");
        break;
    }
    else
    {
        choice = 0;
    }

    break;
}

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 3);

    return 0;
}
