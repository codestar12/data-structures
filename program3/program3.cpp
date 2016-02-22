#include <iostream>
#include "vendingMachine.h"

using namespace std;

int main(){

	//cashRegister cashbox;
	Dispenser vend;
	int choice , firstDeposit;

	// testing class declearation
	//cout << vend.itemCount(0) << endl;

	do{

	cout << "** Welcome to Chris and Cody's Vending Machine! **"<< endl<<endl;
    cout <<"\tSelect one of the following:" << endl << endl;
    cout <<"\t\t1 for Candy" << endl;
    cout <<"\t\t2 for Chips" << endl;
    cout <<"\t\t3 for Gum" << endl;
    cout <<"\t\t4 for Cookies" << endl;
    cout <<"\t\t9 to exit" << endl;
    cin >> choice;


    if(choice != 1 || choice != 2 || choice != 3 || choice != 4 ||choice != 9)
        cout << "Invalid Selection" << endl;
    if (vend.itemCount == 0){
        cout<<"Sorry, this item is sold out"<<endl<<endl;
        choice =5;
    }
    if(choice == 1 || choice == 2 || choice == 3 || choice == 4){
        cout<< "Please deposit " << vend.itemcost(choice) << "cents"<<endl;
        cin >>firstDeposit;
        cout <<endl;
        }
        if( firstDeposit> vend.itemcost(choice)){
            cout<< "Collect your item at the bottom and enjoy."<<endl;
            cout<< "Collect your change: "<< firstDeposit-vend.itemcost(choice)<<endl;
            cout<<"*****************************************"<<endl<<endl;
            vend.Dispense(choice);
        }
        if(firstDeposit == vend.itemcost(choice)){
           cout<< "Collect your item at the bottom and enjoy."<<endl;
           cout<<"*****************************************"<<endl<<endl;
           vend.Dispense(choice);
           }
        if(firstDepost < vend.itemcost(choice)){
            int stillOwed , secondDeposit;
            stillOwed = vend.itemcost(choice)-firstDeposit;
            cout <<"Please deposit another " << stillOwed << "cents."<<endl;
            cin >> secondDeposit;

            if(secondDeposit == stillOwed){
                cout<< "Collect your item at the bottom and enjoy."<<endl;
                cout<<"*****************************************"<<endl<<endl;
                vend.Dispense(choice);
            }
            if(secondDeposit < stillOwed){
                cout<< "The amount is still not enough. Collect what you deposited."<<endl;
                cout<<"*****************************************"<<endl<<endl;
            }
            if(secondDeposit > stillOwed){
                cout<< "Collect your item at the bottom and enjoy."<<endl;
                cout<< "Collect your change: "<< secondDeposit - stillOwed<<endl;
                cout<<"*****************************************"<<endl<<endl;
                vend.Dispense(choice);
            }


        }
	}while(choice != 9)

    cout<<"Thank you for visiting Chris and Cody's vending Machine!"<<endl;


	return 0;
}
