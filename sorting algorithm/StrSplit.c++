/*
c-string is more flexible and has many methods to manipulate

int atoi (const char * str);

Convert c-string to integer
this method is regarding to c-string instead of c++ string
Parses the C-string str interpreting its content as an integral number, 
which is returned as a value of type int.

/////////////split up the c-string
char * strtok ( char * str, const char * delimiters );

On a first call, the function expects a C string as argument for str, 
whose first character is used as the starting location to scan for tokens. 

/////////////////////////////////////////
In subsequent calls, the function expects a null pointer and uses the position
right after the end of the last token as the new starting location for scanning.
/////////////////////////////////////////

Split string into tokens
A sequence of calls to this function split str into tokens, which are sequences of contiguous 
characters separated by any of the characters that are part of delimiters.

///the first @param is the container and the second @param is used to fill up the first one
strcpy(cstr, str.c_str());

convert the c++ string to c-string    str.c_str();

#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="- This, a sample string.";
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);

  pch = strtok (str," ,.-");

  while (pch != NULL)
  {

    printf ("%s\n",pch);
    pch = strtok (NULL, " ,.-");
  }
  return 0;
}
*/


class StrSplit {

public:
    vector<int> split(string str) {
        vector<int> ret;

        //dynamic memory in the cstr 
        char* cstr = new char[str.length() + 1];

        strcpy(cstr, str.c_str());
        
        char* pch = strtok(cstr, ".");
        //whenever there is a remaining "."
        while (pch != NULL) {
        	//before push into the vector/arraylist
        	//we need to firstly convert the c-string to the int type 
        	//using atoi(c-string)
            ret.push_back(atoi(pch));

            //get the next token in the string by 
            //using the delimiter of "."
            pch = strtok(NULL, ".");
            /*
            actually we could use the multiple delimiters within the second @param
             pch = strtok (str," ,.-");
             which could successfullt delimit 
             char str[] ="- This, a sample string."

             and this method will only return the tokens without the delimiters themselves
             */
        }
        ///never forget to delete the pointer after using it
        //if you did not use the dynamic memory with smart pointer
        //if it is an array of pointer you need to delete[] cstr;
        delete[] cstr;
        return ret;
    }
    
    int compareVersion(string version1, string version2) {
        vector<int> nums1 = split(version1);
        vector<int> nums2 = split(version2);

        //max and min do not require extra package to import
        //try to find which version has more tokens split by "."
        int len = max(nums1.size(), nums2.size());
        
        for (int i = 0; i < len; ++i) {

        	//the following logic is really fantastic 
        	// i < len ? nums[i] : 0
        	// the return value would be irrevalent with the statement before ?
        	// but either nums[i] or 0
        	// if the shorter one is examined and it is not as long as the longer one
        	// then the extra places are replaced with number 0
            int num1 = i < len ? nums1[i] : 0;
            int num2 = i < len ? nums2[i] : 0;
            
            if (num1 > num2) {
                return 1;
            } else if (num1 < num2) {
                return -1;
            }
        }
        
        return 0;
    }
};
