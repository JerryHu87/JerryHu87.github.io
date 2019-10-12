import java.util.Scanner;

public class Keepingscore{
	private static void printArray(char [] anArray,int startindex,int endindex) {
		for(int i = startindex + 1; i<endindex;i++) {
			System.out.print(" " + anArray[i]);
		}
		System.out.print("     ");
	}
	private static int findvalue(char [] anArray,int startindex,int endindex) {
		int total = 0;
		if(endindex-startindex == 1) {
			total = total + 3;
		}
		else if(endindex-startindex == 2) {
			total = total + 2;
		}
		else if(endindex-startindex == 3) {
			total = total + 1;
		}
		for(int i = startindex + 1; i<endindex;i++) {
			if(anArray[i] == 'A') {
				total = total + 4;
			}
			else if(anArray[i] == 'K') {
				total = total + 3;
			}
			else if(anArray[i] == 'Q') {
				total = total + 2;
			}
			else if(anArray[i] == 'J') {
				total = total + 1;
			}
		}
		return total;
	}
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		String cardinput = input.next();
		char [] cards = cardinput.toCharArray();
		int clubindex = 0;
		int heartindex = 0;
		int diamondindex = 0;
		int spadeindex = 0;
		for(int i = 0;i<cards.length;i++) {
			if(cards[i] == 'C') {
				clubindex = i;
			}
			else if(cards[i] == 'D') {
				diamondindex = i;
			}
			else if(cards[i] == 'H') {
				heartindex = i;
			}
			else if(cards[i] == 'S') {
				spadeindex = i;
			}
		}
		System.out.println("Cards Dealt                  Points");
		System.out.print("Clubs ");
		printArray(cards,clubindex,diamondindex);
		for(int i = 0;i<(cards.length-(diamondindex-clubindex));i++) {
			System.out.print(" ");
		}
		System.out.print(findvalue(cards,clubindex,diamondindex));
		System.out.println();
		System.out.print("Diamonds ");
		printArray(cards,diamondindex,heartindex);
		for(int i = 0;i<(cards.length-(heartindex-diamondindex));i++) {
			System.out.print(" ");
		}
		System.out.print(findvalue(cards,diamondindex,heartindex));
		System.out.println();
		System.out.print("Hearts ");
		printArray(cards,heartindex,spadeindex);
		for(int i = 0;i<(cards.length-(spadeindex-heartindex));i++) {
			System.out.print(" ");
		}
		System.out.print(findvalue(cards,heartindex,spadeindex));
		System.out.println();
		System.out.print("Spades ");
		printArray(cards,spadeindex,cards.length);
		for(int i = 0;i<(cards.length-(cards.length-spadeindex));i++) {
			System.out.print(" ");
		}
		System.out.print(findvalue(cards,spadeindex,cards.length));
		System.out.println();
		int total = findvalue(cards,clubindex,diamondindex) + findvalue(cards,diamondindex,heartindex) +  findvalue(cards,heartindex,spadeindex) + findvalue(cards,spadeindex,cards.length);
		System.out.println("                                Total " + total);
		input.close();
	}
}
