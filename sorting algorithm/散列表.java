散列表（Hash table，也叫哈希表），是根据关键字（Key value）而直接访问在内存存储位置的数据结构。
也就是说，它通过把键值通过一个函数的计算，映射到表中一个位置来访问记录，这加快了查找速度。
这个映射函数称做散列函数，
存放记录的数组称做散列表。

一个通俗的例子是，为了查找电话簿中某人的号码，可以创建一个按照人名首字母顺序排列的表（
即建立人名x到首字母F(x)的一个函数关系），在首字母为W的表中查找“王”姓的电话号码，显然比直接查找就要快得多。
这里使用人名作为关键字，“取首字母”是这个例子中散列函数的函数法则F()，存放首字母的表对应散列表。
关键字和函数法则理论上可以任意确定。

请问java中的哪个map实现能够按照放入集合的顺序存储？
我用了 hashmap 也不知道他是根据什么胡乱的排序
     treemap 是根据key排序
   我要向根据value排序的map实现 或者 方法和按照装载顺序存放的map

 HashMap的存放是散列的，要按存放顺序的话用LinkedHashMap...

   //使用TreeMap的value的升序来排序。
            Set s = map.entrySet();
            Map.Entry []datas = (Map.Entry[])s.toArray(new Map.Entry[s.size()]);
            Arrays.sort(datas, new Comparator(){
                @Override
                public int compare(Object o1, Object o2) {
                    String key1 = ((Map.Entry)o1).getValue().toString();
                    String key2 = ((Map.Entry)o2).getValue().toString();
                    return key1.compareTo(key2);
                }
                 
            });

    //按插入顺序就用LinkedHashMap
	自己定义按value 值排序就要你的类实现Comparator接口


	散列表的载荷因子定义为：\alpha = 填入表中的元素个数 / 散列表的长度

\alpha是散列表装满程度的标志因子。由于表长是定值，\alpha与“填入表中的元素个数”成正比，所以，\alpha越大，
表明填入表中的元素越多，产生冲突的可能性就越大；反之，\alpha越小，标明填入表中的元素越少，产生冲突的可能性就越小。
实际上，散列表的平均查找长度是载荷因子\alpha的函数，只是不同处理冲突的方法有不同的函数。

对于开放寻址法，荷载因子是特别重要因素，应严格限制在0.7-0.8以下。超过0.8，查表时的CPU缓存不命中（cache missing）
按照指数曲线上升。因此，一些采用开放寻址法的hash库，如Java的系统库限制了荷载因子为0.75，超过此值将resize散列表。