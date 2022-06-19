// Program to Count set bits in an integer

// In GCC, we can directly count set bits using __builtin_popcount()
// Time Complexity: O(1)

#include <iostream>
using namespace std;

int main()
{
	cout << __builtin_popcount(9) << endl;
	cout << __builtin_popcount(15) << endl;

	return 0;
}
