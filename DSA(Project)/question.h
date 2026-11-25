
#ifndef QUESTION_H
#define QUESTION_H

#define MAX 100

typedef struct
{
    int id;
    char question[200];
    char options[4][100];
    int answer;
} Question;

void addQuestion();
void viewQuestions();
void deleteQuestion();
void searchQuestion();
void saveQuestions();
void loadQuestions();
void sortQuestions();
#endif
extern Question q[MAX];
extern int count;