
#include <stdio.h>
#include <string.h>
#include "project.h"

void registerStudent()
{
    Student s;
    FILE *fp;

    printf("\nEnter Name: ");
    scanf(" %49[^\n]", s.name);

    printf("Enter Username: ");
    scanf("%29s", s.username);

    printf("Enter Password: ");
    scanf("%29s", s.password);

    fp = fopen("students.dat", "ab");

    if(fp == NULL)
    {
        printf("File Error!\n");
        return;
    }

    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);

    printf("\nRegistration Successful!\n");
}

void studentLogin()
{
    Student s;
    char username[30], password[30];
    int choice, found;

    printf("\n1. Register");
    printf("\n2. Login");
    printf("\nEnter Choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        registerStudent();
    }
    else if(choice == 2)
    {
        printf("\nUsername: ");
        scanf("%29s", username);

        printf("Password: ");
        scanf("%29s", password);

        FILE *fp = fopen("students.dat", "rb");

        if(fp == NULL)
        {
            printf("\nNo Student Registered!\n");
            return;
        }

        found = 0;

        while(fread(&s, sizeof(Student), 1, fp))
        {
            if(strcmp(s.username, username) == 0 &&
               strcmp(s.password, password) == 0)
            {
                found = 1;
                break;
            }
        }

        fclose(fp);

       if(found)
{
    printf("\nLogin Successful! Welcome %s\n", s.name);
    viewStudentHistory(s.name);
    startExam(s.name);
}
        else
            printf("\nInvalid Username or Password!\n");
    }
    else
    {
        printf("\nInvalid Choice!\n");
    }
}
