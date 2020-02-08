import java.util.*;
import java.io.*;

public class P1_09_Note {
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int [] arr = new int [8];
		for(int i = 0;i<8;i++) {
			int next = input.nextInt();
			arr[i] = next;
		}
		boolean check = false;
		for(int i = 1;i<8;i++) {
			if(arr[i] > arr[i-1]) {
				check = true;
			}
			else {
				check = false;
				break;
			}
		}
		if(check) {
			System.out.println("ascending");
			System.exit(0);
		}
		check = false;
		for(int i = 1;i<8;i++) {
			if(arr[i] < arr[i-1]) {
				check = true;
			}
			else {
				check = false;
				break;
			}
		}
		if(check) {
			System.out.println("descending");
		}
		else {
			System.out.println("mixed");
		}
		input.close();
	}

}
