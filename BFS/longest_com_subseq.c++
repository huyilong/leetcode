 Longest common subsequence问题：已知两序列，求这两个序列的最长公共子序列（不一定要连续）的长度。
 设二维数组dp[i][j]表示长度分别为i和j的序列A和B的LCS的最大长度，有状态转移方程：

 A[i]=B[j]时，dp[i][j]= dp[i-1][j-1] + 1；
 A[i]≠B[j]时，dp[i][j]= max{ dp[i-1][j], dp[i][j-1]}。


    通过观察发现，状态dp[i][j]只与当前行(dp[i][j-1])和上一行(dp[i-1][j]，dp[i-1][j-1])的状态有关。
    这样，我们可以设置2个一维数组c1[],c2[]，其中c1[]保存上一行的状态信息，c2[]更新当前行的状态信息，
    更新完毕之后再将c2[]的状态信息复制到c1[]中，循环结束后c1[length_B]就是所求LCS的最大长度，
    从而降低了空间需求。


 1 #include <iostream>
 2 using namespace std;
 3 
 4 const int MAXN = 5001;
 5 char str1[MAXN],str2[MAXN];
 6 int i,j,len1,len2,c1[MAXN],c2[MAXN];
 7 
 8 int main(){
 9     while(scanf("%s",str1)!=EOF){
10         scanf("%s",str2);
11         len1=strlen(str1),len2=strlen(str2);
12         for(i=0;i<=len2;i++) c1[i]=0;
13         for(i=0;i<=len1;i++){
14             for(j=0;j<=len2;j++){
	
15                 if(str1[i]==str2[j]) 
						c2[j+1]=c1[j]+1;

16                 else 
					c2[j+1]=c2[j]>c1[j+1] ? c2[j]:c1[j+1];
17             }
18             for(j=1;j<=len2;j++) c1[j]=c2[j];
19         }
20         printf("%d\n",c1[len2]);
21     }
22     return 0;
23 }