#include <iostream>
using namespace std;
 
class Base{
public:
	//constructor does not need any return type just as in Java
	//constructor could not be defined as virtual
	Base(): hah_(1),bar_(2){cout<<"Base"<<endl;}
	Base(int hah, int bar): hah_(hah),bar_(bar){cout<<"Base"<<endl;}
	//destructor is same as constructor does not need any return type
	//note: as the dynamic allocated memory must use delete addr to call the destructor
	virtual ~Base(){cout<<"~Base"<<endl;}
	virtual void exam(){
		cout<<"Base method"<<hah_<<"+"<<bar_<<endl;
	}
	//accessor because the sub class could not directly use the private members in base class
	int gethah_()
	{
		return hah_;
	}
	int getbar_()
	{
		return bar_;
	}
	//different with java because here we declare the public in the beginning of the class
	//but in java every methoud should begin with public/private

	//constructor and destructor should not use the return type
	//constructor should not be virtual and must define default () constructor
	//since if you define any type of consturctor the compiler will ignore the original default constructor
	//use of the destructor must call the delete addr in the end of main explicitly
private:
	int hah_, bar_;
};

/*

Yes, instances of the subclass will have copies of a private field of the parent class.

They will however not be visible to the subclass, so the only way to access them is via 
methods of the parent class.

*/
class Sub: public Base{
public:
	//constructor for 'Sub' must explicitly initialize the base class 'Base' which does not have a default constructor
	Sub():foo_(3) {cout<<"Sub"<<endl;}
	virtual ~Sub(){cout<<"~Sub"<<endl;}
	virtual void exam(){
		cout<<"Sub method"<<gethah_()<<getbar_()<<foo_<<endl;
	}
	//the sub class could not see the private member in base class
private:
	int foo_;
};

int main(int argc, char** argv)
{
	Base *ptr =new Sub();
	ptr -> exam();
	delete ptr;
	return 0;
}
