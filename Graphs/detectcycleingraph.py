def DFS(graph, v):
#color -1 means no node is been visited yet
    color = [-1] * v 
#parent -1 means no node have a parent node
    parent = [-1] * v
    time = 0
    for i in range(v):
        if(color[i] == -1):
            DFSvisit(graph, v, i, color, parent, time)
    print(color)
    print(parent)

def DFSvisit(graph, v, s, color, parent, time):
#color is o means that node s is visited
    color[s] = 0
    time += 1
    for i in range(0,v):
        if(graph[s][i]==1):
            if(color[i]==0):
                print("Cycle detected at:",s)
                return
        if(graph[s][i] == 1):
            if(color[i] == 0):
                #s is parent of node i
                parent[i] = s
                DFSvisit(graph, v, i, color, parent, time)
    #color is 1 mean node s is visited and completed
    color[s] = 1
    time += 1 


def main():
#adjacency matrix representation
    Graph=[[0, 1, 1, 0, 0, 0], 
          [1, 0, 0, 1, 0, 0], 
          [0, 0, 1, 0, 0, 0], 
          [0, 0, 1, 1, 0, 0], 
          [0, 0, 0, 0, 0, 0], 
          [0, 0, 0, 0, 0, 1]] 
    v = len(Graph[0])
    DFS(Graph, v)

if __name__ == '__main__':
    main()

#output:
#('Cycle detected at:', 2)
#('Cycle detected at:', 3)
#('Cycle detected at:', 5)
#[1, 1, 0, 0, 1, 0]
#[-1, -1, -1, -1, -1, -1]
