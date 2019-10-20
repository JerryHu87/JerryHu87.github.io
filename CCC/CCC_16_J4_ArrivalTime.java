import java.util.*;

public class J4_16_ArrivalTime {
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		String token = input.next();
		byte hour = Byte.parseByte(token.substring(0, 2));
		byte minute = Byte.parseByte(token.substring(3,5));
		int totalm = hour*60 + minute;
		int ans = totalm;
		for(int i = totalm;i<(totalm+120);i++) {
			if(ans >= (7*60) && ans < (10*60)) {
				ans += 2;
			}
			else if(ans >= (15*60) && ans < (19*60)) {
				ans += 2;
			}
			else {
				ans++;
			}
		}
		if(ans >= (24*60)) {
			ans-= (24*60);
		}
		int temph = ans/60;
		int tempm = ans%60;
		String temp = "";
		if(temph < 10) {
			temp += ("0");
		}
		temp += temph;
		temp += ":";
		if(tempm < 10) {
			temp += "0";
		}
		temp += tempm;
		System.out.println(temp);
		input.close();
	}

}
