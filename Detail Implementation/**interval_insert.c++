struct Interval_encapsulation{
	int start;
	int end;

	//first default constructor
	Interval_encapsulation(): start(0) , end(0) {}
	//actually constructor {} could also get sth
	//we could according to the complex calculation
	//which is based on constructor and directly print it out
	//and when we initilize this A a; it will call the constructor and print out 0 (default value)

	Interval_encapsulation(int s, int e): start(s), end(e)  {}
};

class Foo{
	public:
		vector<Interval_encapsulation> insertInterval(vector<Interval_encapsulation> &existed_intervals
															Interval_encapsulation input_interval)
		{
			auto it = existed_intervals.begin();
			//it is actually the address of the struct??
			//using it->start to visit the field within the struct?

			while(it != existed_intervals.end()){

				//version 1
				if(input_interval.end < it->start){
					//this condition we could directly insert
					existed_intervals.insert( it, input_interval);
					return existed_intervals;
					//this return will apply to the first if and last else
				}
				//version 2
				else if(input_interval.start > it->end){
					//this is not a proper insertion point
					//we need to go forward to find a new position
					it++;	
					//we better do advance(it,1) or next(it)
					continue;
					//go next while and check if at first
				}
				//version 3
				else{
					//this time we actually have overlapping with existed intervals
					//we need to merger these overlappings
					//we need to create a new one and update its start and end
					//meanwhile we need to erase off the existed narrow interval
					input_interval.start = min(input_interval.start, it->start);
					input_interval.end = max(input_interval.end, it->end);

					//we could actually repeatedly erase
					//because when we call erase(addr) we will get a return pointing to the next val
					//after the point of deletion
					it = existed_intervals.erase(it);
				}
			}

			//after the whole while looping 
			//if the case is version 2 i.e. always continue until it = existed_intervals.end()
			//we will just insert it at the end, when it at this time pointing to the end

			existed_intervals.insert(existed_intervals.end(), input_interval);
			return existed_intervals;


		}
};