// C program to store time taken and number of comparisons made by
//____sort1.txt -> time ; ____sort2.txt -> comparisons ; two output files for each sorting function
// bubble sort, selection sort, quick sort and merge sort
// for sorting the exactly same arrays.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "server1.h"
// Driver code
int main()
{
    long int n = 32000;
    int it = 0;

    // Arrays to store time duration
    // of sorting algorithms
    double tim1[10], tim2[10], tim3[10],tim4[10];
    // Arrays to store number of element to element comparisons
    // of sorting algorithms
    double nb[10],ns[10],nq[10],nm[10];
    FILE *bp1 = fopen("bubblesort1_op.txt","w");
    FILE *bp2 = fopen("bubblesort2_op.txt","w");
    FILE *sp1 = fopen("selectionsort1_op.txt","w");
    FILE *sp2 = fopen("selectionsort2_op.txt","w");
    FILE *qp1 = fopen("quicksort1_op.txt","w");
    FILE *qp2 = fopen("quicksort2_op.txt","w");
    FILE *mp1 = fopen("mergesort1_op.txt","w");
    FILE *mp2 = fopen("mergesort2_op.txt","w");
    printf("Size, Bubble, Selection, Quick, Merge\n");

    // Performs 7 iterations (32k to 256k) ; can be adjusted to any array sizes as required (32k to 256k instead of 100k to 1000k chosen to reduce compilation time)
    while (it++ < 1) {
        long int* a=(long int*)malloc(sizeof(long int)*n);
        long int* b=(long int*)malloc(sizeof(long int)*n);
        long int* c=(long int*)malloc(sizeof(long int)*n);
        long int* d=(long int*)malloc(sizeof(long int)*n);
        // generating n random numbers
        // storing them in arrays a, b, c
        for (int i = 0; i < n; i++) {
            long int no = rand() % n + 1;
            a[i] = no;
            b[i] = no;
            c[i] = no;
            d[i] = no;
        }
        // using clock_t to store time
        clock_t start, end;

        // Bubble sort
        start = clock();
        nb[it]=bubbleSort(a, n);
        end = clock();

        tim1[it] = time_elapsed(start,end);

        //Selection sort
        start = clock();
        ns[it]=selectionSort(b, n);
        end = clock();
        tim2[it] = time_elapsed(start,end);


        //Quick Sort
        start = clock();
        quicksort(c, 0,n-1);
        nq[it]=qcount;
        end = clock();
        tim3[it] = time_elapsed(start,end);
        //Merge Sort
        start = clock();
        mergeSort(a, 0,n-1);
        nm[it]=mcount;
        end = clock();
        tim4[it] = time_elapsed(start,end);

        fprintf(bp1,"%lli",(long long int)tim1[it]);
        fprintf(bp1,"\n");
        fprintf(bp2,"%lli",(long long int)nb[it]);
        fprintf(bp2,"\n");
        fprintf(sp1,"%lli",(long long int)tim2[it]);
        fprintf(sp1,"\n");
        fprintf(sp2,"%lli",(long long int)ns[it]);
        fprintf(sp2,"\n");
        fprintf(qp1,"%lli",(long long int)tim3[it]);
        fprintf(qp1,"\n");
        fprintf(qp2,"%lli",(long long int)nq[it]);
        fprintf(qp2,"\n");
        fprintf(mp1,"%lli",(long long int)tim4[it]);
        fprintf(mp1,"\n");
        fprintf(mp2,"%lli",(long long int)nm[it]);
        fprintf(mp2,"\n");
        // increases the size of array by 32000
        qcount=0;
        mcount=0;
        n += 32000;
    }
    fclose(bp1);
    fclose(bp2);
    fclose(sp1);
    fclose(sp2);
    fclose(qp1);
    fclose(qp2);
    fclose(mp1);
    fclose(mp2);
    printf("FILES CLOSED \n");
    return 0;
}
