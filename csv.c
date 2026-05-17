#include "header.h"


int loadCSV()
{
    FILE *fp = fopen(CSV_FILE, "r");
    if (!fp) {
        printf("!!ERROR: Unable to open %s\n", CSV_FILE);
        return 0;
    }

    int count = 0;
    char buffer[128];

    fgets(buffer, sizeof(buffer), fp);

    while (count < MAX_PATIENTS && fgets(buffer, sizeof(buffer), fp))
    {
        char *tok;

        tok = strtok(buffer, ",");
        if (!tok) {
            continue;
        }
        patients[count].id = atoi(tok);

        tok = strtok(NULL, ",");
        if (!tok) {
            continue;
        }
        strncpy(patients[count].name, tok, MAX_NAME_LENGTH - 1);
        patients[count].name[MAX_NAME_LENGTH - 1] = '\0';

        tok = strtok(NULL, ",");
        if (!tok) {
            continue;
        }
        patients[count].age = atoi(tok);

        tok = strtok(NULL, "\n");
        if (!tok) {
            continue;
        }
        strncpy(patients[count].condition, tok, MAX_CONDITION - 1);
        patients[count].condition[MAX_CONDITION - 1] = '\0';

        count++;
    }

    fclose(fp);
    return count;
}

void saveCSV()
{
    FILE *fp = fopen(CSV_FILE, "w");
    if (!fp) {
        printf("!!ERROR: Unable to open %s\n", CSV_FILE);
        return;
    }

    fprintf(fp, "patient id,name,age,condition\n");
    for (int i = 0; i < patientCount; i++)
    {
        fprintf(fp, "%d,%s,%d,%s\n", patients[i].id, patients[i].name, patients[i].age, patients[i].condition);
    }

    fclose(fp);
}