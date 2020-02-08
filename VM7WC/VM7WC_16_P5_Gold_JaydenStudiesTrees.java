import java.util.*;
import java.io.*;

public class P5_16_JaydenStudiesTrees {
	public static void main(String [] args) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(input.readLine());
		List<Integer> [] nodes = new ArrayList[n+1];
		int [] dist = new int [n+1];
		for(int i = 1;i<=n;i++) {
			nodes[i] = new ArrayList<Integer>();
			dist[i] = Integer.MAX_VALUE;
		}
		for(int i = 1;i<=n-1;i++) {
			String [] tokens = input.readLine().split(" ");
			int src = Integer.parseInt(tokens[0]);
			int dest = Integer.parseInt(tokens[1]);
			nodes[src].add(dest);
			nodes[dest].add(src);
		}
		LinkedList<Integer> d = new LinkedList<Integer>();
		d.add(1);
		boolean [] vis = new boolean[n+1];
		int last = 0;
		while(!d.isEmpty()) {
			int currentnode = d.pop();
			vis[currentnode] = true;
			for(int i = 0;i<nodes[currentnode].size();i++) {
				if(vis[nodes[currentnode].get(i)] == false) {
					d.add(nodes[currentnode].get(i));
					last = nodes[currentnode].get(i);
				}
			}
		}
		d.add(last);
		dist[last] = 0;
		while(!d.isEmpty()) {
			int currentnode = d.pop();
			for(int i = 0;i<nodes[currentnode].size();i++) {
				if(dist[nodes[currentnode].get(i)] > dist[currentnode]+1) {
					dist[nodes[currentnode].get(i)] = dist[currentnode]+1;
					d.add(nodes[currentnode].get(i));
				}
			}
		}
		int max = 0;
		for(int i = 0;i<dist.length;i++) {
			if(dist[i] > max) {
				max = dist[i];
			}
		}
		System.out.println(max);
		input.close();
	}

}
