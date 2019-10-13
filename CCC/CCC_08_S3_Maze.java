import java.util.*;
import java.io.*;

public class S3_08_Maze {
	public static class Point{
		byte r;
		byte c;
		public Point(byte R, byte C){
			r = R;
			c = C;
		}
	}
	public static void main(String [] args) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		byte t = Byte.parseByte(input.readLine());
		for(int z = 0;z<t;z++) {
			byte r = Byte.parseByte(input.readLine());
			byte c = Byte.parseByte(input.readLine());
			char [][] grid = new char[r][c];
			short [][] min = new short [r][c];
			for(int i = 0;i<r;i++) {
				String tokens = input.readLine();
				for(int j = 0;j<c;j++) {
					grid[i][j] = tokens.charAt(j);
					min[i][j] = Short.MAX_VALUE;
				}
			}
			Deque<Point> d = new ArrayDeque<Point>();
			min[0][0] = 1;
			d.push(new Point((byte)0,(byte)0));
			while(!d.isEmpty()) {
				Point currentpoint = d.pop();
				if(grid[currentpoint.r][currentpoint.c] == '|') {
					if(currentpoint.r + 1 < r && min[currentpoint.r+1][currentpoint.c] > min[currentpoint.r][currentpoint.c]+1 && grid[currentpoint.r+1][currentpoint.c] != '*') {
						d.push(new Point((byte)(currentpoint.r+1),currentpoint.c));
						min[currentpoint.r+1][currentpoint.c] = (short)(min[currentpoint.r][currentpoint.c] + 1);
					}
					if(currentpoint.r -1 >= 0 && min[currentpoint.r-1][currentpoint.c] > min[currentpoint.r][currentpoint.c]+1&& grid[currentpoint.r-1][currentpoint.c] != '*') {
						d.push(new Point((byte)(currentpoint.r-1),currentpoint.c));
						min[currentpoint.r-1][currentpoint.c] = (short)(min[currentpoint.r][currentpoint.c] + 1);
					}
				}
				else if(grid[currentpoint.r][currentpoint.c] == '-') {
					if(currentpoint.c + 1 < c && min[currentpoint.r][currentpoint.c+1] > min[currentpoint.r][currentpoint.c]+1&& grid[currentpoint.r][currentpoint.c+1] != '*') {
						d.push(new Point(currentpoint.r,(byte)(currentpoint.c+1)));
						min[currentpoint.r][currentpoint.c+1] = (short)(min[currentpoint.r][currentpoint.c] + 1);
					}
					if(currentpoint.c -1 >= 0 && min[currentpoint.r][currentpoint.c-1] > min[currentpoint.r][currentpoint.c]+1&& grid[currentpoint.r][currentpoint.c-1] != '*') {
						d.push(new Point(currentpoint.r,(byte)(currentpoint.c-1)));
						min[currentpoint.r][currentpoint.c-1] = (short)(min[currentpoint.r][currentpoint.c] + 1);
					}
				}
				else if(grid[currentpoint.r][currentpoint.c] == '+') {
					if(currentpoint.r + 1 < r && min[currentpoint.r+1][currentpoint.c] > min[currentpoint.r][currentpoint.c]+1 && grid[currentpoint.r+1][currentpoint.c] != '*') {
						d.push(new Point((byte)(currentpoint.r+1),currentpoint.c));
						min[currentpoint.r+1][currentpoint.c] = (short)(min[currentpoint.r][currentpoint.c] + 1);
					}
					if(currentpoint.r -1 >= 0 && min[currentpoint.r-1][currentpoint.c] > min[currentpoint.r][currentpoint.c]+1 && grid[currentpoint.r-1][currentpoint.c] != '*') {
						d.push(new Point((byte)(currentpoint.r-1),currentpoint.c));
						min[currentpoint.r-1][currentpoint.c] = (short)(min[currentpoint.r][currentpoint.c] + 1);
					}
					if(currentpoint.c + 1 < c && min[currentpoint.r][currentpoint.c+1] > min[currentpoint.r][currentpoint.c]+1 && grid[currentpoint.r][currentpoint.c+1] != '*') {
						d.push(new Point(currentpoint.r,(byte)(currentpoint.c+1)));
						min[currentpoint.r][currentpoint.c+1] = (short)(min[currentpoint.r][currentpoint.c] + 1);
					}
					if(currentpoint.c -1 >= 0 && min[currentpoint.r][currentpoint.c-1] > min[currentpoint.r][currentpoint.c]+1 && grid[currentpoint.r][currentpoint.c-1] != '*') {
						d.push(new Point(currentpoint.r,(byte)(currentpoint.c-1)));
						min[currentpoint.r][currentpoint.c-1] = (short)(min[currentpoint.r][currentpoint.c] + 1);
					}
				}
			}
			if(min[r-1][c-1] == Short.MAX_VALUE) {
				System.out.println(-1);
			}
			else {
				System.out.println(min[r-1][c-1]);
			}
		}
		input.close();
	}

}
