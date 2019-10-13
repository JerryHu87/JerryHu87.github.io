import java.io.*;
import java.util.*;

public class S2_07_Boxes {
	public static class Box{
		long height;
		long width;
		long length;
		long volume;
		public Box(long L, long W, long H){
			height = H;
			width = W;
			length = L;
			volume = height * length * width;
		}

	}
	static class Vcomparator implements Comparator<Box>{
		public int compare(Box a, Box b) {
			return Long.compare(a.volume, b.volume);
		}
	}
	public static void main(String [] args) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(input.readLine());
		Box [] boxes = new Box [n];
		String [] tokens;
		for(int i = 0;i<n;i++) {
			tokens = input.readLine().split(" ");
			boxes[i] = new Box(Long.parseLong(tokens[0]),Long.parseLong(tokens[1]),Long.parseLong(tokens[2]));
		}
		Vcomparator vcm = new Vcomparator();
		Arrays.sort(boxes, vcm);
		int m = Integer.parseInt(input.readLine());
		for(int i = 0;i<m;i++) {
			tokens = input.readLine().split(" ");
			long l = Long.parseLong(tokens[0]);
			long w = Long.parseLong(tokens[1]);
			long h = Long.parseLong(tokens[2]);
			long v = l*w*h;
			boolean check = false;
			for(int j = 0;j<boxes.length;j++) {
				if(boxes[j].volume >= v) {
					if(boxes[j].length >= l && boxes[j].width >= w && boxes[j].height >= h) {
						System.out.println(boxes[j].volume);
						check = true;
						break;
					}
					else if(boxes[j].length >= w && boxes[j].width >= l && boxes[j].height >= h) {
						System.out.println(boxes[j].volume);
						check = true;
						break;
					}
					else if(boxes[j].length >= l && boxes[j].width >= h && boxes[j].height >= w) {
						System.out.println(boxes[j].volume);
						check = true;
						break;
					}
					else if(boxes[j].length >= h && boxes[j].width >= w && boxes[j].height >= l) {
						System.out.println(boxes[j].volume);
						check = true;
						break;
					}
					else if(boxes[j].length >= h && boxes[j].width >= l && boxes[j].height >= w) {
						System.out.println(boxes[j].volume);
						check = true;
						break;
					}
					else if(boxes[j].length >= w && boxes[j].width >= h && boxes[j].height >= l) {
						System.out.println(boxes[j].volume);
						check = true;
						break;
					}
				}
			}
			if(check == false) {
				System.out.println("Item does not fit.");
			}
		}
	}

}
