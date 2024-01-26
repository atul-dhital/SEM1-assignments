#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//9851266911 sir
// Structures for storing data
struct ElectionSchedule {
    char constituency[50];
    char date[9]; 
};

struct Candidate {
    char name[50];
    char party[50];
    char candidacyFrom[50];
};

struct Voter {
    int sno;
    int age;
    char name[50];
    char dob[11]; 
    char address[50];
    char password[20];
};

// Function prototypes
void createElectionSchedule();
void manageCandidates();
void registerVoter();
void updateVoterDetails();
void searchVoterDetails();
void castVote();
void displayVoteResults();
void adminMenu();
void voterMenu();
int authenticatevoter();
// File names creation
const char scheduleFileName[] = "schedule.txt";
const char candidateFileName[] = "candidatelist.txt";
const char voterFileName[] = "voterlist.txt";
const char voteCountFileName[] = "votecount.txt";
const char adminPassword[] = "admin123";

void createElectionSchedule() {
    FILE *scheduleFile;
    struct ElectionSchedule schedule;

    scheduleFile = fopen(scheduleFileName, "a");

    if (scheduleFile == NULL) {
        printf("Error opening schedule file.\n");
        return;
    }

    printf("Enter Constituency: ");
    scanf("%s", schedule.constituency);

    do {
        printf("Enter Date of Election (yyyymmdd): ");
        scanf("%s", schedule.date);

        if (strlen(schedule.date) != 8) {
            printf("Invalid date format. Please enter again.\n");
        }
    } while (strlen(schedule.date) != 8);

    fprintf(scheduleFile, "%s\t%s\n", schedule.constituency, schedule.date);

    printf("Election schedule added successfully.\n");

    fclose(scheduleFile);
}

