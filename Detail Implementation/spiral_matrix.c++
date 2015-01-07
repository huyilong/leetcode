//note: we need clockwise and from outer to inner
class Foo{
public:
	//final result is a 1d sequential sequence for printing out the spiral order traversal
	vector<int> spiralOreder(vector<vectro<int>> &matrix){
		vector<int> result;
		if(matrix.empty())
			return result;
		int beginX = 0, endX = matrix[0].size()-1;
		int beginY = 0, endY = matrix.size()-1;

		while(true){
			for (int j = beginX; j <= endX; ++j){
				result.push_back(matrix[beginY][j]);
			}
			if(++beginY > endY)
				break;

			for(int i = beginY; i<= endY; ++i){
				result.push_back(matrix[i][endX]);
			}
			if(beginX > --endY)
				break;

			for(int j = endX; j>=beginX; --j){
				result.push_back(matrix[endY][j]);
			}
			if(beginY > --endY)
				break;

			for(int i = endY; i >=beginY; --i){
				result.push_back(matrix[i][beginX]);
			}
			if(++beginX > endX)
				break;
		}
	}
}