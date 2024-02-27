#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50
#define MAX_PARTY_LENGTH 50
#define MAX_CONSTITUENCY_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_PASSWORD_LENGTH 20
#define MAX_VOTERS 1000
#define MAX_CANDIDATES 100
#define MAX_CONSTITUENCIES 10

struct Date {
    int year;
    int month;
    int day;
};

struct Candidate {
    char name[MAX_NAME_LENGTH];
    char party[MAX_PARTY_LENGTH];
    char constituency[MAX_CONSTITUENCY_LENGTH];
};

struct Voter {
    int sno;
    char name[MAX_NAME_LENGTH];
    struct Date dob;
    char address[MAX_ADDRESS_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void createElectionSchedule();
void registerCandidate();
void registerVoter();
void updateVoterDetails();
void searchVoterDetails();
void castVote();
void displayVoteResults();

int main() {

    int choice;
    do {
        printf("\n1. Create Election Schedule\n");
        printf("2. Register Candidate\n");
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
                registerCandidate();
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 8.\n");
        }
    } while (choice != 8);

    return 0;
}

void createElectionSchedule() {
    FILE *scheduleFile;
    char constituency[MAX_CONSTITUENCY_LENGTH];
    struct Date date;

    scheduleFile = fopen("schedule.txt", "a");
    if (scheduleFile == NULL) {
        printf("Error opening schedule file.\n");
        return;
    }

    printf("Enter the constituency: ");
    scanf("%s", constituency);
    printf("Enter the date of election (YYYYMMDD): ");
    scanf("%d%d%d", &date.year, &date.month, &date.day);

    fprintf(scheduleFile, "%s\t%d%02d%02d\n", constituency, date.year, date.month, date.day);

    fclose(scheduleFile);

    printf("Election schedule created successfully.\n");
}

void registerCandidate() {
    FILE *candidateFile;
    struct Candidate newCandidate;

    candidateFile = fopen("candidatelist.txt", "a");
    if (candidateFile == NULL) {
        printf("Error opening candidate list file.\n");
        return;
    }

    printf("Enter candidate name: ");
    scanf("%s", newCandidate.name);
    printf("Enter candidate political party: ");
    scanf("%s", newCandidate.party);
    printf("Enter candidate's constituency: ");
    scanf("%s", newCandidate.constituency);

    fprintf(candidateFile, "%s\t%s\t%s\n", newCandidate.name, newCandidate.party, newCandidate.constituency);

    fclose(candidateFile);

    printf("Candidate registered successfully.\n");
}

void registerVoter() {
    FILE *voterFile;
    struct Voter newVoter;

    voterFile = fopen("voterlist.txt", "a");
    if (voterFile == NULL) {
        printf("Error opening voter list file.\n");
        return;
    }

    printf("Enter voter name: ");
    scanf("%s", newVoter.name);
    printf("Enter voter date of birth (YYYY MM DD): ");
    scanf("%d %d %d", &newVoter.dob.year, &newVoter.dob.month, &newVoter.dob.day);
    printf("Enter voter address: ");
    scanf("%s", newVoter.address);
    printf("Enter voter password: ");
    scanf("%s", newVoter.password);

    fprintf(voterFile, "%s\t%d/%02d/%02d\t%s\t%s\n", newVoter.name, newVoter.dob.year, newVoter.dob.month, newVoter.dob.day, newVoter.address, newVoter.password);

    fclose(voterFile);

    printf("Voter registered successfully.\n");
}

void updateVoterDetails() {
    FILE *voterFile, *tempFile;
    struct Voter voter;
    int snoToUpdate;
    char newPassword[MAX_PASSWORD_LENGTH];
    bool found = false;

    voterFile = fopen("voterlist.txt", "r");
    if (voterFile == NULL) {
        printf("Error opening voter list file.\n");
        return;
    }

    tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(voterFile);
        return;
    }

    printf("Enter serial number of voter to update: ");
    scanf("%d", &snoToUpdate);

    printf("Enter new password: ");
    scanf("%s", newPassword);

    while (fscanf(voterFile, "%d %s", &voter.sno, voter.name) != EOF) {
        if (voter.sno == snoToUpdate) {
            fprintf(tempFile, "%d %s %d/%d/%d %s %s\n", voter.sno, voter.name, voter.dob.year, voter.dob.month, voter.dob.day, voter.address, newPassword);
            found = true;
        } else {
            fprintf(tempFile, "%d %s %d/%d/%d %s %s\n", voter.sno, voter.name, voter.dob.year, voter.dob.month, voter.dob.day, voter.address, voter.password);
        }
    }

