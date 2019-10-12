import java.util.Scanner;

public class Squares {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int tiles = input.nextInt();
		double number = Math.sqrt(tiles);
		System.out.println("The largest square has side length " + (int)number + ".");
		input.close();
	}
}
