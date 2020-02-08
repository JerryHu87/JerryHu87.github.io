import java.util.*;
import java.io.*;

public class P2_09_Domino {
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int total = 0;
		for(int i = 1;i<=n+1;i++) {
			total += i;
		}
		System.out.println(n*total);
		input.close();
	}

}
