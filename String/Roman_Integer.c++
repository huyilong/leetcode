class Foo{
public:
	inline int map(const char input_roman){
		switch(input_roman){
			case 'i': return 1;
			case 'v': return 5;
			case 'x': return 10;
			case 'l': return 50;
			case 'c': return 100;
			case 'd': return 500;
			case 'm': return 1000;
			default: return 0;
		}
	}

	int romanToInt(string s){
		int result = 0;
		for(size_t i=0; i<s.size();++i){
			if(i>0 && map(s[i])> map(s[i-1])){
				//this is from left to right and ascending order
				result + = (map(s[i]) - 2*map(s[i-1]));
				//we need to consider the offset so that it is indeed use the right minus left
			}else{
				result + = map(s[i]);
			}
		}
		
		return result;
	}
}