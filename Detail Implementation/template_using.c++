#include <iostream>
using namespace std;

//this could only be used as typename or class
//template<class T>
template<typename T>
void print(const T &val)
{
	cout<<val;
}

//interface specification 
template<> //empty parameter list
void print(const float &f_val)
{
	int i = f_val;
	cout<<i;
	//do something special
}

//specializeation more


int main(){
	print("Using general template because this is a char* not a float");
	cout<<endl;
	print((float) 33.45);//using specilization template<>

	return 0;
}