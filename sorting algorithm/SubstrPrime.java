import java.util.*;
import java.io.*;

//if you want to declare multiple class within a java file 
//only one with main function could be public, others must be encapsulated as non modifier

/*
Yes, it can. However, there can only be one public class per .java file, as public classes must 
have the same name as the source file.

The purpose of including multiple classes in one source file is to bundle related support 
functionality (internal data structures, support classes, etc) together with the main public class. 
Note that it is always ok not to do this -- the only effect is on the readability (or not) of your code.
*/

class IsPrime{
    //checks whether an int is prime or not.
    public boolean isPrime(int n) {
       if(n==2)   return true;
    //check if n is a multiple of 2
       if (n%2==0 && n!=2) return false;
    //if not, then just check the odds

    //attention: because we have checked if(n%2) here we only need to check i = i+2
    //just check the odd factor is enough because it is already could not be an even num
    //and thus could not possibly be divisible (no remainder) by an even num
    //just check until the factor's square is equal to n is enough
       for(int i=3;i*i<=n;i=i+2) {
        if(n%i==0)
            return false;
     }
     return true;
    }
}

//全选后进行 command+/ 可以全部comment out
//全选后进行tab 可以全部向后错移
public class SubstrPrime
{
    public static void main(String[] args)
    {
        IsPrime obj = new IsPrime();
        //brute-force search method
        //enumeration
        System.out.println("isPrime(2)? "+obj.isPrime(2));
        String test = "213";
        //the final result should be 13, which is the biggest substring and prime number
        int input = Integer.parseInt(test);
        //if here is an array then the size should be arr.length without the brackets ()
        int length = test.length();

        HashMap length_prime = new HashMap();
        TreeMap<Integer,Integer> length_prime_sorted = new TreeMap<Integer,Integer>();
        //brute-force search to check every substring

        for(int start_ptr=0; start_ptr<length; ++start_ptr)
        {
            for(int window_size=1; window_size <= length - start_ptr; ++window_size)
            {
                String sub = test.substring(start_ptr, start_ptr+window_size);
                System.out.println(sub);
                int target =  Integer.parseInt(sub);

                if(obj.isPrime(target))
                {
                   length_prime.put(sub.length(), target);
                   length_prime_sorted.put(sub.length(), target);
                }
            }
        }

        //there is no such a method for just get the lowest key or highest key
        //in hashmap but the following could help you find the highest value
        //because it is the same disadvantage in hashmap and treemap

        //conversely, if you just want to find the higherst key and lowest key
        //just use the treemap and use  treeMap.firstKey() to get the lowest
        //and  treeMap.lastKey() to get the highest

        //attention: you could use treemap and swap the key and value to solve problem

        /*

        Entry<String,Integer> maxEntry = null;
        for(Entry<String,Integer> entry : uniqueNames.entrySet()) {
        if (maxEntry == null || entry.getValue() > maxEntry.getValue()) {
             maxEntry = entry;
            }
        }
        
        // maxEntry should now contain the maximum,
        */

        //this is only used in printing out because you cannot do many things without iterator
        for(Object i : length_prime.keySet())
        {
            System.out.println( "key(length): " + i + " value(prime_num): "+ length_prime.get(i) );
        }

        //we do not need to force the Object returned using (int) to cast down
        //because instead of declaring HashMap length_prime = new HashMap();
        //which omits the parameter list of the template
        //here we explicitly declared the parameter list
        //TreeMap<Integer,Integer> length_prime_sorted = new TreeMap<Integer,Integer>();
        int result_key = length_prime_sorted.lastKey();
        int result_value = length_prime_sorted.get(result_key);

        System.out.println("the longest prime substring of 213 is " + result_value);
        /*
        Set setOfKeys = length_prime.keySet()
        Iterator iterator = setOfKeys.iterator();
        
        for(iterator.hasNext())
        {
            String key = (String) iterator.next();
            Integer value = (Integer)map.get(key);
            System.out.println("Key: "+ key+", Value: "+ value);
        }
        */

        /*
        public static void printMap(Map mp) {
             Iterator it = mp.entrySet().iterator();
             while (it.hasNext()) {
                 Map.Entry pairs = (Map.Entry)it.next();
                 System.out.println(pairs.getKey() + " = " + pairs.getValue());
                 it.remove(); // avoids a ConcurrentModificationException
            }
        }
        */

        /*
        for (Map.Entry<String, String> item : params.entrySet()) {
             String key = item.getKey();
             String value = item.getValue();
        }
        */
        /////there is entrySet() and keySet() but no valueSet() !!!!!

    }
}

//using brute-force search
//it is realated to find all the possible substrings of a given String
/*

import java.util.Scanner;
 
class SubstringsOfAString
{
   public static void main(String args[])
   {
      String string, sub;
      int i, c, length;
 
      Scanner in = new Scanner(System.in);
      System.out.println("Enter a string to print it's all substrings");
      string  = in.nextLine();
 
      length = string.length();   
 
      System.out.println("Substrings of \""+string+"\" are :-");
 
      for( c = 0 ; c < length ; c++ )
      {
         for( i = 1 ; i <= length - c ; i++ )
         {
            sub = string.substring(c, c+i);
            System.out.println(sub);
         }
      }
   }
}
*/