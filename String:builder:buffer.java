/*
String object is immutable whereas StringBuffer/StringBuilder objects are mutable.
String myString = “Hello”;
myString = myString + ” Guest”;
Although we made use of the same object(myString), internally a new object was created in the process.

To prove this,

String s = “Let’s test”;

s.concat(” if the String object is IMMUTABLE”);

System.out.println(s);

s = s.concat(” if the String object is IMMUTABLE”);

System.out.println(s);

The output of the above code will be:

Let’s test

Let’s test if the String object is IMMUTABLE


*/


/*
StringBuffer is synchronized( which means it is thread safe and hence you can use it when you implement 
threads for your methods) whereas StringBuilder is not synchronized( which implies it isn’t thread safe).

StringBuilder sb = new StringBuilder(“Hello”);

sb.append(” World”);

system.out.println(sb);

*/