#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>source_destination(100,vector<int>(100,0));

class edge{
private:
	int src;
	int des;
	int weight;
public:
	edge()
	{}
	edge(int in_src,int in_des,int in_weight)
	{
		src=in_src;
		des=in_des;
		weight=in_weight;
	}
	int get_src()
	{
		return src;
	}
	void set_src(int source)
	{
		src=source;
	}
	int get_des()
	{
		return des;
	}
	void set_des(int destination)
	{
		des=destination;
	}
	int get_weight()
	{
		return weight;
	}
	void set_weight(int wght)
	{
		weight=wght;
	}
};
class graph{
private:
	edge grph_edges[100];
	int cnt_edges;
	vector<int>nodes;
	int cnt_nodes;
	
	
public:
	graph()
	{
		cnt_edges=0;
	}
	void set_nodes(int no_nodes)
	{
		nodes.resize(no_nodes);
		cnt_nodes=no_nodes;
	}
	int get_no_nodes()
	{
		return cnt_nodes;
	}
	
	
	void take_input(int no_nodes,int no_edges)
	{
		int src,des,weight;
		for(int i=0;i<no_edges;i++)
		{
		cin>>src>>des>>weight;

		source_destination[src][des]=weight;
		source_destination[des][src]=weight;

		
		}
	}
	 
	int minDistance(vector <int> distance, vector <bool>span_tree)
	{
	 // Initialize min value 
      int min = INT_MAX, min_index; 
	  for (int v = 0; v < cnt_nodes; v++) 
		{
				if (span_tree[v] == false && distance[v] <= min) 
				min = distance[v], min_index = v; 
		}

		return min_index; 
	
	}

	//shortest path function you are free to change the return type of the function
	float shortest_path(int source1,vector<vector<int>>source_destination)
	{ 
		 float sum=0;
		 int a=1;
		 vector <bool> span_tree(cnt_nodes,false);
		 vector <int> distance(cnt_nodes,INT_MAX); // dist[i] will hold the shortest  distance from src to i 
                      

		distance [source1]=0; // Distance of source vertex from itself is always 0

		for (int count=0; count < cnt_nodes-1; count ++)
		{ int u;
		  
		 // Pick the minimum distance vertex from the set of vertices not 
	     // yet processed. u is always equal to src in the first iteration.

	       u = minDistance(distance, span_tree);  //a

		  // Mark the picked vertex as processed
		  span_tree[u]=true; //b

		  		// Update dist value of the adjacent vertices of the picked vertex. 
		for (int v = 0; v < cnt_nodes; v++) 

		{	// Update dist[v] only if is not in sptSet, there is an edge from 
			// u to v, and total weight of path from src to v through u is 
			// smaller than current value of dist[v] 
		if (!span_tree[v] && source_destination[u][v] && distance[u] != INT_MAX && distance[u]+source_destination[u][v] < distance[v])
									 
			distance[v] = distance[u] + source_destination[u][v]; 
		}

	   } //bta3t el count 
		for (int k=0; k < cnt_nodes;k++)
		{
		
			sum= sum + distance [k];

		}
		return sum;

	}

};
class base_algorithem{
public:
	virtual void process(graph z)=0;
};
class degree_algorithem:public base_algorithem{
	//write degree algorithem here
public:
	void process()
	{
		//write your code here
	}
};
class centralized_algorithem:public base_algorithem{
	
public:
	void process( graph project_sys)
	{    
		float n =project_sys.get_no_nodes();
        vector <float> c(n);
	    for (int i=0; i < n; i ++)
		{ 
			float sum = project_sys.shortest_path(i,source_destination);
			c[i]=(n-1)/sum ;
			cout << c[i] <<"\n";
		}    
	}
};
class betweness_algorithem:public base_algorithem{
public:
	void process()
	{
		//write your code here 
	}
};

int main()
{
	int no_nodes,no_edges;
	cin>>no_nodes>>no_edges;

	graph project_sys ;
	
	
	project_sys.set_nodes( no_nodes);
	project_sys.take_input(no_nodes,no_edges);

	centralized_algorithem cent ;
	 
	 cent.process(project_sys);
	
	//system("pause");
	return 0;
}