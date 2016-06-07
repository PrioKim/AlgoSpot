#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	int n;
	string str;
	stack<int> st;
	int m = 0;

	cin >> n;
	while (n--){
		m = 0;
		cin >> str;
		int size = str.size();

		while (!st.empty()) st.pop();
		for (int i = 0; i < size; i++){
			if (str[i] == '(')
				st.push(0);
			else if (str[i] == ')'){
				if (st.empty()){
					cout << "NO" << endl;
					m = 1;
					break;
				}
				else {
					st.pop();
				}
			}
		}
		if (m == 0) {
			if (!st.empty())
				cout << "NO" << endl;
			else
				cout << "YES" << endl;
		}
	}

	return 0;
}