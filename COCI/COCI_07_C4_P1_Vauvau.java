import java.util.*;
import java.io.*;

public class P1_07_VauVau {
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int a1 = input.nextInt();
		int a2 = input.nextInt();
		int adog = a1 + a2;
		int b1 = input.nextInt();
		int b2 = input.nextInt();
		int bdog = b1 + b2;
		int p = input.nextInt();
		int m = input.nextInt();
		int g = input.nextInt();
		if(p%adog <= a1 && p%adog != 0) {
			if(p%bdog <= b1 && p%bdog != 0) {
				System.out.println("both");
			}
			else {
				System.out.println("one");
			}
		}
		else {
			if(p%bdog <= b1 && p%bdog != 0) {
				System.out.println("one");
			}
			else {
				System.out.println("none");
			}
		}
		if(m%adog <= a1 && m%adog != 0) {
			if(m%bdog <= b1 && m%bdog != 0) {
				System.out.println("both");
			}
			else {
				System.out.println("one");
			}
		}
		else {
			if(m%bdog <= b1 && m%bdog != 0) {
				System.out.println("one");
			}
			else {
				System.out.println("none");
			}
		}
		if(g%adog <= a1 && g%adog != 0) {
			if(g%bdog <= b1 && g%bdog != 0) {
				System.out.println("both");
			}
			else {
				System.out.println("one");
			}
		}
		else {
			if(g%bdog <= b1 && g%bdog != 0) {
				System.out.println("one");
			}
			else {
				System.out.println("none");
			}
		}
		input.close();
	}

}
