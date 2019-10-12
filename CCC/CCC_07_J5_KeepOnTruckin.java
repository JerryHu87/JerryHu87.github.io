import java.util.*;

public class KeeponTruckin {
	public static long solve(List<Integer>motels,int mindistance,int maxdistance) {
		long [] paths = new long [motels.size()];
		for(int i = 0;i<motels.size();i++) {
			if(motels.get(i) >= mindistance && motels.get(i) <= maxdistance) {
				paths[i] = 1;
			}
		}
		for(int i  = 0;i<motels.size();i++) {
			for(int j = i;j<motels.size();j++) {
				if(motels.get(i) +maxdistance >= motels.get(j) && motels.get(i) + mindistance <= motels.get(j)) {
					paths[j] += paths[i];
				}
			}
		}
		return paths[paths.length-1];
	}
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		List<Integer> motels = new ArrayList<Integer>();
		motels.add(0);motels.add(990);motels.add(1010);motels.add(1970);motels.add(2030);motels.add(2940);motels.add(3060);motels.add(3930);
		motels.add(4060);motels.add(4970);motels.add(5030);motels.add(5990);motels.add(6010);motels.add(7000);
		int mindistance = input.nextInt();int maxdistance = input.nextInt();int motelnum = input.nextInt();
		for(int i = 0;i<motelnum;i++) {
			int n = input.nextInt();motels.add(n);
		}
		Collections.sort(motels);
		long ans = solve(motels,mindistance,maxdistance);
		System.out.println(ans);
		input.close();
	}

}
