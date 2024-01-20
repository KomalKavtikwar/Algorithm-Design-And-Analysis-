//Write a program to perform quick sort using Divide and Conquer strategy and verify the time complexity.
#include<stdio.h>
#include<time.h>
void quicksort(int arr[],int p,int r)
{
 int q;  // returned by the partition function
 if(p<r)
 {
 q = partition(arr,p ,r); //partition algo //arr array being sorted ,p starting index of current partition, r ending index of the current partition
 quicksort(arr,p,q-1);  
 quicksort(arr,q+1,r);
 }
}
int partition(int arr[],int p,int r)  //function partitions subarray around a pivot element
{
 int x=arr[r];  // This line sets the pivot element x to the value of the element at index r in the array
 int i=p-1;    // The index used to track the partition position.
 for(int j=p;j<r;j++)  
 {
 if(arr[j]<=x)  //This condition checks whether the current element at index j is less than or equal to the pivot x
 {
 i=i+1;  // increment the less than or equal to the pivot
 int t=arr[i]; //swaps the elements at indices i and j
 arr[i]=arr[j];
 arr[j]=t;
 }
 }
 int t=arr[r]; //t temporary variable
 arr[r]=arr[i+1];  //i + 1 represents the position where the pivot element will be placed after the partitioning process
 arr[i+1]=t;  // It places the pivot element (stored in t) into its correct position.
 return i+1;  // pivot element is now located.
}
int main()
{
 int arr[100],n,p=0;
 clock_t start,end;   // Declares variables of type clock_t to store the start and end times for measuring the execution time.
 double time;
 printf("Enter the size of array:");
 scanf("%d",&n);
 int r=n-1;  // Calculates the ending index r for the quicksort algorithm
 printf("Enter the numbers:");
 for(int i=0;i<n;i++)
 {
 scanf("%d",&arr[i]);
 }
 printf("\nArray elements are:");
 for(int i=0;i<n;i++)
 {
 printf("%d\t",arr[i]);
 }
 printf("\n");
 start=clock(); //Measures the start and end times for the execution of quicksort.
 quicksort(arr,p,r);
 end=clock();
 time=(end-start); //Calculates the total execution time and stores it in the variable time
 printf("\narray after sorting:");
 for(int i=0;i<n;i++)
 {
 printf("%d\t",arr[i]);
 }
 printf("\nTime taken is %lf",time);
 return 0;
}
