import java.util.Scanner;

public class Zeroonetwothreefourfivesixseveneightnine {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int digit = input.nextInt();
		if(digit == 0) {
			System.out.println(" * * *");
			System.out.println("*     *");
			System.out.println("*     *");
			System.out.println("*     *");
			System.out.println();
			System.out.println("*     *");
			System.out.println("*     *");
			System.out.println("*     *");
			System.out.println(" * * *");
		}
		else if(digit == 1) {
			System.out.println("*");
			System.out.println("*");
			System.out.println("*");
			System.out.println("*");
			System.out.println("*");
			System.out.println("*");
		}
		else if(digit == 2) {
			System.out.println(" * * *");
			System.out.println("      *");
			System.out.println("      *");
			System.out.println("      *");
			System.out.println(" * * *");
			System.out.println("*      ");
			System.out.println("*      ");
			System.out.println("*      ");
			System.out.println(" * * *");
		}
		else if(digit == 3) {
			System.out.println(" * * *");
			System.out.println("      *");
			System.out.println("      *");
			System.out.println("      *");
			System.out.println(" * * *");
			System.out.println("      *");
			System.out.println("      *");
			System.out.println("      *");
			System.out.println(" * * *");
		}
		else if(digit == 4) {
			System.out.println("*     *");
			System.out.println("*     *");
			System.out.println("*     *");
			System.out.println(" * * *");
			System.out.println("      *");
			System.out.println("      *");
			System.out.println("      *");
		}
		else if(digit == 5) {
			System.out.println(" * * *");
			System.out.println("*");
			System.out.println("*");
			System.out.println("*");
			System.out.println(" * * *");
			System.out.println("      *");
			System.out.println("      *");
			System.out.println("      *");
			System.out.println(" * * *");
		}
		else if(digit == 6) {
			System.out.println(" * * *");
			System.out.println("*");
			System.out.println("*");
			System.out.println("*");
			System.out.println(" * * *");
			System.out.println("*     *");
			System.out.println("*     *");
			System.out.println("*     *");
			System.out.println(" * * *");
		}
		else if(digit == 7) {
			System.out.println(" * * *");
			System.out.println("      *");
			System.out.println("      *");
			System.out.println("      *");
			System.out.println("      *");
			System.out.println("      *");
			System.out.println("      *");
		}
		else if(digit == 8) {
			System.out.println(" * * *");
			System.out.println("*     *");
			System.out.println("*     *");
			System.out.println("*     *");
			System.out.println(" * * *");
			System.out.println("*     *");
			System.out.println("*     *");
			System.out.println("*     *");
			System.out.println(" * * *");
		}
		else if(digit == 9) {
			System.out.println(" * * *");
			System.out.println("*     *");
			System.out.println("*     *");
			System.out.println("*     *");
			System.out.println(" * * *");
			System.out.println("      *");
			System.out.println("      *");
			System.out.println("      *");
			System.out.println(" * * *");
		}
		input.close();
	}
}
