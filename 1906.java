import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

public class Main{
    public static void main(String[] args)throws IOException{
	BigInteger pow3[] = new BigInteger[100];
	pow3[0] = BigInteger.ONE;
	BigInteger v = new BigInteger("3");
	for(int i = 1; i < 100; i++)
	    pow3[i] = pow3[i - 1].multiply(v);
	
	Scanner cin = new Scanner(System.in);
	while(cin.hasNext()){
	    Long N = cin.nextLong();
	    if(N == 0) break;
	    N--;
	    int cnt = 0;
	    boolean f = true;
	    System.out.print("{");
	    while(N > 0){
		if(N % 2 == 1){
		    if(f) System.out.print(" " + pow3[cnt]);
		    else  System.out.print(", " + pow3[cnt]);
		    f = false;
		}
		cnt++;
		N /= 2;
	    }
	    System.out.println(" }");
	}
    }
}
