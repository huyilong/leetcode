        //there is no such a method for just get the lowest key or highest key
        //in hashmap but the following could help you find the highest value
        //because it is the same disadvantage in hashmap and treemap

        //conversely, if you just want to find the higherst key and lowest key
        //just use the treemap and use 

        //treeMap.firstKey() to get the lowest
        //treeMap.lastKey() to get the highest

        //attention: you could use treemap and swap the key and value to solve problem

        /*

        Entry<String,Integer> maxEntry = null;
        for(Entry<String,Integer> entry : uniqueNames.entrySet()) {
        if (maxEntry == null || entry.getValue() > maxEntry.getValue()) {
             maxEntry = entry;
            }
        }

        //in treeMap there are many useful methods API
        ceilingKey(K key)
        Returns the least key greater than or equal to the given key, or null if there is no such key.

        floorKey(K key)
        Returns the greatest key less than or equal to the given key, or null if there is no such key.

        containsValue(Object value)
        Returns true if this map maps one or more keys to the specified value.

        containsKey(Object key)
        Returns true if this map contains a mapping for the specified key.

        higherKey(K key)
        Returns the least key strictly greater than the given key, or null if there is no such key.

        lowerKey(K key)
        Returns the greatest key strictly less than the given key, or null if there is no such key.

        values()
        Returns a Collection view of the values contained in this map

*/


package com.tutorialspoint;

import java.util.*;

public class HashMapDemo {
   public static void main(String args[]) {
      // create hash map
      HashMap newmap = new HashMap();      
      
      // populate hash map
      newmap.put(1, "tutorials");
      newmap.put(2, "point");
      newmap.put(3, "is best");
      
      // checking collection view of the map
      System.out.println("Collection view is: "+ newmap.values());
   }    
}

//Collection view is: [tutorials, point, is best]



import java.util.Collection;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class Main {
  public static void main(String[] a) {
    Map<String,String> map = new HashMap<String,String>();
    map.put("key1", "value1");
    map.put("key2", "value2");
    map.put("key3", "value3");

    //here it is the map.values() which will return a set of values
    Collection set = map.values();
    //must declare explicitly the type of the iterator i.e.   set.iterator()
    Iterator iter = set.iterator();

    while (iter.hasNext()) {
      System.out.println(iter.next());
    }
  }