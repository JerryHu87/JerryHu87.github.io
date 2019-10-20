import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        int [] arr = new int [1001];
        for(int i = 0;i<n;i++){
            int temp = Integer.parseInt(input.readLine());
            arr[temp]++;
        }
        List<Integer> l = new ArrayList<Integer>();
        int max = 0;
        for(int i = 1;i<=1000;i++){
            if(arr[i] > max){
                max = arr[i];
            }
        }
        for(int i = 1;i<=1000;i++){
            if(arr[i] == max){l.add(i);}
        }
        if(l.size() > 1){
            max = 0;
            for(int i = 0;i<l.size();i++){
                for(int j = i+1;j<l.size();j++){
                    if(Math.abs(l.get(i)-l.get(j)) > max){
                        max = Math.abs(l.get(i)-l.get(j));
                    }
                }
            }
            System.out.println(max);
        }
        else{
            int org = l.get(0);
            l.clear();
            int max2 = 0;
            for(int i = 1;i<=1000;i++){
                if(arr[i] > max2 && arr[i] != max){
                    max2 = arr[i];
                }
            }
            for(int i = 1;i<=1000;i++){
                if(arr[i] == max2){
                    l.add(i);
                }
            }
            max2 = 0;
            for(int i = 0;i<l.size();i++){
                if(Math.abs(l.get(i)-org) > max2){
                    max2 = Math.abs(l.get(i)-org);
                }
            }
            System.out.println(max2);
        }
        input.close();

    }
}
