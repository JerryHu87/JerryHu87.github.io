import java.util.Scanner;
import java.util.*;

public class BabblingBrooks {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int game = 0;
		int streamind = input.nextInt();
		double streamchange = 0.00;
		List<Double> streams = new ArrayList<Double>();
		for(int i = 0;i<streamind;i++) {
			double streamadd = input.nextInt();
			streams.add(streamadd);
		}
		while (game == 0) {
			int gameadd = input.nextInt();
			if(gameadd == 99) {
				int streamnum = input.nextInt()-1;
				int percentage1 = input.nextInt();
				streamchange = streams.get(streamnum)*(0.01*percentage1);
				streams.add(streamnum+1,(1-(0.01*percentage1))*streams.get(streamnum));
				streams.set(streamnum,streamchange);
			}
			else if(gameadd == 88) {
				int streamnums = input.nextInt()-1;
				streamchange = streams.get(streamnums) + streams.get(streamnums+1);
				streams.remove(streamnums+1);
				streams.set(streamnums,streamchange);			
			}
			else if(gameadd == 77) {
				game = game + 1;
			}
		}
		input.close();
		for(int i = 0; i<streams.size();i++) {
			System.out.print(streams.get(i)+" ");
		}
	}
}
