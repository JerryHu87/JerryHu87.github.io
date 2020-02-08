import java.util.*;
import java.io.*;

public class P1_17_VeraAndTrailBuilding {
	public static class Connection{
		int src;
		int dest;
		public Connection(int S, int D){
			src = S;
			dest = D;
		}
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int k = input.nextInt();
		if(k == 1) {
			System.out.println("2 2");
			System.out.println("1 2");
			System.out.println("2 1");
		}
		else if(k == 2) {
			System.out.println("4 5");
			System.out.println("1 2");
			System.out.println("2 1");
			System.out.println("3 4");
			System.out.println("4 3");
			System.out.println("1 4");
		}
		else {
			int nodes = 0;
			List <Connection> c = new ArrayList<Connection>();
			List <Integer> allnodes = new ArrayList<Integer>();
			while(k > 0 && k/3 > 0) {
				boolean check = false;
				int findmax = 3;
				int num = 3;
				nodes += 3;
				while(findmax < k) {
					findmax += num;
					num++;
					nodes++;
					check = true;
				}
				if(check && findmax != k) {
					num--;
					nodes--;
				}
				if(findmax > k) {
					findmax -= num;
				}
				k = k%findmax;
				allnodes.add(nodes);
			}
			int previousnode = 1;
			boolean check = false;
			while(!allnodes.isEmpty()) {
				int currentnode = allnodes.remove(0);
				for(int i = previousnode;i<currentnode;i++) {
					c.add(new Connection(i, i + 1));
				}
				c.add(new Connection(currentnode, previousnode));
				if(check) {
					c.add(new Connection(currentnode, 1));
				}
				previousnode = currentnode+1;
				check = true;
			}
			for(int i = 0;i<k;i++) {
				nodes += 2;
				c.add(new Connection(1, nodes-1));
				c.add(new Connection(nodes, nodes-1));
				c.add(new Connection(nodes-1, nodes));
			}
			System.out.println(nodes + " "  + c.size());
			while(!c.isEmpty()) {
				System.out.println(c.get(0).src + " " + c.get(0).dest);
				c.remove(0);
			}
		}
		input.close();
	}

}
