import java.util.*;
import java.io.*;

public class Super_Plumber {
	public static void main(String [] args) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		String [] tokens = input.readLine().split(" ");
		int m = Integer.parseInt(tokens[0]);
		int n = Integer.parseInt(tokens[1]);
		int [][] grid = new int [100][100];
		int [][] dp = new int [100][100];
		boolean [][] visited = new boolean [100][100];
		while(n != 0 && m != 0) {
			for(int i = 0;i<m;i++) {
				String temp = input.readLine();
				for(int j = 0;j<n;j++) {
					char t = temp.charAt(j);
					if(t == '*') {
						grid[i][j] = -1;
					}
					else if(t == '.') {
						grid[i][j] = 0;
					}
					else {
						grid[i][j] = temp.charAt(j)-'0';
					}
					dp[i][j] = 0;
					visited[i][j] = false;
				}	
			}
			dp[m-1][0] = grid[m-1][0];
			for(int i = m-2;i>=0;i--) {
				if(grid[i][0] != -1) {dp[i][0] = dp[i+1][0] +grid[i][0];visited[i][0] = true;}
			}
			visited[m-1][0] = true;
			for(int i = 0;i<n-1;i++) {
				for(int j =  0;j<m;j++) {
					if(grid[j][i] != -1 && visited[j][i]) {
						int sum = dp[j][i];
						for(int z = j;z>=0;z--) {
							if(grid[z][i+1] == -1) {break;}
							sum +=grid[z][i+1];
							if(sum > dp[z][i+1]) {dp[z][i+1] = sum;}
							visited[z][i+1] = true;
						}
						sum = dp[j][i];
						for(int z = j;z<m;z++) {
							if(grid[z][i+1] == -1) {break;}
							sum +=grid[z][i+1];
							if(sum > dp[z][i+1]) {dp[z][i+1] = sum;}
							visited[z][i+1] = true;
						}
					}
				}
			}
			System.out.println(dp[m-1][n-1]);
			tokens = input.readLine().split(" ");
			m = Integer.parseInt(tokens[0]);
			n = Integer.parseInt(tokens[1]);
		}
		input.close();
	}

}