    fclose(voterFile);
    fclose(tempFile);

    remove("voterlist.txt");
    rename("temp.txt", "voterlist.txt");

    if (found) {
        printf("Voter details updated successfully.\n");
    } else {
        printf("Voter not found with serial number %d.\n", snoToUpdate);
    }
}

void searchVoterDetails() {
    FILE *voterFile;
    struct Voter voter;
    int snoToSearch;
    bool found = false;

    voterFile = fopen("voterlist.txt", "r");
    if (voterFile == NULL) {
        printf("Error opening voter list file.\n");
        return;
    }

    printf("Enter serial number of voter to search: ");
    scanf("%d", &snoToSearch);

    while (fscanf(voterFile, "%d %s", &voter.sno, voter.name) != EOF) {
        if (voter.sno == snoToSearch) {
            printf("Voter found:\n");
            printf("Serial Number: %d\n", voter.sno);
            printf("Name: %s\n", voter.name);
            printf("Date of Birth: %d/%d/%d\n", voter.dob.year, voter.dob.month, voter.dob.day);
            printf("Address: %s\n", voter.address);
            found = true;
            break;
        }
    }

    fclose(voterFile);

    if (!found) {
        printf("Voter not found with serial number %d.\n", snoToSearch);
    }
}

void castVote() {
    FILE *voterFile, *candidateFile, *voteCountFile;
    struct Voter voter;
    struct Candidate candidate;
    int sno, choice;
    bool found = false;

    voterFile = fopen("voterlist.txt", "r");
    if (voterFile == NULL) {
        printf("Error opening voter list file.\n");
        return;
    }

    printf("Enter your SNO: ");
    scanf("%d", &sno);
    printf("Enter your password: ");
    char password[MAX_PASSWORD_LENGTH];
    scanf("%s", password);

    while (fscanf(voterFile, "%d %s %d/%d/%d %s %s", &voter.sno, voter.name, &voter.dob.year, &voter.dob.month, &voter.dob.day, voter.address, voter.password) != EOF) {
        if (voter.sno == sno && strcmp(voter.password, password) == 0) {
            found = true;
            break;
        }
    }

    fclose(voterFile);

    if (!found) {
        printf("Invalid SNO or password.\n");
        return;
    }

    candidateFile = fopen("candidatelist.txt", "r");
    if (candidateFile == NULL) {
        printf("Error opening candidate list file.\n");
        return;
    }

    printf("List of candidates:\n");
    while (fscanf(candidateFile, "%s %s %s", candidate.name, candidate.party, candidate.constituency) != EOF) {
        if (strcmp(candidate.constituency, voter.address) == 0) {
            printf("%s - %s\n", candidate.name, candidate.party);
        }
    }

    fclose(candidateFile);

    printf("Enter the number corresponding to your chosen candidate: ");
    scanf("%d", &choice);

    voteCountFile = fopen("votecount.txt", "a");
    if (voteCountFile == NULL) {
        printf("Error opening vote count file.\n");
        return;
    }

    fprintf(voteCountFile, "%d\n", choice);

    fclose(voteCountFile);

    printf("Vote cast successfully.\n");
}

void displayVoteResults() {
    FILE *voteCountFile;
    char candidateName[MAX_NAME_LENGTH];
    int voteCount = 0;

    voteCountFile = fopen("votecount.txt", "r");
    if (voteCountFile == NULL) {
        printf("Error opening vote count file.\n");
        return;
    }

    int ramVotes = 0;
    int shyamVotes = 0;
    int hariVotes = 0;
    int gopalVotes = 0;

    while (fscanf(voteCountFile, "%*d %s", candidateName) != EOF) {
        if (strcmp(candidateName, "Ram") == 0) {
            ramVotes++;
        } else if (strcmp(candidateName, "Shyam") == 0) {
            shyamVotes++;
        } else if (strcmp(candidateName, "Hari") == 0) {
            hariVotes++;
        } else if (strcmp(candidateName, "Gopal") == 0) {
            gopalVotes++;
        }
        voteCount++;
    }

    fclose(voteCountFile);

    printf("Vote Results:\n");
    printf("Ram: %d votes\n", ramVotes);
    printf("Shyam: %d votes\n", shyamVotes);
    printf("Hari: %d votes\n", hariVotes);
    printf("Gopal: %d votes\n", gopalVotes);
    printf("Total votes cast: %d\n", voteCount);
}