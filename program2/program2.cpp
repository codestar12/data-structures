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
	int largest, smallest;

	cout << "please enter an integer: ";
	cin >> n;

	vector<int> hailstone = findHailstone(n);

	printHailstone(hailstone);

	largest = returnLargest(hailstone);
	smallest = returnSmallest(hailstone);

	cout << endl << largest << " " << smallest;

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

int returnLargest(vector<int> & hailstone){
	int largest = 0;

	for(int i = 0; i < hailstone.size(); i++ ){
		if(largest < hailstone.at(i)){
			largest = hailstone.at(i);
		}
	}

	return largest;
}

int returnSmallest(vector<int> & hailstone){
	int smallest = hailstone.at(0);

	for(int i = 0; i < hailstone.size(); i++ ){
		if(smallest > hailstone.at(i)){
			smallest = hailstone.at(i);
		}
	}	

	return smallest;
}