// Roster Number  : 4
//
// Author : Cody Blakeney
// Due Date : April 13th, 2016
// Programming Assignment Number 7
//
// Spring 2016 - CS 3358 - 253
//
// Instructor: Husain Gholoom.
//
// This program compares efficiencies of sorting and search algorithms

#include <iostream> // for output
#include <stdlib.h> // for randomizing numbers
#include <time.h>   // for tracking run time

using namespace std;

int sequentialSearch(int[], int, int, long int &); // searches through 
                                             // array sequentially

int binarySearch(int[], int, int, long int &); // performs binary 
                                              // search on array

long int bubbleSort(int[], int); // uses bubble sort to sort array
long int selectionSort(int[], int);  // uses selection sort to sort array
long int insertionSort(int[], int); // uses insertion sort to sort array
long int quickSort(int[],int,int); // uses quick sort to sort array
void sortPrint(int[],int[],int[], int[], long int, int, time_t, time_t);
                                // used to print information for 
                                // sorting algorithms 

int main(){

    const int ARRAY_SIZE = 100000;

    srand (time(NULL)); // used for randomizing arrays
    time_t start, end;  // used for time between starting functions
                        // and ending 
    long int comparisons = 0; // comparisons is used to 
    int index = 0; // index is used to store the indices returned by 
                   // searching functions.


    int array1[ARRAY_SIZE], // four arrays used for the four 
        array2[ARRAY_SIZE], // sorting algorithms 
        array3[ARRAY_SIZE],
        array4[ARRAY_SIZE];

    for(int i = 0; i < ARRAY_SIZE; i++){    
        array1[i] = rand() % 3000;  // loading all four arrays
        array2[i] = array1[i];      // with same values
        array3[i] = array1[i];
        array4[i] = array1[i];
    }

    cout << endl;

    for(int i = 0; i < 20; i++)
        cout << array1[i] << " ";

    cout << endl << endl;

    
    cout << "Sequential Search\n";
    cout << "Searching for 3001\n\n"; 

    start = time(NULL);
    index = sequentialSearch(array1, 3001, ARRAY_SIZE, comparisons);
    end = time(NULL);


    if(index >= 0)
        cout << "3001 Was Found.\n";
    else if(index == -1)
        cout << "3001 Was Not Found.\n";

    cout << "Start Time : "<< start << endl;
    cout << "End Time   : "<< end << endl;
    cout << "Actual CPU Clock time : " << (end - start) << " s" << endl;
    cout << "Number of Comparisons : " << comparisons << endl << endl; 

    sortPrint(array1, array2, array3, array4, 
              comparisons, ARRAY_SIZE, start, end);

    cout << "Binary Search\n";
    cout << "Searching for 3001\n\n"; 

    comparisons = 0;
    start = time(NULL);
    index = binarySearch(array1, ARRAY_SIZE, 3001, comparisons);
    end = time(NULL);

    if(index >= 0)
        cout << "3001 Was Found.\n";
    else if(index == -1)
        cout << "3001 Was Not Found.\n";

    cout << "Start Time : "<< start << endl;
    cout << "End Time   : "<< end << endl;
    cout << "Actual CPU Clock time : " << (end - start) << " s" << endl;
    cout << "Number of Comparisons : " << comparisons << endl << endl; 

    cout << "Benchmark Algorithm Implemented by : Cody Blakeney\n";
    cout << "April 2016\n\n";

    return 0;
}

/*
    sortPrint outputs all the information about the sorting algorithms
    it takes as inputs all the arrays, the array size, the time objects,
    and a variable for comparisons
*/

void sortPrint(int array1[], int array2[], int array3[], 
               int array4[] , long int comparisons, int ARRAY_SIZE,
               time_t start, time_t end)
{
    cout << "Bubble Sort \n\n";

    start = time(NULL);
    cout << "Start Time : "<< start << endl;
    comparisons = bubbleSort(array1, ARRAY_SIZE);
    end = time(NULL);
    cout << "End Time   : "<< end << endl;
    cout << "Actual CPU Clock time : " << (end - start) << " s" << endl;
    cout << "Number of Exchanges : " << comparisons << endl << endl; 

    cout << "Selection Sort\n\n"; 

    start = time(NULL);
    cout << "Start Time : "<< start << endl;
    comparisons = selectionSort(array2, ARRAY_SIZE);
    end = time(NULL);
    cout << "End Time   : "<< end << endl;
    cout << "Actual CPU Clock time : " << (end - start) << " s" <<  endl;
    cout << "Number of Exchanges : " << comparisons << endl << endl; 

    cout << "Insertion Sort\n\n"; 

    start = time(NULL);
    cout << "Start Time : "<< start << endl;
    comparisons = insertionSort(array3, ARRAY_SIZE);
    end = time(NULL);
    cout << "End Time   : "<< end << endl;
    cout << "Actual CPU Clock time : " << (end - start) << " s" << endl;
    cout << "Number of Exchanges : " << comparisons << endl << endl; 

    cout << "Quick Sort\n\n"; 

    start = time(NULL);
    cout << "Start Time : "<< start << endl;
    comparisons = quickSort(array4, 0, ARRAY_SIZE - 1);
    end = time(NULL);
    cout << "End Time   : "<< end << endl;
    cout << "Actual CPU Clock time : " << (end - start) << " s" << endl;
    cout << "Number of Exchanges : " << comparisons << endl << endl; 
}

