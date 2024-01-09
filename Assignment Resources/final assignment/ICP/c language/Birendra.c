#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void subscribe();
void printPlan();
int planChecker(int);
char claimCheck();
void printClaims();
int genId();
int incId();
void printData();
int searchSub(char[]);
void claimInsur();
int calcClaim(char,int,int,int,int,int);
void WriteClaims();
void printAccountInfo();


void main(){ //Main Function
    FILE *claim;
    claim=fopen("claimData.txt","r");
    if(claim==NULL){
        FILE *c;
        c=fopen("claimData.txt","w");
        fclose(c);
    }
    FILE *count;
    count=fopen("counter.txt","r");
    if(count==NULL){
        FILE *newFile;
        newFile=fopen("counter.txt","w");
        int id=1;
        fprintf(newFile,"%d",id);
        fclose(newFile);
    }
    char b='f';
    int yw;
    printf("\tWelcome to ZeeMedLife Health Insurance Company\n");
    printf("\n");
    printf("1)Make Subscription    2)Claim Insurance    3)Accounts Information    4)Search\n");
    // subscribe();
    do{
        printf(">>");
        scanf("%d",&yw);
        if(yw==1 || yw==2 || yw==3 || yw==4){
            if(yw==1){
                subscribe();
                b='k';
            }else if(yw==4){
                FILE *lamo;
                lamo=fopen("data.txt","r");
                if(lamo==NULL){
                    printf("\n");
                    printf("No Subscriber Found!\n");
                    exit(0);
                }
                char name[100];
                int c=getc(stdin);
                printf("Enter subscriber name: ");
                fgets(name,100,stdin);
                printf("\n");
                name[strlen(name)-1]= '\0'; //removing new line of strings
                searchSub(name);
                b='k';
            }else if(yw==2){
                FILE *lamo;
                lamo=fopen("data.txt","r");
                if(lamo==NULL){
                    printf("\n");
                    printf("No Subscriber Found!\n");
                    exit(0);
                }
                claimInsur();
                b='k';
            }else if(yw==3){
                printAccountInfo();
                b='k';
            }
        }else{
            printf("Invalid Input!\n");
        }
    }while(b=='f');
}

void subscribe(){
    int sl=50;
    int plantype;
    struct Customer{  
        int id;
        char name[sl];
        char addr[sl];
        int age;
        long int phone;
        char planType[sl];
        char claimType[sl];
        char healthHistory[sl];
        int year;
    };
    
    int c=getc(stdin);
    struct Customer c1;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    c1.year=tm.tm_year + 1900;

    printf("Enter your Name: ");
    fgets(c1.name,sl,stdin);


    printf("Enter your Address: ");
    fgets(c1.addr,sl,stdin);

    printf("Enter your Phone Number: ");
    scanf("%li",&c1.phone);

    printf("Enter your age: ");
    scanf("%d",&c1.age);
    if(c1.age>54){
        printf("\n");
        printf("Insurance not available!!\n");
        exit(0);
    }
    c1.name[strlen(c1.name)-1]= '\0'; //removing new line of strings
    c1.addr[strlen(c1.addr)-1]= '\0';
    c1.claimType[strlen(c1.claimType)-1]= '\0';
    c1.planType[strlen(c1.planType)-1]= '\0';
    printf("\n");
    printPlan();
    printClaims();
    plantype=planChecker(c1.age);
    if(plantype==1){
        strcpy(c1.planType,"Plan120");
    }else if(plantype==2){
        strcpy(c1.planType,"Plan150");
    }else if(plantype==3){
        strcpy(c1.planType,"Plan200");
    }
    printf("\n");

    int claimType = claimCheck();
    if(claimType==1){
        strcpy(c1.claimType,"Annual Claim");
    }else{
        strcpy(c1.claimType,"Lifetime Claim");
    }

    FILE *fp;
    c1.id=genId();
    incId();

    fp=fopen("data.txt","a");
    if(fp==NULL){
        printf("Error");
    }else{
        fprintf(fp,"%d-%s-%d-%li-%s-%s-%s-%d\n",c1.id,c1.name,c1.age,c1.phone,c1.addr,c1.planType,c1.claimType,c1.year);
    }
    fclose(fp);
}

