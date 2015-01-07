class Foo{
public:
	//find all the possible solutions where three nums sum equals zero
	vector< vector<int> > threeSum(vector<int> &num){
		vector<vector<int>> result;
		//corner condition
		if(num.size()<3){
			return result;
		}
		sort(num.begin(), num.end());
		const int target = 0;

		auto last = num.end();

		//a only needs to search to n-3 this place will determine whethe there are valid solutions
		for(auto a = num.begin(); a<prev(last,2); a=upper_bound(a,prev(last,2), *a)){
			for(auto b=next(a); b<prev(last); b = upper_bound(b, prev(last), *a)){
				const int c = target - *a - *b;

				if(binary_search(next(b), last, c)){
					result.push_back( vector<int> ( { *a, *b, c}));
				}
			}
		}

		return result;
	}
}