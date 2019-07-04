// ConsoleApplication6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


// Degree_Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <iostream>

#include<vector>
using namespace std;
class edge {
private:
	int src;
	int des;
	int weight;
public:
	edge()
	{}
	edge(int in_src, int in_des, int in_weight)
	{
		src = in_src;
		des = in_des;
		weight = in_weight;
	}
	int get_src()
	{
		return src;
	}
	void set_src(int source)
	{
		src = source;
	}
	int get_des()
	{
		return des;
	}
	void set_des(int destination)
	{
		des = destination;
	}
	int get_weight()
	{
		return weight;
	}
	void set_weight(int wght)
	{
		weight = wght;
	}
};
class graph {
private:
	int cnt_edges;
	vector<int>nodes;
	edge* grph_edges = new edge();
	int cnt_nodes;
public:
	graph()
	{
		cnt_edges = 0;
	}
	void set_nodes(int no_nodes)
	{
		nodes.resize(no_nodes);
		cnt_nodes = no_nodes;
	}
	int get_no_nodes()
	{
		return cnt_nodes;
	}
	int get_no_edges()
	{
		return cnt_edges;
	}

	void set_edge(edge edg)
	{
		//if (cnt_edges >= grph_edges.max_size())
			//grph_edges.resize(3 * cnt_edges++);
		grph_edges[cnt_edges] = edg;
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
		return grph_edges[cnt_edges - 1];
	}
	void take_input(int no_nodes, int no_edges)
	{
		grph_edges = new edge[no_edges];
		int src, des, weight;
		for (int i = 0;i < no_edges;i++)
		{
			cin >> src >> des >> weight;
			edge in_edge(src, des, weight);
			this->set_edge(in_edge);
			this->set_nodes(no_nodes);
		}
	}
	//shortest path function you are free to change the return type of the function
	void shortest_path(int src, vector<vector<int>>table)
	{
		//write your code here 
	}
};
class base_algorithem {
public:
	virtual void process() = 0;
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
	void process()
	{
		int*Degree_cen = new int[sys.get_no_nodes()];
		for (int i = 0;i <= sys.get_no_nodes();i++)
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
			cout << Degree_cen[i] <<'\n';
		}
	}
};
class centralized_algorithem :public base_algorithem {
public:
	void process()
	{
		//write your code here
	}
};
class betweness_algorithem :public base_algorithem {
public:
	void process()
	{
		//write your code here 
	}
};
int main()
{
	int no_nodes, no_edges;
	cin >> no_nodes >> no_edges;
	graph project_sys;
	project_sys.take_input(no_nodes, no_edges);
	/////////test degree algorithm
	degree_algorithem Degree_Test(project_sys);
	Degree_Test.process();
	return 0;
}
