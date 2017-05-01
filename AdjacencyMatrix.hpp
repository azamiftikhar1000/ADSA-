#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1
#include <iostream>
#include "GraphAdjacencyBase.hpp"
using namespace std;
namespace cs202
{

template< class T >
class AdjacencyMatrix : public GraphAdjacencyBase
{
private:
	int vert;
	int edg;
	T ** elem;

public:
   AdjacencyMatrix(int ver);
   AdjacencyMatrix();
  ~AdjacencyMatrix()
  {
  	delete elem;
  }
  bool edgeExits(int i, int j);
  int vertices();
  int edges();
  void add(int i, int j);
  void remove(int i, int j);
  int degree(int i);
  int indegree(int i);

};

template<class T>
AdjacencyMatrix<T>::AdjacencyMatrix()
{
	vert=0;
	edg=0;
	elem=NULL;
}

template<class T>
AdjacencyMatrix<T>::AdjacencyMatrix(int ver)
{
	vert = ver;
	edg=0;
	elem= new T*[ver];
	for(int i=0;i<ver;i++)
	{
		for(int j=0;j<ver;j++)
		{
			elem[i]=new T[ver];
			elem[i][j]=0;
		}
	}
}

template<class T>
void AdjacencyMatrix<T>::add(int i, int j)
{
	if(elem[i][j]==0)
	{
		elem[i][j]=1;
		edg++;
	}

	return;
}

template<class T>
void AdjacencyMatrix<T>::remove(int i, int j)
{
	if(elem[i][j]==1)
	{
		elem[i][j]=0;
		edg--;
	}

	return;
}

template<class T>
bool AdjacencyMatrix<T>::edgeExits(int i, int j)
{
	return elem[i][j];
}

template<class T>
int AdjacencyMatrix<T>::edges()
{
	return edg;
}

template<class T>
int AdjacencyMatrix<T>::vertices()
{
	return vert;
}

template <class T>
int AdjacencyMatrix<T>::degree(int i)
{
	int degree=0;
	for(int j=0;j<vert;j++)
	{
		if(elem[i][j]==1)
			degree++;
	}

	return degree;
}

template <class T>
int AdjacencyMatrix<T>::indegree(int i)
{
	int degree=0;
	for(int j=0;j<vert;j++)
	{
		if(elem[j][i]==1)
			degree++;
	}

	return degree;
}





}


#endif /* ifndef ADJACENCY_LIST */