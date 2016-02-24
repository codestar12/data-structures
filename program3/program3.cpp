//  Roster Number/s:  4 , 20
//
//  Authors: Cody Blakeney, Christopher McCarty
//  Due Date: 2/24/2016
//  Programming Assignment Number 3
//  Spring 2016 - CS 3358 - 253
//
//  Instructor: Husain Gholoom
//
//  This program is designed to act as a vending machine that holds a certain
//  number of items.  The user chooses which item and then must enter the correct
//  price to get the item.  If the user is successful in getting the item, one less
//  of the item is available to choose.  If enough are picked the user will received
//  saying the item so no longer available.


#include <iostream>
#include <limits>
#include "cashReg.h" //correct header file

using namespace std;

int main(){

	//cashRegister cashbox;
	Dispenser vend(2,45);  // testing non-default constructor
    //Dispenser vend;
	int choice , firstDeposit;  //choice is what the user wants to do (1,2,3,4,9) only valids
        //firstDeposit is what the user enters to pay is they pick 1,2,3,4

	// testing class declearation
	//cout << vend.itemCount(0) << endl;

	do{
        // into message displayed every time unless 9(exit) is chosen
	cout << "** Welcome to Chris and Cody's Vending Machine! **"<< endl<<endl;
    cout <<"\tSelect one of the following:" << endl << endl;
    cout <<"\t\t1 for Candy" << endl;
    cout <<"\t\t2 for Chips" << endl;
    cout <<"\t\t3 for Gum" << endl;
    cout <<"\t\t4 for Cookies" << endl;
    cout <<"\t\t9 to exit" << endl;
    cin >> choice;

        // makes sure the user picks a valid int
    if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 9){
        cout << "Invalid Selection" << endl;
        cin.clear(); // handles case of invalid type
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // enters unless 9 is picked
    if(choice == 1 || choice == 2 || choice == 3 || choice == 4){
            // checks to see it item is sold out
        if (vend.itemCount(choice) == 0){
            cout<<"Sorry, this item is sold out"<<endl<<endl;
           choice = -1; // choice set to obvious invalid choice
        }

        else{
                //user enters the price of the candy
            cout<< "Please deposit " << vend.itemCost(choice) << " cents"<<endl;
            cin >>firstDeposit;
            cout <<endl;
                // if user enters more than price
            if( firstDeposit> vend.itemCost(choice)){
                cout<< "Collect your item at the bottom and enjoy."<<endl;
                cout<< "Collect your change: "<< firstDeposit-vend.itemCost(choice)<<endl;
                cout<<"*****************************************"<<endl<<endl;
                vend.itemDispense(choice);
            } //if user enters correct amount
            if(firstDeposit == vend.itemCost(choice)){
               cout<< "Collect your item at the bottom and enjoy."<<endl;
               cout<<"*****************************************"<<endl<<endl;
               vend.itemDispense(choice);
               } //if user enters less than price of item
            if(firstDeposit < vend.itemCost(choice)){
                int stillOwed , secondDeposit;
                // still owed is cost of item - firstDeposit
                // secondDeposit is how much they enter when they didnt pay enough the
                // first time.
                stillOwed = vend.itemCost(choice)-firstDeposit;
                cout <<"Please deposit another " << stillOwed << " cents."<<endl;
                cin >> secondDeposit;
                    // if user enters the correct remaining amount
                if(secondDeposit == stillOwed){
                    cout<< "Collect your item at the bottom and enjoy."<<endl;
                    cout<<"*****************************************"<<endl<<endl;
                    vend.itemDispense(choice);
                }   // if user doesn't enter enough, user doesnt get another chance
                if(secondDeposit < stillOwed){
                    cout<< "The amount is still not enough. Collect what you deposited."<<endl;
                    cout<<"*****************************************"<<endl<<endl;
                }   //user enter more than needed, change is returned
                if(secondDeposit > stillOwed){
                    cout<< "Collect your item at the bottom and enjoy."<<endl;
                    cout<< "Collect your change: "<< secondDeposit - stillOwed<<endl;
                    cout<<"*****************************************"<<endl<<endl;
                    vend.itemDispense(choice);
                }
            } // end if
          } // end else
        } // end correct choice if

	}while(choice != 9);
        // only displayed when 9 is chosen and program ends
    cout<<"Thank you for visiting Chris and Cody's vending Machine!"<<endl;


	return 0;
}

