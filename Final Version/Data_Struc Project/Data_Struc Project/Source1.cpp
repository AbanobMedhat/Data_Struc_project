#include<iostream>
#include<vector>
#include<fstream>
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
	edge grph_edges[10000];
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
	void set_edge(edge edg)
	{
		grph_edges[cnt_edges]=edg;
		cnt_edges++;
	}
	edge get_edge(int index)
	{
		return grph_edges[index];
	}
	edge top_edge()
	{
		return grph_edges[0];
	}
	edge last_edge()
	{
		return grph_edges[cnt_edges-1];
	}
	int get_no_edges()
	{
		return cnt_edges;
	}

	void take_input()
	{
		int src,des,weight;
		int no_nodes,no_edges;
		ifstream infile;
		infile.open("test.txt");
		if(!infile)
		{
		cout<<"unable to allocate file";
		exit(1);
		}
		infile>>no_nodes>>no_edges;
		this->set_nodes(no_nodes);
		for(int i=0;i<no_edges;i++)
		{
		infile>>src>>des>>weight;
		edge in_edge(src, des, weight);
		source_destination[src][des]=weight;
		source_destination[des][src]=weight;
		this->set_edge(in_edge);
		this->set_nodes(no_nodes);
		
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
class degree_algorithem :public base_algorithem {
private:
	graph sys;

	edge graph_edges;
	//write degree algorithem here
public:
	degree_algorithem(graph sys) {
		this->sys = sys;
	}
	void process(graph sys)
	{
		int*Degree_cen = new int[sys.get_no_nodes()];
		for (int i = 0;i < sys.get_no_nodes();i++)
		{
			Degree_cen[i]=0;
		}
		for (int i = 0;i < sys.get_no_edges();i++)
		{
			graph_edges = sys.get_edge(i);
			Degree_cen[graph_edges.get_src()]++;
			Degree_cen[graph_edges.get_des()]++;
		}
		test(Degree_cen);
	}
	void test(int* Degree_cen) {
		for (int i = 0;i < sys.get_no_nodes();i++)
		{
			cout << Degree_cen[i] << "\n";
		}
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
	//cin.get();
	//cin>>no_nodes>>no_edges;
	graph project_sys ;
	char selector;
	
	
	project_sys.take_input();
	do{
	cout<<"for degree : press d , for closs: press c "<<endl;
	
	cin>>selector;
	if(selector=='c')
	{
	centralized_algorithem cent ;
	 
	 cent.process(project_sys);
	}
	else if  (selector =='d')
	{
		degree_algorithem Degree_Test(project_sys);
		Degree_Test.process(project_sys);
	}
	cout<<"do u want to run again ?"<<endl;
	cin>>selector;
	}
	while(selector=='y'||selector=='Y');
	//system("pause");
	return 0;
}