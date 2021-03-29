    import java.util.*;
    import java.io.*;
    public class Solution {
      public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = in.nextInt(); // Scanner has functions to read ints, longs, strings, chars, etc.
        for (int i = 1; i <= t; ++i) {
          int n = in.nextInt();
          int k = in.nextInt();
          String s = in.next();
          
          int score = 0;
          int ops = 0;
          int jj = n;
          char[] ch = s.toCharArray();
          
          if (n%2 != 0){
            jj = n-1;
          }
          
          for (int j = 0; j< jj/2; j++){
            if (ch[j] != ch[n-j-1]){
                score++;
                /*System.out.println(n);
                System.out.println(j);
                System.out.println(jj);
                System.out.println(score);
                */
            }
          }
          
          if (score - k > 0){
            ops = score - k;
          }
          
          if (k - score > 0){
            ops = k - score;
          }
          
          System.out.println("Case #" + i + ": " + ops);
        }
      }
    }

