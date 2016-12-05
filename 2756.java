import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

public class Main{
  public static void main(String[] args)throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    while(n-- > 0){
      String[] s = br.readLine().replaceAll("\\+","").split(" ");
      System.out.println(new BigInteger(s[0]).add(new BigInteger(s[1])));
    }
  }
}
