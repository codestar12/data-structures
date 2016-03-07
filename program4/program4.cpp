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
    	void appendNode(int, int); // inserts a node at the end of list
    	void displayList(); // prints out all values in list
    	void revDispList(); // displays list backwards
    	void fillRand(); // fills list with 20 sorted random #'s between 1-10
    	bool isEmpty() const; // returns true if empty false if not empty
    	void deleteNode(ListNode * &node); //deletes a specific node
    	void removeNumber(int value); // removes a number requested by the user
    	void removeDupl(); // removes duplicate numbers
    	int getSize() const{return size;} //finds the size of the list
    	void rotateList();  // rotates the list two positions to the right
    	void deleteList(); // fixed seg fault after rotate list
        void printHead(){cout << "head is " << head << endl;} //prints where head is pointing
        void splitList(); // splits the list into two lists ( if large enough)
        void searchNum(int value);  //searches for a specific number.
};

intList::intList(){ //sets both head a size to 0

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
//this function inserts a number into a specific position (both num and pos are user input.)
void intList::appendNode(int value, int loc){   

    ListNode *leading_ptr  = 0,
    		 *trailing_ptr = 0;

    ListNode *newNode = makeNode(value);

    if(!head){  // if there is no value in the head ptr
    	head = newNode;
    }

    else{

        int i = 0;
    	leading_ptr = head;
        // until the end of the list is reached or the location to be
        // inserted is reached
    	while(leading_ptr && i < loc){
    		leading_ptr -> prev = trailing_ptr;
    		trailing_ptr = leading_ptr;
    		leading_ptr = leading_ptr -> next;
            i++;
    	}

    	// points the last element on the list to the new node

        if(leading_ptr == NULL){
    	    trailing_ptr -> next = newNode;
    	    newNode -> prev = trailing_ptr;
    	    newNode -> next = NULL;
        }

        else{
            trailing_ptr -> next = newNode;
            newNode -> prev = trailing_ptr;
            newNode -> next = leading_ptr;
            leading_ptr -> prev = newNode;
        }
    }

    size += 1;
}

void intList::displayList(){ //this function displays the list.

    ListNode  * leading_ptr  = 0,
    		  * trailing_ptr = 0;

    if(isEmpty()){
    	cout << "List is empty \n";
    }

    else{

    	leading_ptr = head;

    	while(leading_ptr){ // until the end of the list is reached
    		cout << leading_ptr -> data << " ";
    		trailing_ptr = leading_ptr;
    		leading_ptr = leading_ptr -> next;
    	}

        cout << endl;
    }
}

void intList::revDispList(){ //this function displays the list in reverse

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
void intList::fillRand(){ //this function creates the linked list.

    if(isEmpty()){

	    int count = 20;

	    srand(time(NULL));

	    int arrayRandNums[count];

	    for(int i = 0; i < count; i++){
		    arrayRandNums[i] = rand() % 10 + 1;
	    }

	    sort(arrayRandNums, arrayRandNums + count);

	    for (int i = 0; i < count; ++i)
	    {
		    appendNode(arrayRandNums[i], i);
	    }
    }
    else{
        cout << "list already contains elements \n";
    }
}

bool intList::isEmpty() const{  //this function checks to see if list is empty.
	if(!head)
		return true;
	else
		return false;
}

void intList::deleteNode(ListNode * &node){ //this function deletes a specific node(used by other functions)

	ListNode * prev_ptr = 0,
			 * next_ptr = 0;

	// tells the node before the "to be
    // deleted" node where the next node is

    if(node -> prev != head){
	prev_ptr = node -> prev;
	prev_ptr -> next = node -> next;
    }

	// tells the node after the to be
    // deleted node where the previous node is

    if(node -> next){
	next_ptr = node -> next;
	next_ptr -> prev = prev_ptr;
    }

	size = size - 1;

	delete node;
}

void intList::removeNumber(int value){ //this function removes a specific number (user input)
	ListNode  * leading_ptr  = 0,
    		  * dup = 0;

    bool found = false;

    if(isEmpty()){
    	cout << "List is empty \n";
    }

    else{

    	leading_ptr = head;

    	while(leading_ptr){ // until the end of the list is reached
    		//cout << leading_ptr -> data << endl;
            if(head -> data == value){
                leading_ptr = leading_ptr -> next;
                delete head;
                leading_ptr -> prev = NULL;
                head = leading_ptr;
            }
    		else if(leading_ptr -> data == value){
    			deleteNode(leading_ptr);
    			found = true;
                leading_ptr = leading_ptr -> next;
    		}
    		else
    		leading_ptr = leading_ptr -> next;
    	}

    	if(!found){
    		cout << value<<" has been deleted.\n";
    	}
    }
}


void intList::removeDupl(){   //this function removes any duplicate numbers

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

          /* if the next node isn't the end of the list
             it sets the next node's previous pointer to
             the deleted nodes previous pointer */

          if(ptr2 -> next){
          ptr2 -> next -> prev = dup -> prev;
          }
          delete dup;
          size = size - 1;
       }
       else /* if the data isn't duplicate then move to the next node */
       {
          ptr2 = ptr2 -> next;
       }
     }
     ptr1 = ptr1 -> next;
  }
}

