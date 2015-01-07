#include <iostream>
using namespace std;

class ComplexCal{
private:
	double real_part;
    double imaginary_part;

public:
	ComplexCal(double real = 0, double imag = 0): real_part(real), imaginary_part(imag){
		//the constructor could not be virtual and does not have any return type
			cout<<"("<<real_part;
			//comparing two float or double num must use abs(dif)<
				//could not directly use ==
			if(imaginary_part != 0.0){
				cout<<'+'<<imaginary_part<<"i";
			}

			cout<<")"<<endl;
	}

	//declaration of some functions which would be defined outside the class
	const ComplexCal operator+(const ComplexCal & input);
	//for those who are not friends and just the inner class operator
	//we only need one input because it is default as input_1.+(input_2)

	friend const ComplexCal operator+(const ComplexCal &left, const ComplexCal &right);
	//this would be used as above 
	//but friend has advantage is that this is actually a global function which could
	//also be used by other classes but not just this one
};

//there is no : after friend!!!
//operator+/- actually these are the function name and before this we need a return type

const ComplexCal ComplexCal::operator+(const ComplexCal& input){
	cout<<"calling member function"<<endl;
	return ComplexCal(real_part+input.real_part,  imaginary_part+input.imaginary_part);
}
//when define member function which is not the global ones(frined) we need to 
//using scoping operator before the func name

const ComplexCal operator+(const ComplexCal &left, const ComplexCal &right){
	//this does not have the right to always use the obj to call as the member function
	//therefore this needs two inputs explicitly
	cout<<"calling friend global function"<<endl;
	return ComplexCal(left.real_part+right.real_part,  left.imaginary_part+right.imaginary_part);
	//smartly using the constructor to return and print out
}


int main(){
	ComplexCal a(1,2), b(1.1,2.2), c;
	//class c will call the constructor automatically!!!

	c = a+b;
}
/*
(1+2i)
(1.1+2.2i)
(0)
calling member function
(2.1+4.2i)
*/