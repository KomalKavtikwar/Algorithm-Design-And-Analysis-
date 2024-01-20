//Write a program for Minimum Spanning Trees using Greedy approach (Prim’s algorithm).

#include <stdio.h>
#define MAX 20//reperesents max no. of vertice
int main() {
    int cost[MAX][MAX], t[MAX][2], near[MAX];// cost adjacency matrix, edges of //the minimum cost spanning tree, nearest neighbor information
    int n, mincost = 0;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    // Input cost adjacency matrix
    printf("Enter the cost adjacency matrix:\n");
    for (int i = 1; i <= n; ++i) { // iterates through matrix and reads cost between 
        for (int j = 1; j <= n; ++j) {// each pair of vertices
            scanf("%d", &cost[i][j]);
        }
    }
    // Initialization
    int k, l; //  temporary indices
    k = 1; //vertices 1
    l = 2; //vertices 2
    mincost = cost[1][2]; //Initial mincost to cost between 1st 2 vertices
    t[0][0] = k;//1st edge of MST
    t[0][1] = l;
    for (int i = 1; i <= n; ++i) {
        near[i] = (cost[i][l] < cost[i][k]) ? l : k; // For each vertex, it sets near[i] to the 
        near[k] = near[l] = 0; //closer vertex (either k or l) based on the cost
    }
    // This loop iterates n-2 times, finding next edge to be added to MST
    for (int i = 2; i <= n - 1; ++i) {
        int j = 0;//stores the vertex to be added next
        for (int k = 1; k <= n; ++k) {
            if (near[k] != 0 && (j == 0 || cost[k][near[k]] < cost[j][near[j]])) {
                j = k;
//This conditional statement checks if current vertex k is not already in MST and has lower //cost edge to any vertex in MST than current candidate j. If so, it updates j to k
            }
        }
        // Update t[i]
        t[i - 1][0] = j;//stores newly found edges
        t[i - 1][1] = near[j];
        // Update mincost
        mincost += cost[j][near[j]]; //updates mincost by adding cost of newly added edge
        // Update near[]
        near[j] = 0;//this line marks new vertex in MST
        for (int k = 1; k <= n; ++k)//updates the near array for remaining vertices 
{
            if (near[k] != 0 && cost[k][near[k]] > cost[k][j]) {
                near[k] = j;
            }
        }
    }
    printf("\nMinimum Cost Spanning Tree Edges:\n");
    for (int i = 0; i < n - 1; ++i) {
        printf("(%d, %d)\n", t[i][0], t[i][1]);
    }
    printf("\nMinimum Cost: %d\n", mincost);
    return 0;
}

