#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
#define MAX_SIZE 10000001ll

class doubleHash{
	int TABLE_SIZE, keyPresent, PRIME;
	vector<int> hashTable;
	bitset<MAX_SIZE> isPrime;

	void __setSive(){
		isPrime[0] = isPrime[1] = 1;
		for(long long i = 2; i*i <= MAX_SIZE; i++){
			if(isPrime[i] == 0){
				for(long long j = i*i; j <= MAX_SIZE; j += i){
					isPrime[j] = 1;
				}
			}
		}
	}
	int hash1(int value){
		return value%TABLE_SIZE;
	}
	int hash2(int value){
		return PRIME - (value%PRIME);
	}
	bool isFull(){
		return (keyPresent == TABLE_SIZE);
	}

	public:

	doubleHash(int n){
		__setSive();
		TABLE_SIZE = n;
		PRIME = TABLE_SIZE - 1;
		while(isPrime[PRIME] == 1){
			PRIME--;
		}

		keyPresent = 0;

		for(int i=0; i<TABLE_SIZE; i++){
			hashTable.push_back(-1);
		}
	}

	void __printPrime(long long n){
		for(long long i = 0; i <= n; i++){
			if(isPrime[i] == 0){
				cout << i << ", ";
			}
		}
		cout << endl;
	}

	void insert(int value){
		if(value == -1 || value == -2){
			cout << "ERROR: -1 and -2 cannot insert in the table" << endl;
			return;
		} 
		if(isFull()){
			cout << "ERROR: Hash Table Full" << endl;
			return;
		}
		int probe = hash1(value), offset = hash2(value);
		while((hashTable[probe]) != -1){
			if((hashTable[probe]) == -2){
				break;
			}
			probe = (probe + offset) % TABLE_SIZE;
		}
		hashTable[probe] = value;
		keyPresent++;
	}

	void erase(int value){
		if(!search(value)){
			cout << "Value is not exist" << endl;
		}
		int probe = hash1(value), offset = hash2(value);
		while(hashTable[probe] != -1){
			if(hashTable[probe] == value){
				hashTable[probe] = -2;
				keyPresent--;
				return;
			}
			probe = (probe + offset) % TABLE_SIZE;
		}
	}

	bool search(int value){
		int probe = hash1(value), offset = hash2(value);
		if(hashTable[probe] == -1){
			return false;
		}
		while(hashTable[probe] != -1){
			if(hashTable[probe] == value){
				return true;
			}
			probe = (probe + offset) % TABLE_SIZE;
		}
		return false;
	}

	void print(){
		for(int i=0; i< TABLE_SIZE; i++){
			cout << hashTable[i] << " ";
		}
		cout << endl;
	}
};

int main(){
	doubleHash myHash(13);
	myHash.print();
	int insertions[] = {115, 12, 87, 66, 123},
		n1 = sizeof(insertions)/sizeof(insertions[0]);

	for(int i=0;i<n1; i++){
		myHash.insert(insertions[i]);
	}
	cout << "Status of hash table after initial insertions :\n"; myHash.print();

	int queries[] = {1, 12, 2, 3, 69, 88, 115},
        n2 = sizeof(queries)/sizeof(queries[0]);

    for(int i=0; i<n2; i++){
     	if(myHash.search(queries[i])){
     		cout << queries[i] << " is exist" << endl;
     	}
     	else{
     		cout << queries[i] << " is not found!" << endl;
     	}
    }

    int deletions[] = {123, 87, 66},
        n3 = sizeof(deletions)/sizeof(deletions[0]);

    for(int i=0; i<n3; i++){
    	myHash.erase(deletions[i]);
    }
    myHash.print();

	return 0;
}