#include <iostream>
using namespace std;
//base class
class B{
public:
	void f(){
		cout<<"base non-virtual function called"<<endl;
	}

	virtual void vf(){
		cout<<"base virtual function called"<<endl;
		//this could also be used in debugging for checking which function is called
	}

	void ff(){
		vf();
		f();
	}

	//derived class does not have this vff()
	//therefore even if it is virtual we still use this in the base function
	//because we cannot be more specific in derived class
	virtual void vff(){
		vf();
		f();
	}
};

//derived class
class D : public B{
public:
	void f(){
		cout<<"derived non-virtual function called"<<endl;
	}

	void ff(){
		f();
		vf();
	}

	//although there is no virtual in the front
	//it is still has a virtual type because it is declared as virtual in the base class
	void vf(){
		cout<<"derived virtual function called"<<endl;
	}
};

int main(){
	D d;
	//this is anyway calling the constructor
	//different from java, in c++ we do not need to use()
	//i.e. we could just D d rather than D d = new D();

	B *pB = &d;

	//the above two statements could be implemented by using
	//B *pB = new D;
	//but in this way the D does not have an object with name
	pB -> f(); //non-virtual base
	pB -> ff(); //call f() and vf()


	pB -> vf();//virtual base
	//attention!! if we want to call the virtual function 
	//in base class i.e. prevent the run-time decision
	//we could use the scoping operator to constrict it in the base class
	cout<<"using scoping operator just before the function name to prevent dynamic virtual calling"<<endl;
	B base;
    base.B::vf();


	pB -> vff();
}

