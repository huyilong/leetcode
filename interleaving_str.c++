//交叉存储技术 也就是当前存储的奇数地址和偶数地址分开  这样当前字节被刷新时 可以不影响下一个字节的访问
// T=O(n^2)   S=O(n^2)
class Bar{
public:
	bool Success(string s1, string s2, string s3){
		if(s3.length()! = s1.length() + s2.length())
			return false;
		// y = s1.length()+1, x = s2.length()+1, all true
		// why both rows and columns have to be one more ??? 
		vector< vector<bool> > state(  s1.length()+1, vector<bool> (s2.length()+1, true));

		for(int i=1; i< s1.length(); ++i)
		{
			state[i][0] = ( state[i-1][0] && s1[i-1] == s3[i-1] );
		}

		for(int j=1; j < s2.length(); ++j)
		{
			state[0][j] = ( state[0][j-1] && s2[j-1] == s3[j-1]);
		}
		//the operations above are account for the one more row and column in the 2d matrix
		//i.e. these are basic states which will get into the logic calculation in the
		//following state transfer equation

		for(int i=1; i< s1.length(); ++i)
			for(int j=1; j < s2.length(); ++j)
				state[i][j] = (s1[i-1] == s3[i+j-1] && state[i-1][j]) && (s2[j-1] == s3[i+j-1] && state[i][j-1]);
	}
};

class Foo{
public:
	bool Success(string s1, string s2, string s3){
		if(s3.length()! = s1.length() + s2.length())
			return false;

		return Success(begin(s1),end(s1),begin(s2),end(s2),begin(s3),end(s3));
	}

	template<typename It>
	bool Success(It f1, It e1, It f2, It e2, It f3, It e3)
	{
		if(f3 == e3)
			return f1 == e1 && f2 == e2;
		return (*f1 == *f3 && Success(next(f1),e1,f2,e2,next(f3),e3))
					|| (*f2 == *f3 && Success(f1,e1,next(f2),e2,next(f3),e3));
	}

};