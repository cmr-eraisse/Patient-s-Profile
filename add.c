#include "header.h"


void addPatient()
{
    if (patientCount >= MAX_PATIENTS) {
        printf("[ERROR] Patient list is full.\n");
        return;
    }
 
    Patient newPatient;
    newPatient.id = nextID();
 
    printf("\n=== Add New Patient [ID will be %d] ===\n", newPatient.id);
 

    while (1) {
        printf("Name      : ");
        scanf(" %49[^\n]", newPatient.name);
 
        if (strlen(newPatient.name) == 0) {
            printf("[ERROR] Name cannot be empty.\n");
            continue;
        }
 
        int is_valid = 1;
        for (int i = 0; newPatient.name[i]; i++) {
            if (!isalpha(newPatient.name[i]) && newPatient.name[i] != ' ') {
                is_valid = 0;
                break;
            }
        }
 
        if (!is_valid) {
            printf("[ERROR] Name must contain letters only. No numbers or symbols.\n");
            continue;
        }
 
        break;
    }
 

    while (1) {
        printf("Age       : ");
        char ageBuffer[16];
        scanf(" %15[^\n]", ageBuffer);
 
        int allDigits = 1;
        for (int i = 0; ageBuffer[i]; i++) {
            if (!isdigit(ageBuffer[i])) {
                allDigits = 0;
                break;
            }
        }
 
        if (!allDigits) {
            printf("[ERROR] Age must be a number. No letters or symbols.\n");
            continue;
        }
 
        int age = atoi(ageBuffer);
        if (age < 1 || age > 120) {
            printf("[ERROR] Age must be between 1 and 120.\n");
            continue;
        }
 
        newPatient.age = age;
        break;
    }
 

    while (1) {
        printf("Condition : ");
        scanf(" %99[^\n]", newPatient.condition);
 
        if (strlen(newPatient.condition) == 0) {
            printf("[ERROR] Condition cannot be empty.\n");
            continue;
        }
        break;
    }
 
    patients[patientCount] = newPatient;
    patientCount++;
 
    saveCSV();
    printf("[OK] Patient added successfully.\n");
}
