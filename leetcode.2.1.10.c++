#include <iostream>
using namespace std;

//delete the target element and then return the new length of the array
class Solution {
public:
	int removeEle(int A[], int length, int ele)
	{
		int index=0;
		for(int i=0; i<length; ++i)
		{
			if(A[i]!=ele)
				A[index++]=A[i];
		}
		return index;
	}

};
//class is used for most of the methods and data
///although struct is default as public, it is used to aggregate only data

int main(int argc, char** argv)
{
	Solution A;
	int arr[5]={1,2,3,3,4};
	//array.size() is using the c++ 11 standard which is not supported by sublime2
	int result = A.removeEle(arr,5,3);

	//another method is to declare the static method in the class and then using the scope operator
	int result = Solution::removeEle(arr,5,3);


	cout<<result<<endl;
	return 0;
}