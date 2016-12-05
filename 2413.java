import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

public class Main{
    public static void main(String[] args)throws IOException{
	Scanner cin = new Scanner(System.in);
	while(cin.hasNext()){
	    String A = cin.next();
	    String B = cin.next();
	    BigInteger a = new BigInteger(A);
	    BigInteger b = new BigInteger(B);
	    BigInteger p = new BigInteger("1");
	    BigInteger q = new BigInteger("2");
	    if(A.equals("0") && B.equals("0")) return;

	    int cnt = 0;
	    if(p.compareTo(a) >= 0 && p.compareTo(b) <= 0){
		cnt++;
	    }
	    if(q.compareTo(a) >= 0 && q.compareTo(b) <= 0){
		cnt++;
	    }
	    
	    while(true){
		BigInteger r = p.add(q);
		p = q;
		q = r;
		if(r.compareTo(a) >= 0 && r.compareTo(b) <= 0){
		    cnt++;
		}
		if(r.compareTo(b) >= 0)
		    break;
	    }
	    System.out.println(cnt);
	}
    }
}
