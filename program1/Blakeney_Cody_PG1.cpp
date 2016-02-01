//	 Author	/	s	:	(Your	names 	here!!)
//	 Due Date:
//	 Programming Assignment	Number 1
//	 Spring	 2016 -	CS 3358 - Section Number				
//
//	 Instructor: Husain	Gholoom.
//
// 	<Brief	description	of	the	purpose	of the program>


#include <iostream>
#include <stdlib.h> // srand
#include <time.h>   //seed for srand
#include <stdio.h>  //NULL for seed

using namespace std;


void fillSquare(int square[], int , int);
void printSquare(int square[], int);
bool checkSquare(int square[], int, int);

int main(){

	int n, magicNumber;
	char runFlag;

	do{
	    
	    cout << "Enter the size of the magic square: ";
	    cin >> n;

	    magicNumber = (n*(n*n + 1))/2;

	    //creates a 1D array in heap (all memory sequential) 
	    //the size of a n x n matrix
	    int square[ n * n ];

	    fillSquare(square, magicNumber , n);
	    printSquare(square,n);

	    cout << "\nThe Magic Number is " << magicNumber << endl;

	    if(checkSquare(square, magicNumber, n)){
	    	cout << "This is a magic square" << endl;
	    }

	    else{
	    	cout << "This is not a magic square" << endl;
	    }
	    

	    cout << "\nWould like to find another magic square -";
	    cout << " Enter y or Y for yes or n | N for no " ;

	    cin >> runFlag;          

	}while(runFlag == 'y' || runFlag == 'Y');    


	return 0;
}

void fillSquare(int square[], int magicNumber, int n){

    //required seed for rand
    srand(time(NULL));

        //does math to make a 1D array behave like a 2D
	    for(int i = 0; i < n; i++){
		    for(int j = 0; j < n; j++){	

			    square[ i * n + j] = rand()%magicNumber;
		}
	}	
}

void printSquare(int square[], int n){

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			
			cout << square[i * n + j] << "  ";
		}
		cout << "\n\n";
	}	
}

// check square returns true if square is a magic square
// check square also outputs to terminal sum of rows, columns, and diag
bool checkSquare(int square[], int magicNumber, int n){

	int sumCheck;
	bool isMagic = false;

	// row check
	for(int i = 0; i < n; i++){

		// reset sum for rows
		sumCheck = 0;

		for(int j = 0; j < n; j++){

	    	sumCheck += square[ (i * n) + j ]; 
		}

		cout << "Sum of numbers in Row    # " << (i + 1) << " = " 
		     << sumCheck << endl;
		     
		if(sumCheck != magicNumber)
			isMagic = false;
	}

	// column check
	for(int j = 0; j < n; j++){

		// reset sum for rows
		sumCheck = 0;

		for(int i = 0; i < n; i++){

	    	sumCheck += square[ (i * n) + j ]; 
		}

		cout << "Sum of numbers in Column # " << (j + 1) << " = " 
		     << sumCheck << endl;

		if(sumCheck != magicNumber)
			isMagic = false;
	}

	sumCheck = 0;

	// diagonal 1
	for(int i = 0; i < n; i++){
		sumCheck += square[ (i * n) + i];
	}

	cout << "Sum of numbers in first Diagonal = " << sumCheck << endl;
	if(sumCheck != magicNumber)
			isMagic = false;


	sumCheck = 0;
		
	// diagonal 2
	for(int i = 0; i < n; i++){
		sumCheck += square[ (((n - 1) - i) * n) + i];
	}

	cout << "Sum of numbers in second Diagonal = " << sumCheck << endl;
	if(sumCheck != magicNumber)
			isMagic = false;	

	return isMagic;
}
