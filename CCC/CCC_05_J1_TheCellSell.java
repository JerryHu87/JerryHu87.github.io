import java.io.*;
import java.util.*;

public class TheCellSell {
	public static void main(String args[]) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		String temp = input.readLine();
		double day = Integer.parseInt(temp);
		temp = input.readLine();
		double evening = Integer.parseInt(temp);
		temp = input.readLine();
		double weekend = Integer.parseInt(temp);
		double asum = 0;
		double bsum = 0;
		if(day>100) {
			asum = asum + 0.25 * (day-100);
		}
		asum = asum + 0.15 * evening + 0.20 * weekend;
		if(day>250) {
			bsum = bsum + 0.45 * (day-250);
		}
		bsum = bsum + 0.35 * evening + 0.25 * weekend;
		long inttemp = Math.round(asum * 100);
		asum = inttemp * 0.01;
		inttemp = Math.round(bsum * 100);
		bsum = inttemp * 0.01;
		System.out.println("Plan A costs " + asum);
		System.out.println("Plan B costs " + bsum);
		if(asum < bsum) {
			System.out.println("Plan A is cheapest.");
		}
		else if(bsum < asum) {
			System.out.println("Plan B is cheapest.");
		}
		else {
			System.out.println("Plan A and B are the same price.");
		}
	}

}
