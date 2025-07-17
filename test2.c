#include <string.h>
#include <stdio.h>

struct book {
    char author[100];
    float price;
};

int main() {

    int N;
    printf("\nEnter the number of books: ");
    scanf("%d", &N); 
    getchar();
    
    struct book bk[N];

    for(int i = 0; i < N; i++) {
        printf("\nFor book %d: \n", i + 1);
        
        printf("\nEnter name of the book: ");
        fgets(bk[i].author, 100, stdin); 
        bk[i].author[strcspn(bk[i].author, "\n")] = '\0';

        printf("\nEnter price: ");
        scanf("%f", &bk[i].price);
        getchar();
    }

    float temp;
    char tempName[100];

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(bk[i].price < bk[j].price) {
                temp = bk[i].price;
                strcpy(tempName, bk[i].author);
                bk[i].price = bk[j].price;
                strcpy(bk[i].author, bk[j].author);
                bk[j].price = temp;
                strcpy(bk[j].author, tempName);
            }
        }
    }

    // To print 

    printf("\n=====================================\n");

    for(int i = 0; i < 2; i++) {
        printf("%d. %s: %.2f\n", i + 1, bk[i].author, bk[i].price);
    }

    return 0;
}