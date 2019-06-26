#include<iostream>
#include<vector>
using namespace std;
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
	void take_input(int no_nodes,int no_edges)
	{
		int src,des,weight;
		for(int i=0;i<no_edges;i++)
		{
		cin>>src>>des>>weight;
		edge in_edge(src,des,weight);
		this->set_edge(in_edge);
		}
	}
	//shortest path function you are free to change the return type of the function
	void shortest_path(int src,vector<vector<int>>table)
	{
		//write your code here 
	}
};
class base_algorithem{
public:
	virtual void process()=0;
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
	void process()
	{
		//write your code here
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
	project_sys.take_input(no_nodes,no_edges);
	system("pause");
	return 0;
}