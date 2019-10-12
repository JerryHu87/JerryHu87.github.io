import java.util.*;
import java.io.*;

public class S3_03_FloorPlan {
	public static class Point{
		int r;
		int c;
		public Point(int R, int C){
			r = R;
			c = C;
		}
	}
	public static void main(String [] args) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int flooring = Integer.parseInt(input.readLine());
		int r = Integer.parseInt(input.readLine());
		int c = Integer.parseInt(input.readLine());
		boolean [][] grid = new boolean [r][c];
		boolean [][] visited = new boolean [r][c];
		for(int i = 0;i<r;i++) {
			String temp = input.readLine();
			for(int j = 0;j<c;j++) {
				if(temp.charAt(j) == 'I') {
					grid[i][j] = false;
					visited[i][j] = true;
				}
				else {
					grid[i][j] = true;
				}
			}
		}
		List<Integer> rooms = new ArrayList<Integer>();
		for(int i = 0;i<r;i++) {
			for(int j = 0;j<c;j++) {
				if(grid[i][j] == true && visited[i][j] == false) {
					LinkedList<Point> q = new LinkedList<Point>();
					q.add(new Point(i,j));
					visited[i][j] = true;
					int space = 0;
					while(!q.isEmpty()) {
						int currentr = q.peek().r;
						int currentc = q.pop().c;
						space++;
						if(currentr + 1 < r && visited[currentr+1][currentc] == false && grid[currentr+1][currentc] == true) {
							q.add(new Point(currentr+1, currentc));
							visited[currentr+1][currentc] = true;
						}
						if(currentr - 1 >= 0 && visited[currentr-1][currentc] == false && grid[currentr-1][currentc] == true) {
							q.add(new Point(currentr-1, currentc));
							visited[currentr-1][currentc] = true;
						}
						if(currentc - 1 >= 0 && visited[currentr][currentc-1] == false && grid[currentr][currentc-1] == true) {
							q.add(new Point(currentr, currentc-1));
							visited[currentr][currentc-1] = true;
						}
						if(currentc + 1 < c && visited[currentr][currentc+1] == false && grid[currentr][currentc+1] == true) {
							q.add(new Point(currentr, currentc+1));
							visited[currentr][currentc+1] = true;
						}
					}
					rooms.add(space);
				}
			}
		}
		Collections.sort(rooms);
		int squaremeter = flooring;
		int room = 0;
		boolean check = true;
		while(check) {
			check = false;
			if(rooms.isEmpty()) {break;}
			if(squaremeter - rooms.get(rooms.size()-1) >= 0) {
				squaremeter -= rooms.get(rooms.size()-1);
				rooms.remove(rooms.size()-1);
				room++;
				check = true;
			}
		}
		if(room == 1) {
			System.out.println(room + " room, " + squaremeter + " square metre(s) left over");
		}
		else {
			System.out.println(room + " rooms, " + squaremeter + " square metre(s) left over");
		}
		input.close();
	}

}
