//1d DP
class Foo{
public:
	int treeNum(int n){
		//n is the elemento of data stored in BST
		vector<int> state(n+1, 0);
		//initialize the state
		state[0] = 1;
		state[1] = 1;

		for(int i=2; i<=2; ++i){
			for(int k = 1; k<=i; ++k){
				state[i] + = state[k-1] * state[i-k];
			}
		}

		return state[n];
	}
}