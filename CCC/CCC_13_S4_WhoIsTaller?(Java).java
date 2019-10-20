import java.util.*;
import java.io.*;

public class Main
{
  public static List<Integer>[] nodes;
  public static void main(String[] args) throws IOException
  {
    BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
    String [] tokens = input.readLine().split(" ");
    int n = Integer.parseInt(tokens[0]);int m = Integer.parseInt(tokens[1]);
    nodes = new ArrayList[n+1];
    for (int i = 1; i <= n; i++)
    {
      nodes[i] = new ArrayList<Integer>();
    }
    int p;
    int q;
    for (int i = 0; i < m; i++)
    {
      tokens = input.readLine().split(" ");
      p = Integer.parseInt(tokens[0]);q = Integer.parseInt(tokens[1]);
      nodes[p].add(q);
    }
    tokens = input.readLine().split(" ");
    p = Integer.parseInt(tokens[0]);q = Integer.parseInt(tokens[1]);
    boolean pq = bfs(p, q);
    if (pq)
    {
      System.out.println("yes");
    }
    else
    {
      boolean qp = bfs(q, p);
      if (qp)
      {
        System.out.println("no");
      }
      else
      {
        System.out.println("unknown");
      }
    }
    input.close();
  }
  public static boolean bfs(int src, int dest)
  {
    LinkedList<Integer> q = new LinkedList<Integer>();
    boolean[] visited = new boolean[nodes.length];
    q.add(src);visited[src] = true;
    int current;
    while (!q.isEmpty())
    {
      current = q.pop();
      for (int i : nodes[current])
      {
        if (!visited[i])
        {
          if (i == dest)
          {
            return true;
          }
          q.push(i);visited[i] = true;
        }
      }
    }
    return false;
  }
}
