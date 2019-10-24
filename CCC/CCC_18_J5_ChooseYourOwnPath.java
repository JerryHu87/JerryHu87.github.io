import java.util.*;

public class ChooseYourOwnPath {
	public static class Pair{
		int node;
		int dist;
		public Pair(int node,int dist){
			this.node = node;
			this.dist = dist;
		}
	}
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int pagenum = input.nextInt();
		boolean check = false;
		int mindist = Integer.MAX_VALUE;
		boolean [] visited = new boolean [pagenum+1];
		List<Integer> [] pages = new ArrayList[pagenum+1];
		int [] distances = new int [pagenum+1];
		for(int i = 1;i<=pagenum;i++) {
			pages[i] = new ArrayList();
		}
		for(int i = 1; i<=pagenum;i++) {
			int options = input.nextInt();
			for(int j = 0;j<options;j++) {
				int newconnection = input.nextInt();
				pages[i].add(newconnection);
			}
		}
		for(int i = 2;i<distances.length;i++) {
			distances[i] = Integer.MAX_VALUE;
		}
		LinkedList<Pair> bfs = new LinkedList<Pair>();
		bfs.add(new Pair(1,1));
		distances[1] = 1;
		while(!bfs.isEmpty()) {
			Pair currentnode = bfs.pop();
			int node = currentnode.node;
			int dist = currentnode.dist;
			visited[node] = true;
			if(distances[node] < dist)continue; 
			if(dist<mindist && pages[node].size() == 0) {
				mindist = dist;
			}
			distances[node] = dist;
			for(int i:pages[node]) {
				if(distances[i] > distances[node] + 1) {
					bfs.add(new Pair(i, distances[node] + 1));
				}
			}
		}
	    for(int i = 2;i<distances.length;i++) {
			if(distances[i] == Integer.MAX_VALUE) {
				  check = true;
			      System.out.println("N");
			      break;
			}
	    }
	    if(check == false) {
	      System.out.println("Y");
	    }
		System.out.println(mindist);
		input.close();
	}
}
