import java.io.*;
import java.math.*;
import java.util.*;

class Main {
    static ArrayList<ArrayList<Integer>> g;
    static int[] comm;
    static int N;

    static int rec(int idx, int prev){
	int ret = 1;
	int bal = 0;
	for(int to : g.get(idx)){
	    if(to != prev){
		int subtree = rec(to, idx);
		ret += subtree;
		if(bal < subtree) bal = subtree;
	    }
	}
	if(bal < N - ret) bal = N - ret;
	comm[idx] = bal;
	return ret;
    }
    
    public static void main(String[] args) throws IOException{
	BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(cin.readLine());
	g = new ArrayList<ArrayList<Integer>>();
	for(int i = 0; i <= N; i++)
	    g.add(new ArrayList<Integer>());
	
	comm = new int[N + 1];
	
	for(int i = 0; i < N - 1; i++){
	    StringTokenizer st = new StringTokenizer(cin.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
	    g.get(u).add(v);
	    g.get(v).add(u);
	}
	rec(1, -1);
	int ans = 1 << 29;
	for(int i = 1; i <= N; i++)
	    if(ans > comm[i]) ans = comm[i];

	for(int i = 1; i <= N; i++)
	    if(ans == comm[i])
		System.out.printf("%d ", i);
	System.out.println();
    }

}
