import java.util.Scanner;

public class Snakesandladders {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int move = 2;
		int check = 0;
		int square = 1;
		while(check == 0) {
			move = input.nextInt();
			square = square + move;
			if(square > 100) {
				square = square - move;
			}
			if(square == 54) {
				square = square - (54-19);
			}
			else if(square == 90) {
				square = square - (90-48);
			}
			else if(square == 99) {
				square = square - (99-77);
			}
			else if(square == 9) {
				square = square + (34-9);
			}
			else if(square == 40) {
				square = square + (64-40);
			}
			else if(square == 67) {
				square = square + (86-67);
			}
			else if(move == 0) {
				check = check + 1;
				System.out.println("You Quit!");
				break;
			}
			System.out.println("You are now on square "+square);
			if(square == 100) {
				System.out.println("You Win!");
				check = check + 1;
			}
		}
		input.close();
	}

}
