#include <iostream>
#include "cashReg.h" //correct header file name

using namespace std;

const int DEFAULT_STARTING_VALUE = 50;

cashRegister::cashRegister(){
	cash = 500; // not used
}

cashRegister::cashRegister(int startingCash){
	cash = startingCash; //not used
}

int cashRegister::cashOnHand() const{
	return cash; //not used
}

void cashRegister::deposit(int deposit) {
	cash = cash + deposit; // not used
}

Dispenser::Dispenser(){

	candyCount = DEFAULT_STARTING_VALUE;
	chipCount = DEFAULT_STARTING_VALUE;
	gumCount = 3;
	cookieCount = 2;

	candyCost = DEFAULT_STARTING_VALUE;
	chipCost = 75;
	gumCost = 45;
	cookieCost = 55;
}

Dispenser::Dispenser(int inventory, int cost){

	candyCount = inventory;
	chipCount = inventory;
	gumCount = inventory;
	cookieCount = inventory;

	candyCost = cost;
	chipCost = cost;
	gumCost = cost;
	cookieCost = cost;
}

/*int passed as argument decides item count
to return */
int Dispenser::itemCount(int itemSelection) const{
//returns how many of a certain item remain.
	if(itemSelection == 1)
		return candyCount;

	else if(itemSelection == 2)
		return chipCount;

	else if(itemSelection == 3)
		return gumCount;

	else if(itemSelection == 4)
		return cookieCount;

	// invalid selection
	else
		return -1;
}

/*int passed as argument decides item cost
to return */
int Dispenser::itemCost(int itemSelection) const{
// returns price of item if called
	if(itemSelection == 1)
		return candyCost;

	else if(itemSelection == 2)
		return chipCost;

	else if(itemSelection == 3)
		return gumCost;

	else if(itemSelection == 4)
		return cookieCost;

	// invalid selection
	else
		return -1;
}

void Dispenser::itemDispense(int itemSelection){
// removes 1 item if user correctly chooses an item.
	if(itemSelection == 1)
		candyCount--;

	else if(itemSelection == 2)
		chipCount--;

	else if(itemSelection == 3)
		gumCount--;

	else if(itemSelection == 4)
		cookieCount--;
}
