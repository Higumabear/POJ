import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

public class Main{
    public static void main(String[] args)throws IOException{
	Scanner cin = new Scanner(System.in);
	while(true){
	    BigInteger a = cin.nextBigInteger();
	    if(a.equals(BigInteger.valueOf(-1))) break;
	    if(a.compareTo(BigInteger.valueOf(10)) < 0){
		System.out.println("1" + a);
		continue;
	    }

	    StringBuilder sb = new StringBuilder();
	    for (int i = 9; i >= 2; i--) {
		final BigInteger x = BigInteger.valueOf(i);
		while (!a.equals(BigInteger.ONE)) {
		    BigInteger[] qr = a.divideAndRemainder(x);
		    if (qr[1].equals(BigInteger.ZERO)) {
			sb.append(i);
			a = qr[0];
		    } else {
			break;
		    }
		}
	    }
	    
	    if(!a.equals(BigInteger.ONE)){
		System.out.println("There is no such number.");
	    }else{
		System.out.println(sb.reverse().toString());
	    }
	}
    }
}