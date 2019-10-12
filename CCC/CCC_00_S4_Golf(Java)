import java.io.*;
import java.util.*;

public class Main {
    public static int [] clubs = new int [32];
    public static int [] dis = new int [5281];
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int d = input.nextInt();int n = input.nextInt();
        for(int i = 0;i<n;i++){
            clubs[i] = input.nextInt();
        }
        for(int i = 0;i<=d;i++){dis[i] = 0x3f3f3f3f;}
        dis[0] = 0;
        for(int i = 1;i<=d;i++){
            for(int j = 0;j<n;j++){
                if(i-clubs[j]>=0){dis[i] = Math.min(dis[i],dis[i-clubs[j]]+1);}
            }
        }
        if(dis[d] == 0x3f3f3f3f){
            System.out.println("Roberta acknowledges defeat.");
        }
        else{
            System.out.println("Roberta wins in " + dis[d] + " strokes.");
        }
    }
}
