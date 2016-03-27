#include <iostream>
#include <vector>

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

    Queue myQueue;
    myQueue.push_back(5);
    myQueue.push_back(4);
    myQueue.push_back(3);
    
    Stack myStack;
    
    myStack.push(5);
    myStack.push(4);
    myStack.push(3);

    
    cout << "Queue\n";
    while(!myQueue.empty()){
        cout << myQueue.pop_front() << endl;
    }

    cout << "Stack\n";
    while(!myStack.empty()){
        cout << myStack.pop() << endl;
    }
    return 0;
}