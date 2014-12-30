//linear search and table search(hashsearch)
hash search  -  散列表

/*
Hashing has a worst-case behavior that is linear for finding a target, 
but with some care, hashing can be dramatically fast in the average-case. 
Hashing also makes it easy to add and delete elements from the collection that is being searched.

If student IDs are all in the range 0..99, we could store the records in an array of the following type, 
placing student ID k in location data[k]:

Student data[100];  // array of 100 records 
The record for student ID k can be retrieved immediately since we know it is in data[k].

What, however, if the student IDs do not form a neat range like 0..99. Suppose that we only know that 
there will be a hundred or fewer and that they will be distributed in the range 0..9999. We could 
then use an array with 10,000 components, but that seems wasteful since only a small fraction of the 
array will be used. It appears that we have to store the records in an array with 100 elements and to 
use a serial search through this array whenever we wish to find a particular student ID. 

If we are clever, we can store the records in a relatively small array and still retrieve students 
by ID much faster than we could by serial search.

To illustrate this, suppose that we know that the student IDs will be:

0, 100, 200, ... , 9800, 9900 
In this case, we can store the records in an array called data with only 100 components. 
We'll store the record with student ID k at location:   data[k/100] 


Collisions - we cannot avoid collisions in hashmap

Suppose we no longer have a student ID 400, but we have 399 instead. The record with student ID 300 
will be stored in data[3] as before, but where will student ID 399 be placed? Student ID 399 hashes to 
data[399/100] = data[3]. So there are now two different records that belong in data[3]. This situation 
is known as a collision.

In this case, we could redefine our hash function to avoid the collision, but in practice you do not 
know the exact numbers that will occur as keys, and therefore, you cannot design a hash function that 
is guaranteed to be free of collisions. Typically, though, you do know an upper bound on how many keys 
there will be.

Solution -  but we can solve the collision by design hash function

The usual approach is to use an array size that is larger than needed. The extra array positions make 
the collisions less likely. A good hash function will distribute the keys uniformly throughout the 
locations of the array. If the array indices range from 0 to 99, then you might use the following hash 
function to produce an array index for a record with a given key:

hash(k) = k % 100
This hash function always produces a value in the range 0 to 99.


Solution 1

Open Addressing

One way to resolve collisions is to place the colliding record in another location that is still open. 
This storage algorithm is called open-addressing. Open addressing requires that the array be initialized 
so that the program can test if an array position already contains a record.

With this method of resolving collisions, we still must decide how to choose the locations to search 
for an open position when a collision occurs...There are 2 main ways to do so.

1. Linear Probing

One way of dealing with collisions is the following algorithm:

For a record with key given by key, compute the index hash(key).
If data[hash(key)] does not already contain a record, then store the record in data[hash(key)] and 
end the storage algorithm.
If the location data[hash(key)] already contains a record then try data[hash(key)+1]. If that location 
already contains a record, try data[hash(key)+2], and so forth until a vacant position is found. When 
the highest numbered array position is reached, simply go to the start of the array. For example, if 
the array indices are 0..99, and 98 is the key, then try 98,99,0,1 and so on, in that order. Searching 
for a vacant spot in this manner is called linear probing.

线性探测法很容易产生堆聚现象。所谓堆聚现象，就是存入哈希表的记录在表中连成一片。按照线性探测法处理冲突，
如果生成哈希地址的连续序列愈长 ( 即不同关键字值的哈希地址相邻在一起愈长 ) ，则当新的记录加入该表时，
与这个序列发生冲突的可能性愈大。因此，哈希地址的较长连续序列比较短连续序列生长得快，这就意味着，一旦出现堆聚 
( 伴随着冲突 ) ，就将引起进一步的堆聚。

2. Double Hashing

There is a problem with linear probing. When several different keys hash to the same location, the 
result is a cluster of elements, one after another. As the table approaches its capacity, these clusters 
tend to merge into larger and larger clusters. This is the problem of clustering.

Clustering makes insertions take longer because the insert function must step all the way through a 
cluster to find a vacant location. Searches require more time for the same reason. The most common 
technique to avoid clustering is called double hashing. Replace step 3. in the above algorithm with the 
following step:

3. Let i = hash(key). If the location data[i] already contains a record then let i = (i+hash2(key)) % SIZE, 
and try the new data[i]. If that location already contains a record, then let i= (i+hash2(key)) % SIZE, 
and try that data[i], and so forth until a vacant position is found.

Searching for a vacant spot in this manner is called double hashing.


Important Note:
With double hashing, we could return to our starting position before we have examined every available 
location. An easy way to avoid this problem is to make sure that the array size is relatively prime 
with respect to the value returned by hash2() (in other words, these two numbers must not have any 
common factor, apart from 1).

hash2(key)must return a value in the range [1..SIZE-1]. Two possible implementations are:

1. hash2(key) = 1 + (key % (SIZE - 2)
2. hash2(key) = max(1, (key / SIZE) % SIZE)
Keep in mind that there exist many possible candidates.



Solution 2

Chained hashing

In open addressing, each array element can hold just one entry. When the array is full, no more 
records can be added to the table. One possible solution is to resize the array and rehash all the 
entries. This would require a careful choice of new size and probably require each entry to have a 
new hash value computed.

A better approach is to use a different collision resolution method called chained hashing, or simply 
chaining, in which each component of the hash table's array can hold more than one entry. We still 
hash the key of each entry, but upon collision, we simply place the new entry in its proper array 
component along with other entries that happened to hash to the same array index.

The most common way to implement chaining is to have each array element be a linked list. The nodes 
in a particular linked list will each have a key that hashes to the same value.

在用拉链法构造的散列表中，删除结点的操作易于实现。只要简单地删去链表上相应的结点即可。而对开放地址法构造的散列表，
删除结点不能简单地将被删结 点的空间置为空，否则将截断在它之后填人散列表的同义词结点的查找路径。这是因为各种开放地址法中，
空地址单元(即开放地址)都是查找失败的条件。因此在 用开放地址法处理冲突的散列表上执行删除操作，只能在被删结点上做删除标记
，而不能真正删除结点。

拉链法的缺点是：指针需要额外的空间，故当结点规模较小时，开放定址法较为节省空间，而若将节省的指针空间用来扩大散列表的规模，
可使装填因子变小，这又减少了开放定址法中的冲突，从而提高平均查找速度。