void intList::rotateList(){ //this function rotates the list by two positions

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

    head -> prev = current; // makes the node before the old head the old end

	head = shiftNode -> next; // reassigns the head

	shiftNode -> next = NULL;
}

void intList::splitList(){ //this function splits the list into two

    if(size <= 10){
        cout << "Unable to split list \n\n";
    }

    else{
        ListNode * subHead1 = head,
                 * subHead2 = 0,
                 * leading_ptr = head;

        displayList();

        int i = 0;

        while(leading_ptr && i < 9){
            leading_ptr = leading_ptr -> next;
            i++;
        }
        subHead2 = leading_ptr -> next; // assings list 2's head
        leading_ptr -> next = 0; // makes the end of list 1 point to null

        cout << "1st split :";
        displayList();

        head = subHead2; // makes list 2's head the head for use with
                         // displayList()

        cout << "2nd split :";
        displayList();

        // creates a pointer to go through the list to build our union vector
        ListNode * unionBuilder = subHead1;

        vector<int> unionSplit;

        unionSplit.push_back(unionBuilder -> data);

        while(unionBuilder -> next){

            bool unique = true; // flag for finding unique values


            // searches all our previously found unique values to compare to
            // the current nodes value
            for(int i = 0; i < unionSplit.size(); i++){

                    if(unionSplit[i] == unionBuilder -> data)
                        unique = false;
            }

            // if the number is not found it is added to the union vector
            if(unique)
                unionSplit.push_back(unionBuilder -> data);

            unionBuilder = unionBuilder -> next;
        }

        unionBuilder = subHead2;

        // creates vectors to store the unique values of
        // each list to later find the intersect
        vector<int> intersect1 = unionSplit;
        vector<int> intersect2;

        intersect2.push_back(unionBuilder -> data);

        // repeated again for list 2
        while(unionBuilder -> next){

            bool unique = true; // flag for finding unique values

            // first finds if it is a unique value for this list
            for(int i = 0; i < intersect2.size(); i++){

                    if(intersect2[i] == unionBuilder -> data){
                        unique = false;
                    }
            }

            if(unique)
                intersect2.push_back(unionBuilder -> data);

            unique = true; // reset flag after building intersect


            // searches all our previously found unique values to compare to
            // the current nodes value
            for(int i = 0; i < unionSplit.size(); i++){
                    if(unionSplit[i] == unionBuilder -> data){
                        unique = false;
                    }
            }

            // if the number is not found it is added to the union vector
            if(unique)
                unionSplit.push_back(unionBuilder -> data);

            unionBuilder = unionBuilder -> next;
        }

        cout << "Union of list 1 and 2 is : ";

        for(int i = 0; i < unionSplit.size(); i++){
            cout << unionSplit[i] << " ";
        }

        cout << endl;

        vector<int> intersect;

        // if the
        for(int i = 0; i < intersect1.size(); i++){
            for(int j = 0; j < intersect2.size(); j++){
                if(intersect1[i] == intersect2[j]){
                    intersect.push_back(intersect1[i]);
                }
            }
        }

        if(intersect.size()){

             cout << "intersect of list 1 and 2 is : ";

             for(int i = 0; i < intersect.size(); i++){
                 cout << intersect[i] << " ";
             }
        }

        else{
            cout << "There is no intersection between list 1 and 2 ";
        }

        cout << endl;

        head = subHead1;
        leading_ptr -> next = subHead2;



    }
}

