      
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import java.util.ArrayList;

public class KeySet_HashMap {
  public static void main(String[] args) {

    Map<Integer, String> map = new HashMap<Integer, String>();
    //in treemap the key is sorted automatically by ascending order
    TreeMap<String, String> tmp = new TreeMap<String, String>();

    //map.put(new Integer(),"");
    //map.get(new Integer());
    //map.remove(new Integer())
    map.put(new Integer(1), "One");
    map.put(new Integer(2), "Two");
    map.put(new Integer(3), "Three");
    map.put(new Integer(4), "Four");
    map.put(new Integer(5), "Five");
    map.put(6,"autoboxing six");

    System.out.println("Map Values Before: ");
    Set keys = map.keySet();
    for (Iterator i = keys.iterator(); i.hasNext();) {
      Integer key = (Integer) i.next();
      String value = (String) map.get(key);
      System.out.println(key + " = " + value);
    }


    System.out.println("\nRemove element with key 3");

    //autoboxing
    map.remove(3);

    System.out.println("\nMap Values After: ");
    keys = map.keySet();
    for (Iterator i = keys.iterator(); i.hasNext();) {
      Integer key = (Integer) i.next();
      String value = (String) map.get(key);
      System.out.println(key + " = " + value);
    }

    map.put(777,"not continuous key 777");

    //get the value set of the hashmap
    ArrayList<String> valueSet = new ArrayList<String> ();
    //for arraylist
    //we have many useful methods
    //toArray() is one of them i.e. arraylist could be converted to array directly
    //set(int index, E element)
    //remove(Object o) or remove(int index)
    //indexOf(Object o)

    //most frequently used :: get(int index) & add(E e)  & contains(Object o)

    System.out.println("using for(Integer i : map.keySet()");
    //after : must be the name of a set of keys
    for(Integer i : map.keySet())
    {
      System.out.print(i+" . ");
      //construct our valueSet by putting all the values in the keys to arraylist
      valueSet.add( map.get(i) );
    }
    //instead of using for( auto var : object_array) where auto is only used in c++
    //in java we can use Object to refer to any object
    //for ( Object var : object_array)
    // System.out.println(var);

    System.out.println("using for(Object j : valueSet) to print out self-defined valueSet");
    for(Object j : valueSet)
    {
      System.out.println(j);
    }

  }
}