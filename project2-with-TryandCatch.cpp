//	 //	 Author	/	s	:	#20 Christopher McCarty & #4 Cody Blakeney
//	 Due Date: Feb 15th, 2016
//	 Programming Assignment	Number 2
//	 Spring	 2016 -	CS 3358 - 253
//
//	 Instructor: Husain	Gholoom.
//
//   The purpose of this program is to  take an integer n from the user and
//   create a hailstone sequence from it.  It will then display the hailstone
//   sequence, the largest number, the smallest number, the length, the odds,
//   the evens in the hailstone sequence.  The user try again or exit.



#include <vector>
#include <iostream>

using namespace std;

vector<int>     hailstoneConstructor(int);
void 		    hailstonePrint(vector<int>&);
int 		    hailstoneLength(vector<int>&);
int 		    hailstoneLargest(vector<int>&);
int 		    hailstoneSmallest(vector<int>&);
void 		    hailstoneEvenPrint(vector<int>&);
void 		    hailstoneOddPrint(vector<int>&);


int main(){

    cout<<"Welcome to the hailstone sequence program"<<endl;
    cout<<"The function of the program is to read a number n from the user"<<endl;
    cout<<"and then tells the user four things:"<<endl<<endl;
    cout<<"    1.\tThe entire hailstone sequence starting at n, all on one line,"<<endl;
    cout<<"    \t  with the numbers separated by spaces;"<<endl;
    cout<<"    2.\tThe length of the hailstone sequence that starts with n;"<<endl;
    cout<<"    3.\tThe largest number in the hailstone sequence that starts with n;"<<endl;
    cout<<"    4.\tThe smallest number in the hailstone sequence that starts with n;"<<endl;
    cout<<"    5.\tCount and display the numbers in that hailstone sequence are even."<<endl;
    cout<<"    6.\tCount and display the numbers in that hailstone sequence are odd."<<endl<<endl;


	int n = 0;
	int largest, smallest, length;
	char choice;
    do{

        try{
            cout << "Enter a  Positive integer Number  ";
            cin >> n;
            cout<< endl<<endl;
            if(n <= 0){
                    throw  "Error *** Number must be > 0\n\n";
            }
        

            vector<int> hailstone = hailstoneConstructor(n);

            hailstonePrint(hailstone);

            largest = hailstoneLargest(hailstone);
            smallest = hailstoneSmallest(hailstone);
            length = hailstoneLength(hailstone);

            cout << "The length of the sequence is "<< length;
            cout << "The largest number in the sequence is  "
                 << largest <<"."<<endl;
            cout << "The smallest number in the sequence is  "
                 << smallest <<"."<< endl;

            hailstoneEvenPrint(hailstone);
            hailstoneOddPrint(hailstone);



            do{
                try{

                   cout<<"Would you like to find hailstone" <<
                   " sequence for another number - ";
                   cout<<"Enter y or Y for yes"<<endl;
                   cout<<" or n | N for no ";
                   cin>>choice;
                   cout<<endl;

                   if(choice != 'y' && choice != 'Y' && 
                      choice != 'n' && choice != 'N'){

                    throw "\nError *** invalid choice\n\n";

                       }

                   }
                 catch(char const* message){

                    cout << message;
                  } 
              }while(choice != 'y' && choice != 'Y' && 
                     choice != 'n' && choice != 'N');      
            
        }    

	catch(char const* message){
        cout << message;
    } 


    }
    while(choice != 'n' && choice != 'N');


	cout<< "The hailstone Algorithm is implemented by Cody Blakeney And Christopher McCarty";
    cout<<endl<<endl;
	return 0;
}

vector<int> hailstoneConstructor(int n){

	vector<int> hailstone;

	hailstone.push_back(n);

	while(n != 1){

		if(n % 2 == 1){

			n = n * 3 + 1;
		}

		else if(n % 2 == 0){

			n = n / 2;
		}

		hailstone.push_back(n);
	}

	return hailstone;
}


void hailstonePrint(vector<int> & hailstone){
    cout<<"The sequence of hailstone starting at  "<< hailstone.at(0) << " is"<<endl<<endl;

	for(int i = 0; i < hailstone.size(); i++){

		cout << hailstone.at(i) << " ";
	}
	cout<<endl<<endl;
}

int hailstoneLength(vector<int> & hailstone){

    int length = hailstone.size();

    return length;

}



int hailstoneLargest(vector<int> & hailstone){
	int largest = 0;

	for(int i = 0; i < hailstone.size(); i++ ){
		if(largest < hailstone.at(i)){
			largest = hailstone.at(i);
		}
	}

	return largest;
}

int hailstoneSmallest(vector<int> & hailstone){
	int smallest = hailstone.at(0);

	for(int i = 0; i < hailstone.size(); i++ ){
		if(smallest > hailstone.at(i)){
			smallest = hailstone.at(i);
		}
	}

	return smallest;
}

void hailstoneEvenPrint(vector<int> & hailstone){
    int EvenCount =0;
    for(int i=0; i< hailstone.size(); i++){

        if(hailstone.at(i) % 2 !=0){
            EvenCount++;
        }
    }

    cout<< EvenCount << "    of the numbers are even.  The even sequence :   ";

    for(int i=0; i< hailstone.size(); i++){

        if(hailstone.at(i) % 2 ==0){
            cout << hailstone.at(i)<<" ";
        }
    }
    cout<<endl;
}

void hailstoneOddPrint(vector<int> & hailstone){
    int OddCount =0;
    for(int i=0; i< hailstone.size(); i++){

        if(hailstone.at(i) % 2 !=0){
            OddCount++;
        }
    }

    cout<< OddCount << "    of the numbers are odd.  The odd sequence :   ";



    for(int i=0; i< hailstone.size(); i++){

        if(hailstone.at(i) % 2 !=0){
            cout << hailstone.at(i)<<" ";
        }
    }
    cout<<endl<<endl;
}
