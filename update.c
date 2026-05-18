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

    printf("\n      == CURRENT RECORD ==:\n");
    printPatient(patients[idx]);


    int field;
    do {
        printf("\nWhat do you want to update?\n");
        printf("  [1] Name\n");
        printf("  [2] Age\n");
        printf("  [3] Condition\n");
        printf("  [4] All fields\n");
        printf("  [0] Cancel\n");
        printf("Choice: ");
        scanf("%d", &field);

        if (field < 0 || field > 4) {
            printf("[ERROR] Invalid choice. Enter 0 to 4.\n");
        }
    } while (field < 0 || field > 4);

    if (field == 0) {
        printf("Update cancelled.\n");
        return;
    }


    if (field == 1 || field == 4) {
        while (1) {
            char buffer[MAX_NAME_LENGTH];
            printf("New Name      (current: %s): ", patients[idx].name);
            scanf(" %49[^\n]", buffer);

            if (strlen(buffer) == 0) {
                printf("Name unchanged.\n");
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
            printf("Name updated.\n");
            break;
        }
    }


    if (field == 2 || field == 4) {
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
                printf("Age unchanged.\n");
                break;
            }

            if (age < 1 || age > 120) {
                printf("[ERROR] Age must be between 1 and 120.\n");
                continue;
            }

            patients[idx].age = age;
            printf("Age updated.\n");
            break;
        }
    }


    if (field == 3 || field == 4) {
        while (1) {
            char condtn[MAX_CONDITION];
            printf("New Condition (current: %s): ", patients[idx].condition);
            scanf(" %99[^\n]", condtn);

            if (strlen(condtn) == 0) {
                printf("Condition unchanged.\n");
                break;
            }

            strncpy(patients[idx].condition, condtn, MAX_CONDITION - 1);
            patients[idx].condition[MAX_CONDITION - 1] = '\0';
            printf("Condition updated.\n");
            break;
        }
    }

    saveCSV();
    printf("\n[OK] Patient updated successfully.\n");
    printf("Updated record:\n");
    printPatient(patients[idx]);
}