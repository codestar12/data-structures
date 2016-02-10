#include <vector>
#include <iostream>

using namespace std;

vector<int> findHailstone(int);
void 		printHailstone(vector<int>&);
int 		hailstoneLength(vector<int>&);
int 		returnLargest(vector<int>&);
int 		returnSmallest(vector<int>&);
int 		evenCount(vector<int>&);
int 		oddCount(vector<int>&);

int main(){

	int n = 0;

	cout << "please enter an integer: ";
	cin >> n;

	vector<int> hailstone = findHailstone(n);

	printHailstone(hailstone);

	return 0;
}

vector<int> findHailstone(int n){

	vector<int> hailstone;

	hailstone.push_back(n);

	while(n != 1){

		if(n % 2 == 1){

			n = n * 3 + 1;
		}

		else if(n % 2 == 0){

			n /= 2;
		}

		hailstone.push_back(n);
	}

	return hailstone;
}

void printHailstone(vector<int> & hailstone){

	for(int i = 0; i < hailstone.size(); i++){

		cout << hailstone.at(i) << " ";
	}
}