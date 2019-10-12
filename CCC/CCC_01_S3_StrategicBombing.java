import java.io.*;
import java.util.*;

public class StrategicBombing {
	private static boolean bfs(List<Integer> [] anArray) {
		LinkedList <Integer> q = new LinkedList<Integer>();
		boolean [] visited = new boolean [26];
		q.add(0);
		while(!q.isEmpty()) {
			int currentnode = q.pop();
			visited[currentnode] = true;
			for(int i = 0;i<anArray[currentnode].size();i++) {
				if(visited[anArray[currentnode].get(i)] == false) {
					q.add(anArray[currentnode].get(i));
				}
			}
		}
		if(visited[1] == false) {
			return true;
		}
		else {
			return false;
		}
	}
	public static void main(String args[]) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		String newconnection = "";
		List<Integer> [] connections = new ArrayList[26];
		List<String> c = new ArrayList<String>();
		int src;
		int dest;
		for(int i = 0;i<26;i++) {
			connections[i] = new ArrayList();
		}
		while(true) {
			newconnection = input.readLine();
			if(newconnection.equals("**")) {
				break;
			}
			c.add(newconnection);
			src = newconnection.charAt(0) - 'A';
			dest = newconnection.charAt(1) - 'A';
			connections[src].add(dest);
			connections[dest].add(src);
		}
		int num = 0;
		for(int i = 0;i<c.size();i++) {
			src = c.get(i).charAt(0) - 'A';
			dest = c.get(i).charAt(1) - 'A';
			connections[src].remove(connections[src].indexOf(dest));
			connections[dest].remove(connections[dest].indexOf(src));
			if(bfs(connections) == true) {
				System.out.println(c.get(i));
				num = num + 1;
			}
			connections[src].add(dest);
			connections[dest].add(src);
		}
		if(num > 0) {
			System.out.println("There are " + num + " disconnecting roads.");
		}
		else {
			System.out.println("There are 0 disconnecting roads.");
		}
		input.close();
	}
}
