#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<string> countChar(string s)
{
    9
    vector<string> result;
    map<char, int>::iterator it;
    for(it = mp.begin(); it != mp.end(); it++){
        string temp;
        string str(1, it->first);
        temp = str + ' ' + to_string(it->second);
        result.push_back(temp);
    }
    return result;
}

int main(){
	string str = "ababsavanam";
	vector<string> res = countChar(str);
	for(int i=0; i< res.size(); i++){
		cout << res << endl;
	}
	return 0;
}

