//Implement Traveling Salesperson Problem (or any other suitable problem) using Branch and Bound Method
#include <stdio.h>
#include <limits.h>

#define N 4 // Number of cities

int adjacencyMatrix[N][N] = {    //Represents the cost of traveling from one city to another.
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int visited[N];  //array keeps track of which cities have been visited


int leastCost = INT_MAX;  // initialized to the maximum possible integer value

void copyArray(int dest[], int src[]) {  // This function copies the contents of the dest destination array src source code
    for (int i = 0; i < N; i++) {
        dest[i] = src[i];
    }
}
//function calculates the total cost of the traveling salesperson tour based on the given path //and updates the leastCost variable if it's lower than the current value.
void calculateCost(int path[]) {  
    int cost = 0;
    for (int i = 0; i < N - 1; i++) {
        cost += adjacencyMatrix[path[i]][path[i + 1]];  // each index i, it adds the cost of traveling from the city at index path[i] to the city at index path[i + 1] to the cost variable.
    }
// . It connects the last city (path[N - 1]) to return  the starting city (path[0]).
    cost += adjacencyMatrix[path[N - 1]][path[0]]; // Return to starting city
    if (cost < leastCost) {
        leastCost = cost;
    }
}
//function implements the branch-and-bound algorithm
//path[]: An array representing the current path being explored
//level: Represents the current depth of the recursion (city index in the path)
//bound: Represents an upper bound on the cost of the complete tour based on the visited //cities so far
void branchAndBound(int path[], int level, int bound) {
    if (level == N - 1) {  // if all the cities visited calculate the cost to return        
    calculateCost(path);
        return;
    }

// Loop through all cities to explore possible next steps
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {  // Checks if the city at index i has not been visited (!visited[i]). If it hasn't been visited, the code inside the if block is executed.
            int temp[N];
            copyArray(temp, path);
            temp[level + 1] = i;  // Updates the temporary array by adding the current city index i to the next level
            visited[i] = 1;   // Marks the city at index i as visited.

            int newBound = bound - adjacencyMatrix[path[level]][i];  // Calculates a new cost bound (newBound) by subtracting the cost of the edge from the last city in the current path to the newly added city.
            branchAndBound(temp, level + 1, newBound);  // updated path (temp), increased level (level + 1), and the new cost bound

            visited[i] = 0;  //Backtrack by unmarking city as visited before exploring other possibilities
        }
    }
}

void tsp() {
    int path[N];
    path[0] = 0; // Starting from city 0
    visited[0] = 1;

    int initialBound = 0;
    for (int i = 0; i < N; i++) {
        initialBound += adjacencyMatrix[i][0];  // Calculates the initial cost bound by summing up the costs of edges from all cities to the starting city (city 0).
    }

    branchAndBound(path, 0, initialBound);

    printf("Minimum cost of the Travelling Salesperson Tour: %d\n", leastCost);
}

int main() {
    tsp();
    return 0;
}
