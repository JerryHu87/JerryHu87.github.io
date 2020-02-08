import java.util.*;
import java.io.*;

public class P1_08_BabyDiff {
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		for(int z = 0;z<5;z++) {
			String a = input.nextLine();
			String b = input.nextLine();
			int i = 0;
			while(i < a.length() & i < b.length() && a.charAt(i) == b.charAt(i)) {
				i++;
			}
			System.out.println(i);
		}
		input.close();
	}

}
