import java.util.Scanner;

public class Dressingup {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int height = input.nextInt();
		String staradd = "**";
		String filler = "  ";
		int num = 0;
		if(height%2 == 1) {
			num = num + 1;
		}
		for(int i = 0;i < height/2 + num;i++) {
			System.out.print("*");
			for(int j = 0; j<i;j++) {
				System.out.print(staradd);
			}
			for(int r = 0; r<height/2-i;r++) {
				System.out.print(filler);
			}
			for(int s = 0; s<height/2-i;s++) {
				System.out.print(filler);
			}
			for(int t = 0; t<i;t++) {
				System.out.print(staradd);
			}
			System.out.print("*");
			System.out.println();
		}
		for(int d = 1;d<height/2+1;d++) {
			System.out.print("*");
			for(int u = 0;u<height/2-d;u++) {
				System.out.print(staradd);
			}
			for(int h = 0;h<d;h++) {
				System.out.print(filler);
			}
			for(int f = 0;f<d;f++) {
				System.out.print(filler);
			}
			for(int y = 0;y<height/2-d;y++) {
				System.out.print(staradd);
			}
			System.out.print("*");
			System.out.println();
		}
		input.close();
	}
}
