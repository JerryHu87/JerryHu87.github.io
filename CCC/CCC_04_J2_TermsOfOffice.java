import java.io.*;
import java.util.*;

public class TermsofOffice {
	public static void main(String args[])throws IOException {
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		String temp = input.readLine();
		int startdate = Integer.parseInt(temp);
		temp = input.readLine();
		int enddate = Integer.parseInt(temp);
		int mayor = 0;
		int treasure = 0;
		int dog = 0;
		int chief = 0;
		for(int i = startdate;i<=enddate;i++) {
			if(mayor == 4) {
				mayor = 0;
			}
			if(treasure == 2) {
				treasure = 0;
			}
			if(dog == 5) {
				dog = 0;
			}
			if(chief == 3) {
				chief = 0;
			}
			if(chief == 0 && mayor == 0 && dog == 0 && chief == 0) {
				System.out.println("All positions change in year " + i);
			}
			mayor = mayor + 1;
			treasure = treasure + 1;
			chief = chief + 1;
			dog = dog + 1;
		}
	}
}
