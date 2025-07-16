// WAP in C to properly arrange the case in a name using a function with no arguments but passing values
// Include Middle Name
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char messedUpName[100];
char properName[100];
int indexWhenOneSpace;

const char* manageCase();

int main() {

    char name[100];

    strcpy(name, manageCase());
    printf("\nProper name: %s", name);

    return 0;
}

const char* manageCase() {
    printf("\nEnter name in messed up case: ");
        fgets(messedUpName, sizeof(messedUpName), stdin);
        messedUpName[strcspn(messedUpName, "\n")] = '\0';
    int nameLength = strlen(messedUpName);
    int findSpace = 0;

    for(int index = 0; index < nameLength; index++) {
        messedUpName[index] = tolower(messedUpName[index]);
    }

    for(int index = 0; index < nameLength; index++) {
        if(messedUpName[index] == ' ') {
            findSpace++; 
            indexWhenOneSpace = index;
        }
    }

    if(findSpace == 2) {
        
        // Assuming that there are only two spaces: After first name and after middle name: 

        int spaceOne = -1, spaceTwo = -1;

        // To find the first space: 

        for(int index = 0; (index < nameLength) && (spaceOne == -1); index++) {
            if(messedUpName[index] == ' ') {
                spaceOne = index;
            }
        }

        // To find the second space: 

        for(int index = spaceOne + 1; (index < nameLength) && (spaceTwo == -1); index++) {
            if(messedUpName[index] == ' ') {
                spaceTwo = index;
            }
        }

        // To manage the case:

        messedUpName[0] = toupper(messedUpName[0]);
        messedUpName[spaceOne + 1] = toupper(messedUpName[spaceOne + 1]);
        messedUpName[spaceTwo + 1] = toupper(messedUpName[spaceTwo + 1]);       

        strcpy(properName, messedUpName);
        return properName;

    } else if(findSpace == 1) {

        messedUpName[0] = toupper(messedUpName[0]);
        messedUpName[indexWhenOneSpace + 1] = toupper(messedUpName[indexWhenOneSpace + 1]);

        strcpy(properName, messedUpName);
        return properName;

    } else if(findSpace == 0) {

        messedUpName[0] = toupper(messedUpName[0]);

        strcpy(properName, messedUpName);
        return properName;

    }
}

/*
messedUpName[0] = toupper(messedUpName[0]);
    messedUpName[findSpace + 1] = toupper(messedUpName[findSpace + 1]);

    strcpy(properName, messedUpName);
    return properName;
*/
