import java.util.*;
import java.io.*;

public class S3_17_NailedIt {
	public static void main(String [] args) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(input.readLine());
		String [] tokens = input.readLine().split(" ");
		int [] f = new int [2001];
		int [] s = new int [4001];
		for(int i = 0;i<n;i++) {
			f[Integer.parseInt(tokens[i])]++;
		}
		for(int i = 1;i<=2000;i++) {
			if(f[i] > 0) {
				for(int j = i;j<=2000;j++) {
					if(i == j) {
						s[i + j] = s[i + j] + f[i]/2; 
					}
					else if(f[i] > 0 && f[i] > 0) {
						s[i + j] = s[i+j] + Math.min(f[i],f[j]);
					}
				}
			}
		}
		int maxf = 0;
		int diffh = 1;
		for(int i = 1;i<=4000;i++) {
			if(s[i] > maxf) {
				maxf = s[i];
				diffh = 1;
			}
			else if(s[i] == maxf) {
				diffh++;
			}
		}
		System.out.println(maxf + " " + diffh);
	}

}
