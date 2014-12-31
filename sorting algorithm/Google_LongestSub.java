//Given a string, find the longest substring that contains only two unique characters.
// For example, given "abcbbbbcccbdddadacb", the longest substring that contains 2 unique character 
//is "bcbbbbcccb".

//no matter linkedlist, arraylist or hashset, they are all not thread-safe
//and could only depend on external synchronization
public static String subString(String s) {
	// checking
 	//this is very useful to create a new copy of array
 	//by converting the string in java to an array of characters
 	//char[] arr = s.toCharArray();
	char[] arr = s.toCharArray();
	int max = 0;
	int j = 0;
	int m = 0, n = 0;
 
	HashSet<Character> set = new HashSet<Character>();
	set.add(arr[0]);
 

 	//ArrayList和LinkedList之间的数据传递可通过toArray（）方法。
 	//using the set's property: it contains no duplicates
 	//but arraylist / linked list could have duplicates
	for (int i = 1; i < arr.length; i++) {
		if (set.add(arr[i])) {
			//just keep the set size remain 2
			//and keep updating the current max length
			if (set.size() > 2) {
				String str = s.substring(j, i);
 
				//keep the last character only
				set.clear();
				set.add(arr[i - 1]);
 
				if ((i - j) > max) {
					m = j;
					n = i - 1;
					max = i - j;
				}
 
				j = i - helper(str);
			}
		}
	}
 
	return s.substring(m, n + 1);
}
 
// This method returns the length that contains only one character from right side. 
public static int helper(String str) {
	// null & illegal checking here
	if(str == null){
		return 0;
	}
 
	if(str.length() == 1){
		return 1;
	}
 
	char[] arr = str.toCharArray();
	char p = arr[arr.length - 1];
	int result = 1;
 
	for (int i = arr.length - 2; i >= 0; i--) {
		if (p == arr[i]) {
			result++;
		} else {
			break;
		}
	}
 
	return result;
}


/*

Here is a scalable solution i.e. we could define the k by ourselves instead of 2.

static int findMaxKCharSubstring(String s, int k){
	char[] arr = s.toCharArray();
	int max = 0;
 
	if (arr.length > 0){
		Set<Character> set = new HashSet<Character>();
 
		char c = arr[0];
		set.add(c);
 
		int i = 0;//index
		int currentCount = 0;
 
		while (i < arr.length){
			char temp = arr[i];
			if (!set.contains(temp)){
 
				if (set.size() < k){
					set.add(temp);
					currentCount++;
					i++;
				}else{
					max = Math.max(currentCount, max);
 
					//reset
					currentCount = 0;
					i--;
 
					char keep = arr[i];//keep the right most one
					set.clear();
					set.add(keep);
					set.add(temp);
 
					while (i >= 1){
						if (arr[i - 1] == keep){
							i--;
						}else{
							break;
						}
					}
				}
			}else{
				currentCount++;
				i++;
			}
		}
 
		if (currentCount > max){
			max = currentCount;
		}
	}
 
	return max;
}
*/