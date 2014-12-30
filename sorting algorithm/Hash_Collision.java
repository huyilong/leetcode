1、开放定址法
    　用开放定址法解决冲突的做法是：当冲突发生时，使用某种探查(亦称探测)技术在散列表中形成一个探查(测)序列。沿此序列逐个单元地查找，直到找到给定 的关键字，或者碰到一个开放的地址(即该地址单元为空)为止（若要插入，在探查到开放的地址，则可将待插入的新结点存人该地址单元）。查找时探查到开放的 地址则表明表中无待查的关键字，即查找失败。注意：
①用开放定址法建立散列表时，建表前须将表中所有单元(更严格地说，是指单元中存储的关键字)置空。
②空单元的表示与具体的应用相关。
    　按照形成探查序列的方法不同，可将开放定址法区分为线性探查法、线性补偿探测法、随机探测等。
（1）线性探查法(Linear Probing)
该方法的基本思想是：
    将散列表T[0..m-1]看成是一个循环向量，若初始探查的地址为d(即h(key)=d)，则最长的探查序列为：
        d，d+l，d+2，…，m-1，0，1，…，d-1
    　即:探查时从地址d开始，首先探查T[d]，然后依次探查T[d+1]，…，直到T[m-1]，此后又循环到T[0]，T[1]，…，直到探查到 T[d-1]为止。
探查过程终止于三种情况：
    　(1)若当前探查的单元为空，则表示查找失败（若是插入则将key写入其中）；
    (2)若当前探查的单元中含有key，则查找成功，但对于插入意味着失败；
    　(3)若探查到T[d-1]时仍未发现空单元也未找到key，则无论是查找还是插入均意味着失败(此时表满)。
利用开放地址法的一般形式，线性探查法的探查序列为：
        hi=(h(key)+i)％m 0≤i≤m-1 //即di=i
用线性探测法处理冲突，思路清晰，算法简单，但存在下列缺点：
① 处理溢出需另编程序。一般可另外设立一个溢出表，专门用来存放上述哈希表中放不下的记录。此溢出表最简单的结构是顺序表，查找方法可用顺序查找。
② 按上述算法建立起来的哈希表，删除工作非常困难。假如要从哈希表 HT 中删除一个记录，按理应将这个记录所在位置置为空，但我们不能这样做，而只能标上已被删除的标记，否则，将会影响以后的查找。
③ 线性探测法很容易产生堆聚现象。所谓堆聚现象，就是存入哈希表的记录在表中连成一片。按照线性探测法处理冲突，如果生成哈希地址的连续序列愈长 ( 即不同关键字值的哈希地址相邻在一起愈长 ) ，则当新的记录加入该表时，与这个序列发生冲突的可能性愈大。因此，哈希地址的较长连续序列比较短连续序列生长得快，这就意味着，一旦出现堆聚 ( 伴随着冲突 ) ，就将引起进一步的堆聚。
（2）线性补偿探测法 
线性补偿探测法的基本思想是：
将线性探测的步长从 1 改为 Q ，即将上述算法中的 j ＝ (j ＋ 1) % m 改为： j ＝ (j ＋ Q) % m ，而且要求 Q 与 m 是互质的，以便能探测到哈希表中的所有单元。
【例】 PDP-11 小型计算机中的汇编程序所用的符合表，就采用此方法来解决冲突，所用表长 m ＝ 1321 ，选用 Q ＝ 25 。   2、拉链法
（1）拉链法解决冲突的方法
    　拉链法解决冲突的做法是：将所有关键字为同义词的结点链接在同一个单链表中。若选定的散列表长度为m，则可将散列表定义为一个由m个头指针组成的指针数 组T[0..m-1]。凡是散列地址为i的结点，均插入到以T[i]为头指针的单链表中。T中各分量的初值均应为空指针。在拉链法中，装填因子α可以大于 1，但一般均取α≤1。
【例】设有 m ＝ 5 ， H(K) ＝ K mod 5 ，关键字值序例 5 ， 21 ， 17 ， 9 ， 15 ， 36 ， 41 ， 24 ，按外链地址法所建立的哈希表如下图所示：
           
（2）拉链法的优点
与开放定址法相比，拉链法有如下几个优点：
①拉链法处理冲突简单，且无堆积现象，即非同义词决不会发生冲突，因此平均查找长度较短；
②由于拉链法中各链表上的结点空间是动态申请的，故它更适合于造表前无法确定表长的情况；
③开放定址法为减少冲突，要求装填因子α较小，故当结点规模较大时会浪费很多空间。而拉链法中可取α≥1，且结点较大时，拉链法中增加的指针域可忽略不计，因此节省空间；
④在用拉链法构造的散列表中，删除结点的操作易于实现。只要简单地删去链表上相应的结点即可。而对开放地址法构造的散列表，删除结点不能简单地将被删结 点的空间置为空，否则将截断在它之后填人散列表的同义词结点的查找路径。这是因为各种开放地址法中，空地址单元(即开放地址)都是查找失败的条件。因此在 用开放地址法处理冲突的散列表上执行删除操作，只能在被删结点上做删除标记，而不能真正删除结点。

（3）拉链法的缺点
    　拉链法的缺点是：指针需要额外的空间，故当结点规模较小时，开放定址法较为节省空间，而若将节省的指针空间用来扩大散列表的规模，可使装填因子变小，这又减少了开放定址法中的冲突，从而提高平均查找速度。