import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
public class Main {
    
    public static void main (String[] args) {
	BigInteger dp[] = new BigInteger[300];
	dp[0] = dp[1] = BigInteger.valueOf(1);
	
	for(int i = 2; i < 300; i++)
	    dp[i] = BigInteger.ZERO;
	
	for(int i = 2; i <= 100; i++){
	    BigInteger z = BigInteger.ZERO;
	    for(int j = 0; j <= i - 1; j++){
		dp[i] = dp[i].add(dp[j].multiply(dp[i - 1 - j]));
	    }
	}
	
        Scanner cin = new Scanner(System.in);
        while(cin.hasNextInt()){
	    int N = cin.nextInt();
	    if(N == -1) break;
	    System.out.println(dp[N]);
	}       
    }   
}
