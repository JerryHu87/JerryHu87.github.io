import java.util.Scanner;

public class Voronovillages {
	private static void bubblesort(double [] anArray) {
		for(int i = 0;i<anArray.length;i++) {
			for(int j = 0;j<anArray.length-i-1;j++) {
				if(anArray[j] > anArray[j+1]) {
					double temp = anArray[j+1];
					anArray[j+1] = anArray[j];
					anArray[j] = temp;
				}
			}
		}
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		double minimum = Double.MAX_VALUE;
		int villagenum = input.nextInt();
		double [] village = new double[villagenum];
		for(int villagecount = 0; villagecount<villagenum;villagecount++) {
			double villageadd = input.nextDouble();
			village[villagecount] = villageadd;
		}
		bubblesort(village);
		for(int i = 1; i < village.length-1;i++) {
			double village1 = (village[i] - village[i-1])/2;
			double village2 = (village[i+1] - village[i])/2;
			if(village1 + village2 < minimum) {
				minimum = village1 + village2;
			}
		}
	System.out.printf("%.1f", minimum);
	input.close();
	}
}
