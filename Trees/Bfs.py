#!/usr/bin/env python

#title           :Bfs.py
#description     :Breadth first search implementation in python
#reference       :http://eddmann.com/posts/depth-first-search-and-breadth-first-search-in-python/
#date            :10102017
#version         :0.1
#==============================================================================

# Implementation
class Bfs():
    # Initializer for the class
    def __init__(self,graphAdjList):
        self.graphAdjList = graphAdjList
        # Check for the graph
        if not len(self.graphAdjList)>=1:
            raise ValueError('please pass a valid graph')

    # Function to traverse in a bfs manner
    # BFS algorithm:
    # 1. Start with the head node in queue
    # 2. repeat while queue is not empty
    #   1. Pop queue
    #   2. add neighbors if already not visited to list
    #   3. remove from queue
    # 3. return list
    def traverse(self,start):
        visited, queue = set(), [start]
        while queue and start and start in self.graphAdjList:
            vertex = queue.pop(0)
            if vertex not in visited:
                visited.add(vertex)
                queue.extend(self.graphAdjList[vertex] - visited)
        return visited


# Main method to trigger the execution
if __name__ == '__main__':
    # Variables
    # Define the adjacency list for the graph (undirected)
    graphAdjList = {'A': set(['B', 'C']),
                    'B': set(['A', 'D', 'E']),
                    'C': set(['A']),
                    'D': set(['B']),
                    'E': set(['B', 'F']),
                    'F': set(['E'])}

    thisBfs = Bfs(graphAdjList)
    print "BFS traversal is: "+str(thisBfs.traverse('A'))
