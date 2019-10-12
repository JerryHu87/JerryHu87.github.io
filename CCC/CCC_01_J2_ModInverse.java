import java.util.Scanner;

public class Modinverse {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int firstnum = input.nextInt();
		int secondnum = input.nextInt();
		int output = 0;
		for(int i = 0; i <= secondnum; i++) {
			for(int j = 0; j <= firstnum; j++) {
				if(i*firstnum == secondnum * j + 1) {
					output = i;
				}
			}
		}
		if(output > 0) {
			System.out.println(output);
		}
		
		else {
			System.out.println("No such integer exists.");
		}
		input.close();
	}
}
