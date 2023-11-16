
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count(char* s, const char c)
{
	int k = 0,
		pos = 0;
	char* t;
	while (t = strchr(s + pos, c))
	{
		pos = t - s + 1;
		k++;
	}
	return k;
}
char* Change(char* s) {
	char* t = new char[3 * strlen(s) + 1]; 
	int pos1 = 0, pos2 = 0;
	*t = 0;

	for (int i = 0; s[i] != '\0'; ++i) {
		if (s[i] == '+' || s[i] == '-' || s[i] == '=') {
			strncat(t, s + pos1, i - pos1); 
			pos1 = i + 1; 
		}
	}

	strcat(t, s + pos1); 
	strcpy(s, t);
	return t;
}
int main()
{
	char str[101];
		cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << Count(str, '+') << " count of '+'" << endl;
	cout << "String contained " << Count(str, '-') << " count of '-'" << endl;
	cout << "String contained " << Count(str, '=') << " count of '='" << endl;
	int sum = Count(str, '+') + Count(str, '-') + Count(str, '=');
	cout << "Sum = " << sum << endl;
	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}