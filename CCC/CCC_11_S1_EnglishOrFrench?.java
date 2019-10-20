import java.io.*;
import java.util.*;

public class Main {
    public static int [] freq = new int [256];
    public static void main(String[] args) throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n =Integer.parseInt(input.readLine());
        for(int z = 0;z<n;z++){
            String next = input.readLine();
            for(int i = 0;i<next.length();i++){
                if(next.charAt(i) == 's' || next.charAt(i) == 'S' ||next.charAt(i) == 't' ||next.charAt(i) == 'T'){
                    freq[next.charAt(i)]++;
                }
            }
        }
        if(freq['t']+freq['T'] > freq['s']+freq['S']){
            System.out.println("English");
        }
        else{
            System.out.println("French");
        }
        input.close();
    }
}
