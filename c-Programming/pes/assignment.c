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

struct Admin {
    char username[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void createElectionSchedule();
void registerCandidate();
void registerVoter();
void updateVoterDetails();
void searchVoterDetails();
void castVote();
void displayVoteResults();
void adminMenu();
void voterMenu();

// Hardcoded admin credentials
struct Admin admin = {"admin", "admin123"};

int main() {
    int userType;
    printf("Select User Type:\n");
    printf("1. Admin\n");
    printf("2. Voter\n");
    printf("Enter your choice: ");
    scanf("%d", &userType);

    switch (userType) {
        case 1:
            adminMenu();
            break;
        case 2:
            voterMenu();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

void adminMenu() {
    // Admin login
    struct Admin inputAdmin;
    printf("Admin Login\n");
    printf("Enter username: ");
    scanf("%s", inputAdmin.username);
    printf("Enter password: ");
    scanf("%s", inputAdmin.password);

    // Validate admin credentials
    if (strcmp(inputAdmin.username, admin.username) == 0 && strcmp(inputAdmin.password, admin.password) == 0) {
        int adminChoice;
        do {
            printf("\nAdmin Menu:\n");
            printf("1. Create Election Schedule\n");
            printf("2. Register Candidate\n");
            printf("3. Register Voter\n");
            printf("4. Update Voter Details\n");
            printf("5. Search Voter Details\n");
            printf("6. Cast Vote\n");
            printf("7. Display Vote Results\n");
            printf("8. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &adminChoice);

            switch (adminChoice) {
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
                    printf("Exiting admin panel...\n");
                    break;
                default:
                    printf("Invalid choice.\n");
            }
        } while (adminChoice != 8);
    } else {
        printf("Invalid username or password.\n");
    }
}

#include <stdbool.h>

bool isVoterValid(struct Voter inputVoter) {
    FILE *voterFile;
    struct Voter voter;

    voterFile = fopen("voterlist.txt", "r");
    if (voterFile == NULL) {
        printf("Error opening voter list file.\n");
        return false; // Unable to check, return false
    }

    while (fscanf(voterFile, "%d %*s %*s %*s %*s", &voter.sno) != EOF) {
        if (voter.sno == inputVoter.sno) {
            fclose(voterFile);
            return true; // Voter found
        }
    }

    fclose(voterFile);
    return false; // Voter not found
}

bool isPasswordValid(struct Voter inputVoter) {
    FILE *voterFile;
    struct Voter voter;

    voterFile = fopen("voterlist.txt", "r");
    if (voterFile == NULL) {
        printf("Error opening voter list file.\n");
        return false; // Unable to check, return false
    }

    while (fscanf(voterFile, "%d %*s %*s %*s %s", &voter.sno, voter.password) != EOF) {
        if (voter.sno == inputVoter.sno && strcmp(voter.password, inputVoter.password) == 0) {
            fclose(voterFile);
            return true; // Password matches
        }
    }

    fclose(voterFile);
    return false; // Password doesn't match
}

void voterMenu() {
    struct Voter inputVoter;
    printf("Voter Login\n");
    printf("Enter your SNO: ");
    scanf("%d", &inputVoter.sno);
    printf("Enter your password: ");
    scanf("%s", inputVoter.password);

    if (!isVoterValid(inputVoter)) {
        printf("Invalid SNO. Exiting voter panel...\n");
        return;
    }

    if (!isPasswordValid(inputVoter)) {
        printf("Invalid password. Exiting voter panel...\n");
        return;
    }

    printf("\nVoter Menu:\n");
    printf("1. Update Voter Details\n");
    printf("2. Search Voter Details\n");
    printf("3. Cast Vote\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    int voterChoice;
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
            printf("Exiting voter panel...\n");
            break;
        default:
            printf("Invalid choice.\n");
    }
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
    
    // Generate a random serial number
    newVoter.sno = rand() % MAX_VOTERS + 1;

    // Generate a random password
    char password[MAX_PASSWORD_LENGTH];
    sprintf(password, "%d%d%d", rand() % 10, rand() % 10, rand() % 10); // Generate a 3-digit numeric password
    strcpy(newVoter.password, password);

    fprintf(voterFile, "%d\t%s\t%d/%02d/%02d\t%s\t%s\n", newVoter.sno, newVoter.name, newVoter.dob.year, newVoter.dob.month, newVoter.dob.day, newVoter.address, newVoter.password);

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
    FILE *voteCountFile, *candidateFile;
    int candidate1Votes = 0;
    int candidate2Votes = 0;
    int candidate3Votes = 0;
    int candidate4Votes = 0;
    int totalVotes = 0;
    int vote;

    voteCountFile = fopen("votecount.txt", "r");
    if (voteCountFile == NULL) {
        printf("Error opening vote count file.\n");
        return;
    }

    // Read votes from the vote count file and count votes for each candidate
    while (fscanf(voteCountFile, "%d", &vote) != EOF) {
        switch (vote) {
            case 1:
                candidate1Votes++;
                break;
            case 2:
                candidate2Votes++;
                break;
            case 3:
                candidate3Votes++;
                break;
            case 4:
                candidate4Votes++;
                break;
            // Add more cases if you have more candidates
            default:
                printf("Invalid vote choice.\n");
        }
        totalVotes++;
    }

    fclose(voteCountFile);

    // Display the vote results
    printf("Vote Results:\n");
    printf("Candidate 1: %d votes\n", candidate1Votes);
    printf("Candidate 2: %d votes\n", candidate2Votes);
    printf("Candidate 3: %d votes\n", candidate3Votes);
    printf("Candidate 4: %d votes\n", candidate4Votes);
    // Add more printf statements for additional candidates if needed
    printf("Total votes cast: %d\n", totalVotes);

    // Display registered candidates
    printf("\nRegistered Candidates:\n");

    candidateFile = fopen("candidatelist.txt", "r");
    if (candidateFile == NULL) {
        printf("Error opening candidate list file.\n");
        return;
    }

    struct Candidate candidate;

    while (fscanf(candidateFile, "%s %s %s", candidate.name, candidate.party, candidate.constituency) != EOF) {
        printf("Name: %s\nParty: %s\nConstituency: %s\n\n", candidate.name, candidate.party, candidate.constituency);
    }

    fclose(candidateFile);
}
