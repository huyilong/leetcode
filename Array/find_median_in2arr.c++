//find the median of two sorted arrays
//if O(m+n) just merge two arrays and sorted
//also, we could not sort but just use pA and pB to point and compare each time

//but we could be faster for O(log(m+n))
//each time we would delete half of the arrays which will take full advantage of sorted two arrays
class Foo{
public:
	double findMed(int a[], int m, int b[], int n){
		total = m + n;

		return (findMed(a, m , b ,n ,total/2)) + findMed(a,m,b,n, total/2 + 1)) /2);
		//every time delete all the a[k/2 - 1] > b[k/2-1] ? a[k/2-1] : b[k/2-1] is safe
		//because if it does not larger than the median in the ther arr, it could not
		//possibly be the median of the two whole arrays
	}

private:
	static double findMed(int a[],int m, int b[], int n, int k){
		//k could be the median of 1st arr : (0+ total/2) / 2
		// the median of 2nd arr : (total/2 + 1 + total) / 2
		if(m>n)
			return findMed(b,n,a,m,k);
		//make sure that m must be less or equal to n 
		//if not use the recursion call to swap two pairs of parameters

		if(m == 0)
			return b[k-1];
		if(k==1)
			//one of the sub group only contains one num
			return min(a[0],  b[0]);//because we each time will delete and shorten the arrays by half
		//at the end we pass the arr which only have the length of 1 into next round of recursion
		//and then we will return min(a[0], b[0])

		//divide k into two parts
		int pa = min(k/2, m);
		int pb = k - pa;//we have make sure that m <= n
		if(a[pa-1] < b[pb-1])
			return findMed(a+pa, m-pa, b, n , k-pa);
		else if(a[pa-1 > b[pb-1]])
			return findMed(a, m, b+pb, n-pb, k-pb);
		else//they are equal to each other
			return a[pa-1];
	}
}