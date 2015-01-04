//for c string i.e. an array of characters
//we could use a pointer without ptr = ptr->next
//but just ptr++ to move forward and also judge whether it touchdown by using *ptr as middle condition

class Foo{
public:
	int lengthOfLastWord(const char *s){
		int len = 0 ;
		while(*s){
			if(*s++ != ' ')
				++len;

			else if(*s && *s != ' ')
				len = 0 ;//we reaches the next word in the string
		}

		return length;
	}
};


//using STL, which would save tons of time 
class Bar{
public:
	int lengthOfLastWord(const char *s){
		//whenever it is passed with a char *ptr, we know it is c type string
		//i.e. an array of chars with '\0' at the end
		const string str(s);
		//because for c++ string it is a new object and type which is not built-in
		//we could not use == without override the operator, so we use strcmp(str1,str2) == 0
		auto first = find_if(str.rbegin(), str.rend(), ::isalpha);
		//str.rbegin() does not equal to str.end(), which is null actually
		auto last = find_if_not(first, str.rend(), ::isalpha);

		return distance(first, last);//we could not directly minus two iterator to get the distance
	}
};

