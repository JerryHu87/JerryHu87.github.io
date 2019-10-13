import java.util.*;
import java.io.*;

public class S3_07_Friends {
	public static void main(String [] args) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		short n = (short)(Short.parseShort(input.readLine())+1);
		List<Short> [] nodes = new ArrayList[10000];
		short [] dist = new short[10000];
		for(int i = 1;i<=9999;i++) {
			nodes[i] = new ArrayList<Short>();
			dist[i] = Short.MAX_VALUE;
		}
		for(int i = 1;i<n;i++) {
			String [] tokens = input.readLine().split(" ");
			nodes[Short.parseShort(tokens[0])].add(Short.parseShort(tokens[1]));
		}
		String [] tokens = input.readLine().split(" ");
		LinkedList<Short> q = new LinkedList<Short>();
		while(tokens[0].charAt(0) != '0' && tokens[1].charAt(0) != '0') {
			short src = Short.parseShort(tokens[0]);
			short dest = Short.parseShort(tokens[1]);
			dist[src] = 0;
			q.push(src);
			while(!q.isEmpty()) {
				short currentnode = q.pop();
				if(currentnode == dest) {
					q.clear();
					break;
				}
				else {
					for(int i = 0;i<nodes[currentnode].size();i++) {
						if(dist[nodes[currentnode].get(i)] > dist[currentnode] + 1) {
							dist[nodes[currentnode].get(i)] = (short)(dist[currentnode] + 1);
							q.add(nodes[currentnode].get(i));
						}
					}
				}
			}
			if(dist[dest] == Short.MAX_VALUE) {
				System.out.println("No");
			}
			else {
				System.out.println("Yes " + (short)(dist[dest]-1));
			}
			for(int i = 1;i<=9999;i++) {
				dist[i] = Short.MAX_VALUE;
			}
			tokens = input.readLine().split(" ");
		}
		input.close();
	}

}
