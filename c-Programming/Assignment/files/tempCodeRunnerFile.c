void manageCandidates() {
    FILE * candidateFile, * tempFile;
    struct Candidate candidate;
    int choice;
    int found = 0; // Add this declaration
    char nameToUpdate[50];
    char nameToDelete[50];

    do {
        printf("\nManage Candidates\n");
        printf("1. Add Candidate\n");
        printf("2. Update Candidate\n");
        printf("3. Delete Candidate\n");
        printf("4. Back to Main Menu\n");

        printf("Enter your choice: ");
        scanf("%d", & choice);

        switch (choice) {
        case 1:
            candidateFile = fopen(candidateFileName, "a");

            if (candidateFile == NULL) {
                printf("Error opening candidate file.\n");
                return;
            }

            printf("Enter Candidate Name: ");
            scanf("%s", candidate.name);

            printf("Enter Political Party: ");
            scanf("%s", candidate.party);

            printf("Enter Candidacy From: ");
            scanf("%s", candidate.candidacyFrom);

            fprintf(candidateFile, "%s\t%s\t%s\n", candidate.name, candidate.party, candidate.candidacyFrom);

            printf("Candidate added successfully.\n");

            fclose(candidateFile);
            break;

        case 2: {
            candidateFile = fopen(candidateFileName, "r");
            tempFile = fopen("temp.txt", "w");

            if (candidateFile == NULL || tempFile == NULL) {
                printf("Error opening files.\n");
                return;
            }

            printf("Enter Candidate Name to update: ");
            scanf("%s", nameToUpdate);

            while (fscanf(candidateFile, "%s %s %s\n", candidate.name, candidate.party, candidate.candidacyFrom) != EOF) {
                if (strcmp(candidate.name, nameToUpdate) == 0) {
                    found = 1;

                    printf("Enter new details for the candidate:\n");
                    printf("Enter Candidate Name: ");
                    scanf("%s", candidate.name);

                    printf("Enter Political Party: ");
                    scanf("%s", candidate.party);

                    printf("Enter Candidacy From: ");
                    scanf("%s", candidate.candidacyFrom);

                    fprintf(tempFile, "%s\t%s\t%s\n", candidate.name, candidate.party, candidate.candidacyFrom);
                    printf("Candidate details updated successfully.\n");
                } else {
                    fprintf(tempFile, "%s\t%s\t%s\n", candidate.name, candidate.party, candidate.candidacyFrom);
                }
            }

            fclose(candidateFile);
            fclose(tempFile);

            remove(candidateFileName);
            rename("temp.txt", candidateFileName);

            if (!found) {
                printf("Candidate with name %s not found.\n", nameToUpdate);
            }
            break;
        }
        case 3: {
            candidateFile = fopen(candidateFileName, "r");
            tempFile = fopen("temp.txt", "w");

            if (candidateFile == NULL || tempFile == NULL) {
                printf("Error opening files.\n");
                return;
            }

            printf("Enter Candidate Name to delete: ");
            scanf("%s", nameToDelete);

            while (fscanf(candidateFile, "%s %s %s\n", candidate.name, candidate.party, candidate.candidacyFrom) != EOF) {
                if (strcmp(candidate.name, nameToDelete) == 0) {
                    found = 1;
                    printf("Candidate %s deleted successfully.\n", nameToDelete);
                } else {
                    fprintf(tempFile, "%s\t%s\t%s\n", candidate.name, candidate.party, candidate.candidacyFrom);
                }
            }

            fclose(candidateFile);
            fclose(tempFile);

            remove(candidateFileName);
            rename("temp.txt", candidateFileName);

            if (!found) {
                printf("Candidate with name %s not found.\n", nameToDelete);
            }
            break;
        }
        case 4:
            printf("Returning to the main menu.\n");
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);
}