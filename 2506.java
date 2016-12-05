// Time-stamp: <Mon Sep 12 22:56:48 東京 (標準時) 2016>
import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
public class Main {
    
    public static void main (String[] args) {
        Scanner cin=new Scanner(System.in);
	BigInteger dp[] = new BigInteger[300];
	dp[0] = dp[1] = BigInteger.valueOf(1);
	for(int i = 0; i < 290; i++){
	    dp[i + 2] = dp[i + 1].add(dp[i].multiply(BigInteger.valueOf(2)));
	}
	
        while(cin.hasNextInt()){
	    int N = cin.nextInt();
	    System.out.println(dp[N]);
	}       
    }   
}
