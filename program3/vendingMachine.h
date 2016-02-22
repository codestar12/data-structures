
#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

using namespace std;

class cashRegister {

	private:
		int cash;

	public:

		cashRegister();
		cashRegister(int );
		int cashOnHand() const;
		void deposit(int ); 
		
};

class Dispenser {

	private:

		int candyCount;
		int chipCount;
		int gumCount;
		int cookieCount;

		int candyCost;
		int chipCost;
		int gumCost;
		int cookieCost;

	public:

		Dispenser();
		Dispenser(int , int );
		int itemCount(int ) const;
		int itemCost(int ) const;
		void itemDispense(int );
		
};

#endif