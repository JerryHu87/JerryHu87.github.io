import java.util.*;
import java.io.*;

public class S3_18_RoboThieves {
	public static class Point{
		int r;
		int c;
		public Point(int R, int C) {
			r = R;
			c = C;
		}
	}
	public static void main(String [] args) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		String [] tokens = input.readLine().split(" ");
		int n = Integer.parseInt(tokens[0]);
		int m = Integer.parseInt(tokens[1]);
		char [][] grid = new char [n][m];
		boolean [][] cameras = new boolean[n][m];
		int [][] answers = new int [n][m];
		boolean [][] visited = new boolean [n][m];
		List <Point> clocations = new ArrayList<Point>();
		Point start = new Point(0,0);
		for(int i = 0;i<n;i++) {
			String temp = input.readLine();
			for(int j = 0;j<m;j++) {
				grid[i][j] = temp.charAt(j);
				if(grid[i][j] == 'C') {
					clocations.add(new Point(i,j));
				}
				else if(grid[i][j] == 'S') {
					start = new Point(i, j);
				}
				answers[i][j] = Integer.MAX_VALUE;
			}
		}
		while(!clocations.isEmpty()) {
			int cr = clocations.get(0).r;
			int cc = clocations.remove(0).c;
			int temp = cr;
			while(grid[temp][cc] != 'W') {
				cameras[temp][cc] = true;
				temp++;
			}
			temp = cr;
			while(grid[temp][cc] != 'W') {
				cameras[temp][cc] = true;
				temp--;
			}
			temp = cc;
			while(grid[cr][temp] != 'W') {
				cameras[cr][temp] = true;
				temp++;
			}
			temp = cc;
			while(grid[cr][temp] != 'W') {
				cameras[cr][temp] = true;
				temp--;
			}
		}
		if(cameras[start.r][start.c]) {
			for(int i = 0;i<n;i++) {
				for(int j = 0;j<m;j++) {
					if(grid[i][j] == '.') {
						System.out.println(-1);
					}
				}
			}
			System.exit(0);
		}
		answers[start.r][start.c] = 0;
		LinkedList<Point> q = new LinkedList<Point>();
		q.add(start);
		while(!q.isEmpty()) {
			int currentr = q.peek().r;
			int currentc = q.pop().c;
			if(currentr + 1 < n && grid[currentr+1][currentc] != 'W' && grid[currentr+1][currentc] != 'S') {
				int tempr = currentr+1;
				int tempc = currentc;
				while(grid[tempr][tempc] != '.' && grid[tempr][tempc] != 'S' && visited[tempr][tempc] == false) {
					if(visited[tempr][tempc]) {
						tempr = start.r;
						tempc = start.c;
						break;
					}
					if(grid[tempr][tempc] == 'D') {
						visited[tempr][tempc] = true;
						tempr++;
					}
					else if(grid[tempr][tempc] == 'U') {
						visited[tempr][tempc] = true;
						tempr--;
					}
					else if(grid[tempr][tempc] == 'R') {
						visited[tempr][tempc] = true;
						tempc++;
					}
					else if(grid[tempr][tempc] == 'L') {
						visited[tempr][tempc] = true;
						tempc--;
					}
					else {
						tempr = start.r;
						tempc = start.c;
						break;
					}
					if(grid[tempr][tempc] == 'W') {cameras[tempr][tempc] = true;}
				}
				if(cameras[tempr][tempc] == false && answers[tempr][tempc] > answers[currentr][currentc] + 1 && visited[tempr][tempc] == false) {
					q.add(new Point(tempr, tempc));
					answers[tempr][tempc] = answers[currentr][currentc] + 1;
				}
			}
			if(currentr - 1 >= 0 && grid[currentr-1][currentc] != 'W' && grid[currentr-1][currentc] != 'S') {
				int tempr = currentr-1;
				int tempc = currentc;
				while(grid[tempr][tempc] != '.' && grid[tempr][tempc] != 'S' && visited[tempr][tempc] == false) {
					if(visited[tempr][tempc]) {
						tempr = start.r;
						tempc = start.c;
						break;
					}
					if(grid[tempr][tempc] == 'D') {
						visited[tempr][tempc] = true;
						tempr++;
					}
					else if(grid[tempr][tempc] == 'U') {
						visited[tempr][tempc] = true;
						tempr--;
					}
					else if(grid[tempr][tempc] == 'R') {
						visited[tempr][tempc] = true;
						tempc++;
					}
					else if(grid[tempr][tempc] == 'L') {
						visited[tempr][tempc] = true;
						tempc--;
					}
					else {
						tempr = start.r;
						tempc = start.c;
						break;
					}
					if(grid[tempr][tempc] == 'W') {cameras[tempr][tempc] = true;}
				}
				if(cameras[tempr][tempc] == false && answers[tempr][tempc] > answers[currentr][currentc] + 1 && visited[tempr][tempc] == false) {
					q.add(new Point(tempr, tempc));
					answers[tempr][tempc] = answers[currentr][currentc] + 1;
				}
			}
			if(currentc + 1 < m && grid[currentr][currentc+1] != 'W' && grid[currentr][currentc+1] != 'S') {
				int tempr = currentr;
				int tempc = currentc+1;
				while(grid[tempr][tempc] != '.' && grid[tempr][tempc] != 'S' && visited[tempr][tempc] == false) {
					if(visited[tempr][tempc]) {
						tempr = start.r;
						tempc = start.c;
						break;
					}
					if(grid[tempr][tempc] == 'D') {
						visited[tempr][tempc] = true;
						tempr++;
					}
					else if(grid[tempr][tempc] == 'U') {
						visited[tempr][tempc] = true;
						tempr--;
					}
					else if(grid[tempr][tempc] == 'R') {
						visited[tempr][tempc] = true;
						tempc++;
					}
					else if(grid[tempr][tempc] == 'L') {
						visited[tempr][tempc] = true;
						tempc--;
					}
					else {
						tempr = start.r;
						tempc = start.c;
						break;
					}
					if(grid[tempr][tempc] == 'W') {cameras[tempr][tempc] = true;}
				}
				if(cameras[tempr][tempc] == false && answers[tempr][tempc] > answers[currentr][currentc] + 1 && visited[tempr][tempc] == false) {
					q.add(new Point(tempr, tempc));
					answers[tempr][tempc] = answers[currentr][currentc] + 1;
				}
			}
			if(currentc - 1 >= 0 && grid[currentr][currentc-1] != 'W' && grid[currentr][currentc-1] != 'S') {
				int tempr = currentr;
				int tempc = currentc-1;
				while(grid[tempr][tempc] != '.' && grid[tempr][tempc] != 'S' && visited[tempr][tempc] == false) {
					if(visited[tempr][tempc]) {
						tempr = start.r;
						tempc = start.c;
						break;
					}
					if(grid[tempr][tempc] == 'D') {
						visited[tempr][tempc] = true;
						tempr++;
					}
					else if(grid[tempr][tempc] == 'U') {
						visited[tempr][tempc] = true;
						tempr--;
					}
					else if(grid[tempr][tempc] == 'R') {
						visited[tempr][tempc] = true;
						tempc++;
					}
					else if(grid[tempr][tempc] == 'L') {
						visited[tempr][tempc] = true;
						tempc--;
					}
					else {
						tempr = start.r;
						tempc = start.c;
						break;
					}
					if(grid[tempr][tempc] == 'W') {cameras[tempr][tempc] = true;}
				}
				if(cameras[tempr][tempc] == false && answers[tempr][tempc] > answers[currentr][currentc] + 1 && visited[tempr][tempc] == false) {
					q.add(new Point(tempr, tempc));
					answers[tempr][tempc] = answers[currentr][currentc] + 1;
				}
			}
		}
		for(int i = 0;i<n;i++) {
			for(int j = 0;j<m;j++) {
				if(grid[i][j] == '.') {
					if(answers[i][j] == Integer.MAX_VALUE || cameras[i][j]) {answers[i][j] = -1;}
					System.out.println(answers[i][j]);
				}
			}
		}
		input.close();
	}

}
