import java.util.*;
import java.io.*;

public class S1_10_ComputerPurchase {
	public static void main(String [] args) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(input.readLine());
		long [] cost = new long [n];
		String [] name = new String [n];
		for(int i = 0;i<n;i++) {
			String [] tokens = input.readLine().split(" ");
			name[i] = tokens[0];
			cost[i] = (2*Integer.parseInt(tokens[1]))+(3*Integer.parseInt(tokens[2]))+Integer.parseInt(tokens[3]);
		}
		long max1 = Integer.MIN_VALUE;
		String maxn1 = "";
		int index = 0;
		for(int i = 0;i<n;i++) {
			if(cost[i] > max1) {
				max1 = cost[i];
				maxn1 = name[i];
				index = i;
			}
		}
		long max2 = Integer.MIN_VALUE;
		String maxn2 = "";
		for(int i = 0;i<n;i++) {
			if(i != index && cost[i] > max2) {
				max2 = cost[i];
				maxn2 = name[i];
			}
		}
		if(max1 == max2 && maxn1.compareTo(maxn2) == 0) {
			System.out.println(maxn1);
		}
		else if(max1 == max2 && maxn1.compareTo(maxn2) > 0) {
			System.out.println(maxn2);
			System.out.println(maxn1);
		}
		else{
			System.out.println(maxn1);
			System.out.println(maxn2);
		}
		input.close();
	}

}
