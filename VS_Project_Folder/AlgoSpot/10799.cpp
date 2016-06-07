#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	stack<char> st;
	string str;
	int size, scatter_num = 0;
	int memory = 0; 

	cin >> str;
	
	size = str.size();

	for (int i = 0; i < size; i++){
		if (str[i] == '(')
			st.push(1);
		else if (str[i] == ')'){
			st.pop();
			if (str[i - 1] == '(') {// ·¹ÀÌÀú
				scatter_num += st.size();
				memory = st.size();
			}
			else {
				scatter_num++;
			}
		}
	}

	cout << scatter_num;
	
	
	return 0;
}