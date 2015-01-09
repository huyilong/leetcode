//given height = [2,1,5,6,2,3]
//every width will be 1
//and then the largest rectangle in histogram would be (5+6-1)*(1+1)=10

class Foo{
public:
	int largestRec_Histogram(vector<int> &height_arr){
		stack<int> s;
		//in c++ we do not need constructor we just declare the variable name
		//then the constructor would be called automatically
		height_arr.push_back(0);
		//in vector we could use the random iterator
		//i.e. [] to visit which ensure the visit time is a constant
		int result = 0;
		for(int i=0; i<height_arr.size(); )
		{
			//that is why we need to push _back(0) at first?
			//we must gurantee that the top of the stack is always the biggest one 
			//i.e. it is an increasing stack
			if(s.empty() || height_arr[i] > height_arr[ s.top() ]){
				s.push(i++);
				//in for loop we do not have i++
				//we firstly put i and then i++ for next loop
				//that is in else we do not need i++
			}
			else{
				//for stack we must use a variable to contain the value of the element
				//because read and remove have two operations
				int temp = s.top();
				s.pop();
				//each time we will recompare the values we get so far
				//and update the value of result by using max function
				result = max(result, height[temp] * (s.empty() ? i : i-s.top()-1 ));
			}
		}
	}
}