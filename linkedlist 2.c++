/*
Linked Lists

Just like the vector, the standard list is a template.
You can use push_back to add elements to the list.
list<string> staff;

staff.push_back("Cracker, Carl");
staff.push_back("Hacker, Harry");
staff.push_back("Lam, Larry");
staff.push_back("Sandman, Susan");
You cannot directly access elements using subscript access (e.g. staff[3]).
Instead you must start at the beginning of the list, and visit each element in turn using a list iterator.
list<string>::iterator pos;
pos = staff.begin();

To insert another string before the iterator position, use the insert function.
staff.insert(pos, "Reindeer, Rudolph");
*/

 #include <string>
 #include <list>
 #include <iostream>
 
 using namespace std;
 
 int main()
 {  
    list<string> staff;

   staff.push_back("Cracker, Carl");
   staff.push_back("Hacker, Harry");
   staff.push_back("Lam, Larry");
   staff.push_back("Sandman, Susan");

  /* add a value in fourth place */
   //or you can directly use auto to declare the cursor or iterator

 ////// list<string>::iterator pos;
 ////// pos = staff.begin();

//////using the following auto iterator instead, very convenient
   auto pos = staff.begin();


   pos++;
   pos++;
   pos++;


////////for insert function, the first param is the location, i.e. the address
   staff.insert(pos, "Reindeer, Rudolf");
   /* remove the value in second place */

   pos = staff.begin();
   pos++;


//////////for erase function, its parameter is also an iterator, i.e. an address rather than value
   staff.erase(pos);

   /* print all values */

 	for (pos = staff.begin(); pos != staff.end(); pos++)
     cout << *pos << "\n";

    return 0;
 }

