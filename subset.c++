class Foo{
public:
	vector <vector<int>> subsets(vector<int> &s)
	{
		sort(s.begin(),s.end());
		vector<vector<int>> 2d;
		vector<int> 1d;
		subsets(s,1d,0,2d);
		return 2d;
	}

private:
	static void subsets(const vector<int> &s,vector<int> &1d, int step, vector<vector<int>> &2d)
	{
		if(step == s.size())
		{
			2d.push_back(1d);
			return;
		}
	}
	//choose s[step] in the subsets
	subsets(s, 1d, step+1, 2d);

	//not choose s[step] in the subsets
	p1d.push_back(s[step]);
	subsets(s, 1d, step+1, 2d);
	1d.pop_back();

};