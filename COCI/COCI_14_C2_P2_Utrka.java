import java.util.*;
import java.io.*;

public class P2_14_Utrka {
	public static void main(String [] args) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(input.readLine());
		HashSet<String> cont = new HashSet<String>(n);
		List<String> repeat = new ArrayList<String>();
		String temp = "";
		for(int i = 0;i<n;i++) {
			temp = input.readLine();
			if(cont.add(temp) == false) {
				repeat.add(temp);
			}
			else {
				cont.add(temp);
			}
		}
		for(int i = 0;i<n-1;i++) {
			temp = input.readLine();
			if(cont.remove(temp) == false) {
				repeat.remove(temp);
			}
			else {
				cont.remove(temp);
			}
		}
		Iterator i = cont.iterator();
		if(i.hasNext()) {
			System.out.println(i.next());
		}
		else {
			System.out.println(repeat.get(0));
		}
	}

}
