#include <tuple>
#include <string>
#include <iostream>
#include <vector>
using namespace std;



typedef tuple <int, string> student;
vector <student> classList;
//using reference for ostream and const reference for input data
ostream & operator << (ostream &out, const student &input_stu)
{
	///////can I use endl in the end of the following statement?
	///////Yes I can
	out<<get<0>(input_stu)<<" "<<get<1> (input_stu)<< endl;
	return out;
}

//auto could be used in cursor/iterator/ loop getter/ make_pair/make_tuple
int main(int, char**)
{
	//auto could be used in cursor/iterator/ loop getter/ make_pair/make_tuple
	auto studentA = make_tuple(12345, "Aaron");
	classList.push_back(studentA);
	//if it is too troublesome we can define our own << operator
	cout<< get<0> (studentA)<<" "<<get<1>(studentA)<<endl;

	classList.push_back(make_tuple(23456,"Baron"));
	classList.push_back(make_tuple(34567,"Caron"));
	classList.push_back(make_tuple(45678,"Daron"));

//////auto could be used in cursor/iterator/ loop getter/ make_pair/make_tuple
	///using const auto to promise not alter the data u fetch from the : classList
	for(const auto stu : classList)
	{
		cout<<stu;
	}

	auto studentB = make_tuple(12345, "Zaron");
	bool compare = studentA < studentB;
	cout<<compare<<endl;
	///using the form operation first input boolalpha into the stream then output the bool
	///similar to put the setw(num) into the stream and then the following output
	cout<<  std::boolalpha  <<compare<<endl;

}