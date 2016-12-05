// Time-stamp: <Mon Nov 07 21:39:41 東京 (標準時) 2016>
import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
public class Main {
    
    public static void main (String[] args) {
	BigInteger dp[] = new BigInteger[1001];
	dp[0] = BigInteger.valueOf(0);
	boolean t = true;
	for(int i = 0; i < 1000; i++){
	    dp[i + 1] = dp[i].multiply(BigInteger.valueOf(2));
	    if(t) 
		dp[i + 1] = dp[i + 1].add(BigInteger.valueOf(1));
	    else 
		dp[i + 1] = dp[i + 1].add(BigInteger.valueOf(-1));
	    t = !t;
	}
	Scanner cin=new Scanner(System.in);
        while(cin.hasNextInt()){
	    int N = cin.nextInt();
	    System.out.println(dp[N - 1]);
	}       
    }   
}
