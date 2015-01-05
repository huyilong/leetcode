//binary search 
/*
template <class ForwardIterator, class T>
  bool binary_search (ForwardIterator first, ForwardIterator last,  const T& val);

i.e. we could use STL function named binary_search(it1,it2, target)
*/

int binary_search(int array[], int first, int last, int search_key)
{
	int index;

	if (first > last)
		index = -1; // base condition?
	//this is the signal of does not find ?
	//because the first and last are always updated by the following recursion calls

	else
	{
		int mid = (first + last)/2;

		if (search_key == array[mid])
			index = mid;
		else{

			if (search_key < array[mid])
				index = binary_search(array, first, mid-1, search_key);
			//using the recursion calls to work as the updating statements
			//for parameters in while loop iteration
			else
				index = binary_search(array, mid+1, last, search_key);
		}

 } // end if
 	return index;
 }// end binarySearch

 //follow up: binary search in a rotated sorted array
 //binary search's precondition: must be sorted at first
 class Foo{
 public:
 	int search(int A[], int n, int target){
 		int first = 0, last = n;
 		while(first != last){
 			const int mid = (first+last) / 2;
 			if(A[mid] == target){
 				return mid;
 			}

 			if(A[first] <= A[mid]){
 				if(A[first] <=target && target < A[mid]){
 					last = mid;
 				}else{
 					first = mid+1;
 				}
 			else{
 				if(A[mid]<target && target <= A[last-1])
 					first = mid+1;
 				else
 					last = mid;
 			}

 			}
 		}
 		return -1;//after all the while loop still not found
 	}
 };
