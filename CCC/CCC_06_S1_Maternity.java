import java.io.*;

public class S1_06_Maternity {
	public static boolean [] a = new boolean [2];
	public static boolean [] b = new boolean [2];
	public static boolean [] c = new boolean [2];
	public static boolean [] d = new boolean [2];
	public static boolean [] e = new boolean [2];
	public static String [][] as = new String [2][2];
	public static String [][] bs = new String [2][2];
	public static String [][] cs = new String [2][2];
	public static String [][] ds = new String [2][2];
	public static String [][] es = new String [2][2];
	public static void main(String [] args) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		String t1 = input.readLine();String t2 = input.readLine();
		int x = Integer.parseInt(input.readLine());
		as[0][0] = Character.toString(t1.charAt(0)) + Character.toString(t2.charAt(0));
		as[1][0] = Character.toString(t1.charAt(1)) + Character.toString(t2.charAt(0));
		as[0][1] = Character.toString(t1.charAt(0)) + Character.toString(t2.charAt(1));
		as[1][1] = Character.toString(t1.charAt(1)) + Character.toString(t2.charAt(1));
		bs[0][0] = Character.toString(t1.charAt(2)) + Character.toString(t2.charAt(2));
		bs[1][0] = Character.toString(t1.charAt(3)) + Character.toString(t2.charAt(2));
		bs[0][1] = Character.toString(t1.charAt(2)) + Character.toString(t2.charAt(3));
		bs[1][1] = Character.toString(t1.charAt(3)) + Character.toString(t2.charAt(3));
		cs[0][0] = Character.toString(t1.charAt(4)) + Character.toString(t2.charAt(4));
		cs[1][0] = Character.toString(t1.charAt(5)) + Character.toString(t2.charAt(4));
		cs[0][1] = Character.toString(t1.charAt(4)) + Character.toString(t2.charAt(5));
		cs[1][1] = Character.toString(t1.charAt(5)) + Character.toString(t2.charAt(5));
		ds[0][0] = Character.toString(t1.charAt(6)) + Character.toString(t2.charAt(6));
		ds[1][0] = Character.toString(t1.charAt(7)) + Character.toString(t2.charAt(6));
		ds[0][1] = Character.toString(t1.charAt(6)) + Character.toString(t2.charAt(7));
		ds[1][1] = Character.toString(t1.charAt(7)) + Character.toString(t2.charAt(7));
		es[0][0] = Character.toString(t1.charAt(8)) + Character.toString(t2.charAt(8));
		es[1][0] = Character.toString(t1.charAt(9)) + Character.toString(t2.charAt(8));
		es[0][1] = Character.toString(t1.charAt(8)) + Character.toString(t2.charAt(9));
		es[1][1] = Character.toString(t1.charAt(9)) + Character.toString(t2.charAt(9));
		for(int i = 0;i<2;i++) {
			for(int j = 0;j<2;j++) {
				if(as[i][j].equals("AA") || as[i][j].equals("Aa") || as[i][j].equals("aA")) {
					a[0] = true;
				}
				else{
					a[1] = true;
				}
			}
		}
		for(int i = 0;i<2;i++) {
			for(int j = 0;j<2;j++) {
				if(bs[i][j].equals("BB") || bs[i][j].equals("Bb") || bs[i][j].equals("bB")) {
					b[0] = true;
				}
				else{
					b[1] = true;
				}
			}
		}
		for(int i = 0;i<2;i++) {
			for(int j = 0;j<2;j++) {
				if(cs[i][j].equals("CC") || cs[i][j].equals("Cc") || cs[i][j].equals("cC")) {
					c[0] = true;
				}
				else{
					c[1] = true;
				}
			}
		}
		for(int i = 0;i<2;i++) {
			for(int j = 0;j<2;j++) {
				if(ds[i][j].equals("DD") || ds[i][j].equals("Dd") || ds[i][j].equals("dD")) {
					d[0] = true;
				}
				else{
					d[1] = true;
				}
			}
		}
		for(int i = 0;i<2;i++) {
			for(int j = 0;j<2;j++) {
				if(es[i][j].equals("EE") || es[i][j].equals("Ee") || es[i][j].equals("eE")) {
					e[0] = true;
				}
				else{
					e[1] = true;
				}
			}
		}
		for(int i = 0;i<x;i++) {
			String ch = input.readLine();
			if(ch.charAt(0) == 'A' && !a[0] || ch.charAt(0) == 'a' && !a[1]) {
				System.out.println("Not their baby!");continue;
			}
			if(ch.charAt(1) == 'B' && !b[0] || ch.charAt(1) == 'b' && !b[1]) {
				System.out.println("Not their baby!");continue;
			}
			if(ch.charAt(2) == 'C' && !c[0] || ch.charAt(2) == 'c' && !c[1]) {
				System.out.println("Not their baby!");continue;
			}
			if(ch.charAt(3) == 'D' && !d[0] || ch.charAt(3) == 'd' && !d[1]) {
				System.out.println("Not their baby!");continue;
			}
			if(ch.charAt(4) == 'E' && !e[0] || ch.charAt(4) == 'e' && !e[1]) {
				System.out.println("Not their baby!");continue;
			}
			System.out.println("Possible baby.");
		}
		input.close();
	}

}
