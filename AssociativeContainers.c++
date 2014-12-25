#include <set> //set and map are ordered (tree-structured) associative container
//they are already ordered and thus should not be used by sort() algorithm
#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>//use copy(it,it,ostream_iterator<type>(cout," "));
using namespace  std;

struct Man{

	Man (const char *n, int i): name_(n) , id_(i){}
	//because we pass in a c-type string like    Man("cc",22222)
	//it is used as char *n but not string???
	string name_;
	int id_;
};


//////for struct we do not need to declare the ostream& operator<< as friend???
ostream& operator << (ostream &o, const Man &m)
{
	o<<m.name_<<" "<<m.id_<<" ";
	return o;
}

//if the element stored in set is not the built-in type
//then the operator < must be redefined and overrided
bool operator < (const Man &m, const Man &n)
{
	return m.name_<n.name_||(m.name_==n.name_&&m.id_<n.id_);
}

//////now it is important because callable object ordered associative containers cannot use sort()
//therefore the object of this struct should not be used in sort()
//instead it should be used in the declaration of the set without using ()
// because we just need the callable object type Bar rather than the obj :: it is different with former study
struct Bar{
	//override operator () to make a callable struct must use the bool return type
	bool operator() (const Man &m, const Man &n)
	{
		//different with the former example because now we firstly compare the id instead of name
		return m.id_<n.id_||(m.id_==n.id_&&m.name_<n.name_);
	}
};

int main(int, char**)
{
	vector<Man> v;
	v.push_back(Man("cc",22222));
	v.push_back(Man("bb",11111));
	v.push_back(Man("aa",55555));
	copy(v.begin(), v.end(), ostream_iterator<Man>(cout," "));
	cout<<endl;

	set<Man> default_set;//ordered with the self-defined operator < because it is a new element type
	///////////////insert the original unordered vector into this ordered set
	default_set.insert(v.begin(),v.end());
	copy(default_set.begin(), default_set.end(), ostream_iterator<Man>(cout," "));
	cout<<endl;

	set<Man, Bar> callable_set;
	callable_set.insert(v.begin(),v.end());
	copy(callable_set.begin(), callable_set.end(), ostream_iterator<Man>(cout," "));
	cout<<endl;

	return 0;
}