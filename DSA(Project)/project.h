
#ifndef PROJECT_H
#define PROJECT_H

#include "question.h"

void adminLogin();
void studentLogin();
void viewResults();
void viewStudentHistory(const char *studentName);
void adminDashboard();
#endif
void startExam(const char *studentName);
typedef struct
{
    char name[50];
    char username[30];
    char password[30];
} Student;