/*


HashMap里面没有出现hash冲突时，没有形成单链表时，hashmap查找元素很快,get()方法能够直接定位到元素，但是出现单链表后，
单个bucket 里存储的不是一个 Entry，而是一个 Entry 链，系统只能必须按顺序遍历每个 Entry，直到找到想搜索的 Entry 
为止——如果恰好要搜索的 Entry 位于该 Entry 链的最末端（该 Entry 是最早放入该 bucket 中），那系统必须循环到最后才能
找到该元素。

当创建 HashMap 时，有一个默认的负载因子（load factor），其默认值为 0.75，这是时间和空间成本上一种折衷：
增大负载因子可以减少 Hash 表（就是那个 Entry 数组）所占用的内存空间，但会增加查询数据的时间开销，
而查询是最频繁的的操作（HashMap 的 get() 与 put() 方法都要用到查询）；

减小负载因子会提高数据查询的性能，但会增加 Hash 表所占用的内存空间。


HashMap通过hashcode对其内容进行快速查找，而 TreeMap中所有的元素都保持着某种固定的顺序，
如果你需要得到一个有序的结果你就应该使用TreeMap（HashMap中元素的排列顺序是不固定的）。 
HashMap 非线程安全 TreeMap 非线程安全 

Thread Safe

在Java里，线程安全一般体现在两个方面： 
1、多个thread对同一个java实例的访问（read和modify）不会相互干扰，它主要体现在关键字synchronized。
如ArrayList和Vector，HashMap和Hashtable 
（后者每个方法前都有synchronized关键字）。如果你在interator一个List对象时，其它线程remove一个element，
问题就出现了。 

2、每个线程都有自己的字段，而不会在多个线程之间共享。它主要体现在java.lang.ThreadLocal类，
而没有Java关键字支持，如像static、transient那样。

*/

/*
(1)HashMap(): 构建一个空的哈希映像 
(2)HashMap(Map m): 构建一个哈希映像，并且添加映像m的所有映射 
(3)HashMap(int initialCapacity): 构建一个拥有特定容量的空的哈希映像 
(4)HashMap(int initialCapacity, float loadFactor): 构建一个拥有特定容量和加载因子的空的哈希映像 

loadFactor

如果负载因子是0.75，hashmap(16)最多可以存储12个元素，想存第16个就得扩容成32。
如果负载因子是1，hashmap(16)最多可以存储16个元素。

同样存16个元素，一个占了32个空间，一个占了16个空间的内存。

实际容量 = 最大容量  * 负载因子，
advantage: 如果最大容量不变的情况下增大负载因子，当然可以增加实际容量，如果负载因子大了会增加哈希冲突发生的概率
disadcantage: 会增加查询数据的时间开销，这个就是由于需要解决哈希冲突需要的事件开销

TreeMap：基于红黑树实现。TreeMap没有调优选项，因为该树总处于平衡状态。 
(1)TreeMap():构建一个空的映像树 
(2)TreeMap(Map m): 构建一个映像树，并且添加映像m中所有元素 
(3)TreeMap(Comparator c): 构建一个映像树，并且使用特定的比较器对关键字进行排序 
(4)TreeMap(SortedMap s): 构建一个映像树，添加映像树s中所有映射，并且使用与有序映像s相同的比较器排序 
*/

/*

首先2个都是map，所以用key取值肯定是没区别的，区别在于用Iterator遍历的时候
LinkedHashMap保存了记录的插入顺序，先插入的先遍历到
TreeMap默认是按升序排，也可以指定排序的比较器。遍历的时候按升序遍历。
例如：a是LinkedHashMap，b是TreeMap。
a.put("2","ab");
a.put("1","bc");
b.put("2","ab");
b.put("1","bc");

那么遍历a的时候，先遍历到key是2的，因为2先放进去。
遍历b的时候，先遍历到“1”，因为按顺序是先1后2。

*/

//HashMap通常比TreeMap快一点(树和哈希表的数据结构使然)，建议多使用HashMap，在需要排序的Map时候才用TreeMap。

//command+A && command+D
import java.util.HashMap; 
import java.util.Hashtable; 
import java.util.Iterator; 
import java.util.Map; 
import java.util.TreeMap; 
public class HashMapEg { 
	public static void main(String[] args) { 
		Map<String, String> map = new HashMap<String, String>(); 
		map.put("a", "aaa"); 
		map.put("b", "bbb"); 
		map.put("c", "ccc"); 
		map.put("d", "ddd"); 

		Iterator<String> iterator = map.keySet().iterator(); 
		//we have key set but we do not have valueSet?

		while (iterator.hasNext()) { 
			Object key = iterator.next(); 
			System.out.println("map.get(key) is :" + map.get(key)); 
		} 
// 定义HashTable,用来测试 
		Hashtable<String, String> tab = new Hashtable<String, String>(); 
		tab.put("a", "aaa"); 
		tab.put("b", "bbb"); 
		tab.put("c", "ccc"); 
		tab.put("d", "ddd"); 
		Iterator<String> iterator_1 = tab.keySet().iterator(); 
		while (iterator_1.hasNext()) { 
			Object key = iterator_1.next(); 
			System.out.println("tab.get(key) is :" + tab.get(key)); 
		} 
		TreeMap<String, String> tmp = new TreeMap<String, String>(); 
		tmp.put("a", "aaa"); 
		tmp.put("b", "bbb"); 
		tmp.put("c", "ccc"); 
		tmp.put("d", "cdc"); 
		Iterator<String> iterator_2 = tmp.keySet().iterator(); 
		while (iterator_2.hasNext()) { 
			Object key = iterator_2.next(); 
			System.out.println("tmp.get(key) is :" + tmp.get(key)); 
		} 
	} 
} 

//command+A && command+D
//toString()  
// -> Integer.toString()  /  Integer.parseInt()  /  arrayList.toArray() 
import java.util.*; 
public class Exp1 { 
	public static void main(String[] args){ 
		HashMap h1=new HashMap(); 
		Random r1=new Random(); 
		for (int i=0;i<1000;i++){ 
			Integer t=new Integer(r1.nextInt(20)); 
			if (h1.containsKey(t)) 
				((Ctime)h1.get(t)).count++; 
			else 
				h1.put(t, new Ctime()); 
		} 
		System.out.println(h1); 
	} 
} 
class Ctime{ 
	int count=1; 
	public String toString(){ 
		return Integer.toString(count); 
	} 
} 