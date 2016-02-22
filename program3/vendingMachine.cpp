#include <iostream>
#include "vendingMachine.h" 

using namespace std;

const int DEFAULT_STARTING_VALUE = 50;

cashRegister::cashRegister(){
	cash = 500;
}

cashRegister::cashRegister(int startingCash){
	cash = startingCash;
}

int cashRegister::cashOnHand() const{
	return cash;
}

void cashRegister::deposit(int deposit) {
	cash = cash + deposit;
}

Dispenser::Dispenser(){

	candyCount = DEFAULT_STARTING_VALUE;
	chipCount = DEFAULT_STARTING_VALUE;
	gumCount = DEFAULT_STARTING_VALUE;
	cookieCount = DEFAULT_STARTING_VALUE;

	candyCost = DEFAULT_STARTING_VALUE;
	chipCost = DEFAULT_STARTING_VALUE;
	gumCost = DEFAULT_STARTING_VALUE;
	cookieCost = DEFAULT_STARTING_VALUE;
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

	if(itemSelection == 0)
		return candyCount;

	else if(itemSelection == 1)
		return chipCount;

	else if(itemSelection == 2)
		return gumCount;

	else if(itemSelection == 3)
		return cookieCount;

	// invalid selection
	else
		return -1;
}

/*int passed as argument decides item cost
to return */
int Dispenser::itemCost(int itemSelection) const{

	if(itemSelection == 0)
		return candyCost;

	else if(itemSelection == 1)
		return chipCost;

	else if(itemSelection == 2)
		return gumCost;

	else if(itemSelection == 3)
		return cookieCost;

	// invalid selection
	else
		return -1;
}

void Dispenser::itemDispense(int itemSelection){

	if(itemSelection == 0)
		candyCount--;

	else if(itemSelection == 1)
		chipCount--;

	else if(itemSelection == 2)
		gumCount--;

	else if(itemSelection == 3)
		cookieCount--;
}