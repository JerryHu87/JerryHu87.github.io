import java.util.*;

public class P1_08_Buka {
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		String a = input.next();
		char operation = input.next().charAt(0);
		String b = input.next();
		if(operation == '+') {
			if(a.length() > b.length()) {
				a = a.substring(0, a.length()-b.length()) + b;
				System.out.println(a);
			}
			else if(a.length() < b.length()){
				b = b.substring(0, b.length()-a.length()) + a;
				System.out.println(b);
			}
			else {
				System.out.println(2 + a.substring(1,a.length()));
			}
		}
		else {
			if(b.length() == 1 && b.charAt(0) == '0') {
				System.out.println(0);
			}
			else if(b.length() == 1 && b.charAt(0) == '1') {
				System.out.println(a);
			}
			else if(a.charAt(0) == '0' && a.length() == 1) {
				System.out.println(0);
			}
			else if(a.charAt(0) == '1' && a.length() == 1) {
				System.out.println(b);
			}
			else {
				System.out.println(a + b.substring(1, b.length()));
			}
		}	
		input.close();
	}
}
