import java.util.Scanner;

public class Fractionaction {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int numerator = input.nextInt();
		int denominator = input.nextInt();
		for(int j = 1;j<numerator; j++) {
			for(int i = 1; i < numerator; i++) {
				if(numerator%i == 0 && denominator%i == 0) {
					numerator = numerator/i;
					denominator = denominator/i;
				}
			}
		}
		if (denominator > 1) {
			if(numerator>denominator) {
				System.out.print(numerator/denominator + "");
				numerator = numerator - (denominator * (numerator/denominator));
			}
				System.out.println(numerator + "/"  + denominator);
		}
		else if(denominator == 1) {
			System.out.println(numerator);
		}
		input.close();
	}

}
