#include "analyze.h"
#include "algorithm.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>  // rand(), srand()
#include <time.h>
#define MAX 16384 // *100
// Private
//
int myRand(){
return rand() %6 +1;
}
int searchKey; // for key to search for
bool found; // set to true if found
int numToWorkOn,in,arr[MAX];
//int n=512;
// for x =1 x< SIZE_START * ITERATIONS 512*1 512*2 512*4 512*8 ...
void createData(const case_t c, int n ){ 
 srand(time(NULL)); // alltid unika slump tal
 //srand(1); // alltid samma slump tal
    for(int i=0;i<n;i++) {
        //data asending sorted {1,2,3,4,..n-1}
        if (c==best_t)
        {
            arr[i]=(i);
        }
        //data worse case 1 desending sorted {n,n-1,n-2,n-3,.. 3,2,1,0}
        if (c==worst_t)
        {
            arr[i]=n-i;
        }
         //data random -> average {20,1,332,33,..}
        if (c==average_t)
        {
            arr[i]= rand()%MAX;
        }
    }
}
void showTestData(){
    printf("Sample of test data:");
for (int i = 0; i < 10; i++)
				{
				printf("[%d]=%d ",i,arr[i]);
				}
    printf("\n");
}         
//
// Public
//
void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n) // n=ITERATIONS??
{
            for (int i = 0; i < ITERATIONS; i++) 
            {
                //set testdata size
                numToWorkOn=SIZE_START*pow(2,i);
                //create data
                if (c==best_t) searchKey=1; //set key first
                if (c==worst_t) searchKey=MAX+1; //numToWorkOn; //set key out of range
                if (c==average_t) searchKey=rand()%numToWorkOn; //set key random 
                if (a==binary_search_t)
                {
                    createData(best_t,numToWorkOn); //make testadtat - Binary needs sorted testdata
                    if (c==best_t) searchKey=numToWorkOn/2; //set key middel value
                }
                else {
                   createData(c,numToWorkOn); //make testdata
                }
                
                clock_t start_time = clock();
                if (a==bubble_sort_t) bubble_sort(arr, numToWorkOn);
                if (a==insertion_sort_t) insertion_sort(arr, numToWorkOn);
                if (a==quick_sort_t) quick_sort(arr, numToWorkOn);
                if (a==linear_search_t) found=linear_search(arr, numToWorkOn,searchKey);
                if (a==binary_search_t) found=binary_search(arr, numToWorkOn,searchKey);
                double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
                buf[i].size=numToWorkOn;
                buf[i].time=elapsed_time;
            }   
}

