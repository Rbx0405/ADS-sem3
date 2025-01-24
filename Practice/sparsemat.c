
#include <stdio.h>

#define MAX 100

int main()
{
    int rows = 3, cols = 3; // Define the matrix size
    int matrix[3][3] = {    // Predefined sparse matrix
                        {0, 1, 0},
                        {4, 0, 0},
                        {0, 0, 5}};

    int triplet[MAX][3], k = 1;

    // Convert sparse matrix to triplet representation
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                triplet[k][0] = i;            // Row index
                triplet[k][1] = j;            // Column index
                triplet[k][2] = matrix[i][j]; // Value
                k++;
            }
        }
    }

    // Store metadata in the 0th row of triplet
    triplet[0][0] = rows;
    triplet[0][1] = cols;
    triplet[0][2] = k - 1;

    // Print the triplet representation
    printf("\nTriplet Representation:\n");
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < k; i++)
    {
        printf("%d\t%d\t%d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }

    return 0;
}