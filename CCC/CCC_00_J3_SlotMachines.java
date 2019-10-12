import java.util.Scanner;
public class Slotmachines {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int money = input.nextInt();
		int machine1 = input.nextInt();
		int machine2 = input.nextInt();
		int machine3 = input.nextInt();
		int mastercounter = 0;{
		while(money > 0) {
			if(money > 0) {
				money = money-1;
				machine1 = machine1 + 1;
				mastercounter = mastercounter + 1;
				if (machine1 == 35) {
					money = money + 30;
					machine1 = 0;
				}
			if(money > 0) {
				if (money > 0) {
					money = money - 1 ;
					machine2 = machine2 + 1;
					mastercounter = mastercounter + 1;
					if(machine2 == 100) {
						money = money + 60;
						machine2 = 0;
					}
				}
			if(money > 0) {
				if(money > 0) {
					money = money - 1;
					machine3 = machine3 + 1;
					mastercounter = mastercounter + 1;
					if(machine3 == 10) {
						money = money + 9;
						machine3 = 0;
					}
				}
			}
			}
			}
		}
	System.out.println("Martha plays "+mastercounter+" times before going broke.");
	input.close();
	}
	}
}
