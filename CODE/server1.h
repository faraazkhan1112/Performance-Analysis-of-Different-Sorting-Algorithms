//GLOBAL VARIABLES TO STORE THE NUMBER OF COMAPARISONS MADE IN QUICK SORT AND MERGE SORT

long long int qcount;
long long int mcount;

double time_elapsed(clock_t start, clock_t end);
// Swap utility 
void swap( long int* a, long int* b);
// Bubble sort 
double bubbleSort(long int a[], long int n);
// Selection sort 
double selectionSort(long int arr[], long int n);
//Quick Sort
long int partition(long int arr[],long int l,long int r);
void quicksort(long int arr[],long int l,long int r);
//Merge Sort
void merge(long int arr[],long int l,long int m,long int r);
void mergeSort(long int arr[],long int l,long int r);

