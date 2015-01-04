class Foo{
	public:
		string simplifyPath(string const &path){
			vector <string> dirs;//used as stack

			for(auto i = path.begin(); i!=path.end(); ){
				++i;
				//for vector and dequeue we could not only use ++iterator
				//but also iterator+/-n
				//but for the list and forward_list 
				//these sequence container could only use advance/prev(it, distance)
				//or keep ++/-- without n

				auto j = find(i, path.end(), '/');
				//str.indexOf('sth') in java
				//auto j = find(it1, it2, 'sth')
				//str1.equals(str2) in java and strcmp in c-type string rather than c++!!!
				//str1.toLowerCase().contains(str2.toLowerCase())

				auto dir = string(i,j);//snippet of the string between /... /

				if(!dir.empty() && dir!='.'){
					if(dir=='..'){
						if(!dirs.empty())
							dirs.pop_back();
					}else{
						dirs.push_back(dir);
					}
				}
			}

			stringstream out;
			if(dirs.empty()){
				out<<"/";
			}else{
				for(auto dir : dirs){
					out<<"/"<<dir;//no endl in string stream!!!
					//string stream is used as string buileder in c++ and java
				}
			}

			return out.str();
		}
}