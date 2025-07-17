// You are given all numbers from 1 to n, except one number is missing.
// Find the missing number

#include <stdio.h>

int main() {

    int N;
    printf("\nEnter n: ");
    scanf("%d", &N);

    int array[N];
    
    // I can use algebra; E = n(n + 1) / 2 for every n belongs to natural number

    int expectedSum;
    int actualSum = 0;

    expectedSum = N * (N + 1) / 2;

    // Take input

    for(int i = 0; i < N - 1; i++) {
        printf("\nEnter number: ");
        scanf("%d", &array[i]);
    }
    
    // Using a for loop for the actual sum

    for(int i = 0; i < N - 1; i++) {
        actualSum += array[i];
    }

    int missingNumber;
    missingNumber = expectedSum - actualSum;

    printf("\n\nYour missing number is: %d\n\n", missingNumber);

    return 0;
}
