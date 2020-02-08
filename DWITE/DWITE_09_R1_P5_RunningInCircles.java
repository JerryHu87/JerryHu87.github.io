import java.util.*;
import java.io.*;

public class R1_P5_09_RunningInCircles {
	static int [] dist, visited; static int [][] nodes; static int loop;
	public static void dfs(int u) {
		visited[u] = 1;
		for(int v = 1;v<=100;v++) {
			if(nodes[u][v] == 0) {
				continue;
			}
			if(visited[v] == 1) {
				loop = Math.max(loop, dist[u]-dist[v]+1);
				return;
			}
			else if(visited[v] == 0) {
				dist[v] = dist[u] + 1;
				dfs(v);
			}
		}
		visited[u] = 2;
	}
	public static void main(String []args) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		for(int z = 0;z<5;z++) {
			String [] tokens = input.readLine().split(" ");
			int c = Integer.parseInt(tokens[0]);
			visited = new int [101];
			dist = new int [101];
			nodes= new int[101][101];
			loop = 0;
			for(int i = 0;i<c;i++) {
				tokens = input.readLine().split(" ");
				nodes[Integer.parseInt(tokens[0])][Integer.parseInt(tokens[1])] = 1;
			}
			dfs(1);
			System.out.println(loop);
		}
		input.close();
	}

}
