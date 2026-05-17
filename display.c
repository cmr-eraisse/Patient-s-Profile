#include "header.h"

void displayPatients()
{
    if (patientCount == 0) {
        printf("\n  No patients on record.\n");
        return;
    }

    printf("\n--- Patient List (%d record%s) ---\n",
           patientCount, patientCount == 1 ? "" : "s");
    printf("  %-4s | %-20s | %-4s | %s\n",
           "ID", "Name", "Age", "Condition");
    printf("  %-4s-+-%-20s-+-%-4s-+-%s\n",
           "----", "--------------------", "----", "----------");

    for (int i = 0; i < patientCount; i++) {
        printPatient(patients[i]);
    }
}