//num = {2,7,11,15}  target = 9
//return: index1=1, index2=2 (2+7=9)

class Foo{
public:
	vector<int> twoSum(vector<int> &num, int target){
		unordered_map<int, int> hash_map;
		vector<int> result;

		//store the index as the value in the new hashmap
		//and the value in the original array would be the index in hashmap
		for(int i = 0; i<num.size(); ++i){
			hash_map[ num[i] ] = i;
		}

		for(int i=0; i<num.size(); ++i){
			const int gap = target - num[i];

			if(hash_map.find(gap) != hash_map.end()){
				//this is very important
				//find in hash_map: hash_map.find(gap) != hash_map.end()
				//find in string: string.indexOf(target) != -1
				//hash_map.end() is used as null or -1 in other search

				result.push_back(i+1);
				result.push_back(hash_map[gap] + 1);
				break;
			}
		}

		return result;
	}
} 