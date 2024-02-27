#ifndef VOTING_SYSTEM_H
#define VOTING_SYSTEM_H

#define MAX_NAME_LENGTH 50
#define MAX_PARTY_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_PASSWORD_LENGTH 20

struct ElectionSchedule {
    char constituency[50];
    char date[9];
};


struct Candidate {
    int serialNumber;
    char name[MAX_NAME_LENGTH];
    char party[MAX_PARTY_LENGTH];
    char candidacyFrom[MAX_NAME_LENGTH];
};

struct Voter {
    int sno;
    char name[MAX_NAME_LENGTH];
    char dob[11];
    char address[MAX_ADDRESS_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};


void adminMenu();
void voterMenu();
int authenticateAdmin();
int authenticateVoter(int sno, const char *password);
void createElectionSchedule();
void manageCandidates();
void addCandidate();
void updateCandidate();
void registerVoter();
void updateVoterDetails();
void searchVoterDetails();
void castVote();
void displayVoteResults();

#endif 
