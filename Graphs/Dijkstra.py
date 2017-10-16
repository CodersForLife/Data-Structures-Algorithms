# Dijkstra v1.0
""" Dijkstra take a graph and source and returns the minimum distance of each vertex to that source.
	Pre-Conditions - Graph is a list of Connection to that vertex and Weight to that vertex in same order.	
				   - Source is an integer value between 0 to n 
				   - Connections should have n lists inside it similarly for Weights. ! Can be empty also.

	Dijkstra(Graph, Source)  --> Standard Function Call
	
	
	Example:

	Graph --> [ [[1, 2], [3], [1, 3, 4], [], [3]] , [[ 5, 3], [3], [2, 5, 6], [], [1]] ]

			    |__________Connections_________|    |___________Weights______________|

			 	Here 0 vertex is connected to 1 and 2 with weights 5 and 3 resp.
			 	Here 3 vertex is connected to no other vertex.
			 	Here 4 vertex is connected to 3 with weight of 1.

	Source --> Source can be any integer value between [0,4].

	Output --> For this Graph, and source = 0 will be: [0, 5, 3, 8, 9]. ! If a vertex is not accessible returns distance as inf i.e. Infinity.

	"""

def Dijkstra(Graph, Source):
	
	# Shortest distances to each node
	Short_Distances = []                           
	
	# Vertex to be visited are stored here
	Queue_Vertex = []                               
	
	# Connections stores connnections to each Vertex and Weights store corresponding Weight
	Connections = Graph[0]                          
	Weights = Graph[1]
	Queue_Vertex = list(range(len(Connections)))
	
	# Setting all distances except source to infinity and source distance to 0
	for Vertex in Queue_Vertex:
		if Vertex == Source:
			Short_Distances.append(0)
		else:
			Short_Distances.append(float('inf'))

	# To visit all Vertices
	while (len(Queue_Vertex) != 0):
		Min_Dist = float('inf')
		
		#Pick Node with minimum distance currently
		for i in Queue_Vertex:
			if Short_Distances[i] <= Min_Dist:
				Min_Dist = Short_Distances[i]
				Node = i
		
		# Remove Vertex from Queue as visited
		Queue_Vertex.remove(Node)

		# Set distances of vertices connected to node as minimum
		for Con_Node in Connections[Node]:
			Try_Dist = Short_Distances[Node] + Weights[Node][Connections[Node].index(Con_Node)]
			if Try_Dist <= Short_Distances[Con_Node]:
				Short_Distances[Con_Node] = Try_Dist
		
	return Short_Distances

#Sample Run for Example Graph
if __name__ == '__main__':
	Test_Graph = [ [[1, 2], [3], [1, 3, 4], [], [3]] , [[ 5, 3], [3], [2, 5, 6], [], [1]] ]
	print(Dijkstra(Test_Graph,0))
	print(Dijkstra(Test_Graph,1))
	print(Dijkstra(Test_Graph,2))
	print(Dijkstra(Test_Graph,3))
	print(Dijkstra(Test_Graph,4))