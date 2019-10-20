import java.util.*;
import java.io.*;

public class J2_13_RotatingLetters {
	public static void main(String [] args) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		String temp = input.readLine();
		boolean check = false;
		for(int i = 0;i<temp.length();i++) {
			if(temp.charAt(i) != 'I' && temp.charAt(i) != 'O' && temp.charAt(i) != 'S' && temp.charAt(i) != 'H' && temp.charAt(i) != 'Z' && temp.charAt(i) != 'X' && temp.charAt(i) != 'N') {
				System.out.println("NO");
				check = true;
				break;
			}
		}
		if(check == false) {
			System.out.println("YES");
		}
		input.close();
	}

}
