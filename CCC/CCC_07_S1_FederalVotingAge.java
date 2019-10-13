import java.util.Scanner;

public class Federalvotingage {
	private static void printArray(String [] anArray) {
		for(int i = 0;i<anArray.length;i++) {
			System.out.println(anArray[i]);
		}
	}
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int birthdaynum = input.nextInt();
		int [] year = new int [birthdaynum];
		int [] month = new int [birthdaynum];
		int [] day = new int [birthdaynum];
		String [] check = new String[birthdaynum];
		for(int i = 0; i<birthdaynum;i++) {
			int yearadd = input.nextInt();
			year[i] = yearadd;
			int monthadd = input.nextInt();
			month[i] = monthadd;
			int dayadd = input.nextInt();
			day[i] = dayadd;
		}
		for(int j = 0; j<birthdaynum;j++) {
			if(year[j] <= 1988) {
				check[j] = "Yes";
			}
			else if(year[j] >= 1990) {
				check[j] = "No";
			}
			else if(year[j] == 1989 && month[j] < 2) {
				check[j] = "Yes";
			}
			else if(year[j] == 1989 && month[j] > 2) {
				check[j] = "No";
			}
			else if(year[j] == 1989 && month[j] == 2 && day[j] <= 27) {
				check[j] = "Yes";
			}
			else if(year[j] == 1989 && month[j] == 2 && day[j] > 27) {
				check[j] = "No";
			}
		}
		printArray(check);
		input.close();
	}
}
