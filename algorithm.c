#include "algorithm.h"
#include <stdio.h>
#include <stdbool.h> // bool
//
// Private
//

//
// Public
//

// swap to switch 2 values used in bubbel and binäry
void swap(int *xp, int *yp){
   int temp = *xp;
    *xp = *yp;
    *yp = temp;  
}

// Bubble sort
void bubble_sort(int *a, int n)
{
	for(int i=0;i<n-1; i++){          
        for(int j=0; j<n-1; j++){
           if( a[j] > a[j +1])
           swap(&a[j], &a[j+1]);
        }
    }
}

// Insertion sort
void insertion_sort(int *a, int n)
{
	  int i, key, j;
    for(i =1; i<n; i++){
        key=a[i];
        j= i -1;

         while(j>=0 && a[j]>key){
             a[j+1]=a[j];
             //j=j-1;
             j--;
         }
         a[j+1]=key;
    }
}

// Quick sort
int partition(int *a, int low, int high){
       int pivot_value = a[high];
       int i = low;

       for(int j= low; j<high;j++){
           if(a[j]<=pivot_value){
               swap(&a[i],&a[j]);
               i++;
           }
       }
       swap(&a[i],&a[high]);
       return i;
   }

void quicksort_r(int *a, int low, int high){
       if(low <high){
       int pivot_index = partition(a,low,high);
       quicksort_r(a,low,pivot_index-1);
       quicksort_r(a,pivot_index+1,high);
       }
   }

void quick_sort(int *a,int n){
     quicksort_r(a,0,n-1);
 }

// Linear search
bool linear_search(const int *a, int n, int v)
{
	
	for(int i=0;i<n-1; i++){          
           if( a[i]==v  ){
           return true;
           }
        }
	return false; 
}

// Binary search
bool binary_search(const int *a, int n, int v)
{
    int start = 0;
    int stop = n - 1;
    int index = -1;
    while (start <= stop && index == -1)
    {
        int mid = (start + stop) / 2;
        if (v > a[mid])
        {
            start = mid + 1;
        }
        else if (v < a[mid])
        {
            stop = mid - 1;
        }
        else
        {
            index = mid;
        }
    }
    //return index;
    if (index==-1) return true;
    else return false;
}
