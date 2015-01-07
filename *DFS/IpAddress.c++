class Foo{
	public: vector<string> restoreIpAdr(string s){
		//"25525511135" -> "255.255.11.135" & "255.255.111.35"
		vector<string> result;
		string ip;// one of the possible possibility
		dfs(s, 0, 0, ip, result);
		return result;
	}

	/**
	 * @brief read the string and return all possible ip addresses
	 * @param[in] s is input string
	 * @param[in] startIndex is where the checking begins
	 * @param[in] step is the current step starts from 0, when hits 4 it ends
	 * @param[out] ip is one possibility to store intermediate result
	 * @param[out] result is the group of all valid possibilities
	 * @return void
	 * @author Aaron
	 */
	void dfs(string s, size_t start, size_t step, string ip, vector<string> &result){
		if(start==s.size() && step == 4)
		{
			//valid ip has 4 parts where each part value less than 255
			ip.resize(ip.size()-1);
			result.push_back(ip);
			return;
		}

		if(s.size()-start > (4-step)*3)
			return;
		if(s.size()-start < (4-step))
			return;
		//illegal error and prune
		//cannot recursion into off-limit area

		//each time for a new recursion reset the num = 0
		int num=0;
		for(size_t i = start; i<start+3; ++i){
			num = num*10 + (s[i] - '0');//read each bit in the string and convert it into decimal
			//each time have to move left by *10

			if(num<=255){
				//legal possibility
				ip+ = s[i];
				dfs(s,i+1.step+1, ip+'.', result);
			}

			//!!!!!cannot have multiple zeros between dot
			if(num == 0) break; 
		}
	}
}