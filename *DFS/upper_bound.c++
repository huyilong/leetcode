#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<int> num( {9,9,9,9,9,10,8,11,7,12,6});
	vector<int> num2( {9,9,9,9,9,11,7,10,14,8,12,6,13,14});

	auto last = num.end();
	for(auto it = num.begin(); it<prev(last,2); it = upper_bound(it, prev(last,2), 9)){
		//upper_bound is for strictly larger than
		cout<<*it<<" "<<endl;
	}

	for(auto it = num.begin(); it<last; it = lower_bound(it, last, 10)){
		//lower_bound is for not bigger than
		cout<<*it<<" "<<endl;
	}

    last = num2.end();

	for(auto it = num2.begin(); it<last; it = upper_bound(it, last, 9)){
		//Returns an iterator pointing to the first element in the range [first,last) which compares greater than val.
		//upper_bound is for strictly larger than
		cout<<"the result of it = upper_bound(it, last, 9) for {9,9,9,9,9,11,7,10,8,12,6}"<<endl;
		cout<<*it<<" "<<endl;
	}

	last = num2.end();
	//prev(it,2);
	//advance(it,3);

	for(auto it = num2.begin(); it<last; it = upper_bound(it, last, *it)){
		//upper_bound is for strictly larger than
		cout<<"the result of it = upper_bound(it, last, *it) for {9,9,9,9,9,11,7,10,8,12,6}"<<endl;
		cout<<*it<<" "<<endl;
	}
}

/*
int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  std::vector<int>::iterator low,up;
  low=std::lower_bound (v.begin(), v.end(), 20); //          ^
  up= std::upper_bound (v.begin(), v.end(), 20); //                   ^
 */