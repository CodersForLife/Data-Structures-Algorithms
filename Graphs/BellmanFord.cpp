#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF 1e9

int main(){

	int n,m,x,y,z;

	cin >> n >> m; // n: number of vertex , m: number of edges

	vector<vector<int> > edges(m+1,vector<int>());
	vector<int> distances(n,INF);

	for(int i=0;i<m;i++){
   		cin >> x >> y >> z;
        edges[i].push_back(x);
        edges[i].push_back(y);
        edges[i].push_back(z);
	}

	distances[0] = 0;

	for(int i=0;i<n-1;i++){
		int j=0;
		while(edges[j].size()!= 0){
			if(distances[edges[j][0]]+edges[j][2]<distances[edges[j][1]]){
				distances[edges[j][1]]=distances[edges[j][0]]+edges[j][2];
			}
			j++;
		}
	}

	for(int i=0;i<n;i++)
		cout << distances[i] << " ";
	cout << endl;
}