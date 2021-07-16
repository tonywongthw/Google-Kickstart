import java.util.*;
import java.io.*;

public class Solution2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = in.nextInt(); // Scanner has functions to read ints, longs, strings, chars, etc.

        for (int i = 1; i <= t; ++i) {
            int n = in.nextInt();
            int m = in.nextInt();

            String result = "";
            List<Boolean> list=new ArrayList<Boolean>(Arrays.asList(new Boolean[1001]));
            Collections.fill(list, Boolean.FALSE);

            for (int j=1; j<=n; j++){
                int a = in.nextInt();
                int b = in.nextInt();
                while (a <= b){
                    list.set(a, Boolean.TRUE);
                    a += 1;
                }
            }

            for (int l=1 ;l<=m ;l++){
                int s = in.nextInt();
                int pchosen = 1;
                int mindiff = 1100;

                for (int o=1; o<=1000; o++){
                    if (list.get(o) == Boolean.TRUE){
                        //System.out.print(o);
                        int diff = Math.abs(s-o);
                        if (diff < mindiff){
                            mindiff = diff;
                            pchosen = o;
                        }
                    }
                }
                result += pchosen + " ";
                list.set(pchosen, Boolean.FALSE);
            }
            result = result.trim();
            System.out.println("Case #" + i + ": " + result);
        }
    }
}