#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){
	vector<int> v = {1,2,3,4};
	cout << *&v << endl;
	return 0;
}