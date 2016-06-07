#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	stack<char> left;
	stack<char> right;
	string str;
	char cmd;
	char data;
	int n;

	cin >> str;
	cin >> n;

	for (int i = 0; i < str.size(); i++)
		left.push(str[i]);

	while (n--){
		cin >> cmd;
		if (cmd == 'P'){
			cin >> data;
			left.push(data);
		}
		else if (cmd == 'L' || cmd == 'B'){
			if (left.empty())
				continue;
			else{
				int tmp = left.top();
				left.pop();
				if (cmd == 'L')
					right.push(tmp);
			}
		}
		else {
			if (right.empty())
				continue;
			left.push(right.top());
			right.pop();
		}
	}

	while (!left.empty()){
		right.push(left.top());
		left.pop();
	}

	while (!right.empty()){
		cout << right.top();
		right.pop();
	}

	cout << endl;

	return 0;
}