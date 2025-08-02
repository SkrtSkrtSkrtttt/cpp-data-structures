//Naafiul Hossain
//SBU ID: 115107623
#include <iostream>
#include <list>

using namespace std;

void reverse_list(list<int>& m1, int left, int right) {
	list<int>::iterator start = m1.begin();
	list <int>::iterator end = m1.begin();

	int tmp = 0;
	//get left point
	for (int i = 0; i < left; i++) {
		start++;
	}
	//get right point 
	for (int i = 0; i < right; i++) {
		end++;
	}
	//reverse
	while (start != end) {
		tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		if (start == end) {
			break;
		}
		end--;
	}
}

int main() {
	list<int> mylist = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int left = 1;
	int right = 5;

	reverse_list(mylist, left, right);

	// Print the updated list
	for (const int& element : mylist) {
		cout << element << " ";
	}
	cout << endl;

	return 0;
}
