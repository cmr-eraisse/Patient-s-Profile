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
    printf("\n||  ID: %-4d | Name: %-20s | Age: %3d | Condition: %s  ||\n", patient.id, patient.name, patient.age, patient.condition);
}


int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    patientCount = loadCSV();

    system("cls");
    SetConsoleTextAttribute(hConsole, 6);
    printf("=======================================\n");
    SetConsoleTextAttribute(hConsole, 3);
    printf("\tPATIENT PROFILE SYSTEM");
    SetConsoleTextAttribute(hConsole, 6);
    printf("\n=======================================\n");
    SetConsoleTextAttribute(hConsole, 5);
    printf("\t** %d Patient/s loaded **\n\n", patientCount);
    SetConsoleTextAttribute(hConsole, 7);
    int choice = 0;

    do
    {
        SetConsoleTextAttribute(hConsole, 6);
        printf("\n\t    == MAIN MENU ==\n");
        SetConsoleTextAttribute(hConsole, 7);
        printf("    [1] Add Patient\n");
        printf("    [2] Search Patient\n");
        printf("    [3] Update a Patient Profile\n");
        printf("    [4] Delete a Patient Profile\n");
        printf("    [5] Display All Patient Records\n");
        printf("    [6] Exit System\n");
        printf("\nEnter choice: ");
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
                SetConsoleTextAttribute(hConsole, 6);
                printf("Session Terminated. Exiting...");
                SetConsoleTextAttribute(hConsole, 7);
                Sleep(1500);
                exit(0);
            default:
                SetConsoleTextAttribute(hConsole, 4);
                printf("\nInvalid option.");
                SetConsoleTextAttribute(hConsole, 7);
        }
    } while (choice != 0);
    
    SetConsoleTextAttribute(hConsole, 6);
    printf("Session Terminated. Exiting...");
    SetConsoleTextAttribute(hConsole, 7);
    Sleep(1500);
}