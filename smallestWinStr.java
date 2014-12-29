import java.util.HashMap;
import java.util.Map;

/*
 * LeetCode 155 Minimum Window Substring 
 * Given a string S and a string T, 
 * find the minimum window in S which will contain all the characters in T in complexity O(n).
 * @author: Scarlett Chen
 * @date: 12/27/2014 Sat 8:36 PM
 * Time: o(2n)
 * space: o(n)
 * 思路：记录minWindow的开始点sb,每次匹配完T的值后，删掉第一个点，继续往后找，直到T再次匹配完全。
 * 每次完全匹配时，更新minWindown是否有更小。
 */
public class MinWindow {
        public static String minWindow(String S, String T) {
               Map<Character,Integer> map = new HashMap<Character, Integer>();
               String minWindow = S;
               if (T.length()> S.length()) return "";
               if (T.equals(S)) return minWindow;
               int count  = T.length();
               for (int i=0; i<count; i++) {
                   char ch = T.charAt(i);
                   if (map.containsKey(ch)) {
                       map.put(ch, map.get(ch)-1);
                   }
                   else map.put(ch, -1);
               }
               int sb = -1;
               boolean ansExist = false;
               for (int i=0; i<S.length(); i++ ) {
                   char ch = S.charAt(i);
                   if (map.containsKey(ch)) {
                           System.out.println(ch);
                           //First beginning of the window
                       if (sb==-1) sb = i;
                       map.put(ch, map.get(ch)+1);
                       if (map.get(ch)<=0) 
                               count--;
                       while (count==0) {
                               ansExist = true;
                           minWindow =i-sb+1 <minWindow.length() ? S.substring(sb,i+1): minWindow;
                           ch = S.charAt(sb);
                          // if (map.containsKey(ch))  must contain, since sb is the begining of the minwindow
                                   map.put(ch, map.get(ch)-1);
                           if (map.get(ch)<0) count++;
                        sb++;
                        while (sb <= S.length()-T.length() && !map.containsKey(S.charAt(sb)))
                                  sb++;
                        if (sb>S.length()-T.length()) return minWindow;
                           }
                          
                           
                       }
                   }
                  
                   
               
              return ansExist? minWindow: "";   
            }
        public static void main(String[] args) {
                System.out.println(minWindow("bdab","ab"));
   
        }

}
