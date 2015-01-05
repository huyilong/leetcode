//do not use assistant memory
class Foo{
public:
	//judge duplicates etc, always sorting at first
	//make the duplicates together
	int removeDup(int A[], int n){
		//actually we could use int removeDup(int *A, int len) *A to receive the passing &arr[0] / arr
		if(n==0)
			return 0;
		int index = 0;
		for(int i=1; i<n; ++i){
			if(A[index] != A[i] )
				++index; // meet with new distinct elements
				A[index] = A[i]; // move around
		}
		return index+1;
	}
};

class Bar{
public:
	//return the final length of the array by arr[n]-arr = n, which is actually the length
	int removeDup(int *A, int n){
		return removeDupHelper(A, A+n, A)   - A;
		//removeDup() will return the last address of the new array which contains no dups
	}

	template<typename InIt, typename OutIt>
	//RETURN AN ITRATOR/ADDRESS

	OutIt removeDupHelper(InIt first, InIt last, OutIt output){
		while(first != last){
			*output ++ = *first;
			first = find_if(first, last, bind1st(not_equal_to<int>(), *first) );
		}
		return output;
	}
};

//followup: what if the requirement become could have at most two dups
//[1,1,1,2,2,3] -> [1,1,2,2,3]
class FooBar{
public:
	int removeDup(int *A, int n){
		if(n==0) return 0;
		int occur = 1;
		int index = 0;
		//this is the new version of the class Foo
		for(int i=1; i<n; ++i){
			if(A[index] == A[i]){
				//if we allow at most 3 dups we could alter the following statement with occur<3
				if(occur < 2){
					A[++index] = A[i];
					occur++;
				}else{
					A[++index] = A[i];
					occur = 1;
					//reset the occur
				}
			}
		}

		return index+1;//index and length will always have a difference of 1
	}

	//we need a new variable to record the occurence 
};

