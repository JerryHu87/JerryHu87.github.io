import java.util.Scanner;
import java.util.*;

public class SheepsandCoyotes {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int sheepnum = input.nextInt();
		double [][] sheeps = new double [sheepnum][2];
		List<Double> minimum1 = new ArrayList<Double>();
		List<Double> minimum2= new ArrayList<Double>();
		for(int i = 0; i<sheepnum;i++) {
			double xadd = input.nextDouble();
			double yadd = input.nextDouble();
			sheeps[i][0] = xadd;
			sheeps[i][1] = yadd;
		}
		for(double i = 0.00;i<1000.01;i = i+0.01) {
			double [] distances = new double [sheepnum];
			int minimumindex = 0;
			for(int h = 0;h<sheepnum;h++) {
				distances[h] = Math.sqrt(((i-sheeps[h][0])*(i-sheeps[h][0]))+((0.00-sheeps[h][1])*(0.00-sheeps[h][1])));
			}
			for(int u = 0;u<sheepnum;u++) {
				if(distances[u] < distances[minimumindex]) {
					minimumindex = u;	
				}
			}
			if(minimum1.size() != 0) {
				if(sheeps[minimumindex][0] != minimum1.get(minimum1.size()-1) || sheeps[minimumindex][1] != minimum2.get(minimum2.size()-1)) {
					minimum1.add(sheeps[minimumindex][0]);
					minimum2.add(sheeps[minimumindex][1]);
				}
			}
			else {
				minimum1.add(sheeps[minimumindex][0]);
				minimum2.add(sheeps[minimumindex][1]);
			}
		}
		int minimumlength = minimum1.size();
		for(int i = 0; i<minimumlength; i++) {
			System.out.print("The sheep at (");
			System.out.printf("%.2f", minimum1.get(i));
			System.out.print(", ");
			System.out.printf("%.2f", minimum2.get(i));
			System.out.print(") might be eaten.");
			System.out.println();
		}
		input.close();
	}
}
