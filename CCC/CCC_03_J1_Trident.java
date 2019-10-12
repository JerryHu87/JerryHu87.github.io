import java.util.Scanner;

public class Trident {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		int s = input.nextInt();
		int h = input.nextInt();
		String spaces = "";
		for(int i = 0; i<s;i++) {
			spaces = spaces + " ";
		}
		int totallength = spaces.length() * 2 + 3;
		for(int j = 0; j < t;j++) {
			for(int i = 0; i<3;i++) {
				System.out.print("*");
				System.out.print(spaces);
			}
			System.out.println();
		}
		for(int i = 0; i<totallength;i++) {
			System.out.print("*");
		}
		System.out.println();
		for(int i = 0; i<h;i++) {
			System.out.print(spaces + " ");
			System.out.println("*");
		}
		input.close();
	}
}
