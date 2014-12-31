//hashmap and hashset will not store and 

import java.util.*;
public class HashSetDemo {

   public static void main(String args[]) {
      // create a hash set
      HashSet hs = new HashSet();
      // add elements to the hash set
      //for hashmap we need to use put and get
      //it is hashset and just used as an arraylist 
      //so we use add instead of put
      hs.add("B");
      hs.add("A");
      hs.add("D");
      hs.add("E");
      hs.add("C");
      hs.add("F");
      //we could directly print out without using any iterator
      //just print out the hashset's name
      System.out.println(hs);
   }
}

HashSet is much faster than TreeSet (constant-time versus log-time for most operations like add, 
   remove and contains) but offers no ordering guarantees like TreeSet.

HashSet:
class offers constant time performance for the basic operations (add, remove, contains and size).
it does not guarantee that the order of elements will remain constant over time
iteration performance depends on the initial capacity and the load factor of the HashSet.
It's quite safe to accept default load factor but you may want to specify an initial capacity that's 
about twice the size to which you expect the set to grow.

TreeSet:
guarantees log(n) time cost for the basic operations (add, remove and contains)
guarantees that elements of set will be sorted (ascending, natural, or the one specified by you via its 
   constructor)
doesn't offer any tuning parameters for iteration performance
offers a few handy methods to deal with the ordered set like first(), last(), headSet(), and tailSet()


Important points:
Both guarantee duplicate-free collection of elements

It is generally faster to add elements to the HashSet and then convert the collection to a TreeSet 
for a duplicate-free sorted traversal.

None of these implementation are synchronized. That is if multiple threads access a set concurrently, 
and at least one of the threads modifies the set, it must be synchronized externally.

LinkedHashSet is in some sense intermediate between HashSet and TreeSet. Implemented as a hash table 
with a linked list running through it, however it provides insertion-ordered iteration which is not same
as sorted traversal guaranteed by TreeSet.

So choice of usage depends entirely on your needs but I feel that even if you need an ordered collection 
then you should still prefer HashSet to create the Set and then convert it into TreeSet.

e.g. SortedSet<String> s = new TreeSet<String>(hashSet);