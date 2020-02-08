import java.io.*;
import java.util.*;

public class Main {
    public static int [] dis = new int [100001];
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt(); int x = input.nextInt();int y = input.nextInt();int z =input.nextInt();
        for(int i =1;i<=n;i++){dis[i] = -0x3f3f3f3f;}
        dis[0] = 0;
        for(int i = 1;i<=n;i++){
            if(i-x>=0){dis[i] = Math.max(dis[i],dis[i-x]+1);}
            if(i-y>=0){dis[i] = Math.max(dis[i],dis[i-y]+1);}
            if(i-z>=0){dis[i] = Math.max(dis[i],dis[i-z]+1);}
        }
        System.out.println(dis[n]);
        input.close();
    }
}
