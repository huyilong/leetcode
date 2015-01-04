//validate if a given string is numeric
class Foo{
public:
	enum InputType{
		INVALID, //0
		SPACE, //1
		SIGN, //2
		DIGIT, //3
		DOT //4
	};

	//directly use the STL strtod() to convert a string to double number
	bool isNumeric(char const *s){
		//attention: Parses the C-string str interpreting its content as a floating point number
		//therefore the c-string would be passed only by the head char pointer
		//const char *s

		char *endptr;
		strtod(s, &endptr);
		//strtod(endptr, &endptr2)
		//strtod(endptr2, null);

		//in the way above we could read three numbers in a string
		//endptr would point to the rest of the string after the first valid number

		/*
		Reference to an already allocated object of type char*, 
		whose value is set by the function to the next character in str after the numerical value.
		This parameter can also be a null pointer, in which case it is not used.

		char szOrbits[] = "365.24 29.53";
 		 char* pEnd;
 		 double d1, d2;

 		  d1 = strtod (szOrbits, &pEnd);

  		  d2 = strtod (pEnd, NULL);

  		  //d1 =365,24   d2 =29.53

  		  //A pointer to the rest of the string after the last valid character is 
  		  stored in the object pointed by endptr.
  		 */

  		 /*

  		 	this is different from atof() function, which could only read one number 

  		 	The rest of the string after the last valid character is ignored and has no 
  		 	effect on the behavior of this function.

  		 	and thus it could not be used to check for this problem
  		 */

  		if(endptr == s)//the last valid character is the beginning of the string itself
  			//i.e. does not scan any valid numeric num
  		return false;

  		for(; *endptr;  ++endptr){
  			if(!isspace(*endptr))
  				return false;
  		}//the function is only require one numeric number
  		//if there is anything rather than whitespace after the first valid number
  		//then return false

  		return true;

	}
}