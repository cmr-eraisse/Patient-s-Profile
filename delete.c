#include "header.h"


void deletePatient() 
{
    if (patientCount == 0) {
        printf("\nThere are no patients to remove.\n");
        return;
    }

    int id;
    printf("\nEnter patient ID to remove: ");
    scanf("%d", &id);

    int idx = searchByID(id);
    if (idx == -1) {
        printf("[ERROR] Patient ID %d not found.\n", id);
        return;
    }

    printf("Removing: ");
    printPatient(patients[idx]);

    char confirm;
    printf("Are you sure? (y/n): ");
    scanf(" %c", &confirm);
    if (confirm != 'y' && confirm != 'Y') {
        printf("Operation cancelled.\n");
        return;
    }

    for (int i = idx; i < patientCount - 1; i++) {
        patients[i] = patients[i + 1];
    }
    patientCount--;

    saveCSV();
    printf("[OK] Patient removed successfully.\n");
}