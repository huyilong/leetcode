//first discard all the whitespace characters 
//in java here is a method named trim() ??
//the string could contain additional illegal chars after the legal numbers

//note: str[i] will return the ASCII value of the number
//if you want to convert it into a number value, we need to str[i] - '0'
//all the character could be represented with 128 specified characters in ASCII /aski/ table
//  A : 65     a : 97     0 : 48

/*
ASCII ( i/ˈæski/ ASS-kee), abbreviated from American Standard Code for Information Interchange, 
is a character-encoding scheme. Originally based on the English alphabet, it encodes 128 specified 
characters into 7-bit binary integers as shown by the ASCII chart on the right.
*/

class Foo{
public:
	int atoi(const char *str){
		int num = 0;
		int sign = 1;

		//const is similar to the "final" keyword in java
		const int n = strlen(str);
		//om c++ for c++ string we could use .length() or size()
		//but for c string it is not an object we could only use strlen(str)

		int index = 0;

		while(str[index] == ' ' && index < n)
		{
			++ index;//abbreviate all the whitespace before the first character
		}

		if(str[index] == '+')
		{
			++index;
		}

		if(str[index] == '-')
		{
			sign = -1;
			++index;
		}

		for(; index<n; ++index){
			//for the first non-space character 
			//check if it is legal, if not, directly return 0
			if(str[index] < '0' || str[index] > '9')
				break;
			//if(str[index] - '0' < 0 || str[index] - '0' > 9)

			//BEFORE ADDING THE LAST BIT OF NUMBER
			//we need to ensure that the number before is not larger than largest/10
			//or equal to largest/10 and the current bit exactly equals to the largest%10
			if(num > INT_MAX / 10 || (num == INT_MAX /10 && str[index]-'0' > INT_MAX % 10))
			{
				return sign == -1 ? INT_MIN : INT_MAX;
			}

			num = num*10 + (str[index] - '0');
		}

		return num * sign;
	}
}