#include <time.h>
#include "server1.h"
long long int qcount = 0;
long long int mcount = 0;

double time_elapsed(clock_t start, clock_t end) {
	double t;
	t = (end-start);
	t += (end - start) * 0.000000001;
	return t;
}
  
// Swap utility 
void swap( long int* a, long int* b) 
{ 
    int tmp = *a; 
    *a = *b; 
    *b = tmp; 
} 
  
// Bubble sort 
double bubbleSort(long int a[], long int n) 
{ 
    double nb = 0;	
    int swap1;
    for (long int i = 0; i < n - 1; i++) { 
        swap1=0;
        for (long int j = 0; j < n - 1 - i; j++) { 
            if (a[j] > a[j + 1]) { 
		swap(&a[j], &a[j + 1]); 
		swap1=1;
            } 
            nb++;
        } 
        if(!swap1)
        	return nb;
    } 
    return nb;
} 
  
// Selection sort 
double selectionSort(long int arr[], long int n) 
{ 
    long int i, j, midx;
    double ns = 0; 
  
    for (i = 0; i < n - 1; i++) { 
  
        // Find the minimum element in unsorted array 
        midx = i; 
  
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[midx])
                midx = j;
            ns++; 
            }
        // Swap the found minimum element 
        // with the first element 
        swap(&arr[midx], &arr[i]); 
    } 
    return ns;
} 
  
//Quick Sort
long int partition(long int arr[],long int l,long int r){
    long int p,i,j;
    p=arr[l];
    i=l;
    j=r + 1;
    do{
        do{
            i++;
            qcount++;
        }while(arr[i]<p);
        do{
            j--;
            qcount++;
        }while(arr[j]>p);
        //qcount--;
        swap(&arr[i],&arr[j]);
    }while(i<j);
    
    swap(&arr[i], &arr[j]);
    swap(&arr[l], &arr[j]);
    return j;
}
void quicksort(long int arr[],long int l,long int r){
    long int s;
    if(l<r){
        s=partition(arr,l,r);
        quicksort(arr,l,s-1);
        quicksort(arr,s+1,r);
    }
}

//Merge Sort
void merge(long int arr[],long int l,long int m,long int r) 
{ 
    long int i, j, k; 
    long int n1 = m - l + 1; 
    long int n2 =  r - m; 
  
    /* create temp arrays */
    long int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
            mcount++;
        } 
        else
        { 
            arr[k] = R[j]; 
            j++;
            mcount++;
        } 
        k++; 
        mcount++;
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(long int arr[],long int l,long int r) 
{ 
    if (l < r) 
    { 
        long int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
