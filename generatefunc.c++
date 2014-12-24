#include <iostream>     // std::cout
#include <algorithm>    // std::generate
// C++ STL algorithm, generate()
#include <vector>       // std::vector
#include <deque>
#include <list>

using namespace std;

// class generator:
struct c_unique {
  int current;
  c_unique() {current=0;}
  int operator()() {return ++current;}
} UniqueNumber;
//in this way UniqueNumber is one of the object of the c_unique struct
// we can directly use itself as a callable object   
// we can use it without () because itself is a callable object, same with callable function

struct jump {
  int current;
  jump() {current=0;}
  //there are two sequential ()() 
  /////////attention!!!
  int operator()() 
  {
  	current=current+2;
  	return (current);
  }
} ;
///////////here we did not use a name before the semicolon
///////////therefore we need to use the () to create an object of this struct when we use generate

int main(int argc, char**agrv)
{
	vector<int> myvector (8);
	//since we use the generate function we must initialize the vector with a fixed space
	generate (myvector.begin(), myvector.end(), UniqueNumber);
	cout << "myvector contains:";
    for (auto it=myvector.begin(); it!=myvector.end(); ++it)
    {
       cout << ' ' << *it;
    }
    cout << endl;



    deque <int> deq(5);
    generate(deq.begin(), deq.end(), jump ());
    cout << "my deque contains:";
    for (auto it=deq.begin(); it!=deq.end(); ++it)
    {
       cout << ' ' << *it;
    }
    cout << endl;




    list <int> ll(7);
    auto begin_it = ll.begin();

    advance(begin_it,5);
    ///////advance or pre will not return anything it has void return-type
    ////auto end_it = advance(begin_it,5);
    //list<int> ll = generate(1,7);  this is wrong
    //generate function requires 3 args :: beginning ite, ending ite and generator
    fill(ll.begin(), begin_it,111111);
    //this is wrong because list is not random access, i.e. it could not use iterator+/-num
    cout << "my list contains:";
    for (auto it=ll.begin(); it!=ll.end(); ++it)
    {
       cout << ' ' << *it;
    }
    cout << endl;
    cout<<distance(ll.begin(),begin_it)<<endl;
}

/*
myvector contains: 1 2 3 4 5 6 7 8
my deque contains: 2 4 6 8 10
my list contains: 111111 111111 111111 111111 111111 0 0
5
*/