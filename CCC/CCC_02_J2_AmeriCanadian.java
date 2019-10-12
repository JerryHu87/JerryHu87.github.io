import java.util.Scanner;
import java.util.*;

public class AmeriCanadian {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		List<String> words = new ArrayList<String>();
		while(true) {
			String newstring = input.next();
			if(newstring.equals("quit!")) {
				break;
			}
			words.add(newstring);
		}
		for(int i = 0; i<words.size();i++) {
			if(words.get(i).length() > 4 && words.get(i).substring(words.get(i).length()-2, words.get(i).length()).equals("or") && !words.get(i).substring(words.get(i).length()-3, words.get(i).length()-2).equals("a") && !words.get(i).substring(words.get(i).length()-3, words.get(i).length()-2).equals("e") && !words.get(i).substring(words.get(i).length()-3, words.get(i).length()-2).equals("i") && !words.get(i).substring(words.get(i).length()-3, words.get(i).length()-2).equals("o") && !words.get(i).substring(words.get(i).length()-3, words.get(i).length()-2).equals("u") && !words.get(i).substring(words.get(i).length()-3, words.get(i).length()-2).equals("y")) {
				System.out.println(words.get(i).substring(0, words.get(i).length()-1) + "u" + words.get(i).substring(words.get(i).length()-1));
			}
			else {
				System.out.println(words.get(i));
			}
		}
		input.close();
	}

}
