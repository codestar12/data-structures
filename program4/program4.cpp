//  Roster Numbers: 4 , 20
//
//  Authors: Cody Blakeney and Christopher McCarty
//  Due Date: 3/7/2016
//  Programming Assignment Number 4
//
//  Spring 2016 - CS 3358 - 253
//
//  Instructor: Husain Gholoom
//
//  This program is designed to let the user build and preform opperations on a
//  linked list.

#include <iostream>
#include <cstddef>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <vector>

using namespace std;

struct ListNode{
		int data;    // value store
		ListNode *prev; // ptr to previous value
		ListNode *next;  // ptr to next value
};

class intList {

    private:

	    ListNode *head; // the list head
	    int size;

    public:

    	intList();
    	ListNode * makeNode(int); // returns pointer of newly created node
    	void appendNode(int value , int position); // inserts a node at the end of list
    	void displayList(); // prints out all values in list
    	void revDispList(); // displays list backwards
    	void fillRand(); // fills list with 20 sorted random #'s between 1-10
    	bool isEmpty(); // returns true if empty false if not empty
    	void deleteNode(ListNode * &node);
    	void removeNumber(int value);
    	void removeDupl(); // removes duplicate numbers
    	int getSize(){return size;}
    	void rotateList();
    	void deleteList(); //right now deleteList() causes a seg fault when used after rotateList()
    	void searchVal(int value);
    	void splitList();
};

intList::intList(){

    head = NULL;
    size = 0;
}

ListNode *intList::makeNode(int value){
    ListNode *newNode;
    newNode = new ListNode;
    newNode -> data = value;
    newNode -> next = NULL;
    newNode -> prev = NULL;

    return newNode;
}

void intList::appendNode(int value , int position){

    ListNode *leading_ptr  = 0,
    		 *trailing_ptr = 0;

    int tempList_ptr=0;

    ListNode *newNode = makeNode(value);
    leading_ptr = head;
    if(head != 0){
        while(leading_ptr->next && tempList_ptr != position){
            trailing_ptr = leading_ptr;
            leading_ptr = leading_ptr -> next;
            tempList_ptr++;
        }
    if(position > tempList_ptr +1){
        cout<<"not a valid location."<<endl;
    }
    else{
        trailing_ptr-> next = newNode;
        newNode ->next= leading_ptr;

    }
    }
    else{
        head = newNode;
        newNode -> next =0;
    }


    /*
    if(!head){  // if there is no value in the head ptr
    	head = newNode;
    }

    else {



    	 leading_ptr = head;
    	while(leading_ptr){ // until the end of the list is reached
    		leading_ptr -> prev = trailing_ptr;
    		trailing_ptr = leading_ptr;
    		leading_ptr = leading_ptr -> next;
    	}

    	// points the last element on the list to the new node
    	trailing_ptr -> next = newNode;
    	newNode -> prev = trailing_ptr;
    	newNode -> next = NULL;
    	*/


    //size += 1;
}

void intList::displayList(){

    ListNode  * leading_ptr  = 0,
    		  * trailing_ptr = 0;

    if(isEmpty()){
    	cout << "List is empty \n";
    }

    else{

    	leading_ptr = head;

    	while(leading_ptr){ // until the end of the list is reached
    		cout << leading_ptr -> data << endl;
    		trailing_ptr = leading_ptr;
    		leading_ptr = leading_ptr -> next;
    	}
    }
}

void intList::revDispList(){

	ListNode  * leading_ptr  = 0,
    		  * trailing_ptr = 0;

    if(isEmpty()){
    	cout << "List is empty \n";
    }

    else{

    	leading_ptr = head;

    	while(leading_ptr){ // until the end of the list is reached
    		trailing_ptr = leading_ptr;
    		leading_ptr = leading_ptr -> next;
    	}

    	while(trailing_ptr != head){
    		cout << trailing_ptr -> data << endl;
    		leading_ptr = trailing_ptr;
    		trailing_ptr = trailing_ptr -> prev;
    	}

    	cout << trailing_ptr -> data;
    }
}
void intList::fillRand(){

	int count = 20;

	srand(time(NULL));

	int arrayRandNums[count];

	for(int i = 0; i < count; i++){
		arrayRandNums[i] = rand() % 10 + 1;
	}

	sort(arrayRandNums, arrayRandNums + count);

	for (int i = 0; i < count; ++i)
	{
		appendNode(arrayRandNums[i],count);
	}
}

