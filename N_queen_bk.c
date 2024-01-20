//Write a program for N-Queen problem using Backtracking approach.
#include <stdio.h>
#include<math.h>

int board[20],count;  // array board of size 20 to store the positions of the queen(row no.)
//Declares integer variable count to track number of solutions found

int main()
{
    int n,i,j;  //no. of queens=n
    void queen(int row, int n);
    printf("N queens Problem Using Backtracking;");
    printf("\nEnter number of queens:");
    scanf("%d",&n);
    queen(1,n);  // Queen function call
    return 0;
}
void print(int n)
{
    int i,j;
    printf("\n\nSolution %d:\n\n",++count);  // count variable track  solution number
    for(i=1;i<=n;++i)
    printf("\t%d",i);
   
    for(i=1;i<=n;++i)  // header no
    {
        printf("\n\n%d",i);
        for(j=1;j<=n;++j) // row no
        {
            if(board[i]==j)  // If a queen is placed in the current cell
             printf("\tQ");
            else
             printf("\t-");
        }
    }
}
// it is valid to place a queen in a specified cell on the chessboard. It checks for conflicts with queens already placed in previous rows.
int place(int row, int column)
{
    int i;
    for(i=1;i<=row-1;++i) // loops through previously placed queen

    {
        if(board[i]==column)   // Checks if there is already a queen placed in the same column it returns 0
            return 0;
        else
            if(abs(board[i]-column)==abs(i-row))  // Queen placed diagonally from current position return 0 

            return 0;
    }
    return 1;
}
//recursive backtracking algorithm responsible for finding solutions to the N-Queens problem. It explores different configurations of placing queens on the chessboard until a valid solution is found.
void queen(int row, int n)
{
    int column; // represent current column to be explored
    for(column=1;column<=n;++column)  //The loop iterates through each column in the current row.
    {
        if(place(row,column))  // Check if we can place the queen there or no        
{
            board[row]=column;   // placement is valid, the current column is recorded as the position for the queen in the current row.
            if(row==n)  // last row is reached a valid solution has been found
                print(n);
            else
                queen(row+1,n);  // current row is not the last row, the function calls itself recursively for the next row continuing the exploration of possible configurations.
        }
    }
}

