import java.io.*;
import java.math.*;
import java.util.*;

class Main {
    public static void main(String[] args) {
	Scanner scan=new Scanner(System.in);
	BigDecimal a, b;
	a = scan.nextBigDecimal();
	b = scan.nextBigDecimal();
	a = a.multiply(b);
	System.out.println(a);
    }
}