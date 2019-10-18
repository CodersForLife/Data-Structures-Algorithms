#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9

int main(){

	int n,m,x,y,z;

	cin >> n >> m; // n: number of vertex , m: number of edges

	vector<vector<int> > distances(n,vector<int>(n,INF));

	for(int i=0;i<m;i++){
		cin >> x >> y >> z;
		x--; y--;
		distances[x][y]=min(distances[x][y],z);
		distances[y][x]=min(distances[y][x],z);
	}

	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(i==j)
					distances[i][j]=0;
				else
					distances[i][j]=min(distances[i][j],distances[i][k]+distances[k][j]);

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout << distances[i][j] << " ";
		cout << endl;
	}

}