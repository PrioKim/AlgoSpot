#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string str;
	string substr[1000];

	int size;

	cin >> str;
	size = str.size();

	for (int i; i < size; i++){
		substr[i] = str.substr(i, size - i);
	}

	sort(substr[0], substr[size]);

	for (int i = 0; i < size; i++){
		cout << substr[i] << endl;
	}

}