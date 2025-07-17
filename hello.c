// WAP in C to properly arrange the case in a name using a function with no arguments but passing values
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char messedUpName[100];
char properName[100];

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
    int findSpace;

    for(int index = 0; index < nameLength; index++) {
        messedUpName[index] = tolower(messedUpName[index]);
    }

    for(int index = 0; index < nameLength; index++) {
        if(messedUpName[index] == ' ') {
            findSpace = index;
        }
    }

    messedUpName[0] = toupper(messedUpName[0]);
    messedUpName[findSpace + 1] = toupper(messedUpName[findSpace + 1]);

    strcpy(properName, messedUpName);
    return properName;
}