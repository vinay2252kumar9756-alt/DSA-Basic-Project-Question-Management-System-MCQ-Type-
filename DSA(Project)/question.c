
#include <stdio.h>
#include "question.h"
#include <string.h>

Question q[MAX];
int count = 0;

void addQuestion()
{
    if(count >= MAX)
    {
        printf("Question limit reached!\n");
        return;
    }

    q[count].id = count + 1;

    printf("\nEnter Question: ");
    scanf(" %[^\n]", q[count].question);

    for(int i = 0; i < 4; i++)
    {
        printf("Enter Option %d: ", i + 1);
        scanf(" %[^\n]", q[count].options[i]);
    }

    printf("Enter Correct Option (1-4): ");
    scanf("%d", &q[count].answer);

    count++;
    saveQuestions();
    printf("\nQuestion Added Successfully!\n");
}

void viewQuestions()
{
    if(count == 0)
    {
        printf("\nNo Questions Available!\n");
        return;
    }

    for(int i = 0; i < count; i++)
    {
        printf("\nQ%d. %s\n", q[i].id, q[i].question);

        for(int j = 0; j < 4; j++)
            printf("%d. %s\n", j + 1, q[i].options[j]);

        printf("Correct Answer: %d\n", q[i].answer);
    }
}

void deleteQuestion()
{
    int id, i, found = 0;

    printf("\nEnter Question ID to Delete: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(q[i].id == id)
        {
            found = 1;
            break;
        }
    }

    if(found)
    {
        for(int j = i; j < count - 1; j++)
        {
            q[j] = q[j + 1];
        }

        count--;

        for(int j = 0; j < count; j++)
            q[j].id = j + 1;
        saveQuestions();

        printf("\nQuestion Deleted Successfully!\n");
    }
    else
    {
        printf("\nQuestion Not Found!\n");
    }
}

void searchQuestion()
{
    int id, found = 0;

    printf("\nEnter Question ID: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++)
    {
        if(q[i].id == id)
        {
            printf("\nQuestion Found!\n");
            printf("Q%d. %s\n", q[i].id, q[i].question);

            for(int j = 0; j < 4; j++)
                printf("%d. %s\n", j + 1, q[i].options[j]);

            found = 1;
            break;
        }
    }

    if(!found)
        printf("\nQuestion Not Found!\n");
}

void saveQuestions()
{
    FILE *fp = fopen("questions.dat", "wb");

    if(fp == NULL)
    {
        printf("File Error!\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(q, sizeof(Question), count, fp);

    fclose(fp);
}

void loadQuestions()
{
    FILE *fp = fopen("questions.dat", "rb");

    if(fp == NULL)
        return;

    fread(&count, sizeof(int), 1, fp);

    if(count < 0 || count > MAX)
    {
        count = 0;
        fclose(fp);
        return;
    }

    fread(q, sizeof(Question), count, fp);

    fclose(fp);
}
void sortQuestions()
{
    Question temp;

    if(count == 0)
    {
        printf("\nNo Questions Available!\n");
        return;
    }

    for(int i = 0; i < count - 1; i++)
    {
        for(int j = 0; j < count - i - 1; j++)
        {
            if(strcmp(q[j].question, q[j + 1].question) > 0)
            {
                temp = q[j];
                q[j] = q[j + 1];
                q[j + 1] = temp;
            }
        }
    }

    saveQuestions();

    printf("\nQuestions Sorted Successfully!\n");
    viewQuestions();
}