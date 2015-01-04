class Foo{
public:
	//21 is read off: 1211
	string countAndSay(int n)//find the nth in the sequence 1,11,21,1211....
	{
		string s("1");
		while(--n)
			s = getNext(s);

		return s;
	}

	string getNext(const string &s)//using the reference
	{
		stringstream ss;

		for(auto i =s.bigen(); i!=s.end(); ){
			auto j = find_if( i , s.end(), bind1st(not_equal_to<char>(), *i));

			ss<< distance(i, j)<<*i;  //for stringstream we do not use endl
			i = j ;
		}
			return ss.str();
			//similar to stringbuilder in java and return sb.toString();
			//because the file stored in stringstream and stringbuilder are no longer string type

			//binary function could be used as the callable object in algorithm
			//like bind2nd and bind1st and with type parameters

			//*i is the fixed value for the first parameter of not_equal_to binary function

			//find_if(l.rend(), l.rbegin(), ::isalpha);

			//bindfunction, used in find_if, count_if, find_if_not
			//bind one of the value fixed in the binary function like
			//i1,i2,  bind1st(  not_equal_to<char>(), 'c');

			//i1,i2, bind2nd(  greater<int>, 7);


			//find_if_not(l.begin(), l.end(), not_equal_to<char>(), *i);

			//count_if(l.begin(), l.end(), bind2nd(greater<int>(), 7));

			//for template must explicitly declare the type
			//copy(l.begin(), l.end(), ostream_iterator<int> (cout, " "));


		}
	};
}