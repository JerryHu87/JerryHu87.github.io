import java.util.*;
import java.io.*;

public class J2_09_OldFishingHole {
	public static void main(String [] args){
		Scanner input = new Scanner(System.in);
		int a = input.nextInt();int b = input.nextInt();int c = input.nextInt();int d = input.nextInt();int cnt = 0;
		for(int i = 0;i<=(d/a)+1;i++) {
			for(int j = 0;j<=(d/b)+1;j++) {
				for(int x = 0;x<=(d/c)+1;x++) {
					if(i == 0 && j == 0 && x == 0) {continue;}
					if(i*a+j*b+x*c<=d) {
						System.out.println(i + " Brown Trout, " + j + " Northern Pike, " + x + " Yellow Pickerel");cnt++;
					}
				}
			}
		}
		System.out.println("Number of ways to catch fish: " + cnt);
		input.close();
	}

}