void printPlan(){ //this print insurance plans
    printf("ZeeMedLife Health Insurance Plan (Choose by plan number): \n");
    printf("\n");
    printf("Types of Plans\t\tMonthly Premium\t\tAnnual Claim Limit\t\tLifetime Claim limit\n");
    printf("1)Plan120     \t\t120RM        \t\t120000RM            \t\t600000RM\n");
    printf("2)Plan150     \t\t150RM        \t\t150000RM            \t\t750000RM\n");
    printf("3)Plan200     \t\t200RM        \t\t200000RM            \t\t1000000RM\n");
    printf("(Note: Annual Claim is available till age of 60 and Lifetime Claim till exausted. )\n");
    printf("\n");
    printf("\n");
}

int planChecker(int age){ //this is for chossing plan type
    int planType;
    char b='f';
    do{
        printf(">>");
        scanf("%d",&planType);
        if(planType==1 || planType ==2 ||planType ==3){
            if(planType==1){
               if(age>=1 && age<=20){
                    printf("Plan120 Successfully chosen\n");
                    b='t';
               }else{
                   printf("plan not available!\n");
               }
            }else if(planType==2){
                if(age>=1 && age<40){
                    printf("Plan150 Successfully chosen\n");
                    b='t';
                }else if(age>41 && age<=54){
                    printf("Plan not available!\n");
                }else{
                    printf("Plan not available!\n");
                }
            }else if(planType==3){
                printf("Plan200 successfully chosen\n");
                b='t';
            }
        }else{
            printf("Invalid input!\n");
        }
    }while(b=='f');
    return planType;
}

char claimCheck(){
    int cType;
    printf("Enter your Claim type:\n");
    printf("1)Annual Claim\t 2)Lifetime Claim\n");
    char b='f';
    do{
        printf(">>");
        scanf("%d",&cType);
        if(cType==1 || cType==2){
            if(cType==1){
                printf("You've Chosen Annual Claim!\n");
                b='q';
                
            }else{
                printf("You've Chosen Lifetime Claim!\n");
                b='q';
            }
        }else{
            printf("Invalid Input!\n");
        }
    }while(b=='f');
    return cType;
}

int genId(){
    int id;
    FILE *fp;
    fp=fopen("counter.txt","r");
    rewind(fp);
    fscanf(fp,"%d",&id);
    return id;
    fclose(fp);
}
int incId(){
    FILE *fp;
    int id;
    fp=fopen("counter.txt","r");
    fscanf(fp,"%d",&id);
    fclose(fp);
    FILE *nFile;    
    id++;
    nFile=fopen("counter.txt","w");
    fprintf(nFile,"%d",id);
    fclose(nFile);
    // FILE *fp;
    // int id;
    // fp=fopen("counter.txt","r");
    // rewind(fp);
    // fscanf(fp,"%d",&id);
    // id++;
    // fclose(fp);
    // FILE *nFile;
    // nFile=fopen("counter.txt","w");   
    // fprintf(nFile,"%d",id); 
    // fclose(nFile);
}

void printClaims(){
    printf("Hospital and Surgical Benefits\n");
    printf("\n");
    printf("Types of Claim             plan120\t\tplan150\t\tplan200\n");
    printf("Room Charges               120/day\t\t150/day\t\t200/day\n");
    printf("ICU Charges                250/day\t\t400/day\t\t700/day\n");
    printf("(Note: For Hospital service and supplies, Surgical fees, other fees are as approved by ZeeMedLife)\n");
}

int searchSub(char name[]){
    int check;
    char* arr[8];
    FILE *fp;
    fp=fopen("data.txt","r");
    char lamo[400];
    while(fscanf(fp,"%[^\n] ",lamo)!=EOF){
        // printf("%s\n",lamo);
        char* token = strtok(lamo, "-");
        int n=0;
        while(token!=NULL){
            // printf("%s\n",token);
            arr[n]=token;
            n++;
            token=strtok(NULL, "-");
        }
        check=strcmp(name,arr[1]);
        if(check==0){
            break;
        }
    }
    if(check==0){
        printf("Your Details:\n");
        printf("id\t\t%s\n",arr[0]);
        printf("Name\t\t%s\n",arr[1]);
        printf("Age\t\t%s\n",arr[2]);
        printf("Phone No.\t%s\n",arr[3]);
        printf("Address.\t%s\n",arr[4]);
        printf("Plan Type\t%s\n",arr[5]);
        printf("Claim Type\t%s\n",arr[6]);
        printf("Subscribed Year\t%s\n",arr[7]);
        int b=atoi(arr[0]);
        return b;
    }else{
        printf("Subscriber Doesn't exist!\n");
        return 0;
    }
}

