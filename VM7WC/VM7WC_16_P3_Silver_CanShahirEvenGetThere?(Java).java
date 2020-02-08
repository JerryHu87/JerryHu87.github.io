import java.util.*;
import java.io.*;

public class test{
	//Given an array of Strings output all Strings that occur more than once
	public static void main(String [] args) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		String [] tokens = input.readLine().split(" ");
		int n = Integer.parseInt(tokens[0]);
		int m = Integer.parseInt(tokens[1]);
		int a = Integer.parseInt(tokens[2]);
		int b = Integer.parseInt(tokens[3]);
		List<Integer> [] adj = new ArrayList[n+1];
		for(int i = 1;i<=n;i++) {
			adj[i] = new ArrayList<Integer>();
		}
		for(int i = 1;i<=m;i++) {
			tokens = input.readLine().split(" ");
			int temp1 = Integer.parseInt(tokens[0]);
			int temp2 = Integer.parseInt(tokens[1]);
			adj[temp1].add(temp2);
			adj[temp2].add(temp1);
		}
		LinkedList<Integer> q = new LinkedList<Integer>();
		boolean [] vis = new boolean[n+1];
		q.push(a);
		vis[a] = true;
		while(!q.isEmpty()) {
			int u = q.pop();
			for(int v:adj[u]) {
				if(!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
		if(vis[b]) {
			System.out.println("GO SHAHIR!");
		}
		else {
			System.out.println("NO SHAHIR!");
		}
	}
		
}