void intList::searchNum(int value){  //this function search for a number(user input)
	ListNode  * leading_ptr  = 0,
    		  * dup = 0;

    bool found = false;

    if(isEmpty()){
    	cout << "List is empty \n";
    }

    else{

    	leading_ptr = head;

    	while(leading_ptr){ // until the end of the list is reached
    		//cout << leading_ptr -> data << endl;
            if(head -> data == value){
                leading_ptr = leading_ptr -> next;
                found = true;

            }
    		else if(leading_ptr -> data == value){

    			found = true;
                leading_ptr = leading_ptr -> next;
    		}
    		else
    		leading_ptr = leading_ptr -> next;


    	}

    	if(found){
    		cout << value<<" has been found.  And is in the list\n";
    	}
    	else
            cout<< value << " not found.  And is not in the list"<<endl;
    }
}


void intList::deleteList(){ //this function deletes the entire list.

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
            size = size - 1;
    	}

    	free(head);
        size = size - 1;

    	head = NULL;
    }
}

int main(){


    intList myList;
    char choice; //should be a char that is listed on the menu



    
    do{ //loop repeats unless x is selected when prompted.
    
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
    cout<<"X - exits the program."<<endl << endl;
    cin>> choice;
    int value=0;

    cout << endl;

    if(choice == 'A' || choice == 'a'){ //builds and populates list
        myList.fillRand();
    }

    else if(choice == 'B' || choice =='b'){ //Inserts a new number at a specific location
        cout<<"At what position would you like to insert then number?"<<endl;
        int position;       //the position the user would like to add the number
        cin>> position;
        cout<<endl<<"What number would you like it insert?"<<endl;
        cin >> value;                   //the value the user wants to insert into the list
        myList.appendNode(value , position - 1);
        cout << endl;
       }
     else if(choice == 'C' || choice == 'c'){  //Searches list for a number and displays it
        cout<<"What value would you like to search for?"<<endl;
        cin>>value;
        myList.searchNum(value);    // calls function to search the list for a specific number
        }

    else if(choice == 'D' || choice == 'd'){
        cout<<"What value would you like to delete?"<<endl;
        cin>>value;
        myList.removeNumber(value);  // calls function to remove requested number
        }
    else if(choice == 'E' || choice == 'e'){
        if(myList.isEmpty()){       // calls function to check if list is empty or not
            cout << "The List is empty\n";
        }
        else
            cout << "The List is not empty\n";
    }
    else if(choice == 'F' || choice == 'f')
        myList.rotateList();    // calls function to rotate list 2 positions
    else if(choice == 'G' || choice == 'g')
        myList.revDispList();   // calls function display list in reverse order, doesnt 
                                // actually reverse the list.
    else if(choice == 'H' || choice == 'h')
        myList.splitList();     // calls function to split the list into two lists
    else if(choice == 'i' || choice == 'I')
        myList.removeDupl();    // calls function to remove all duplicate numbers
    else if(choice == 'J' || choice == 'j')
        myList.deleteList();     // calls function to delete entire list
    else if(choice == 'X' || choice == 'x'){
    }
    else
        cout<<"You have entered an invalid choice, please try again."<<endl;

    myList.displayList();

    myList.printHead();

    cout << endl << myList.getSize() << endl;
        }while(choice !='X' && choice !='x');


cout<<"Thank you for using Chris and Cody's linked list builder!"<<endl<<endl;
cout<<"Implemented by Christopher McCarty and Cody Blakeney."<<endl;



	return 0;
}
