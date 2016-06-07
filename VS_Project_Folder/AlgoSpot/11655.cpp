#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	int size;

	getline(cin, str);
	size = str.size();

	for (int i = 0; i < size; i++){

		if ('a' <= str[i] && str[i] <= 'z'){
			if (str[i] + 13 > 'z')
				str[i] = str[i] + 13 - 26;
			else
				str[i] += 13;
		}
		else if ('A' <= str[i] && str[i] <= 'Z'){
			if (str[i] + 13 > 'Z')
				str[i] = str[i] + 13 - 26;
			else
				str[i] += 13;
		}
	}

	cout << str;


	return 0;
}