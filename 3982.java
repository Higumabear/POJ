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
	    String C = cin.next();
	    BigInteger a = new BigInteger(A);
	    BigInteger b = new BigInteger(B);
	    BigInteger c = new BigInteger(C);

	    for(int i = 3; i <= 99; i++){
		BigInteger r = a.add(b).add(c);
		a = b;
		b = c;
		c = r;
	    }
	    System.out.println(c);
	}
    }
}
