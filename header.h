#ifndef HEADER_H
#define HEADER_H


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>

#define MAX_PATIENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_CONDITION 100
#define CSV_FILE "patients.csv"

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    char condition[MAX_CONDITION];
} Patient;

extern int patientCount;
extern Patient patients[MAX_PATIENTS];

int loadCSV();
void saveCSV();

int searchByID(int id);
int nextID();
void printPatient(Patient patient);

void addPatient();
void deletePatient();
void updatePatient();
void displayPatients();
void searchPatient();

#endif