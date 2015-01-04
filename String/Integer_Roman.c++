class Foo{
/*

Both UTF-8 and UTF-16 are variable length encodings. However, 
in UTF-8 a character may occupy a minimum of 8 bits, while in 
UTF-16 character length starts with 16 bits.


Most reasonable characters, like Latin, Cyrillic, Chinese, Japanese can be represented with 2 bytes. 
Unless really exotic characters are needed, this means that the 16-bit subset of UTF-16 can be used 
as a fixed-length encoding, which speeds indexing.

Basic ASCII characters like digits, Latin characters with no accents, etc. occupy one byte which 
is identical to US-ASCII representation. This way all US-ASCII strings become valid UTF-8, 
which provides decent backwards compatibility in many cases.
No null bytes, which allows to use null-terminated strings, this introduces a great deal of 
backwards compatibility too.

*/
public:
	string intToRoman(int num){
		//L: 50 C: 100 D:500 M:1000
		//if from the left to the right the roman letter is ascending then use the 
		//latter minus the former will result in the final result
		//in the roman -> int program we need to offset this effect by minus 2*former num

		const int radix[] = {1000, 900, 500, 400, 100,90,50,40,10,9,5,4,1};
		const string symbol[] = {"M","CM", "D", "CD", "C", "XC", "L","XL","X","IX","V","IV","I"};

		string roman;
		for(size_t i = 0; num>0; ++i){
			int repeated_letter = num/radix[i];
			//the number for the next loop using different roman will be num% radix[i]
			//in roman the number is represented by repeated the letter like III = 3
			num% = radix[i];
			for(; repeated_letter>0; --repeated_letter){
				roman+ = symbol[i];
				//string is flexible and could be directly added even it is immutable
				//using the same roman letter for this current radix
			}

			return roman;


		}
	}
};
