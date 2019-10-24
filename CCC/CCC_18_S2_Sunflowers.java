import java.util.Scanner;

public class Sunflowers {
	private static void printArray(int [][] array) {
		for(int i = 0;i<array.length;i++) {
			for(int j = 0;j<array.length;j++) {
				System.out.print(array[i][j]+" ");
			}
			System.out.println("");
		}
	}
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int sunflowernum = input.nextInt();
		int game = 0;
		int [][] sunflowers = new int [sunflowernum][sunflowernum];
		int [] shift = new int [sunflowernum];
		for(int j = 0; j<sunflowernum;j++) {
			for(int i = 0; i<sunflowernum;i++) {
				sunflowers[j][i] = input.nextInt();
			}
		}
		for(int z = 0;z<4;z++) {
			int [][] temp = new int [sunflowernum][sunflowernum];
			int column = 0;
			boolean check = true;
			for(int rowcounter = sunflowernum-1; rowcounter>=0;rowcounter--) {
				for(int columncounter = sunflowernum-1;columncounter>=0;columncounter--) {
					shift[columncounter] = sunflowers[rowcounter][columncounter];
				}
				for(int row = sunflowernum-1; row>=0;row--) {
					temp[row][column] = shift[row];
				}
				column = column + 1;
			}
			sunflowers = temp;
			for(int j = 0;j<sunflowernum-1;j++) {
				for(int g = 0;g<sunflowernum-1;g++) {
					if(sunflowers[j][g]>sunflowers[j][g+1]) {
						check = false;
					}
					else if(sunflowers[j][g]>sunflowers[j+1][g]) {
						check = false;
					}
				}
				
			}
			if(check == true) {
				printArray(sunflowers);
				game = game+1;
			}
		}
		input.close();
	}
}
