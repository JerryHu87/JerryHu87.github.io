import java.util.*;

public class J5_09_DegreesOfSeparation {
	public static void main(String [] args){
		Scanner input = new Scanner(System.in);
		List<Integer> [] friends = new ArrayList [51];
		for(int i = 1;i<=50;i++) {
			friends[i] = new ArrayList();
		}
		friends[1].add(6);
		friends[6].add(1);
		friends[2].add(6);
		friends[6].add(2);
		friends[7].add(6);
		friends[6].add(7);
		friends[3].add(6);
		friends[6].add(3);
		friends[5].add(6);
		friends[6].add(5);
		friends[4].add(6);
		friends[6].add(4);
		friends[3].add(4);
		friends[4].add(3);
		friends[4].add(5);
		friends[5].add(4);
		friends[3].add(5);
		friends[5].add(3);
		friends[3].add(15);
		friends[15].add(3);
		friends[7].add(8);
		friends[8].add(7);
		friends[9].add(8);
		friends[8].add(9);
		friends[10].add(9);
		friends[9].add(10);
		friends[11].add(10);
		friends[10].add(11);
		friends[9].add(12);
		friends[12].add(9);
		friends[12].add(11);
		friends[11].add(12);
		friends[13].add(12);
		friends[12].add(13);
		friends[13].add(15);
		friends[15].add(13);
		friends[14].add(13);
		friends[13].add(14);
		friends[16].add(17);
		friends[17].add(16);
		friends[17].add(18);
		friends[18].add(17);
		friends[16].add(18);
		friends[18].add(16);
		String tokens = " ";
		while(tokens.charAt(0) != 'q') {
			tokens = input.next();
			if(tokens.charAt(0) == 'i') {
				int src = input.nextInt();
				int dest = input.nextInt();
				if(!friends[src].contains(dest)) {
					friends[src].add(dest);
					friends[dest].add(src);
				}
 			}
			else if(tokens.charAt(0) == 'd') {
				int src = input.nextInt();
				int dest = input.nextInt();
				friends[src].remove(friends[src].indexOf(dest));
				friends[dest].remove(friends[dest].indexOf(src));
			}
			else if(tokens.charAt(0) == 'n') {
				int src = input.nextInt();
				System.out.println(friends[src].size());
			}
			else if(tokens.charAt(0) == 'f') {
				int src = input.nextInt();
				HashSet <Integer> t = new HashSet<Integer>();
				for(int i = 0;i<friends[src].size();i++) {
					t.addAll(friends[friends[src].get(i)]);
				}
				for(int i = 0;i<friends[src].size();i++) {
					while(t.contains(friends[src].get(i))) {
						t.remove(friends[src].get(i));
					}
				}
				while(t.contains(src)) {
					t.remove(src);
				}
				System.out.println(t.size());
				t.clear();
			}
			else if(tokens.charAt(0) == 's'){
				int src = input.nextInt();
				int dest = input.nextInt();
				LinkedList<Integer> q = new LinkedList<Integer>();
				int [] distances = new int [51];
				for(int i = 1;i<=50;i++) {
					distances[i] = Integer.MAX_VALUE;
				}
				q.add(src);
				distances[src] = 0;
				while(!q.isEmpty()) {
					int currentnode = q.pop();
					for(int j = 0;j<friends[currentnode].size();j++) {
						if(distances[friends[currentnode].get(j)] > distances[currentnode] + 1) {
							distances[friends[currentnode].get(j)] = distances[currentnode] + 1;
							q.add(friends[currentnode].get(j));
						}
					}
				}
				if(distances[dest] == Integer.MAX_VALUE) {
					System.out.println("Not connected");
				}
				else {
					System.out.println(distances[dest]);
				}
			}
		}
		input.close();
	}

}
