// Java program to find out whether a given graph is Bipartite or not

import java.util.*;
import java.lang.*;
import java.io.*;


class BipartiteCheck
{
    final static int V = 8;


    public static class node{
       public List<node> neighbours;
       public int number;

        public node(int number){

            neighbours=new ArrayList<>();
            this.number=number;
        }

        public void addNeighbour(node n){
            neighbours.add(n);

        }
    }

    boolean isBipartite(node Graph[],int src)
    {
        int colorArr[] = new int[V];
        for (int i=0; i<V; ++i)
            colorArr[i] = -1;

        colorArr[src] = 1;          // Assign first color to source

        LinkedList<Integer>q = new LinkedList<Integer>();
        q.add(src);

        while (q.size() != 0)        // Run while there are vertices in queue (Similar to BFS)
        {
            int u = q.poll();

            for (int v=0; v<Graph[u].neighbours.size(); ++v)            // Find all non-colored adjacent vertices
            {
                if (colorArr[Graph[u].neighbours.get(v).number]==-1)        //destination v is not colored
                {
                    colorArr[Graph[u].neighbours.get(v).number] = 1-colorArr[u];     // Assign alternate color to this adjacent v of u
                    q.add(Graph[u].neighbours.get(v).number);
                }

                else if (colorArr[Graph[u].neighbours.get(v).number]==colorArr[u]) //destination v is colored with same color as u
                    return false;

                else if(Graph[u].neighbours.get(v).number==u)       // Return false if there is a self-loop
                    return false;
            }
        }

        return true;
    }

   
}
