//Implement 0/1 Knapsack using Dynamic Programming
#include <stdio.h>
int main() {
    int n = 4; 
    int c = 5; 
     printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the maximum weight capacity: ");
    scanf("%d", &c);
    int weights[n], values[n];  //Array that stores the weight and value of items.

    printf("Enter the weights and values for each element:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d (weight value): ", i + 1);
        scanf("%d %d", &weights[i], &values[i]);
    }
// 2D array B with dimensions n+1 rows and c+1 columns. It will be used to store the optimal values for different combinations of items and weight capacities.
    int B[n + 1][c+ 1];

    for (int w = 0; w <= c; w++) {
        B[0][w] = 0; //1st row of the table =0

    }
    for (int i = 1; i <= n; i++) {
        B[i][0] = 0; //1st columnof the table =0
    }
    for (int i = 1; i <= n; i++) {  // all items, starting from the first item (index 1) to the last item (index n).
        for (int w = 0; w <= c; w++) { // all possible weight capacities, starting from zero weight to the maximum capacity
            if (weights[i - 1] <= w) { // weight of current item <= to current knapsack capacity (w).

// (value of current item + remaining value) is greater than the value obtained without including it.
                if (values[i - 1] + B[i - 1][w - weights[i - 1]] > B[i - 1][w]) {  
                    B[i][w] = values[i - 1] + B[i - 1][w - weights[i - 1]];  //If including item is better, updates value in table by adding item's value to value obtained //by excluding it but considering remaining capacity after including item.
                } 
else
 {
                    B[i][w] = B[i - 1][w];  //If excluding item is better or it is not feasible due to //weight constraints, keep value obtained without including it.
                }
            } 
else 
{
                B[i][w] = B[i - 1][w];
            }
        }
    }
    printf("Maximum value: %d\n", B[n][c]);
   int i = n;
    int k = c;
    while (i > 0 && k >= 0) {
        if (B[i][k] != B[i - 1][k]) {  // it means the current item contributes to the optimal solution for the current weight capacity.
            printf("Item %d is in the knapsack (weight: %d, value: %d)\n", i, weights[i - 1], values[i - 1]);
            k -= weights[i - 1];  // This line updates the remaining weight capacity by subtracting the weight of the selected item.
        }
        i--;
    }
    return 0;
}
