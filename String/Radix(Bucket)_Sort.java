publicclassRadixSort{
publicstaticvoidsort(int[]number,intd){//d表示最大的数有多少位
intk=0;
intn=1;
intm=1;//控制键值排序依据在哪一位
int[][]temp=newint[10][number.length];//数组的第一维表示可能的余数0-9
int[]order=newint[10];//数组orderp[i]用来表示该位是i的数的个数
while(m<=d){
for(inti=0;i<number.length;i++){
intlsd=((number[i]/n)%10);
temp[lsd][order[lsd]]=number[i];
order[lsd]++;
}
for(inti=0;i<10;i++){
if(order[i]!=0)
for(intj=0;j<order[i];j++){
number[k]=temp[i][j];
k++;
}
order[i]=0;
}
n*=10;
k=0;
m++;
}
}
publicstaticvoidmain(String[]args){
int[]data=
{73,22,93,43,55,14,28,65,39,81,33,100};
RadixSort.sort(data,3);
for(inti=0;i<data.length;i++){
System.out.print(data[i]+"");
}
}