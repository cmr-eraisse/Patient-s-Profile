#include "header.h"

void searchPatient() {

    while (1) {
        if (patientCount == 0) {
            printf("\n  No patients on record.\n");
            return;
        }
        system("cls");
        printf("\n\t    == SEARCH BY: ==\n");
        printf("    [1] ID\n");
        printf("    [2] Name\n");
        printf("    [3] Back to Main Menu\n");
        printf("\nEnter choice: ");

        int option;
        scanf("%d", &option);

        if (option == 1) {
            int id;
            printf("Enter ID: ");
            scanf("%d", &id);

            int idx = searchByID(id);
            if (idx == -1) {
                printf("[NOT FOUND] No patient with ID %d.\n", id);
            }
            else {
                printPatient(patients[idx]);
            }

        } else if (option == 2) {
            char needle[MAX_NAME_LENGTH];
            printf("Enter Name (or part of it): ");
            scanf(" %49[^\n]", needle);

            int is_found = 0;
            for (int i = 0; i < patientCount; i++) {

                char hay[MAX_NAME_LENGTH];
                char lowerNeedle[MAX_NAME_LENGTH];
                int j;

                for (j = 0; patients[i].name[j]; j++)
                    hay[j] = (char)tolower((unsigned char)patients[i].name[j]);
                hay[j] = '\0';

                for (j = 0; needle[j]; j++)
                    lowerNeedle[j] = (char)tolower((unsigned char)needle[j]);
                lowerNeedle[j] = '\0';

                if (strstr(hay, lowerNeedle) != NULL) {
                    printPatient(patients[i]);
                    is_found++;
                }
            }

            if (is_found == 0) {
                printf("[NOT FOUND] No patient matching \"%s\".\n", needle);
            }
            else {
                printf("\n%d match(es) found.\n", is_found);
            }
        } 
        else if (option == 3) {
            system("cls");
            return;
        }
        else {
            printf("Invalid search option.\n");
        }

        char choice;


        printf("\nSearch Again? (Y/y): ");
        scanf(" %c", &choice);

        if (choice == 'Y' || choice == 'y') {
            continue;
        }

        printf("\nGoing back...");
        Sleep(1000);
        system("cls");
        return;
    }

}