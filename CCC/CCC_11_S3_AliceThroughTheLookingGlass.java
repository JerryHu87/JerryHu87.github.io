import java.util.*;

public class S3_11_AliceThroughTheLookingGlass{
	public static boolean check(long x, long y,long modx,long mody, long m) {
		long x2 = x/((long)Math.pow(5,m-1));
		long y2 = y/((long)Math.pow(5,m-1));
		if(x2 >= 1 && x2 <= 3 && y2 == 0) {
			return true;
		}
		else if(x2 == 2 && y2 == 1) {
			return true;
		}
		else if(x2 == 1 && y2 == 1) {
			if(modx >= 1 && modx <= 3 && mody == 0) {
				return true;
			}
			else if(modx == 2 && mody == 1) {
				return true;
			}
			else {
				return false;
			}
		}
		else if(x2 == 3 && y2 == 1) {
			if(modx >= 1 && modx <= 3 && mody == 0) {
				return true;
			}
			else if(modx == 2 && mody == 1) {
				return true;
			}
			else {
				return false;
			}
		}
		else if(x2 == 2 && y2 == 2 && m > 1) {	
			x = x%((long)Math.pow(5,m-1));
			y = y%((long)Math.pow(5,m-1));
			return check(x,y,modx,mody,m-1);
		}
		else {
			return false;
		}
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		for(int i = 0;i<t;i++) {
			long m = input.nextLong();
			long x = input.nextLong();
			long y = input.nextLong();
			long modx = x%5;
			long mody = y%5;
			if(check(x,y,modx,mody,m) == true) {
				System.out.println("crystal");
			}
			else {
				System.out.println("empty");
			}
		}
		input.close();
	}

}
