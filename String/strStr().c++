//this is very important 
//return a pointer to the first char of the first occurrence of the needle in the haystack


//char[] str = "This is a simple str";
//char *cur;
//cur = strstr(str,"simple");
//strcpy(cur, "sample", 6);
//puts(str);    -> "This is a sample str"

class StrStr{
public:
	//because we will eventually return a pointer to the char 
	//O(N*M) where the haystack is N length and the needle is M length
	char *strStr(const char *haystack, const char *needle){
		//if the needle is empty then return the full string
		if(!*needle)
			return (char*) haystack;

		//using the const to constrain and promise not to alter the string
		const char *haystack_ptr;
		const char *needle_ptr;
		const char *haystack_advance_ptr = haystack;//this is just used to reduce the loop times

		//save time operation
		for(needle_ptr = &needle[1]; *needle_ptr; needle_ptr++){
			haystack_advance_ptr++; //advance the pointer for M-1 times
		}

		for(haystack_ptr = haystack; 
			*haystack_advance_ptr; 
			haystack_advance_ptr++)
		{

			//update the ptr of the record, which is according to the last statement
			char *haystack_record_first_char = (char*) haystack_ptr;
			//char * ptr = "hello"; 
			//does not need & operator to get the address of the c string char[] = "  "
			needle_ptr = needle;
			while(*needle_ptr == *haystack_ptr && *needle_ptr && *haystack_ptr){

				needle_ptr++;
				haystack_ptr++;
			}

			if(!*needle_ptr)//the needle_ptr is null and thus it is perfectly matched in the haystack
			{
				return haystack_record_first_char;
			}

			haystack_ptr = haystack_record_first_char + 1;//each time just move forward by 1 char

		}

		return nullptr;//if after all the rounds above still not found
	}
};