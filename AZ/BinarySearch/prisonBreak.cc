
#include<bits/stdc++.h>
using namespace std;

int N;

class Graph
{
	int V ;
	list <char> *adj;
public :
	Graph( int V )
	{
		this->V = V ;
		adj = new list<char>[V];
	}
	void addEdge( char s , char d ) ;
	int BFS ( char  s , char  d) ;
};

// add edge to graph
void Graph :: addEdge ( char s , char d )
{
	adj[s].push_back(d);
	adj[d].push_back(s);
}

// Level BFS function to find minimum path
// from source to sink
int Graph :: BFS(char s, char d)
{
	// Base case
	if (s == d)
		return 0;

	// make initial distance of all vertex -1
	// from source
	int *level = new int[V];
	for (int i = 0; i < V; i++)
		level[i] = -1 ;

	// Create a queue for BFS
	list<char> queue;

	level[s] = 0 ;
	queue.push_back(s);

	
	list<char>::iterator i;

	while (!queue.empty())
	{
		s = queue.front();
		queue.pop_front();
		
		for (i = adj[s].begin(); i != adj[s].end(); ++i) {
			if (level[*i] < 0 || level[*i] > level[s] + 1 ) {
				level[*i] = level[s] + 1 ;
				queue.push_back(*i);
			}
		}

	}

	return level[d] ;
}

bool isSafe(int i, int j, vector<vector<char>> M, int N)
{
	if ((i < 0 || i >= N) ||
			(j < 0 || j >= N ) || M[i][j] == 'T')
		return false;
	return true;
}

int MinimumPath(vector<vector<char>> &M, int N)
{
	char s , d ; // source and destination
	int V = N*N+2;
	Graph g(V);

	int k = 1 ; // Number of current vertex
	for (int i =0 ; i < N ; i++)
	{
		for (int j = 0 ; j < N; j++)
		{
			if (M[i][j] != 'T')
			{
				// connect all 4 adjacent cell to
				// current cell
				if ( isSafe ( i , j+1 , M ) )
					g.addEdge ( k , k+1 );
				if ( isSafe ( i , j-1 , M ) )
					g.addEdge ( k , k-1 );
				if (j< N-1 && isSafe ( i+1 , j , M ) )
					g.addEdge ( k , k+N );
				if ( i > 0 && isSafe ( i-1 , j , M ) )
					g.addEdge ( k , k-N );
			}

			// source index
			if( M[i][j] == 'S' )
				s = k ;

			// destination index
			if (M[i][j] == 'E')
				d = k;
			k++;
		}
	}

	// find minimum moves
	return g.BFS (s, d) ;
}

// driver program to check above function
int main()
{
    cin >> N;
    vector<vector<char>> M(N, vector<char>(N));
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            cin >> M[i][j];
        }
    }
	
    cout << MinimumPath(M, N) << endl;

	return 0;
}
