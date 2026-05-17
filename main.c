#include "header.h"


Patient patients[MAX_PATIENTS];
int patientCount = 0;

int searchByID(int id)
{
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            return i;
        }
    }
    return -1;
}

int nextID()
{
    int max = 0;
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id > max) {
            max = patients[i].id;
        }
    }
    return max + 1;
}


void printPatient(Patient patient)
{
    printf("||  ID: %-4d | Name: %-20s | Age: %3d | Condition: %s  ||\n", patient.id, patient.name, patient.age, patient.condition);
}

int main()
{
    patientCount = loadCSV();

    printf("======================================\n");
    printf("\tPATIENT PROFILE SYSTEM");
    printf("\n======================================\n");
    printf("\t** %d Patient/s loaded **\n\n", patientCount);

    int choice = 0;

    do
    {
        printf("\n\t\t== MAIN MENU ==\n");
        printf("    [1] Add Patient\n");
        printf("    [2] Search Patient\n");
        printf("    [3] Update a Patient Profile\n");
        printf("    [4] Delete a Patient Profile\n");
        printf("    [5] Display All Patient Records\n");
        printf("    [6] Exit System\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                searchPatient();
                break;
            case 3:
                updatePatient();
                break;
            case 4:
                deletePatient();
                break;
            case 5:
                displayPatients();
                break;
            case 6:
                printf("Exiting...");
                exit(0);
            default:
                printf("\nInvalid option.");
        }
    } while (choice != 0);
    
    printf("Exiting...");

}