/*
    bubbleSort sorts an array according to the bubble sort method.
    once the sorting is completed it returns the number of exchanges 
    needed to sort the array.
*/

long int bubbleSort(int array[], int ARRAY_SIZE){

    int swap;                // swap is used to hold a value 
                             // for swapping it between indices

    long int exchanges = 0;  // this stores the value of exchanges
                             // that occur during sorting.

    for (int i = 0 ; i < ( ARRAY_SIZE - 1 ); i++){
        for (int j = 0 ; j < ARRAY_SIZE - i - 1; j++){      
            if (array[j] > array[j+1]){ 
            
                swap = array[j];
                array[j] = array[j+1];
                array[j+1] = swap;
                exchanges++;
            }
        }
    }

    return exchanges;
}

/*
    selectionSort sorts an array according to the selection sort method.
    once the sorting is completed it returns the number of exchanges 
    needed to sort the array.
*/

long int selectionSort(int array[], int ARRAY_SIZE){

    int min, temp; // min stores the value of the smallest number
                   // temp is used to swap values between array
                   // indices

    long int exchanges = 0; // exchanges is used to count 
                            // number of exchanges

    for(int i = 0; i < ARRAY_SIZE - 1; i++){
        min = i;

        for(int j = i + 1; j < ARRAY_SIZE; j++){

            if(array[j] < array[min])
                min = j;
        }

        if(min != i){
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
            exchanges++;
        }
    }
    return exchanges;
}

/*
    insertionSort sorts an array according to the insertion sort method.
    once the sorting is completed it returns the number of exchanges 
    needed to sort the array.
*/

long int insertionSort(int array[], int ARRAY_SIZE){
    
    int temp, j;            // temp is used to swap values between 
                            // array indices.
                            // j is used for shifting values in array

    long int exchanges = 0; // exchanges is used to count exchanges
                            // while sorting

    for(int i = 1; i < ARRAY_SIZE; i++){
        temp = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > temp){ // moves all values down 
            array[j + 1] = array[j];      // in array until the correct
                                          // location for temp is found
            j = j - 1;

            exchanges++;
        }
        array[j + 1] = temp;        
    }

    return exchanges;
}

/*
    quickSort sorts an array according to the quick sort method.
    once the sorting is completed it returns the number of exchanges 
    needed to sort the array.
*/

long int quickSort(int array[], int left, int right){

    int i = left, j = right; // left is the first element in sub-array
                             // right is last element in sub-array

    int temp;    // temp is used to swap values between array

    int pivot = array[(left + right) / 2]; // pivot is pivot value

    int exchanges = 0;  // exchanges is used to count exchanges
                        // while sorting
    while(i <= j){

        while(array[i] < pivot)
            i++;

        while(array[j] > pivot)
            j--;

        if(i <= j){
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
            exchanges++;
        }
    }

    if(left < j)
        exchanges += quickSort(array, left, j);

    if(i < right)
        exchanges += quickSort(array, i, right);

    return exchanges;
}

/*
    sequential search searches through an array sequential
    until the desired element is found. 
    At the end of its search it returns the index of the desired element.
    if the element is not found it returns -1. comparisons is passed 
    by reference so the number of comparisons can be counted.
*/
int sequentialSearch(int array[], int value, int ARRAY_SIZE, 
                     long int &comparisons)
{
    
    int count = 0;
    comparisons = 0;
    do{
        if(array[count] == value){
            return count;
        }
        count++;
        comparisons++;
    }while(count < ARRAY_SIZE);

    return -1;
}

/*
    binarySearch search searches through an array by dividing it
    until the desired element is found. 
    At the end of its search it returns the index of the desired element.
    if the element is not found it returns -1. comparisons is passed 
    by reference so the number of comparisons can be counted.
*/

int binarySearch(int array[], int ARRAY_SIZE, int value ,  
                 long int &comparisons)
{    
    int low = 0;
    int high = ARRAY_SIZE - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (array[mid] == value) return mid;
        else if (array[mid] < value) low = mid + 1;
        else high = mid - 1;
        comparisons++;
   }
   return -1;
    
}