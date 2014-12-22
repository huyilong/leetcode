#include <iostream>
using namespace std;

class DiffNameWithFile{
public:
	void hello()
	{
		cout<<"hello with non-static function using initializing the class obj to call"<<endl;
	}
//private:
//in the main function it could not see the private member function in class
//different from java because public static void main is in the same class with other private members
	static void hhello()
	{
		cout<<"hhello with static function using scoping operator"<<endl;
	}
} ;   // this semi-colon is not used in java since the main function must within the same class
//i.e. in java there should not be more than one class in one file.java

//public static void main(Stirng[] args)  in java
//static function could be called with scoping operator without initialize the obj
int main(int argc, char** argv)
{
	DiffNameWithFile obj;
	//different with java
	//1. the name of the file could be different with the class name
	//2. in c++ if not the dynamic memory then do not use "new"
	// i.e. Base * ptr = new Subclass obj;
	// but in the java there must be a default constructor to use the new and ()
	// i.e. Class obj = new Class();  where the name of the constructor should be
	// as same as the name of the class and the whole file
	obj.hello();
	DiffNameWithFile::hhello();
}