void claimInsur(){
    printf("\n");
    char name[100];
    int c=getc(stdin);
    printf("Enter Subscriber name: ");
    fgets(name,100,stdin);
    name[strlen(name)-1]= '\0';
    printf("\n");
    char id = searchSub(name);
    if(id){
        char type;
        int hd,hSS,sF,oF;
        printf("\n");
        printf("Enter Claim details:\n");
        printf("\n");
        printf("Number of Days in Hospital: ");
        scanf("%d",&hd);
        printf("ICU(I) or Normal(N): ");
        scanf(" %c",&type);
        printf("Hospital Supplies and Services: ");
        scanf("%d",&hSS);
        printf("Surgical Fees: ");
        scanf("%d",&sF);
        printf("Other Fees: ");
        scanf("%d",&oF);        
        calcClaim(type, id, hd, hSS,sF, oF);
    }
}

int calcClaim(char type, int id, int hD, int hSS, int sF, int oF){
    char str1[400];
    int RoomClaim=0;
    int claimLimit=0;
    char claimtype[100];
    int rDate;
    FILE *fp;
    char* arr[8];
    fp=fopen("data.txt","r");
    while(fscanf(fp,"%[^\n] ",str1)!=EOF){
        char* token = strtok(str1, "-");
        int n=0;
        while(token!=NULL){
            // printf("%s\n",token);
            arr[n]=token;
            n++;
            token=strtok(NULL, "-");
        }
        int newId=atoi(arr[0]);
        if(id==newId){
            rDate=atoi(arr[7]);
            strcpy(claimtype,arr[6]);
            if(strcmp(arr[5],"Plan120")==0){
                if(strcmp(arr[6],"Lifetime Claim")==0){
                    claimLimit=600000;
                }else if(strcmp(arr[6],"Annual Claim")==0){
                    claimLimit=120000;
                }
                if(type=='N'){
                    RoomClaim=hD*120;
                }else if(type=='I'){
                    RoomClaim=hD*250;
                }
            }else if(strcmp(arr[5],"Plan150")==0){
                if(strcmp(arr[6],"Annual Claim")==0){
                    claimLimit=150000;
                }else if(strcmp(arr[6],"Lifetime Claim")==0){
                    claimLimit=750000;
                }
                if(type=='N'){
                    RoomClaim=hD*150;
                }else if(type=='I'){
                    RoomClaim=hD*400;
                }
            }else if(strcmp(arr[5],"Plan200")==0){
                if(strcmp(arr[6],"Annual Claim")==0){
                    claimLimit=200000;
                }else if(strcmp(arr[6],"Lifetime Claim")==0){
                    claimLimit=1000000;
                }
                if(type=='N'){
                    RoomClaim=hD*200;
                }else if(type=='I'){
                    RoomClaim=hD*700;
                }
            }
        }
    }
    FILE *checkClaim;
    checkClaim=fopen("claimData.txt","r");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int claimDate=tm.tm_year + 1900;
    if(checkClaim!=NULL){
        fseek(checkClaim,0,SEEK_END);
        size_t size= ftell(checkClaim);
        if(0==size){
            int totalClaim=RoomClaim+hSS+sF+oF;
            int RemainingClaim = claimLimit-totalClaim;
            WriteClaims(id,totalClaim,RemainingClaim,claimtype,claimDate,rDate);
        }else{
            char str1[400];
            FILE *readClaim;
            char* arr[7];
            readClaim=fopen("claimData.txt","r");
            char checkId=6;
            while(fscanf(readClaim,"%[^\n] ",str1)!=EOF){
                char* token = strtok(str1, "-");
                int n=0;
                while(token!=NULL){
                    // printf("%s\n",token);
                    arr[n]=token;
                    n++;
                    token=strtok(NULL, "-");
                }
                if(id==atoi(arr[0])){
                    checkId=1;
                    FILE *sClaim;
                    char sss[500];
                    char* sArr[7];
                    int sId;
                    sClaim=fopen("claimData.txt","r");
                    while(fscanf(sClaim,"%[^\n] ",sss)!=EOF){
                        char* token = strtok(sss, "-");
                        int p=0;
                        while(token!=NULL){
                            // printf("%s\n",token);
                            sArr[p]=token;
                            p++;
                            token=strtok(NULL, "-");
                        }
                        sId=atoi(sArr[0]);
                        if(id==sId){
                            claimLimit=atoi(sArr[2]);
                            if(claimLimit==0){
                                printf("\n");
                                printf("You've exausted Your claims!\n");
                                exit(0);
                            }
                            int OldClaim=atoi(sArr[1]);
                        }
                    }
                    
                }
            }
            int totalClaim=RoomClaim+hSS+sF+oF;
            int RemainingClaim;
            if(totalClaim>claimLimit){
                RemainingClaim=claimLimit;
            }else{
                RemainingClaim=claimLimit-totalClaim;
            }
            if(checkId!=1){
                int totalClaim=RoomClaim+hSS+sF+oF;
                int RemainingClaim = claimLimit-totalClaim;
                WriteClaims(id,totalClaim,RemainingClaim,claimtype,claimDate,rDate);
            }else{
                WriteClaims(id,totalClaim,RemainingClaim,claimtype,claimDate,rDate);
            }
        }
    }
    fclose(checkClaim);
}

