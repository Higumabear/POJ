import java.util.*;

public class Main {
    public static void main(String[] args) {
	Scanner cin = new Scanner(System.in);
	HashMap<Pair, Long> m = new HashMap<Pair, Long>();
	TreeSet<Integer> iid = new TreeSet<Integer>();
	TreeSet<Integer> sid = new TreeSet<Integer>();

	int N = cin.nextInt();
	for(int i = 0; i < N; i++){
	    int a = cin.nextInt();
	    int b = cin.nextInt();
	    int c = cin.nextInt();
	    iid.add(a);
	    sid.add(b);
	    Pair p = new Pair(a, b);
	    if(m.containsKey(p)){
		Long v = m.get(p);
		m.put(p, v + c);
	    }else{
		m.put(p, (long)c);
	    }
	}
	Integer[] shop_id = new Integer[sid.size()];
	Integer[] item_id = new Integer[iid.size()];
	iid.toArray(item_id);
	sid.toArray(shop_id);

	System.out.print("-1");
	for(int i : item_id)
	    System.out.print(" " + i);
	System.out.println("");
	for(int shop : shop_id){
	    StringBuilder sb = new StringBuilder();
	    sb.append("" + shop);
	    for(int item : item_id){
		Pair p = new Pair(item, shop);
		if(m.containsKey(p)){
		    sb.append(" " + m.get(p));
		}else{
		    sb.append(" 0");
		}
	    }
	    System.out.println(sb.toString());
	}
    }
}

class Pair{
    public int x, y;
    public Pair(int a, int b){
	x = a; y = b;
    }

    @Override
    public boolean equals(Object o){
	Pair p = (Pair)o;
	return x == p.x && y == p.y;
    }

    @Override
    public int hashCode(){
	return new Long((long)x * y).hashCode();
    }
}
