#include <iostream>
#include <vector>

using namespace std;

int main () {
	int p, q;
	
	while (cin >> p >> q) {
		vector<int> arr1, arr2;

	for (int i=1; i<=p; i++)
		if (p % i==0)
			arr1.push_back(i);
	for (int i=1; i<=q; i++)
		if (q % i==0)
			arr2.push_back(i);

	for (int m=0; m<arr1.size(); m++)
		for (int n=0; n<arr2.size(); n++)
			cout << arr1[m] << " " << arr2[n] << endl;
	}
	
	return 0;
}