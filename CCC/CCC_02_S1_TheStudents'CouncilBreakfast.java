import java.util.Scanner;
public class Studentcouncilbreakfast {
	public static void main(String[] args){
			Scanner input = new Scanner(System.in);
			int combinations = 0;
			int j = 0;
			int r = 0;
			int q = 0;
			int s = 0;
			int pink = input.nextInt();
			int green = input.nextInt();
			int red = input.nextInt();
			int orange = input.nextInt();
			int money = input.nextInt();
			int minimum = Integer.MAX_VALUE;
			for(j = 0; j <= money/orange; j++) {
				if(pink*s+green*q+red*r+orange*j==money){
					System.out.println("# of PINK is "+s+" # of GREEN is "+q+" # of RED is "+r+" # of ORANGE is "+j);
					combinations = combinations + 1;
					if(j+q+r+s<minimum) {
						minimum = j + q + r + s;
					}
				}
				for(r = 0; r <= money/red; r++) {
					if(pink*s+green*q+red*r+orange*j==money){
						System.out.println("# of PINK is "+s+" # of GREEN is "+q+" # of RED is "+r+" # of ORANGE is "+j);
						combinations = combinations + 1;
						if(j+q+r+s<minimum) {
							minimum = j + q + r + s;
						}
					}
					for(q = 0; q <= money/green; q++) {
						if(pink*s+green*q+red*r+orange*j==money){
							System.out.println("# of PINK is "+s+" # of GREEN is "+q+" # of RED is "+r+" # of ORANGE is "+j);
							combinations = combinations + 1;
							if(j+q+r+s<minimum) {
								minimum = j + q + r + s;
							}
						}
						for(s = 0; s <= money/pink; s++) {
							if(pink*s+green*q+red*r+orange*j==money){
								System.out.println("# of PINK is "+s+" # of GREEN is "+q+" # of RED is "+r+" # of ORANGE is "+j);
								combinations = combinations + 1;
								if(j+q+r+s<minimum) {
									minimum = j + q + r + s;
								}
							}
						}
						
					}
					
				}
				
			}
			System.out.println("Total combinations is " + combinations+".");
			System.out.println("Minimum number of tickets to print is " + minimum+".");
			input.close();
			}
		}
