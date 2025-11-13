// Blaine Swieder
// C Programming: Pascal's Triangle
// June 12th, 2025

#include <stdio.h>

int main(void) {
    int num_rows, coeff, space, row, col;

    printf("Enter the number of rows (1-20): ");
    scanf("%d", &num_rows);

    if (num_rows < 1 || num_rows > 20) {
        printf("Please enter a valid number between 1 and 20.\n");
        return 1;
    }

    for (row = 0; row < num_rows; row++) {
        // Print leading spaces to center the triangle
        for (space = 1; space <= num_rows - row; space++) {
            printf("   ");
        }

        coeff = 1;
        for (col = 0; col <= row; col++) {
            if (col != 0)
                coeff = coeff * (row - col + 1) / col;

            printf("%6d", coeff);
        }
        printf("\n");
    }

    return 0;
}
