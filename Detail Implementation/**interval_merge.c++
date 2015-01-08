//at this time we will repeatedly call the insert interval function
//for each interval in the given group 
//which will implementation the fulfillment of merge all the intervals

struct Interval{
	int start;
	int end;
	Interval(): start(0) , end(0){}
	Interval(int s, int e): start(s), end(e){}
};

class Bar{
public:
	vector<Interval> mergeIntervals(vector<Interval> &input_intervals){
		vector<Interval> merge_result;
		for (int i=0; i<input_intervals.size(); ++i){
			insert(merge_result, input_intervals[i]);

			//for each interval in the input intervals
			//we will repeatedly call the function before
			//and create the new merge_result
		}

		return merge_result;
	}

private:
	vector<Interval> insert(vector<Interval> &merge_result, Interval input_interval){
		auto it = merge_result.begin();
		while(it!=merge_result.end()){

			if(input_interval.end < it->start){
				merge_result.insert(it, input_interval);
				return merge_result;
			}

			else if(input_interval.start > it->end){
				++it;
				continue;
			}

			else{
				input_interval.start = min(input_interval.start, it->start);
				input_interval.end = max(input_interval.end, it->end);
				it = merge_result.erase(it);
			}
		}

		merge_result.insert(merge_result.end(), input_interval);
		return merge_result;
	}
}