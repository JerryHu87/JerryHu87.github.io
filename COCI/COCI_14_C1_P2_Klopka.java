import java.io.*;

public class P2_14_Klopka {
	public static void main(String [] args) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(input.readLine());
		int minx = Integer.MAX_VALUE;
		int miny = Integer.MAX_VALUE;
		int maxx = Integer.MIN_VALUE;
		int maxy = Integer.MIN_VALUE;
		for(int i = 0;i<n;i++) {
			String [] tokens = input.readLine().split(" ");
			int x = Integer.parseInt(tokens[0]);
			int y = Integer.parseInt(tokens[1]);
			if(x < minx) {
				minx = x;
			}
			else if(x > maxx) {
				maxx = x;
			}
			if(y < miny) {
				miny = y;
			}
			else if(y > maxy) {
				maxy = y;
			}
		}
		int finalx = maxx-minx;
		int finaly = maxy-miny;
		if(finalx>finaly) {
			System.out.println(finalx * finalx);
		}
		else if(finalx == finaly) {
			System.out.println(finalx * finaly);
		}
		else {
			System.out.println(finaly * finaly);
		}
	}

}
