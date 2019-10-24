import java.util.*;
import java.io.*;

public class CCC_17_S1_SumGame {
	public static int [] a = new int[100000];
	public static int [] b = new int[100000];
	public static void main(String [] args) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(input.readLine());
		String [] tokens = input.readLine().split(" ");
		for(int i = 0;i<n;i++) {
			a[i] = Integer.parseInt(tokens[i]);
		}
		tokens = input.readLine().split(" ");
		for(int i = 0;i<n;i++) {
			b[i] = Integer.parseInt(tokens[i]);
		}
		int max = -1;int s1 = 0;int s2 = 0;
		for(int i = 0;i<n;i++) {
			s1 += a[i];s2+=b[i];
			if(s1 == s2) {max = i;}
		}
		if(max == -1) {
			System.out.println(0);
		}
		else {
			System.out.println(max+1);
		}
		input.close();
	}

}
