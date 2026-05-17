#include "header.h"


void updatePatient() 
{
    if (patientCount == 0) {
        printf("\nThere are no patients to edit.\n");
        return;
    }

    int id;
    printf("\nEnter patient ID to edit: ");
    scanf("%d", &id);

    int idx = searchByID(id);
    if (idx == -1) {
        printf("[ERROR] Patient ID %d not found.\n", id);
        return;
    }

    printf("Current record:\n");
    printPatient(patients[idx]);
    printf("\n(Press Enter without typing to keep the current value)\n");


    while (1) {
        char buffer[MAX_NAME_LENGTH];
        printf("New Name      (current: %s): ", patients[idx].name);
        scanf(" %49[^\n]", buffer);

        if (strlen(buffer) == 0)
        {
            break;
        }

        int valid = 1;
        for (int i = 0; buffer[i]; i++) {
            if (!isalpha((unsigned char)buffer[i]) && buffer[i] != ' ') {
                valid = 0;
                break;
            }
        }

        if (!valid) {
            printf("[ERROR] Name must contain letters only. No numbers or symbols.\n");
            continue;
        }

        strncpy(patients[idx].name, buffer, MAX_NAME_LENGTH - 1);
        patients[idx].name[MAX_NAME_LENGTH - 1] = '\0';
        break;
    }


    while (1) {
        char ageBuffer[16];
        printf("New Age       (current: %d, enter 0 to keep): ", patients[idx].age);
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
        if (age == 0) {
            break;
        }

        if (age < 1 || age > 120) {
            printf("[ERROR] Age must be between 1 and 120.\n");
            continue;
        }

        patients[idx].age = age;
        break;
    }


    while (1) {
        char condtn[MAX_CONDITION];
        printf("New Condition (current: %s): ", patients[idx].condition);
        scanf(" %99[^\n]", condtn);

        if (strlen(condtn) == 0) {
            printf("[ERROR] Condition cannot be empty.\n");
            continue;
        }

        strncpy(patients[idx].condition, condtn, MAX_CONDITION - 1);
        patients[idx].condition[MAX_CONDITION - 1] = '\0';
        break;
    }

    saveCSV();
    printf("[OK] Patient updated successfully.\n");
}