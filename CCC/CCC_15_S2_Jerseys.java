import java.util.*;
import java.io.*;

public class S2_15_Jersey {
	private static class Athlete{
		int S;
		int N;
		public Athlete(int size,int num) {
			S = size;
			N = num;
		}
		public int getSize() {
			return S;
		}
		public int getNum() {
			return N;
		}
	}
	public static void main(String args[]) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int temp = Integer.parseInt(input.readLine());
		int [] j = new int [temp+1];
		temp = Integer.parseInt(input.readLine());
		Athlete [] a = new Athlete [temp];
		for(int i = 1;i<=j.length-1;i++) {
			char t = input.readLine().charAt(0);
			if(t == 'S') {
				j[i] = 1;
			}
			else if(t == 'M') {
				j[i] = 2;
			}
			else{
				j[i] = 3;
			}
		}
		for(int i = 0;i<a.length;i++) {
			String tokens [] = input.readLine().split(" ");
			temp = Integer.parseInt(tokens[1]);
			if(tokens[0].charAt(0) == 'S') {
				a[i] = new Athlete(1, temp);
			}
			else if(tokens[0].charAt(0) == 'M') {
				a[i] = new Athlete(2, temp);
			}
			else {
				a[i] = new Athlete(3, temp);
			}
		}
		int request = 0;
		for(int i = 0;i<a.length;i++) {
			if(j[a[i].getNum()] >= a[i].getSize()) {
				request = request + 1;
				j[a[i].getNum()] = 0;
			}
			
		}
		System.out.println(request);
	}

}
