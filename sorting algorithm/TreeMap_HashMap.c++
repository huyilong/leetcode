首先介绍一下什么是Map。在数组中我们是通过数组下标来对其内容索引的，而在Map中我们通过对象来对对象进行索引，用来索引的对象叫做key，其对应的对象叫做value。这就是我们平时说的键值对。

HashMap通过hashcode对其内容进行快速查找，而 TreeMap中所有的元素都保持着某种固定的顺序，如果你需要得到一个有序的结果你就应该使用TreeMap（HashMap中元素的排列顺序是不固定的）。 
HashMap 非线程安全 TreeMap 非线程安全 

线程安全 
在Java里，线程安全一般体现在两个方面： 
1、多个thread对同一个java实例的访问（read和modify）不会相互干扰，它主要体现在关键字synchronized。如ArrayList和Vector，HashMap和Hashtable 
（后者每个方法前都有synchronized关键字）。如果你在interator一个List对象时，其它线程remove一个element，问题就出现了。 

2、每个线程都有自己的字段，而不会在多个线程之间共享。它主要体现在java.lang.ThreadLocal类，而没有Java关键字支持，如像static、transient那样。 
1.AbstractMap抽象类和SortedMap接口 
AbstractMap抽象类：(HashMap继承AbstractMap)覆盖了equals()和hashCode()方法以确保两个相等映射返回相同的哈希码。如果两个映射大小相等、包含同样的键且每个键在这两个映射中对应的值都相同，则这两个映射相等。映射的哈希码是映射元素哈希码的总和，其中每个元素是Map.Entry接口的一个实现。因此，不论映射内部顺序如何，两个相等映射会报告相同的哈希码。 
SortedMap接口：（TreeMap继承自SortedMap）它用来保持键的有序顺序。SortedMap接口为映像的视图(子集)，包括两个端点提供了访问方法。除了排序是作用于映射的键以外，处理SortedMap和处理SortedSet一样。添加到SortedMap实现类的元素必须实现Comparable接口，否则您必须给它的构造函数提供一个Comparator接口的实现。TreeMap类是它的唯一一份实现。 

2.两种常规Map实现 
HashMap：基于哈希表实现。使用HashMap要求添加的键类明确定义了hashCode()和equals()[可以重写hashCode()和equals()]，为了优化HashMap空间的使用，您可以调优初始容量和负载因子。 
(1)HashMap(): 构建一个空的哈希映像 
(2)HashMap(Map m): 构建一个哈希映像，并且添加映像m的所有映射 
(3)HashMap(int initialCapacity): 构建一个拥有特定容量的空的哈希映像 
(4)HashMap(int initialCapacity, float loadFactor): 构建一个拥有特定容量和加载因子的空的哈希映像 
TreeMap：基于红黑树实现。TreeMap没有调优选项，因为该树总处于平衡状态。 
(1)TreeMap():构建一个空的映像树 
(2)TreeMap(Map m): 构建一个映像树，并且添加映像m中所有元素 
(3)TreeMap(Comparator c): 构建一个映像树，并且使用特定的比较器对关键字进行排序 
(4)TreeMap(SortedMap s): 构建一个映像树，添加映像树s中所有映射，并且使用与有序映像s相同的比较器排序 

3.两种常规Map性能 
HashMap：适用于在Map中插入、删除和定位元素。 
Treemap：适用于按自然顺序或自定义顺序遍历键(key)。 

4.总结 
HashMap通常比TreeMap快一点(树和哈希表的数据结构使然)，建议多使用HashMap，在需要排序的Map时候才用TreeMap。 
复制代码 代码如下:

