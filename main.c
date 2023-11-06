/*
* File: main.c
* Author: Oriol Aguilà Pérez
* Date: 04-11-2023
* Description: PR1 UOCStadium programm
*/

/* System header files */
#include <stdio.h>
#include <stdbool.h>

/* Symbolic constants */
#define MIN_SUPPORTERS 1
#define MAX_SUPPORTERS 10
#define BASE_MEMBERSHIP_YEARS 5
#define SILVER_MEMBERSHIP_YEARS 10

/* User defined types */
typedef enum tMembershipType {BASE, SILVER, GOLD};

/* Main function */
int main(int argc, char **argv)
{
    //variable declaration
    int supporterIds[MAX_SUPPORTERS];
    int supporterAges[MAX_SUPPORTERS];
    bool supporterRecords[MAX_SUPPORTERS];
    int membershipYears;
    
    int i;
    int numSupporters;
    int recoveredSupporters[MAX_SUPPORTERS];
    enum tMembershipType supporterMembershipTypes[MAX_SUPPORTERS];
    
    float averageSupporterAge;
    int sum;
    int membershipSearchFilter;
    int recoveredCount;
    
    //collect user input 
    printf("INPUT DATA\n");
    printf("NUMBER OF SUPPORTERS(1-10)?\n");
    scanf("%d", &numSupporters);
    
    while (numSupporters < 1 || numSupporters > 10){
        printf("INVALID DATA, TRY AGAIN!\n");
        printf("NUMBER OF SUPPORTERS(1-10)?\n");
        scanf("%d", &numSupporters);
    }

    for (i = 0; i < numSupporters; i++){
        printf("SUPPORTER #%d\n", i+1);
        printf("ID(AN INTEGER)?\n");
        scanf("%d", &supporterIds[i]);
        printf("AGE (AN INTEGER)?\n");
        scanf("%d", &supporterAges[i]);
        printf("HAS RECORDS (0-FALSE, 1-TRUE)?\n");
        scanf("%d", &supporterRecords[i]);
        printf("MEMBERSHIP YEARS (AN INTEGER)?\n");
        scanf("%d", &membershipYears);
        
        if (membershipYears <= BASE_MEMBERSHIP_YEARS){
            supporterMembershipTypes[i] = BASE;
        } else if(membershipYears > BASE_MEMBERSHIP_YEARS && membershipYears <= SILVER_MEMBERSHIP_YEARS){
            supporterMembershipTypes[i] = SILVER;
        } else{
            supporterMembershipTypes[i] = GOLD;
        }
    }
    
    //calculate supporter average age
    
    for (i = 0; i < numSupporters; i++){
        sum = sum + supporterAges[i];
    }
    
    averageSupporterAge = sum/(float)numSupporters;
    
    
    //search and print data from requested membership type users
    
    printf("LOOKING FOR SUPPORTERS\n");
    printf("MEMBERSHIP TYPE(1-BASE, 2-SILVER, 3-GOLD)?\n");
    scanf("%d", &membershipSearchFilter);
    
    printf("RESULTS\n");
    printf("AVERAGE SUPPORTER AGE: %.2f\n", averageSupporterAge);
    
    recoveredCount = 0;
    for (i = 0; i < numSupporters; i++){
        if (membershipSearchFilter == (supporterMembershipTypes[i] + 1) && supporterAges[i] < averageSupporterAge && supporterRecords[i] == false){
            recoveredSupporters[recoveredCount] = supporterIds[i];
            recoveredCount = recoveredCount + 1;
        }
    }
    
    for (i=0; i < recoveredCount; i++){
        printf("recovered supporters %d\n",recoveredSupporters[i]);
    }
    
    if (recoveredCount > 0) {
        printf("recovered supporters num: %d\n", recoveredCount);
        for (i=0; i < recoveredCount; i++){
            printf("SUPPORTER ID: %d\n", recoveredSupporters[i]);
            printf("AGE: %d\n", supporterAges[recoveredSupporters[i-1]]);
            printf("HAS RECORDS (0-FALSE, 1-TRUE): %d\n", supporterRecords[recoveredSupporters[i-1]]);
            printf("MEMBERSHIP TYPE (1-BASE, 2-SILVER, 3-GOLD): %d\n", supporterMembershipTypes[recoveredSupporters[i - 1]] + 1);
        }
    }
    
    else {
        printf("NO SUPPORTERS RECOVERED.\n");
    }
    
    
    /*for (i = 0; i < numSupporters; i++){
        if (membershipSearchFilter == (supporterMembershipTypes[i] + 1) && supporterAges[i] < averageSupporterAge && supporterRecords[i] == false){
            printf("SUPPORTER ID: %d\n", supporterIds[i]);
            printf("AGE: %d\n", supporterAges[i]);
            printf("HAS RECORDS (0-FALSE, 1-TRUE): %d\n", supporterRecords[i]);
            printf("MEMBERSHIP TYPE (1-BASE, 2-SILVER, 3-GOLD): %d\n", supporterMembershipTypes[i] + 1);
            recoveredCount = recoveredCount + 1;
        }
    }
    
    //recoveredCount increases by 1 every time a supporter matches the criteria. If it's equal to 0, it means no supporters matched the requested crtieria. 
    if (recoveredCount == 0){
        printf("NO SUPPORTERS RECOVERED.\n");
    }*/
    

	return 0;
}