void WriteClaims(int id, int totalClaim, int RemainingClaim, char claimType[100], int claimDate, int rDate){
    if(RemainingClaim==0){
        printf("\n");
        printf("Claim Successful!\n");
        printf("Total Claim: %dRM\n",totalClaim);
        printf("Remaining Claim: %dRM\n",RemainingClaim);
        FILE *claimWrite;
        claimWrite=fopen("claimData.txt","a");
        fprintf(claimWrite,"%d-%d-%d-%s-%d-%d\n",id,totalClaim,RemainingClaim,claimType,claimDate,rDate);
        fclose(claimWrite);
    }else if(totalClaim>RemainingClaim){
        printf("\n");
        printf("Error!Your claim is greater than Available balance\n",RemainingClaim);
        printf("Your claim: %dRM\n",totalClaim);
        printf("Available Balance:%dRM\n",RemainingClaim);
    }else{
        printf("\n");
        printf("Claim Successful!\n");
        printf("Total Claim: %dRM\n",totalClaim);
        printf("Remaining Claim: %dRM\n",RemainingClaim);
        FILE *claimWrite;
        claimWrite=fopen("claimData.txt","a");
        fprintf(claimWrite,"%d-%d-%d-%s-%d-%d\n",id,totalClaim,RemainingClaim,claimType,claimDate,rDate);
        fclose(claimWrite);
    }
    
}

void printAccountInfo(){
    FILE *readData;
    FILE *readClaim;
    readClaim=fopen("claimData.txt","r");
    readData=fopen("data.txt","r");
    if(readClaim!=NULL){
        fseek(readClaim,0,SEEK_END);
        size_t size = ftell(readClaim);
        if(size == 0 && readData ==NULL){
            printf("\n");
            printf("No Datas found!\n");
        }else if(readData!=NULL){
            char spp[500];
            char* arr[8];
            int lCount=0,aCount=0;
            while(fscanf(readData,"%[^\n] ",spp)!=EOF){
                char* token = strtok(spp, "-");
                int n=0;
                while(token!=NULL){
                    arr[n]=token;
                    n++;
                    token=strtok(NULL, "-");
                }
                if(strcmp(arr[6],"Lifetime Claim")==0){
                    lCount++;
                }else if(strcmp(arr[6],"Annual Claim")==0){
                    aCount++;
                }
            }
            printf("\n");
            printf("Account Details\n");
            printf("\n");
            printf("Total Lifetime Claim Subscribers: %d\n",lCount);
            printf("Total Annual Claim Subscribers: %d\n",aCount);
        }
        if(size!=0){
            FILE *rrClaim;
            char stt[500];
            char* arr[6];
            int countA=0,countL=0,eSubs=0,totalL=0,totalA=0;
            rrClaim=fopen("claimData.txt","r");
            while(fscanf(rrClaim,"%[^\n] ",stt)!=EOF){
                char* token = strtok(stt, "-");
                int n=0;
                while(token!=NULL){
                    // printf("%s\n",token);
                    arr[n]=token;
                    n++;
                    token=strtok(NULL, "-");
                }
                if(strcmp(arr[3],"Annual Claim")==0){
                    totalA+=atoi(arr[1]);
                }else if(strcmp(arr[3],"Lifetime Claim")==0){
                    totalL+=atoi(arr[1]);
                }
                if(atoi(arr[2])==0){
                    eSubs++;
                }
            }
            fclose(rrClaim);
            // printf("\n");
            printf("Total Exausted subscribers: %d\n",eSubs);
            printf("Total Amount Claimed by Lifetime Subscriber: %d\n",totalL);
            printf("Total Amount Claimed by Annual Subscriber: %d\n",totalA);
        }
    }   
}


