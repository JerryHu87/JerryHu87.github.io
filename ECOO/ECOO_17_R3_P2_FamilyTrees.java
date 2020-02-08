import java.io.*;
import java.util.*;

public class Main {
    static int MOD = (int)1e9+7;
    static class Node{
        int mx;
        Map<Integer,Node> child;
        Node(){
            mx = 0;child = new HashMap();
        }
    }
    static int dfs(Node root){
        if(root == null){
            return 0;
        }
        int ans = root.mx;
        for(int ch:root.child.keySet()){
            ans = (ans+dfs(root.child.get(ch)))%MOD;
        }
        return ans;
    }
    public static void main(String[] args) throws IOException{
        BufferedReader input =new BufferedReader(new InputStreamReader(System.in));
        for(int z = 0;z<10;z++){
            int n = Integer.parseInt(input.readLine());
            Node root = new Node();
            for(int i = 0;i<n;i++){
                String s[] = input.readLine().split("\\.");
                Node cur = root;
                for(int j = 1;j<s.length;j++){
                    int v = Integer.parseInt(s[j]);
                    cur.mx = Math.max(cur.mx,v);
                    if(!cur.child.containsKey(v)){
                        cur.child.put(v,new Node());
                    }
                    cur = cur.child.get(v);
                }
            }
            System.out.println(dfs(root)+1);
        }
    }
}
