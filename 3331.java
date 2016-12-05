import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

public class Main{
    public static void main(String[] args)throws IOException{
	Scanner cin = new Scanner(System.in);
	while(cin.hasNext()){
	    // String A = cin.next();
	    // String B = cin.next();
	    // String C = cin.next();
	    //BigInteger a = new BigInteger(cin.next());
	    int n = cin.nextInt();
	    for(int t = 0; t < n; t++){
		int a = cin.nextInt();
		int b = cin.nextInt();

		BigInteger r = new BigInteger("1");
		for(int i = 1; i <= a; i++)
		    r = r.multiply(BigInteger.valueOf(i));

		int cnt = 0;
		String s = r.toString();
		for(int i = 0; i < s.length(); i++)
		    if(s.charAt(i) == '0' + b) cnt++;
		
		System.out.println(cnt);
	    }
	}
    }
}
