import java.util.Scanner;
 


 //只有动手写代码了才知道自己的缺陷和思维盲区
//例如对于最基本的字符串  和 链表, map里面的所有method api都不了解怎么去面试？
//还想着用window一个个遍历 麻烦死了
public class allSubstr{
   public static void main(String args[])
   {
      String string, sub;
      int i, c, length;
 
      Scanner in = new Scanner(System.in);

      System.out.println("Enter a string to print it's all substrings");

      string  = in.nextLine();
      length = string.length();   
      System.out.println("Substrings of \""+string+"\" are :-");
 
      //using the sub = string.substring(c, c+i);
      //i.e. the substring method could save you tons of time to set window
      //and iterate through each character

      //using the string method API! be flexible
      for( c = 0 ; c < length ; c++ )
      {
         for( i = 1 ; i <= length - c ; i++ )
         {
            sub = string.substring(c, c+i);
            System.out.println(sub);
         }
      }
   }
}