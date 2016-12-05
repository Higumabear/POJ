import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

public class Main{
    public static void main(String[] args)throws IOException{
	Scanner cin = new Scanner(System.in);
	while(cin.hasNext()){
	    int N = cin.nextInt();
	    if(N == 0) return;
	    
	    BigInteger r = new BigInteger("1");
	    for(int i = 1; i <= N; i++){
		r = r.multiply(BigInteger.valueOf(i));
	    }
	    String s = r.toString();

	    int cnt[] = new int[10];
	    for(int i = 0; i < s.length(); i++){
		cnt[s.charAt(i) - '0']++;
	    }
	    System.out.println(N + "! --");
	    for(int i = 0; i < 5; i++){
		if(i == 0) System.out.printf("   ");
		else System.out.printf("    ");
		System.out.printf("(%d)%5d", i, cnt[i]);
	    }
	    System.out.printf("\n");
	    for(int i = 5; i < 10; i++){
		if(i == 5) System.out.printf("   ");
		else System.out.printf("    ");
		System.out.printf("(%d)%5d", i, cnt[i]);
	    }
	    System.out.printf("\n");
	}
    }
}