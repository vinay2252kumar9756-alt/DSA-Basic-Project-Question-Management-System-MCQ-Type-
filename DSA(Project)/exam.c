
#include <stdio.h>
#include "question.h"
#include "project.h"
#include <string.h>
#include <time.h>
#include <conio.h>

void startExam(const char *studentName)
{
    int answer, score = 0;
    int i = 0;
    int userAnswers[MAX] = {0};

    int timeLimit = 120;
    time_t startTime;

    if(count == 0)
    {
        printf("\nNo Questions Available!\n");
        return;
    }

    printf("\n===== EXAM INSTRUCTIONS =====\n");
    printf("1. Each question has 4 options.\n");
    printf("2. Enter 1-4 to select an answer.\n");
    printf("3. Enter 5 for Next Question.\n");
    printf("4. Enter 6 for Previous Question.\n");
    printf("5. Exam Time: 2 Minutes.\n");

    printf("\nPress any key to start exam...");
    _getch();

    startTime = time(NULL);

    while(i < count)
    {
        printf("\n\nTime Remaining: %.0f seconds\n",
               timeLimit - difftime(time(NULL), startTime));

        printf("\nQ%d. %s\n", q[i].id, q[i].question);

        for(int j = 0; j < 4; j++)
            printf("%d. %s\n", j + 1, q[i].options[j]);

        printf("\nYour Answer (1-4)");
        printf("\n5: Next | 6: Previous");
        printf("\nEnter choice: ");

        while(!_kbhit())
        {
            if(difftime(time(NULL), startTime) >= timeLimit)
                break;
        }

        if(difftime(time(NULL), startTime) >= timeLimit)
        {
            printf("\n\nTime Up! Exam Finished.\n");
            break;
        }

        char key = _getch();

if(key < '1' || key > '6')
{
    printf("\nInvalid Input! Enter 1-6.\n");
    continue;
}

answer = key - '0';
printf("%d\n", answer);

        if(answer >= 1 && answer <= 4)
        {
            userAnswers[i] = answer;
            i++;
        }
        else if(answer == 5 && i < count - 1)
        {
            i++;
        }
        else if(answer == 6 && i > 0)
        {
            i--;
        }
        else
        {
            printf("\nInvalid Choice!\n");
        }
    }

    for(int j = 0; j < count; j++)
    {
        if(userAnswers[j] == q[j].answer)
            score++;
    }

    printf("\n===== EXAM RESULT =====\n");
    printf("Student: %s\n", studentName);
    printf("Score: %d/%d\n", score, count);

    float percentage = (float)score / count * 100;

    printf("Percentage: %.2f%%\n", percentage);

    if(percentage >= 80)
        printf("Grade: A\n");
    else if(percentage >= 60)
        printf("Grade: B\n");
    else if(percentage >= 40)
        printf("Grade: C\n");
    else
        printf("Grade: D\n");

    FILE *fp = fopen("results.txt", "a");

    if(fp != NULL)
    {
        fprintf(fp, "%s %d/%d\n", studentName, score, count);
        fclose(fp);
    }
}
void viewResults()
{
    char name[50];
    int score, total;

    FILE *fp = fopen("results.txt", "r");

    if(fp == NULL)
    {
        printf("\nNo Results Available!\n");
        return;
    }

    printf("\n===== STUDENT RESULTS =====\n");

    while(fscanf(fp, "%49s %d/%d", name, &score, &total) == 3)
    {
        printf("\nStudent: %s", name);
        printf("\nScore: %d/%d\n", score, total);
    }

    fclose(fp);
}
void viewStudentHistory(const char *studentName)
{
    char line[200];
    int found = 0;
    int len = strlen(studentName);

    FILE *fp = fopen("results.txt", "r");

    if(fp == NULL)
    {
        printf("\nNo Exam History Available!\n");
        return;
    }

    printf("\n===== MY EXAM HISTORY =====\n");

    while(fgets(line, sizeof(line), fp))
    {
        if(strncmp(line, studentName, len) == 0 &&
           line[len] == ' ')
        {
            printf("%s", line);
            found = 1;
        }
    }

    if(!found)
        printf("\nNo Previous Exams Found!\n");

    fclose(fp);
}
void adminDashboard()
{
    Student s;
    int students = 0;
    int attempts = 0;
    int score, total;

    printf("\n===== ADMIN DASHBOARD =====\n");

    printf("\nTotal Questions: %d\n", count);

    FILE *fp = fopen("students.dat", "rb");

    if(fp != NULL)
    {
        while(fread(&s, sizeof(Student), 1, fp) == 1)
            students++;

        fclose(fp);
    }

    fp = fopen("results.txt", "r");

    if(fp != NULL)
    {
        char name[50];

        while(fscanf(fp, "%49s %d/%d", name, &score, &total) == 3)
            attempts++;

        fclose(fp);
    }

    printf("Total Students: %d\n", students);
    printf("Total Exam Attempts: %d\n", attempts);
}