import java.util.HashMap; 
import java.util.Hashtable; 
import java.util.Iterator; 
import java.util.Map; 
import java.util.TreeMap; 
public class HashMaps { 
public static void main(String[] args) { 
Map<String, String> map = new HashMap<String, String>(); 
map.put("a", "aaa"); 
map.put("b", "bbb"); 
map.put("c", "ccc"); 
map.put("d", "ddd"); 
Iterator<String> iterator = map.keySet().iterator(); 
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

运行结果如下： 
map.get(key) is :ddd 
map.get(key) is :bbb 
map.get(key) is :ccc 
map.get(key) is :aaa 
tab.get(key) is :bbb 
tab.get(key) is :aaa 
tab.get(key) is :ddd 
tab.get(key) is :ccc 
tmp.get(key) is :aaa 
tmp.get(key) is :bbb 
tmp.get(key) is :ccc 
tmp.get(key) is :cdc 
HashMap的结果是没有排序的，而TreeMap输出的结果是排好序的。 
下面就要进入本文的主题了。先举个例子说明一下怎样使用HashMap: 
复制代码 代码如下:

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

在HashMap中通过get()来获取value，通过put()来插入value，ContainsKey()则用来检验对象是否已经存在。可以看出，和ArrayList的操作相比，HashMap除了通过key索引其内容之外，别的方面差异并不大。 
前面介绍了，HashMap是基于HashCode的，在所有对象的超类Object中有一个HashCode()方法，但是它和equals方法一样，并不能适用于所有的情况，这样我们就需要重写自己的HashCode()方法。下面就举这样一个例子： 
复制代码 代码如下:

import java.util.*; 
public class Exp2 { 
public static void main(String[] args){ 
HashMap h2=new HashMap(); 
for (int i=0;i<10;i++) 
h2.put(new Element(i), new Figureout()); 
System.out.println("h2:"); 
System.out.println("Get the result for Element:"); 
Element test=new Element(5); 
if (h2.containsKey(test)) 
System.out.println((Figureout)h2.get(test)); 
else 
System.out.println("Not found"); 
} 
} 
class Element{ 
int number; 
public Element(int n){ 
number=n; 
} 
} 
class Figureout{ 
Random r=new Random(); 
boolean possible=r.nextDouble()>0.5; 
public String toString(){ 
if (possible) 
return "OK!"; 
else 
return "Impossible!"; 
} 
} 

在这个例子中，Element用来索引对象Figureout,也即Element为key，Figureout为value。在Figureout中随机生成一个浮点数，如果它比0.5大，打印"OK!"，否则打印"Impossible!"。之后查看Element(3)对应的Figureout结果如何。 

结果却发现，无论你运行多少次，得到的结果都是"Not found"。也就是说索引Element(3)并不在HashMap中。这怎么可能呢？ 
原因得慢慢来说：Element的HashCode方法继承自Object，而Object中的HashCode方法返回的HashCode对应于当前的地址，也就是说对于不同的对象，即使它们的内容完全相同，用HashCode（）返回的值也会不同。这样实际上违背了我们的意图。因为我们在使用 HashMap时，希望利用相同内容的对象索引得到相同的目标对象，这就需要HashCode()在此时能够返回相同的值。在上面的例子中，我们期望 new Element(i) (i=5)与 Elementtest=newElement(5)是相同的，而实际上这是两个不同的对象，尽管它们的内容相同，但它们在内存中的地址不同。因此很自然的，上面的程序得不到我们设想的结果。下面对Element类更改如下： 
复制代码 代码如下:

class Element{ 
int number; 
public Element(int n){ 
number=n; 
} 
public int hashCode(){ 
return number; 
} 
public boolean equals(Object o){ 
return (o instanceof Element) && (number==((Element)o).number); 
} 
} 

在这里Element覆盖了Object中的hashCode()和equals()方法。覆盖hashCode()使其以number的值作为 hashcode返回，这样对于相同内容的对象来说它们的hashcode也就相同了。而覆盖equals()是为了在HashMap判断两个key是否相等时使结果有意义（有关重写equals()的内容可以参考我的另一篇文章《重新编写Object类中的方法》）。修改后的程序运行结果如下： 
h2: 
Get the result for Element: 
Impossible! 
请记住：如果你想有效的使用HashMap，你就必须重写在其的HashCode()。 
还有两条重写HashCode()的原则： 
[list=1] 
不必对每个不同的对象都产生一个唯一的hashcode，只要你的HashCode方法使get()能够得到put()放进去的内容就可以了。即"不为一原则"。 

生成hashcode的算法尽量使hashcode的值分散一些，不要很多hashcode都集中在一个范围内，这样有利于提高HashMap的性能。即"分散原则"。至于第二条原则的具体原因，有兴趣者可以参考Bruce Eckel的《Thinking in Java》，在那里有对HashMap内部实现原理的介绍，这里就不赘述了。 
掌握了这两条原则，你就能够用好HashMap编写自己的程序了。不知道大家注意没有，java.lang.Object中提供的三个方法：clone()，equals()和hashCode()虽然很典型，但在很多情况下都不能够适用，它们只是简单的由对象的地址得出结果。这就需要我们在自己的程序中重写它们，其实java类库中也重写了千千万万个这样的方法。利用面向对象的多态性——覆盖，Java的设计者很优雅的构建了Java的结构，也更加体现了Java是一门纯OOP语言的特性。