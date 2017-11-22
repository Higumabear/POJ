import java.io.*;
import java.math.*;
import java.util.*;

class Main {

    public static void main(String[] args) {
	boolean sieve[] = new boolean[1001000];
	Arrays.fill(sieve, true);
	sieve[0] = sieve[1] = false;
	for(int i = 2; i < 1001000; i++){
	    if(!sieve[i]) continue;
	    for(int j = 2 * i; j < 1001000; j += i) sieve[j] = false;
	}

	ArrayList<Integer> prime = new ArrayList<Integer>();
	for(int i = 2; i < 1001000; i++)
	    if(sieve[i]) prime.add(new Integer(i));
	
	Scanner scan=new Scanner(System.in);
	while(true){
	    BigInteger N = scan.nextBigInteger();
	    int K = scan.nextInt();
	    if(K == 0) break;

	    int p = -1;
	    for(int i = 0; ; i++){
		int pr = prime.get(i);
		if(pr >= K) break;
		BigInteger bi = BigInteger.valueOf(pr);
		BigInteger rem = N.remainder(bi);
		if(rem.compareTo(BigInteger.ZERO) == 0){
		    p = pr;
		    break;
		}
	    }
	    if(p == -1) System.out.println("GOOD");
	    else System.out.printf("BAD %d\n", p);
	}
    }
}
