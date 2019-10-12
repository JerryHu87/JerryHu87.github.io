import java.util.Scanner;

public class Nineninesixsix {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int start = input.nextInt();
		int end = input.nextInt();
		int combinations = 0;
		for(int i = start; i <= end;i++) {
			int num = 0;
			int stringcheck = 0;
			String str = Integer.toString(i);
			int varlength = str.length();
			int original = varlength;
			char[] check = str.toCharArray();
			if (varlength == 1) {
				original = original + 1;
			}
			if(varlength%2 == 1 && varlength != 1) {
				num = 1;
			}
			for (int r = 0; r < (original/2) + num; r++) {
				if(check[r] == '0' && check[varlength-1] == '0') {
					stringcheck = stringcheck + 1; 
				}
				else if(check[r] == '1' && check[varlength-1] == '1') {
					stringcheck = stringcheck + 1;
				}
				else if(check[r] == '8' && check[varlength-1] == '8') {
					stringcheck = stringcheck + 1;
				}
				else if(check[r] == '6' && check[varlength-1] == '9') {
					stringcheck = stringcheck + 1;
				}
				else if(check[r] == '9' && check[varlength-1] == '6') {
					stringcheck = stringcheck + 1;
				}
				varlength = varlength - 1;
			}
			if((original/2)+num <= stringcheck) {
				combinations = combinations + 1;
			}
		}
		System.out.println(combinations);
		input.close();
	}
}