bool intList::isEmpty(){
	if(!head){
		return true;
		cout<<"List is empty."<<endl;
	}
	else{
		return false;
		cout<<"List is not empty."<<endl;
	}

}

void intList::deleteNode(ListNode * &node){

	ListNode * prev_ptr = 0,
			 * next_ptr = 0;

	// tells the node before the "to be
    // deleted" node where the next node is

	prev_ptr = node -> prev;
	prev_ptr -> next = node -> next;

	// tells the node after the to be
    // deleted node where the previous node is

	next_ptr = node -> next;
	next_ptr -> prev = prev_ptr;

	size = size - 1;

	delete node;
}

void intList::removeNumber(int value){
	ListNode  * leading_ptr  = 0,
    		  * trailing_ptr = 0;

    bool found = false;

    if(isEmpty()){
    	cout << "List is empty \n";
    }

    else{

    	leading_ptr = head;

    	while(leading_ptr){ // until the end of the list is reached
    		//cout << leading_ptr -> data << endl;
    		if(leading_ptr -> data == value){
    			deleteNode(leading_ptr);
    			found = true;
    		}
    		trailing_ptr = leading_ptr;
    		leading_ptr = leading_ptr -> next;
    	}

    	if(!found){
    		cout << "value not found \n";
    	}
    }
}

void intList::removeDupl(){

	ListNode *ptr1, *ptr2, *dup;
  ptr1 = head;

  /* Pick elements one by one */
  while(ptr1 != NULL && ptr1 -> next != NULL)
  {
     ptr2 = ptr1;

     /* Compare the picked element with rest of the elements */
     while(ptr2 -> next != NULL)
     {
       /* If duplicate then delete it */
       if(ptr1 -> data == ptr2 -> next -> data)
       {
          /* sequence of steps is important here */
          dup = ptr2 -> next;
          ptr2 -> next = ptr2 -> next -> next;
          free(dup);
          size = size - 1;
       }
       else /* This is tricky */
       {
          ptr2 = ptr2 -> next;
       }
     }
     ptr1 = ptr1 -> next;
  }
}

void intList::rotateList(){

	ListNode * current = head;

	if(size < 2){
		cout << "not enough elements to rotate \n";
		return;
	}

	for(int i = 0; i < 1; i++){ // moves the current pointer over by 2
		current = current -> next;
	}

	ListNode * shiftNode = current; // node to be made head

	while(current -> next){ // moves current to the last node
		current = current -> next;
	}

	// makes the pointer at the end of the list
	// the old head
	current -> next = head;

	head = shiftNode -> next; // reassigns the head

	shiftNode -> next = NULL;
}

//right now deleteList() causes a seg fault when used after rotateList()
void intList::searchVal(int value){
    ListNode * leading_ptr = head;
    
    while((leading_ptr != 0 ) && value != leading_ptr ->value)
    {
        leading_ptr = leading_ptr -> next;
    }
    if(value == leading_ptr -> value)
        return leading_ptr;
    else
        cout<<"Value not found"<<endl;

}

