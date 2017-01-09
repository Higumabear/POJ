import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;


public class Main{
	public static void main (String[] args) throws java.lang.Exception
  {
    Scanner cin = new Scanner(System.in);
    while(cin.hasNext()){
      int N = cin.nextInt();
      int D = cin.nextInt();
      if(N == 0 && D == 0) break;
      BigInteger r = new BigInteger("1");
      for(int i = 0; i < D; i++){
	r = r.multiply(BigInteger.valueOf(N));
      }
      System.out.println(r);
    }
  }
}
  
