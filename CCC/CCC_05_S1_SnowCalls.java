import java.util.Scanner;
import java.util.*;

public class SnowCalls {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int phonenum = input.nextInt();
		for(int i = 0;i<phonenum;i++) {
			String phone = input.next();
			List <Character> nums = new ArrayList<Character>();
			char [] finalnum = new char[10];
			for(int j = 0;j<phone.length();j++) {
				if(phone.charAt(j) != '-') {
					nums.add(phone.charAt(j));
				}
			}
			for(int j = 0;j<10;j++) {
				if(nums.get(j) == 'A' || nums.get(j) == 'B' || nums.get(j) == 'C') {
					finalnum[j] = '2';
				}
				else if(nums.get(j) == 'D' || nums.get(j) == 'E' || nums.get(j) == 'F') {
					finalnum[j] = '3';
				}
				else if(nums.get(j) == 'G' || nums.get(j) == 'H' || nums.get(j) == 'I') {
					finalnum[j] = '4';
				}
				else if(nums.get(j) == 'J' || nums.get(j) == 'K' || nums.get(j) == 'L') {
					finalnum[j] = '5';
				}
				else if(nums.get(j) == 'M' || nums.get(j) == 'N' || nums.get(j) == 'O') {
					finalnum[j] = '6';
				}
				else if(nums.get(j) == 'P' || nums.get(j) == 'Q' || nums.get(j) == 'R' || nums.get(j) == 'S') {
					finalnum[j] = '7';
				}
				else if(nums.get(j) == 'T' || nums.get(j) == 'U' || nums.get(j) == 'V') {
					finalnum[j] = '8';
				}
				else if(nums.get(j) == 'W' || nums.get(j) == 'X' || nums.get(j) == 'Y' || nums.get(j) == 'Z') {
					finalnum[j] = '9';
				}
				else {
					finalnum[j] = nums.get(j);
				}
			}
			System.out.println();
			for(int j = 0;j<3;j++) {
				System.out.print(finalnum[j]);
			}
			System.out.print("-");
			for(int j = 3;j<6;j++) {
				System.out.print(finalnum[j]);
			}
			System.out.print("-");
			for(int j = 6;j<10;j++) {
				System.out.print(finalnum[j]);
			}
			System.out.println();
		}
		input.close();
	}

}
