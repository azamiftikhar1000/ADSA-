#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 1
#include "GraphAdjacencyBase.hpp"
#include "list.hpp"
#include "seqLinearList.hpp"
using namespace cs202;
using namespace std;

namespace cs202
{
template<class T>
class AdjacencyList : public GraphAdjacencyBase
{
private:
	int vert;
	int edg;
	list<int> * graph;

public:
	AdjacencyList();
	AdjacencyList(int v);
	bool edgeExits(int i, int j);
  	int vertices();
  	int edges();
  	void add(int i, int j);
  	void remove(int i, int j);
  	int degree(int i);
  	int indegree(int i);
  	int * getarray(int i);


	 ~AdjacencyList()
	 {
	 	delete graph;
	 }
};

template<class T>
AdjacencyList<T>::AdjacencyList()
{
	vert=0;
	edg=0;
	graph=NULL;
}

template<class T>
AdjacencyList<T>::AdjacencyList(int v)
{
	vert=v;
	edg=0;
	graph= new list<int>[v];
}


template<class T>
void AdjacencyList<T>::add(int i, int j)
{
	if(!edgeExits(i,j))
	{
		cout<<"1"<<endl;
		graph[i].append(j);
		edg++;
	}
}

template<class T>
void AdjacencyList<T>::remove(int i, int j)
{
	if(edgeExits(i,j))
	{
		graph[i].remove(j);
		edg--;
	}
}

template<class T>
bool AdjacencyList<T>::edgeExits(int i, int j)
{
	//cout<<graph[i]<<endl;
	//cout<<"edgeExists"<<endl;
	return graph[i].search(j);
}

template<class T>
int AdjacencyList<T>::edges()
{
	return edg;
}

template<class T>
int AdjacencyList<T>::vertices()
{
	return vert;
}

template <class T>
int AdjacencyList<T>::degree(int i)
{
	return graph[i].length();
}


template <class T>
int AdjacencyList<T>::indegree(int i)
{
	int degree=0;
	for(int j=0;j<vert;j++)
	{
		if(graph[j].search(i))
			degree++;
	}

	return degree;
}

template<class T>
int* AdjacencyList<T>::getarray(int i)
{
	int n = vertices();
	int array[n];
	for(int j=0;j<vert;j++)
	{
		if(edgeExits(i,j))
			array[j]=1;

		else
			array[j]=0;
	}

	return array;
}

}
#endif /* ifndef ADJACENCY_MATRIX */