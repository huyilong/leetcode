import java.util.*;

public class MapValue{
	public static void main(String[] args){
		Map<String,String> map = new HashMap<String,String>();
		map.put("key1", "value1");
		map.put("key2", "value2");
		map.put("key3", "value3");

		Collection set = map.values();
		Iterator iter = set.iterator();

		while (iter.hasNext()) {
			System.out.println(iter.next());
		}

		//using Object in java as auto in C++ for iterator/return sth
		Object auto_set = map.values();
		Object auto_it = auto_set.iterator();

		while(auto_it.hasNext()){
			System.out.println(auto_it.next());
		}


		//will compile failure
		//must memorize that the map.values() will return the type of Collection
		//and the iterator should be declared Iterator it = set.iterator()
		//only in this way would it work !!! differnet from c++
	}
}