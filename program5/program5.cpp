//  Roster Numbers: 4, 20
//
//  Authors: Cody Blakeney, Christopher McCarty
//  Due Date: 3/28/2016
//  Programming Assignment Number 5
//
//  Spring 2016 - CS 3358 - 253
//
//  Instructor: Husain Gholoom
//
//  This program is designed to built a stack and a queue allow the user to
//  edit them and the test to see if the stack and the queue are equal.


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Queue{
    private:
        vector<int> intQueue;
        int size;
    public:
        Queue(){ //initializes size to 0
            size = 0;
         }
         bool empty(){   // checks to see if queue is empty
            if(size == 0)
                return true;
            else
                return false;
         }
         int returnSize(){   //returns the size of the queue
            return(size);
         }
         void push_back(int x){  //pushes the user input to the back of the queue
            intQueue.push_back(x);
            size++;
         }
         int pop_front(){   //pops a value from the front of the queue
            int front;
            front = intQueue.front();
            intQueue.erase(intQueue.begin());
            size--;
            return(front);
         }

};

class Stack{
    private:
        vector<int> intStack;
        int size;

    public:
        Stack(){
            size = 0;  // initializes stack size to 0
        }
        bool empty(){  // checks to see if stack is empty
            if(size == 0)
                return true;
            else
                return false;
        }
        int returnSize(){ //returns size
            return(size);
        }
        void push(int x){ // pushes user values onto the end of the stack
            intStack.push_back(x);
            size++;
        }
        int pop(){  // pops values from the stack
            int top;
            top = intStack.back();
            intStack.pop_back();
            size--;
            return(top);
        }


};

int main(){

    string input1, input2;  //input1 is whats added to the stack, input2 to the queue
    Stack myStack, reverseStack;
    Queue myQueue;
    int choice;  // user var that chooses from the menu

    do{
        cout << "*** Welcome to My stack / Queue Program ***\n";
        cout << "The function of this program is validate that\n";
        cout << "a stack and a queue are identical.\n";
        cout << "Stacks / queues are  same if\n";
        cout << "they have the same number of elements\n";
        cout << "and the their elements at the\n";
        cout << "corresponding positions are the same.\n\n";
        cout << "Select from the following menu\n";
        cout << "1.   Enter Stack / Queue Values.\n";
        cout << "9.   Terminate the program.    \n";

        do{
            cin >> choice;
            while(cin.fail()){ //makes sure an integer was the input
            cin.clear();
            cout << "You did not enter an integer. ";
            cout << "You will be returned to the menu after the"<<endl;
            cout<<" next question."<<endl;
            cin.ignore(256, '\n');
            }
            if(choice != 1 && choice != 9)  // if anything other than 1, 9 is picked, error is displayed
                cout << "Invalid selection. Please select 1 or 9\n";
        }while(choice != 1 && choice != 9);

        bool same = true;  // initializing var same which will set to either true or false depending on
                            // the entries.

        if(choice == 1){  // user selection if they choose to enter the stack/queue

            do{
                cout << "Enter Stack Values terminated by ;    ";  // ; needed b/c string is being used.
                cin >> input1;
                if(input1[input1.length()-1] != ';'){
                    cout << "please terminate values with ;\n"; // error if ; is missing
                }
            }while(input1[input1.length()-1] != ';');

            do{
                cout << "Enter Queue Values terminated by ;    "; // ; needed b/c string is being used.
                cin >> input2;
                if(input2[input2.length()-1] != ';'){
                    cout << "please terminate values with ;\n"; // error if ; is missing
                }
            }while(input2[input2.length()-1] != ';');

            int value;  // holds the value user inputs but in ints instead of sting
            for(int i = 0; i < input1.length(); i++){ //changes the sting into ints and pushes them 1 by 1
                if(input1[i] != ';'){
                    value = int(input1[i]) - 48; // 48 is ascii value for 0
                    myStack.push(value);
                }
            }

            for(int i = 0; i < input2.length(); i++){  //changes the sting into ints and pushes them 1 by 1
                if(input2[i] != ';'){
                    value = int(input2[i]) - 48; // 48 is ascii value for 0
                    myQueue.push_back(value);
                }
            }

            if(myStack.returnSize() == myQueue.returnSize()){ // if stack and queue have the same size loops runs.
                while(!myStack.empty()){
                    reverseStack.push(myStack.pop());
                }
                while(!reverseStack.empty()){               // checks to see if the individual values in the correlating spots are the same.
                    if(reverseStack.pop() != myQueue.pop_front())
                        same = false;
                }
            }
            else
                same = false;

            if(same)
                cout << "\nStack and Queue are identical\n";  // displayed if same is true
            else
                cout << "\nStack and Queue are not identical\n"; // displayed is same is false
        }
        cout << endl << endl;
    }while(choice != 9);  // only way loop ends is if 9 is picked.

    cout << "*** Program is terminated."
         << "Written by Cody Blakeney and Chris McCarty ***"; // only displays once

    return 0;
}
