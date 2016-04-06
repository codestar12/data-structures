#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int bubbleSort(int[]);
int selectionSort(int[]);
int insertionSort(int[]);

const int ARRAY_SIZE = 100;

int main(){

    
    srand (time(NULL));

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

    for(int i = 0; i < 20; i++)
        cout << array1[i] << " ";
    
    cout << endl; 

    cout << "sorts for bubbleSort " << bubbleSort(array1) << endl;

    for(int i = 0; i < 20; i++)
        cout << array1[i] << " ";

    cout << "\nsorts for selectionSort " << selectionSort(array2) << endl;  
    
    

    for(int i = 0; i < 20; i++)
        cout << array2[i] << " ";

    return 0;
}

int bubbleSort(int array[]){

    int swap;
    int exchanges = 0;

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

int selectionSort(int array[]){

    int min, temp;
     int exchanges = 0;

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

int insertionSort(int array[]){
    return 0;
}