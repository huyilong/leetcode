#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> unsorted_arr({1,3,2,4,6,5,0,99});
	//fill(it1, it2, num)
	//fill_n(begin_it, quantity, num)
	auto last = unsorted_arr.end();
	//actully last is pointing to the null after the final element
	for(auto a = unsorted_arr.begin(); a<last; a = lower_bound(a, last, *a)){
		cout<< *a <<endl;
	}
}