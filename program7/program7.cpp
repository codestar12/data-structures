#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

long int sequentialSearch(int[]);
long int binarySearch(int[]); 
long int bubbleSort(int[]);
long int selectionSort(int[]);
long int insertionSort(int[]);
long int quickSort(int[],int,int);

const int ARRAY_SIZE = 10000;

int main(){

    
    srand (time(NULL));
    long int comparisons;
    time_t start, end;

    int array1[ARRAY_SIZE],
        array2[ARRAY_SIZE],
        array3[ARRAY_SIZE],
        array4[ARRAY_SIZE];

    for(int i = 0; i < ARRAY_SIZE; i++){
        array1[i] = rand() % 100;
        array2[i] = array1[i];
        array3[i] = array1[i];
        array4[i] = array1[i];

        // cout << array1[i] << " ";
    }

    cout << endl;

    for(int i = 0; i < 20; i++)
        cout << array1[i] << " ";

    cout << endl << endl;

    /*
    cout << "Sequential Search\n";
    cout << "Searching for 99\n"; */

    cout << "Bubble Sort \n\n";

    
    start = time(NULL);
    cout << "Start Time : "<< start << endl;
    comparisons = bubbleSort(array1);
    end = time(NULL);
    cout << "End Time   : "<< end << endl;
    cout << "Actual CPU Clock time : " << (end - start) << endl;
    cout << "Number of Exchanges : " << comparisons << endl << endl; 

    cout << "Selection Sort\n\n"; 

    //12345 Was Not found.
    start = time(NULL);
    cout << "Start Time : "<< start << endl;
    comparisons = selectionSort(array2);
    end = time(NULL);
    cout << "End Time   : "<< end << endl;
    cout << "Actual CPU Clock time : " << (end - start) << endl;
    cout << "Number of Exchanges : " << comparisons << endl << endl; 

    cout << "Insertion Sort\n\n"; 

    //12345 Was Not found.
    start = time(NULL);
    cout << "Start Time : "<< start << endl;
    comparisons = insertionSort(array3);
    end = time(NULL);
    cout << "End Time   : "<< end << endl;
    cout << "Actual CPU Clock time : " << (end - start) << endl;
    cout << "Number of Exchanges : " << comparisons << endl << endl; 

    cout << "Quick Sort\n\n"; 

    //12345 Was Not found.
    start = time(NULL);
    cout << "Start Time : "<< start << endl;
    comparisons = quickSort(array4, 0, ARRAY_SIZE - 1);
    end = time(NULL);
    cout << "End Time   : "<< end << endl;
    cout << "Actual CPU Clock time : " << (end - start) << endl;
    cout << "Number of Exchanges : " << comparisons << endl << endl; 
    
    cout << "Benchmark Algorithm Implemented by : Cody Blakeney\n";
    cout << "April 2016\n\n";

    return 0;
}

long int bubbleSort(int array[]){

    int swap;
    long int exchanges = 0;

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

long int selectionSort(int array[]){

    int min, temp;
    long int exchanges = 0;

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

long int insertionSort(int array[]){
    
    int temp, j;
    long int exchanges = 0;

    for(int i = 1; i < ARRAY_SIZE; i++){
        temp = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > temp){
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = temp;
        exchanges++;
    }

    return exchanges;
}

long int quickSort(int array[], int left, int right){

    int i = left, j = right;
    int temp;
    int pivot = array[(left + right) / 2];
    int exchanges = 0;

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
    if(left < j){
        exchanges += quickSort(array, left, j);
    }

    if(i < right){
        exchanges += quickSort(array, i, right);
    }

    return exchanges;
}

long int sequentialSearch(int[]){
    return 0;
}
long int binarySearch(int[]){
    return 0;
}