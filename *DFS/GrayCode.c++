//gray code generated from the binary bit code
//the MSD(most significant digit) will be the same
//and then repeadtedly apply ^ between the neighboring two bits in the natural bits to generate nth gray code

class Foo{
public:
	vector<int> grayCode(int n){
		vector<int> result;
		const size_t size = 1<<n; //make this as the MSD by moving it left by n bits
		result.reserve(size);
		//the final result group at least contains this amount of results
		for(size_t i = 0; i<size; ++i){
			result.push_back(binary_to_gray(i));
			//each time generate a new LSD based on the two bits in natural binary code
		}

		return result;
	}

private:
	static unsigned int binary_to_gray(unsigned int n){
		return n ^ (n>>1);
		//regarding the input decimal n as the binary bits representation
		//by applying bit manipulation
	}

	static unsigned int gray_to_binary(unsigned int g){
		for(unsigned int mask = g >> 1; mask!=0; mask = mask >>1){
			g = g ^ mask;
		}
		return g;
	}

}