#define HAYSTACK_SIZE 50
#define NEEDLE_SZ 10
#include <iostream>
#include <string>

using namespace std;

//also known as haystack and needle problem
//must think comprehensively and think thoroughly before typing code
//firstly analyze on the paper and list some simple examples
char *strstr(const char *haystack, const char *needle)
{
	//whenever handle a problem must get out of more from it rather than hurry to next problem
	//if needle it self is empty then return the full string
	if(!*needle) return (char*) haystack;

	const char *p1;
	const char *p2;
	const char *save_time;

	for(p2 = &needle[1]; *p2; ++p2)
	{
		save_time++; // advance the ptr M-1 times where the length of substring is m
		//and the original string is n thus the time complex is O(n*m)
	}

	for(p1 = haystack; *save_time; save_time++)
	{
		//updating p1_record with new p1 each iteration
		char *p1_record = (char*) p1;

		p2 = needle;  // which is equal to p2 = &needle[0]
		while (*p1 && *p2 && *p1 == *p2)
		{
			++p1;
			++p2;
		}
		if(!*p2) return p1_record; // i.e. the substring's ptr has gone to null and it is completedly matched

		p1 = p1_record + 1;
	}

	return NULL; // after the whole iteration there is still no match then return null
}

int main(void)
{
	// how to initilize the c type string i.e. an array of char ended with \0 ?
	// note: for c string and c++ string we both could use [] to visit the data stored in it
	char haystack[HAYSTACK_SIZE] = "zzzzzzzhelzzzhellzzhellozzzzz";
	//use the following expression will result in a warning
	//char * needle = "hello";
	char needle[NEEDLE_SZ] = "hello";

	cout<< needle << endl;
	cout<< *needle << endl;

	//char * find = strstr(&haystack[0], &needle[0]);
	char * find = strstr(haystack,needle);
	//if(!find)
	//this is wrong because the address of find will always be nen-zero
	if(!*find)
	{	
		cout<<find<<endl;
	}
	return 0;

}

/*
Signal 11, or officially know as "segmentation fault", 
means that the program accessed a memory location that was not assigned.
 That's usually a bug in the program. So if you're writing your own program, 
 that's the most likely cause. 
 */