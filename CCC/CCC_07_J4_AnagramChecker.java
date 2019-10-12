import java.util.*;
import java.io.*;

public class J4_07_AnagramChecker {
	public static int [] freq = new int [26];
	public static void main(String [] args) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		String a = input.readLine();
		String b = input.readLine();
		for(int i = 0;i<a.length();i++) {
			if(a.charAt(i) != ' ') {freq[a.charAt(i)-'A']++;}
		}
		for(int i =0;i<b.length();i++) {
			if(b.charAt(i) != ' ') {freq[b.charAt(i)-'A']--;}
		}
		boolean an = true;
		for(int i = 0;i<26;i++) {
			if(freq[i] != 0) {
				an = false;
				break;
			}
		}
		if(an) {
			System.out.println("Is an anagram.");
		}
		else {
			System.out.println("Is not an anagram.");
		}
		input.close();
	}

}
