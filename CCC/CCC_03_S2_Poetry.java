import java.util.Scanner;
public class Poetry {
	private static String getlastword(String line) {
		String word = "";
		int index = 0;
		int length = line.length();
		for(int i = 0; i<length;i++) {
			if(line.substring(i,i+1).equals(" ")) {
				index = i+1;
			}
		}
		word = line.substring(index);
		return word;
	}
	private static String getlastrhyme(String line) {
		String rhyme = "";
		boolean check = false;
		int length = line.length();
		for(int i = 0;i<length;i++) {
			String temp = line.substring(i, i+1);
			if(temp.equals("a") || temp.equals("e") || temp.equals("i") || temp.equals("o") || temp.equals("u")) {
				rhyme = line.substring(i);
				check = true;
			}
		}
		if(check == false) {
			rhyme = line;
		}
		return rhyme;
	}
	private static boolean crosscheck(String [] anArray) {
		boolean check = false;
		if(anArray[0].equals(anArray[2]) && anArray[1].equals(anArray[3])) {
			check = true;
		}
		return check;
	}
	private static boolean evencheck(String [] anArray) {
		boolean check = false;
		if(anArray[0].equals(anArray[1]) && anArray[2].equals(anArray[3])) {
			check = true;
		}
		return check;
	}
	private static boolean shellcheck(String [] anArray){
		boolean check = false;
		if(anArray[0].equals(anArray[3]) && anArray[1].equals(anArray[2])) {
			check = true;
		}
		return check;
	}
	private static boolean perfectcheck(String [] anArray) {
		boolean check = false;
		if(anArray[0].equals(anArray[1]) && anArray[1].equals(anArray[2])&& anArray[2].equals(anArray[3]) && anArray[0].equals(anArray[2]) && anArray[0].equals(anArray[3])) {
			check = true;
		}
		return check;
	}
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int versenum = input.nextInt();
		input.nextLine();
		for(int j = 0; j<versenum;j++) {
			String [] rhymes = new String[4];
			for(int i = 0;i<4;i++) {
				String newline = input.nextLine();
				newline = newline.toLowerCase();
				String rhymeadd = getlastword(newline);
				rhymes[i] = getlastrhyme(rhymeadd);
			}
			if(perfectcheck(rhymes)) {
				System.out.println("perfect");
			}
			else if(crosscheck(rhymes)) {
				System.out.println("cross");
			}
			else if(evencheck(rhymes)) {
				System.out.println("even");
			}
			else if(shellcheck(rhymes)) {
				System.out.println("shell");
			}
			else {
				System.out.println("free");
			}
		}
		input.close();
	}

}
