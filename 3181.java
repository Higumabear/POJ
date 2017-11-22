import java.io.*;
import java.math.*;
import java.util.*;

class Main {

    public static void main(String[] args) {
	BigInteger dp[][] = new BigInteger[1200][110];
	for(int i = 0; i < 1200; i++){
	    for(int j = 0; j < 110; j++){
		dp[i][j] = new BigInteger("0");
	    }
	}

	Scanner scan=new Scanner(System.in);
	int N, K;
	N = scan.nextInt();
	K = scan.nextInt(); 
	
	dp[0][1] = new BigInteger("1");
	for(int i = 0; i < N; i++){
	    for(int j = 1; j <= K; j++){
		for(int k = j; k <= K; k++){
		    dp[i + k][k] = dp[i + k][k].add(dp[i][j]);
		}
	    }
	}

	BigInteger ans = new BigInteger("0");
	for(int j = 1; j <= K; j++)
	    ans = ans.add(dp[N][j]);
	System.out.println(ans);
    }
}
