import java.util.Scanner;
import java.util.*;

public class Bananas {
	public static boolean testtrue(List<Character> word) {
		if(word.size() == 1 && word.get(0) == 'A') {
			return true;
		}
		if(word.size() == 0) {
			return true;
		}
		else if(word.get(0) == 'A' && word.get(1) == 'N') {
			return testtrue(word.subList(2,word.size()));
		}
		else if(word.get(0) == 'B' && word.get(word.size()-1) == 'S') {
			if(word.subList(1, word.size()-1).size() == 0) {
				return false;
			}
			return testtrue(word.subList(1, word.size()-1));
		}
		else {
			return false;
		}
	}
	public static boolean determine(List<Character> word) {
		int start = 0;
		for(int i = 0;i<word.size();i++) {
			if(word.get(i) == 'B') {
				start = i;
			}
			else if(word.get(i) == 'S') {
				word.add(i,'S');
				if(testtrue(word.subList(start, i+1))) {
					for(int j = i;j>=start;j--) {
						word.remove(j);
					}
					word.add(start,'A');
					word.remove(start+1);
					return determine(word);
				}
				else {
					return false;
				}
			}
		}
		if(start == 0 && testtrue(word) == false) {
			return false;
		}
		return true;
	}
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		List<String> test = new ArrayList<String>();
 		String word = "";
		while(true) {
			word = input.next();
			if(word.equals("X")) {
				break;
			}
			else {
				test.add(word);
			}
		}
		for(int i = 0;i<test.size();i++) {
			List <Character> temp = new ArrayList<Character>();
			for(int j = 0;j<test.get(i).length();j++) {
				temp.add(test.get(i).charAt(j));
			}
			if(determine(temp)) {
				System.out.println("YES");
			}
			else {
				System.out.println("NO");
			}
		}
		input.close();
	}
}
