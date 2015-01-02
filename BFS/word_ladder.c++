//BFS could be bi-directional and could be single directional, which is the normal type
/*

start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

shortest transformation : hit -> hot -> dot -> dog -> cog  return 5

all words contain only lowercase alphabetic charactiers and only one letter can be changed at a time

*/

class Foo{
public:
	typedef string state;
	int ladderlen(string start, string end, const unordered_set<string> &dict)
	//which is hashset in java
	{
		if(start.size() != end.size())  return 0;
		//do not use else if : be careful
		if(start.empty() || end.empty())  return 0;

		queue<string> next, current;
		//used for different level, next level stored in one queue, and current level stored in another

		unordered_set<string> visited;
		//the hashset visited is used to avoid repetition
		unordered_map<string, string> parent;
		int level = 0;
		bool found = false;
		//push the start point string into the current queue
		current.push(start);

		//find the character key points of coding and memorize with skills
		while(!current.empty() && !found)
		{
			++level;
			while(!current.empty() && !found){
				//each time get the first string stored in current queue and then give to str
				const string first(current.front());
				//dump the front string in queue :: pop will not return anything
				current.pop();
				for(int i = 0; i < first.size(); ++i)
				{
					string new_word(first);
					for(char check = 'a'; check < = 'z'; ++check){
						if(check == new_word[i])
							continue;
						//loop until there is a position containing different value
						swap(check, new_word[i]);
						
						//if we touch down we will break and it will result in jump out two loops
						if(new_word == end)//we successfully touchdown
						{
							found = true;
							father[new_word] = first;
							break;
						}

						//we have not touchdown yet and therefore we need to 
						//push the current bar which is eligible because it is in the dict
						//into the queue
						if(dict.count(new_word) > 0 && !visited.count(new_word))
						{
							//for hashset we could use count() to judge if there is element in it
							//for queue in c++ we could use front(), pop() and push()
							next.push(new_word);
							//for hashset we need to use insert 
							visited.insert(new_word);
							parent[new_word] = first;
						}

						//resume the original word in new_word
						swap(check, new_word[i]);

					}
				}
				swap(next, current);//swapping the two queues? for each turn
			}
			if(found) return level+1;
			else return 0;
		}
	}

};