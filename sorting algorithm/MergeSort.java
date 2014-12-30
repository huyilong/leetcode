//o(nlogn)  no matter worse or average
//memory complexity: it depends

//http://www.princeton.edu/~achaney/tmve/wiki100k/docs/Merge_sort.html
void mergesort(int[] arr)
{
	int[] helper = new int[arr.length];
	mergesort(arr, helper, 0, arr.length-1);

}

//low is starting from 0! and thus if there is one part of the array still
//remaining, it must be the left part, i.e. the part starting from 0
void mergesort(int[] arr, int[] helper, int low, int high)
{
	if(low<high)
	{
		int middle = (low + high)/2;
		//sort the left half
		mergesort(arr, helper, low, middle);
		//sort the right half
		mergesort(arr, helper, middle+1, high);

		//because we calculate a new @param internally
		//we have to create a new internal interface to calculate
		merge(arr, helper, low, middle, high);
	}
}

void merge(int[] arr, int[] helper, int low, int middle, int high)
{
	//copy the whole array into the helper array
	//for the following 
	for (int i = low; i<=high; ++i)
	{
		helper[i] = arr[i];
	}

	int helperleft = low;
	int helperright = middle+1;
	//current is for reestablish the sorted arr which will be returned to the main
	int current = low;


	while(helperleft < =middle && helperright <= high){
		if(helper[helperleft] <= helper[helperright])
		{
			arr[current] = helper[helperleft];
			helperleft ++;
		}else{
			arr[current] = helper[helperright];
			helperright ++;
		}
		//must all the cursor be updated after one iteration
		//be careful!
		current ++;
	}

	//if one part is remaining, it must be the left part
	int remaining = middle - helperleft;
	for(int i=0; i <= remaining; i++)
	{
		arr[current+i] = helper[helperleft +i];
	}
}