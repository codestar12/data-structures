#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Queue{
    private:
        vector<int> intQueue;
        int size;
    public:
        Queue(){
            size = 0;
         }
         bool empty(){
            if(size == 0)
                return true;
            else
                return false;
         }
         int returnSize(){
            return(size);
         }
         void push_back(int x){
            intQueue.push_back(x);
            size++;
         }
         int pop_front(){
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
            size = 0;
        }
        bool empty(){
            if(size == 0)
                return true;
            else
                return false;
        }
        int returnSize(){
            return(size);
        }
        void push(int x){
            intStack.push_back(x);
            size++;
        }
        int pop(){
            int top;
            top = intStack.back();
            intStack.pop_back();
            size--;
            return(top);
        }

};

int main(){

    string input1, input2;
    Stack myStack, reverseStack;
    Queue myQueue;
    int choice;
    
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
            if(choice != 1 && choice != 9)
                cout << "Invalid selection. Please select 1 or 9\n";
        }while(choice != 1 && choice != 9);

        bool same = true;

        if(choice == 1){
            cout << "Enter Stack Values terminated by ;    ";
            cin >> input1;
            cout << "Enter Queue Values terminated by ;    ";
            cin >> input2;
            int value;

            for(int i = 0; i < input1.length(); i++){
                if(input1[i] != ';'){
                    value = int(input1[i]) - 48; // 48 is ascii value for 0
                    myStack.push(value);
                }
            }

            for(int i = 0; i < input2.length(); i++){
                if(input2[i] != ';'){
                    value = int(input2[i]) - 48; // 48 is ascii value for 0
                    myQueue.push_back(value);
                }
            } 

            if(myStack.returnSize() == myQueue.returnSize()){
                while(!myStack.empty()){
                    reverseStack.push(myStack.pop());
                }
                while(!reverseStack.empty()){
                    if(reverseStack.pop() != myQueue.pop_front())
                        same = false;
                }
            }
            else
                same = false;  

            if(same)
                cout << "\nStack and Queue are identical\n";
            else
                cout << "\nStack and Queue are not identical\n";         
        }
        cout << endl << endl; 
    }while(choice != 9);  

    cout << "*** Program is terminated." 
         << "Written by Cody Blakeney and Chris McCarty ***";

    return 0;
}