void intList::splitList(){
     ListNode  * leading_ptr  = 0,
    		  * trailing_ptr = 0;

    if(isEmpty()){
    	cout << "List is empty \n";
    }

    else{
        
    	leading_ptr = head;
    	int tempValue = leading_ptr;
    	while(leading_ptr < tempValue + 10 )

}
void intList::deleteList(){

    /* //another option to delete?
    ListNode  * leading_ptr  = 0,
    		  * trailing_ptr = 0;
        if(isEmpty())
            cout<<"already empty."<<endl;
        leading_ptr = head;
        while(leading_ptr){
            trailing_ptr = leading_ptr -> next;
            delete leading_ptr;
            leading_ptr = trailing_ptr;


    */
	ListNode  * leading_ptr  = 0,
    		  * trailing_ptr = 0;

    if(isEmpty()){
    	cout << "List is empty \n";
    }

    else{

    	leading_ptr = head;

    	while(leading_ptr){ // until the end of the list is reached
    		trailing_ptr = leading_ptr;
    		leading_ptr = leading_ptr -> next;
    	}

    	while(trailing_ptr != head){
    		leading_ptr = trailing_ptr;
    		trailing_ptr = trailing_ptr -> prev;
    		free(leading_ptr);
    	}

    	free(head);

    	head = NULL;
    }
}

int main(){

	intList myList;
	char choice;

	//testing random sorted array
	do{

    cout<<"Hello.  Welcome to Chris and Cody's Linked list builder."<<endl;
    cout<<"Please choose one of the following options."<<endl<<endl;
    cout<<"A - build a sorted main list of 20 random integer numbers that are"<<endl;
    cout<<"less than or equal to 10."<<endl;
    cout<<"B - Insert a new number in the main list at a specific location."<<endl;
    cout<<"C - Search the main list for a given item or number.  Display a "<<endl;
    cout<<"message if it does not exist."<<endl;
    cout<<"D - Remove an existing number from the list.  A message will be "<<endl;
    cout<<"if it does not exist."<<endl;
    cout<<"E - Display whether or not this main list is empty."<<endl;
    cout<<"F - Rotates the list two positions."<<endl;
    cout<<"G - Display the main list backwards."<<endl;
    cout<<"H - splits the main list into two lists."<<endl;
    cout<<"I - deletes duplicate numbers from the main list."<<endl;
    cout<<"J - deletes the entire list."<<endl;
    cout<<"X - exits the program."<<endl;
    cin>> choice;
    int value=0;

    if(choice == 'A' || choice == 'a'){ //builds and populates list
        myList.fillRand();
    }

    else if(choice == 'B' || choice =='b'){ //Inserts a new number at a specific location
        cout<<"At what position would you like to insert then number?"<<endl;
        int position;
        cin>> position;
        cout<<endl<<"What number would you like it insert?"<<endl;
        cin >> value;
       myList.appendNode(value , position);
       }
     else if(choice == 'C' || choice == 'c'){  //Searches list for a number and displays it
        cout<<"What value would you like to search for?"<<endl;
        cin>>value;
        myList.searchVal(value);
        }

    else if(choice == 'D' || choice == 'd'){
        cout<<"What value would you like to delete?"<<endl;
        cin>>value;
        myList.removeNumber(value);
        }
    else if(choice == 'E' || choice == 'e')
        myList.isEmpty();
    else if(choice == 'F' || choice == 'f')
        myList.rotateList();
    else if(choice == 'G' || choice == 'g')
        myList.revDispList();
    else if(choice == 'H' || choice == 'h')
        myList.splitList();
    else if(choice == 'i' || choice == 'I')
        myList.removeDupl();
    else if(choice == 'J' || choice == 'j')
        myList.deleteList();
    else if(choice == 'X' || choice == 'x'){
    }
    else
        cout<<"You have entered an invalid choice, please try again."<<endl;
        }while(choice !='X' || choice !='x');
cout<<"Thank you for using Chris and Cody's linked list builder!"<<endl<<endl;
cout<<"Implemented by Christopher McCarty and Cody Blakeney."<<endl;
    return 0;

	//if(myList.isEmpty())
		//cout << "myList is empty now\n";

	//myList.fillRand();
	//myList.displayList();
   // myList.rotateList();
	//myList.displayList();
	//cout << "size is " << myList.getSize() << endl;
	//myList.removeDupl();
	//cout << "size is " << myList.getSize() << endl;
	//myList.displayList();

	//right now deleteList() causes a seg fault when used after rotateList()
	//myList.deleteList();
	//myList.displayList();


	return 0;
}
