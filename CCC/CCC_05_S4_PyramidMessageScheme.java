import java.util.*;
import java.io.*;

public class S4_05_PyramidMessageScheme {
	public static void main(String [] args) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int l = Integer.parseInt(input.readLine());
		for(int z = 0;z<l;z++) {
			int max = Integer.MIN_VALUE;
			int m = Integer.parseInt(input.readLine());
			HashSet<String> vis = new HashSet<String>();
			int newm = -1;
			String [] people = new String [m];
			for(int i = 0;i<m;i++) {
				String next = input.readLine();
				people[i] = next;
			}
			for(int i = people.length-1;i>=0;i--) {
				if(vis.add(people[i])) {
					newm++;
					if(newm > max) {
						max = newm;
					}
				}
				else {
					newm--;
				}
			}
			System.out.println(m*10 - max*20);
		}
		input.close();
	}

}
