import java.util.*;
import java.io.*;

public class P5_07_BridgesInAGraph {
	public static class Connection{
		byte src;
		byte dest;
		public Connection(byte S,byte D) {
			src = S;
			dest = D;
		}
	}
	public static void main(String [] args) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		for(byte z = 0;z<5;z++) {
			byte n = Byte.parseByte(input.readLine());
			short c = Short.parseShort(input.readLine());
			List<Byte> [] nodes = new ArrayList[n+1];
			List <Connection> connections = new ArrayList<Connection>();
			for(byte i = 1;i<=n;i++) {
				nodes[i] = new ArrayList<Byte>();
			}
			for(short i = 0;i<c;i++) {
				String [] tokens = input.readLine().split(" ");
				byte src =	Byte.parseByte(tokens[0]);
				byte dest = Byte.parseByte(tokens[1]);
				nodes[src].add(dest);
				nodes[dest].add(src);
				connections.add(new Connection(src,dest));
			}
			short bridges = 0;
			LinkedList<Byte> q = new LinkedList<Byte>();
			for(short i =0;i<connections.size();i++) {
				byte node1 = connections.get(i).src;
				byte node2 = connections.get(i).dest;
				nodes[node1].remove(nodes[node1].indexOf(node2));
				nodes[node2].remove(nodes[node2].indexOf(node1));
				boolean [] visited = new boolean [n+1];
				q.add((byte)1);
				while(!q.isEmpty()) {
					byte currentnode = q.pop();
					visited[currentnode] = true;
					for(byte j = 0;j<nodes[currentnode].size();j++) {
						if(visited[nodes[currentnode].get(j)] == false) {
							q.add(nodes[currentnode].get(j));
						}
					}
				}
				nodes[node1].add(node2);
				nodes[node2].add(node1);
				for(byte j = 1;j<visited.length;j++) {
					if(visited[j] == false) {
						bridges++;
						break;
					}
				}
			}
			System.out.println(bridges);
		}
		input.close();
	}
	
}
