// Write a C program to find and list the top five most expensive books out of N number of books
// This was my homework 7 / 17 / 2025

#include <stdio.h>
#include <string.h>

struct book {
    int totalPages;
    float price;
    char author[100];
    char title[100];
};

int main() {

    int N;
    printf("\nEnter the number of books: ");
    scanf("%d", &N);

    struct book bk[N];

    // To take the input:

    int primaryIndex;
    for(primaryIndex = 0; primaryIndex < N; primaryIndex++) {
        printf("\nFor book %d: \n", primaryIndex + 1);
        printf("\nEnter the number of pages: ");
        scanf("%d", &bk[primaryIndex].totalPages);
        printf("Enter the price: ");
        scanf("%f", &bk[primaryIndex].price); getchar();
        printf("Enter the title of the book: ");
        fgets(bk[primaryIndex].title, 100, stdin);
        bk[primaryIndex].title[strcspn(bk[primaryIndex].title, "\n")] = '\0';
        printf("Enter the name of the author of the book: ");
        fgets(bk[primaryIndex].author, 100, stdin);
        bk[primaryIndex].author[strcspn(bk[primaryIndex].author, "\n")] = '\0';
        }
    
    // To find the top five most expensive books:
    // Using Bubble Sort method: 

    int secondaryIndex;
    float temp;
    char tempName[100];
    for(primaryIndex = 0; primaryIndex < N; primaryIndex++) {
        for(secondaryIndex = primaryIndex + 1; secondaryIndex < N; secondaryIndex++) {
            if(bk[secondaryIndex].price > bk[primaryIndex].price) {
                temp = bk[primaryIndex].price;
                strcpy(tempName, bk[primaryIndex].title);
                bk[primaryIndex].price = bk[secondaryIndex].price;
                strcpy(bk[primaryIndex].title, bk[secondaryIndex].title);
                bk[secondaryIndex].price = temp;
                strcpy(bk[secondaryIndex].title, tempName);
            }
        }
    }

    // To print out the top five most expensive books: 

    printf("\n==================================\n");

    printf("\nTop five most expensive books: \n");
    for(int i = 0; i < 5; i++) {
        printf("%d. Name: %s and Price: %.2f\n", i + 1, bk[i].title, bk[i].price);
    }

    return 0;
}
