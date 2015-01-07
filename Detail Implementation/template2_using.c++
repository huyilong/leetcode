//note: local(automatic) variable would be automatically GC
//i.e. it is just in its block , lifetime is very short, even less than the function lifetime
//break; just break out the inner looping
//however, any dynamic memory(which is allocate the space in run-time would require explicit delete)
//like arr[] run-time = new arr[input_size];
//delete pointer;  or delete arr[]; we need this ! or using smart pointers

#include <iostream>
using namespace std;

void f(int i)
{
	cout<<"f(int): " << i <<endl;
}

//when interface polymorphism
//we even do not need template<>
void f(float i)
{
	cout<<"f(float) " << i << endl;
}

void f(double i)
{
	cout<<"f(double) " << i << endl;
}

template< class T>
void f(T i)
{
	cout<<"f(T) "<<i<<endl;
}
//their names must be the same because we are overloading

int main(){
	f(1);
	f(3.14);
	//3.14 is double, but not float!!!
	//double is more precise and thus it is the default set for the 3.14 in c++
	//otherwise you must do the conversion yourself (float)3.14
	///this will print out f(T)????
	f((float) 3.14);
	f("helloworld");
}