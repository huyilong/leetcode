class Bar{
	//usingt the sandwich finding 
	//because the array is sorted in advance
public:
	//return the closet sum which is near the target passed in
	int closest_3Sum(vector<int> &num, int target){
		int nearest_result = 0;
		//initialize the variable to compare out of the looping
		int min_gap = INT_MAX;

		sort(num.begin(), num.end());
		//this sorting is a must for the following sandwich finding

		for(auto a = num.begin(); a! = prev(num.end(),2); a = upper_bound(a, prev(num.end(), 2), *a)){
			auto b = next(a);
			//the second number start with the next of a in sorted arr
			auto c = prev(num.end());

			while(b<c){
				const int sum = *a + *b + *c;
				const int gap = abs(sum - target);

				if( gap < min_gap){
					result = sum;
					min_gap = gap;
				}

				if(sum < target)   ++b;
				else 			   --c;
				//using the sandwich
			}
		}

		return result;
	}
}