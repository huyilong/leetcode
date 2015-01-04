//dynamic-programming    bottom-up method
class Foo{
public:
	string longestPalindrome(string s){
		const int n = s.size();
		bool state[n][n];
		fill_n(&f[0][0], n*n, false);
		//using vector will exceed the time limit
		//vector<vector<bool>> state(n, vactor<bool> (n,false))

		size_t max_len = 1, start = 0;

		for(size_t i = 0; i<s.size();  ++i){
			state[i][i] = true;
			for(size_t j = 0 ; j<i; j++){
				state[j][i] = (s[j] == s[i] && (i-j<2 || state[j+1][i-1]);
					//max_len is defined outside the loop and be initialized with 0
					//each time will be compared with the new value and decide whether
					//to update max_len to new max value
					if(state[j][i] && max_len < i-j+1){
						//state[j][i] = true means [j,i] substring is a palindrome
						max_len = i-j+1;
						start = j;
					}
			}
		}

		return s.substr(start,  max_len);
	}
}