void manageCandidates() {
    FILE *candidateFile;
    struct Candidate candidate;
    int choice;

    do {
        printf("\nManage Candidates\n");
        printf("1. Add Candidate\n");
        printf("2. Update Candidate\n");
        printf("3. Delete Candidate\n");
        printf("4. Back to Main Menu\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

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
            // Implement update and delete cases
            // ...
            case 4:
                printf("Returning to the main menu.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);
}

void registerVoter() {
    FILE *voterFile;
    struct Voter voter;
    int age;

    voterFile = fopen(voterFileName, "a");

    if (voterFile == NULL) {
        printf("Error opening voter file.\n");
        return;
    }
printf("please enter the voter AGE");
scanf("%d",age);
if(age>=18){
  printf("Enter Voter Serial Number: ");
    scanf("%d", &voter.sno);

    printf("Enter Voter Name: ");
    scanf("%s", voter.name);

    printf("Enter Date of Birth (yyyy/mm/dd): ");
    scanf("%s", voter.dob);

    printf("Enter Address: ");
    scanf("%s", voter.address);

    printf("Enter Password: ");
    scanf("%s", voter.password);

    fprintf(voterFile, "%d\t%s\t%s\t%s\t%s\n", voter.sno, voter.name, voter.dob, voter.address, voter.password);

    printf("Voter registered successfully.\n");

    fclose(voterFile);
}
else{
    printf("Invilde AGE");
}
}

void updateVoterDetails() {
    FILE *voterFile, *tempFile;
    struct Voter voter;
    int sno, found = 0;

    voterFile = fopen(voterFileName, "r");
    tempFile = fopen("temp.txt", "w");

    if (voterFile == NULL || tempFile == NULL) {
        printf("Error opening files.\n");
        return;
    }

    printf("Enter Voter Serial Number to update details: ");
    scanf("%d", &sno);

    while (fscanf(voterFile, "%d %s %s %s %s\n", &voter.sno, voter.name, voter.dob, voter.address, voter.password) != EOF) {
        if (voter.sno == sno) {
            found = 1;

            printf("Enter new details for the voter:\n");
            printf("Enter Voter Name: ");
            scanf("%s", voter.name);

            printf("Enter Date of Birth (yyyy/mm/dd): ");
            scanf("%s", voter.dob);

            printf("Enter Address: ");
            scanf("%s", voter.address);

            printf("Enter new Password: ");
            scanf("%s", voter.password);

            fprintf(tempFile, "%d\t%s\t%s\t%s\t%s\n", voter.sno, voter.name, voter.dob, voter.address, voter.password);
            printf("Voter details updated successfully.\n");
        } else {
            fprintf(tempFile, "%d\t%s\t%s\t%s\t%s\n", voter.sno, voter.name, voter.dob, voter.address, voter.password);
        }
    }

    fclose(voterFile);
    fclose(tempFile);

    remove(voterFileName);
    rename("temp.txt", voterFileName);

    if (!found) {
        printf("Voter with Serial Number %d not found.\n", sno);
    }
}

void searchVoterDetails() {
    FILE *voterFile;
    struct Voter voter;
    int sno, found = 0;

    voterFile = fopen(voterFileName, "r");

    if (voterFile == NULL) {
        printf("Error opening voter file.\n");
        return;
    }

    printf("Enter Voter Serial Number to search details: ");
    scanf("%d", &sno);

    while (fscanf(voterFile, "%d %s %s %s %s\n", &voter.sno, voter.name, voter.dob, voter.address, voter.password) != EOF) {
        if (voter.sno == sno) {
            found = 1;
            printf("\nVoter Details:\n");
            printf("Serial Number: %d\n", voter.sno);
            printf("Name: %s\n", voter.name);
            printf("Date of Birth: %s\n", voter.dob);
            printf("Address: %s\n", voter.address);
            // Do not print the password for security reasons
            printf("-------------------------------\n");
            break; // No need to continue searching once found
        }
    }

    fclose(voterFile);

    if (!found) {
        printf("Voter with Serial Number %d not found.\n", sno);
    }
}

void castVote() {
    FILE *candidateFile, *voteCountFile;
    struct Candidate candidate;
    struct Voter voter;
    int choice, voted = 0;

    candidateFile = fopen(candidateFileName, "r");
    voteCountFile = fopen(voteCountFileName, "a");

    if (candidateFile == NULL || voteCountFile == NULL) {
        printf("Error opening files.\n");
        return;
    }

    printf("Enter your Voter Serial Number: ");
    scanf("%d", &voter.sno);

    // Authenticate the voter (Check if the voter is registered)
    // This part is not implemented in the example. You may need to add authentication logic.

    printf("\nList of Candidates:\n");

    // Display candidates from the file
    while (fscanf(candidateFile, "%s %s %s\n", candidate.name, candidate.party, candidate.candidacyFrom) != EOF) {
        printf("%s - %s\n", candidate.name, candidate.party);
    }

    fclose(candidateFile);

    do {
        printf("\nEnter the Serial Number of the candidate you want to vote for (0 to cancel): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Vote canceled.\n");
            return;
        }

        // Validate the candidate choice
        // This part is not implemented in the example. You may need to add validation logic.

        // Record the vote in the votecount.txt file
        fprintf(voteCountFile, "%d\t%d\n", voter.sno, choice);
        printf("Vote recorded successfully.\n");
        voted = 1;

    } while (!voted);

    fclose(voteCountFile);
}

void displayVoteResults() {
    FILE *voteCountFile;
    int voterSno, candidateSno;

    voteCountFile = fopen(voteCountFileName, "r");

    if (voteCountFile == NULL) {
        printf("Error opening vote count file.\n");
        return;
    }

    printf("\nVote Results:\n");

    // Display the details of the votes from the file
    while (fscanf(voteCountFile, "%d %d\n", &voterSno, &candidateSno) != EOF) {
        printf("Voter Serial Number: %d, Voted for Candidate Serial Number: %d\n", voterSno, candidateSno);
    }

    fclose(voteCountFile);
}
int main() {
    int roleChoice;

    printf("\nVOTING SYSTEM\n");
    printf("1. Admin\n");
    printf("2. voter\n");
    printf("3. Exit\n");
    printf("Enter your role (1 for Admin, 2 for voter, 3 to Exit): ");
    scanf("%d", &roleChoice);

    switch (roleChoice) {
        case 1:
            // Admin login
            adminMenu();
            break;
        case 2:
            // voter login
            voterMenu();
            break;
        case 3:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
    }

    return 0;
}

void adminMenu() {
    char password[20];
    printf("Enter Admin Password: ");
    scanf("%s", password);

    if (strcmp(password, adminPassword) == 0) {
        int choice;

        do {
            printf("\nVOTING SYSTEM\n");
            printf("1. Create Election Schedule\n");
            printf("2. Manage Candidates\n");
            printf("3. Register Voter\n");
            printf("4. Update Voter Details\n");
            printf("5. Search Voter Details\n");
            printf("6. Cast Vote\n");
            printf("7. Display Vote Results\n");
            printf("8. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    createElectionSchedule();
                    break;
                case 2:
                    manageCandidates();
                    break;
                case 3:
                    registerVoter();
                    break;
                case 4:
                    updateVoterDetails();
                    break;
                case 5:
                    searchVoterDetails();
                    break;
                case 6:
                    castVote();
                    break;
                case 7:
                    displayVoteResults();
                    break;
                case 8:
                    printf("Exiting the program. Goodbye!\n");
                    break;
                default:
                    printf("Invalid choice. Please enter a number between 1 and 8.\n");
            }
        } while (choice != 8);
    } else {
        printf("Incorrect password. Access denied.\n");
    }
}
// Function to handle voter login
void voterMenu() {
    int voterChoice;
    int sno;
    char password[20];

    // Prompt the voter for their credentials
    printf("Enter Voter Serial Number: ");
    scanf("%d", &sno);

    printf("Enter Password: ");
    scanf("%s", password);

    // Authenticate the voter
    if (authenticatevoter(sno, password)) {
        // Authentication successful
        do {
            printf("\nvoter Menu\n");
            printf("1. Update Voter Details\n");
            printf("2. Search Voter Details\n");
            printf("3. Cast Vote\n");
            printf("4. Display Vote Results\n");
            printf("5. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &voterChoice);

            switch (voterChoice) {
                case 1:
                    updateVoterDetails();
                    break;
                case 2:
                    searchVoterDetails();
                    break;
                case 3:
                    castVote();
                    break;
                case 4:
                    displayVoteResults();
                    break;
                case 5:
                    printf("Exiting voter Menu.\n");
                    break;
                default:
                    printf("Invalid choice. Please enter a number between 1 and 5.\n");
            }
        } while (voterChoice != 5);
    } else {
        // Authentication failed
        printf("Authentication failed. Exiting voter Menu.\n");
    }
}

// Function to authenticate the voter based on Serial Number and Password
int authenticatevoter(int sno, const char* password) {
    FILE *voterFile;
    struct Voter voter;
    int found = 0;

    voterFile = fopen(voterFileName, "r");

    if (voterFile == NULL) {
        printf("Error opening voter file.\n");
        return 0;  // Authentication failed
    }

    while (fscanf(voterFile, "%d %*s %*s %*s %s\n", &voter.sno, voter.password) != EOF) {
        if (voter.sno == sno && strcmp(voter.password, password) == 0) {
            found = 1;
            break;  // voter authenticated
        }
    }

    fclose(voterFile);

    return found;
}
