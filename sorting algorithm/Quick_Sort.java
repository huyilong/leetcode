//O(nlogn) and worst O(n^2)  :: which is not good as merge sort because this one
//quick sort need some luck, because the middle one is not guaranteed to be the median
//actually we are supposed to randomly pick up a value and then repeatedly swap
//but to be specific we just pick up the middle one

void quickSort(int arr[], int left, int right)
{

	/*
	The main idea is to find the “right” position for the pivot element
 	After each “pass”, the pivot element, P, should be “in place”.
 	Eventually, the elements are sorted since each pass puts at least one 
	element (i.e., P) into its final position.
	*/

	int index = partition(arr, left, right);

	//sort the left part
	if(left<index-1)
	{
		quickSort(arr, left, index-1);
	}
	if(index < right)
	{
		quickSort(arr, index, right);
	}
}

int partition(int arr[], int left, int right)
{
	//pick up the pivot element, here we just use the middle one
	//actually it is randomly picked
	int pivot = arr[(left+right)/2];
	//we begin to compare and swap until these two cursors collide in the middle
	while(left<=right)
	{
		while (arr[left]<pivot)   left++;//when it stopped, the cursor points to the target
		while (arr[right]>pivot)  right--;

		if(left<=right){
			swap(arr, left, right);
			left++;
			right--;
		}
	}

	//ok : now we return the left, which is actually in the middle to the quickSort
	//function and let it equal to index -> then we can partition more sub arrays
	return left;
}

/*
this example is for the pivot element just picked as first element rather than the middle

65 70 75 80 85 60 55 50 45
P: 65
i
Pass 1: 65 70 75 80 85 60 55 50 45
(i)
i j
Å swap (A[i], A[j])
65 45 75 80 85 60 55 50 70
(ii)
i j
Å swap (A[i], A[j])
65 45 50 80 85 60 55 75 70
(iii)
i
j
Å swap (A[i], A[j])
65 45 50 55 85 60 80 75 70
(iv)
i
j
Å swap (A[i], A[j])
65 45 50 55 60 85 80 75 70
(v)
j
i if (i>=j) break
60 45 50 55 65 85 80 75 70 swap (A[left], A[j])