//Naafiul Hossain
//SBU ID: 115107623

#include <iostream>

//Euclidean Algorithm 
int g_c_d(int x, int y) {
	if (x < 0 || y < 0) {
		return 0;
	}
	while (x && y) { //if both x and y are non zero
		x %= y;
		std::swap(x, y);

	}
	return x + y;

}

int main() {
	using std::cout;
	using std::endl;
	cout << g_c_d(42, 6) << endl;
	cout << g_c_d(0, 32) << endl;
	cout << g_c_d(10, -6) << endl;
	return 0;
}