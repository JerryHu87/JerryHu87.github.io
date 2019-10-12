import java.util.Scanner;

public class Blindfold {
	private static void printArray(String [][] anArray) {
		for(int i = 0; i<anArray.length;i++) {
			for(int j = 0; j<anArray[0].length;j++) {
				System.out.print(anArray[i][j]);
			}
		System.out.println();
		}
	}
	public static int [] forward(int direction,int [] person) {
		if(direction == 1) {
			person[0] = person[0] - 1;
		}
		else if(direction ==  2) {
			person[1] = person[1] + 1;
		}
		else if(direction == 3) {
			person[0] = person[0] + 1;
		}
		else if(direction == 4) {
			person[1] = person[1] - 1;
		}
		return person;
	}
	public static int right(int direction) {
		direction = direction + 1;
		if(direction == 5) {
			direction = 1;
		}
		return direction;
	}
	public static int left(int direction) {
		direction = direction - 1;
		if(direction == 0) {
			direction = 4;
		}
		return direction;
	}
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int row = input.nextInt();
		int column = input.nextInt();
		int [] person = new int [2];
		String [][] grid= new String [row][column];
		boolean [][] obstacles = new boolean[row][column];
		for(int z = 0;z <row;z++) {
			String gridadd = input.next();
			for(int i = 0;i < gridadd.length();i++) {
				grid[z][i] = gridadd.substring(i,i+1);
			}
		}
		for(int h = 0;h<row;h++){
			for(int k = 0; k<column;k++){
				if(grid[h][k].equals(".")) {
					obstacles[h][k] = true;
				}
				else if(grid[h][k].equals("X")) {
					obstacles[h][k] = false;
				}
			}
		}
		int directionnum = input.nextInt();
		String [] directions = new String [directionnum];
		for(int r = 0; r<directionnum;r++) {
			String newdirection = input.next();
			directions[r] = newdirection;
		}
		for(int q = 0;q<row;q++) {
			for(int s = 0;s<column;s++) {
				if(obstacles[q][s] == true) {
					for(int y = 1;y<= 4;y++) {
						int direction = y;
						boolean check = true;
						person[0] = q;
						person[1] = s;
						for(int r = 0;r < directions.length;r++) {
							if(directions[r].equals("R")) {
								direction = right(direction);
							}
							else if(directions[r].equals("L")) {
								direction = left(direction);
									
							}
							else if(directions[r].equals("F")) {
								person = forward(direction, person);
								if(person[0] > row || person[0] < 0 || person[1] >column || person[1] < 0) {
									check = false;
								}
								else if(person[0] < row && person[0] >= 0 && person[1] < column && person[1] >= 0) {
									if(obstacles[person[0]][person[1]] == false) {
										check = false;
									}
								}
							}
						}
						if(person[0] < row && person[0] >= 0 && person[1] <column && person[1] >= 0) {
							if(check == true && obstacles[person[0]][person[1]] == true && person[0] < row && person[0] >= 0 && person[1] <column && person[1] >= 0) {
								grid[person[0]][person[1]] = "*";
							}
						}
					}
				}
			}
		}
		printArray(grid);
		input.close();
	}
}
