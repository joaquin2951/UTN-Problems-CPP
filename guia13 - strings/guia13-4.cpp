#include <iostream>
#include <string>
using namespace std;

string newString(string str1, string str2);

int main() {
	
	string str1, str2;
	
	getline(cin,str1);
	getline(cin,str2);
	
	
	cout << newString(str1,str2);
	
	return 0;
}

string newString(string str1, string str2){
	string str;
	
	if(str1.length() < str2.length()){
		str1.swap(str2);//el mayor está guardado en str1
	}
	
	str = str2 + str1 + str2;
	
	
	return str;
}
