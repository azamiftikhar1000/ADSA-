#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 1
/*
 * A class to represent an UndirectedGraph
 * Subclasses AbstractGraph
 */
#include "AbstractGraph.hpp"
#include "AdjacencyMatrix.hpp"
#include "AdjacencyList.hpp"
#include "queue.hpp"
#include "seqLinearList.hpp"
#include "stack.hpp"
#include <limits.h>
//using namespace cs202;
using namespace std;

namespace cs202
{


template<class T>
class bfsnode
{
    template <class T1>
   friend class UndirectedGraph;
  protected: 
    bfsnode<T> * predecessor;
    int color ; // 0 for white , 1 for gray and 2 for black
    int distance;
    int index;

  public:
    bfsnode()
    {
      predecessor=NULL;
      color =0;
      distance =INT_MAX;
    }

    void setnode(int dist,int col,bfsnode<int> * pred,int ind)
    {
      distance=dist;
      color=col;
      predecessor = pred;
      index=ind;
    }

    int getcolor()
      {
        return color;
      }

      int getindex()
      {
        return index;
      }

    void setcolor(int col)
      {
        color= col;
      }

      int getdistance()
      {
        return distance;
      }

};

template<class T>
class UndirectedGraph : public AbstractGraph 
{
protected:
  AdjacencyMatrix<int> * amatrix;
  AdjacencyList<int> *alist;
  int flag ; 
  int unedg;
  bfsnode<int>* bfsgr;// 0 for adjacencylist and 1 for adjacency matrix , 2 indicates that no construction occurs

 public:

  void work (int& i);
  int degree(int i);
  bool edgeExits(int i, int j);
  int edges();
  int vertices();
  void add(int i, int j) ;
  void remove(int i, int j);
  void dfs(int src);
  void bfs(int src);
  /*
   * Constructor: UndirectedGraph
   *
   * Parameters: mode
   * Used to decide which representation to use
   * 'm' for AdjacencyMatrix
   * 'l' for AdjacencyList
   */
  UndirectedGraph(int vertices, char mode);
  /*
   * Returns the degree of the vertex->
   */



};



template<class T>
UndirectedGraph<T>::UndirectedGraph(int vertices, char mode)
  {
    if(mode=='m')
    {
      unedg=0;
      amatrix=new AdjacencyMatrix<int>(vertices);
      flag=0;
    }

    else if(mode=='l')
      {
        unedg=0;
        alist=new AdjacencyList<int>(vertices);
        flag=1;
      }

      else
      {
        unedg=0;
        flag=2;
      }
  }


template<class T>
bool UndirectedGraph<T>::edgeExits(int i, int j)
{
  if(flag==0)
    return amatrix->edgeExits(i,j);

  else if(flag==1)
    return alist->edgeExits(i,j);

  else 
    return false;
}

template<class T>
int UndirectedGraph<T>::edges()
{
  return unedg;
}

template<class T>
int UndirectedGraph<T>::vertices()
{
  if(flag==0)
    return amatrix->vertices();

  else if(flag==1)
    return alist->vertices();

  else
    return 0;
}


template<class T>
void UndirectedGraph<T>::add(int i,int j)
{
  if(flag==0)
     {
      if(!amatrix->edgeExits(i,j))
      {
      amatrix->add(i,j);
      amatrix->add(j,i);
      unedg++;
      }

     }

  else if(flag==1)
    {
      if(!alist->edgeExits(i,j))
      {
        alist->add(i,j);
        alist->add(j,i);
        unedg++;
      }
    }

  else
    return ;
}


template<class T>
void UndirectedGraph<T>::remove(int i,int j)
{
  if(flag==0)
  {
    if(amatrix->edgeExits(i,j))
     {
      amatrix->remove(i,j);
      amatrix->remove(j,i);
      unedg--;
     }
  }

  else if(flag==1)
  {
    if(alist->edgeExits(i,j))
    {
      alist->remove(i,j);
      alist->remove(j,i);
      unedg--;
    }

  }

  else
    return ;
}

template<class T>
int UndirectedGraph<T>::degree(int i)
{
  if(flag==0)
    return amatrix->degree(i);

  else if(flag==1)
    return alist->degree(i);

}


template<class T>
void UndirectedGraph<T>::bfs(int src)
{
  if(flag==1)
  {
    int n=alist->vertices();
    int color[n];
    int dis[n];
    queue<int> q1;
    for(int j=0;j<n;j++)
    {
      if(j!=src)
      {
        dis[j]=INT_MAX;
        color[j]=0;
      }
    }

    dis[src]=0;
    color[src]=1;
    q1.push(src);
    while(!q1.empty())
    {
      int index = q1.pop();
      color[index]=2;
      cout<<"Visited the index  "<< index<<endl<<"Distance from source"<<"\t"<<dis[index]<<endl;
      for(int j=0;j<n;j++)
      {
        if(alist->edgeExits(index,j) && color[j]==0)
        {
          dis[j]=dis[index]+1;
          color[j]=1;
          q1.push(j);
        }
      }
    }
  }

  else if(flag==0)
  {
    int n=amatrix->vertices();
    int color[n];
    int dis[n];
    queue<int> q1;
    for(int j=0;j<n;j++)
    {
      if(j!=src)
      {
        dis[j]=INT_MAX;
        color[j]=0;
      }
    }

    dis[src]=0;
    color[src]=1;
    q1.push(src);
    while(!q1.empty())
    {
      int index = q1.pop();
      color[index]=2;
      cout<<"Visited the index  "<< index<<endl<<"Distance from source"<<"\t"<<dis[index]<<endl;
      for(int j=0;j<n;j++)
      {
        if(amatrix->edgeExits(index,j) && color[j]==0)
        {
          dis[j]=dis[index]+1;
          color[j]=1;
          q1.push(j);
        }
      }
    }
  }
}


template<class T>
void UndirectedGraph<T>::dfs(int src)
{
  if(flag==1)
  {
    int f=1;
    int temp;
    int n=alist->vertices();
    int color[n];
    //int dis[n];
    stack<int> s1;
    for(int j=0;j<n;j++)
    {
      if(j!=src)
      {
        //dis[j]=INT_MAX;
        color[j]=0;
      }
    }

    //dis[src]=0;
    color[src]=1;
    s1.push(src);
    cout<<"Vistited the index "<<src<<endl;

    while(!s1.empty())
    {
      f=1;
      int index = s1.top();
      //color[index]=2;
     // cout<<"Visited the index  "<< index<<endl;
       
      for(int j=0;j<n;j++)
      {
        if(alist->edgeExits(index,j) && color[j]==0)
        {
          //dis[j]=dis[index]+1;
          color[j]=1;
          s1.push(j);
          f=0;
          cout<<"Visited the index "<<j<<endl;
          break;
        }
      }

      if(f)
      {
        temp=s1.pop();
        color[temp]=2;
      }
    }
  }

  else if(flag==0)
  {
    int f=1;
    int temp;
    int n=amatrix->vertices();
    int color[n];
    //int dis[n];
    stack<int> s1;
    for(int j=0;j<n;j++)
    {
      if(j!=src)
      {
        //dis[j]=INT_MAX;
        color[j]=0;
      }
    }

    //dis[src]=0;
    color[src]=1;
    s1.push(src);
    cout<<"Vistited the index "<<src<<endl;

    while(!s1.empty())
    {
      f=1;
      int index = s1.top();
      //color[index]=2;
     // cout<<"Visited the index  "<< index<<endl;
       
      for(int j=0;j<n;j++)
      {
        if(amatrix->edgeExits(index,j) && color[j]==0)
        {
          //dis[j]=dis[index]+1;
          color[j]=1;
          s1.push(j);
          f=0;
          cout<<"Visited the index "<<j<<endl;
          break;
        }
      }

      if(f)
      {
        temp=s1.pop();
        color[temp]=2;
      }
    }
  }
}


template<class T>
void UndirectedGraph<T>::work(int &i)
{
  cout<<"Visited the vertex \t"<<i<<endl;
}




}

#endif /* ifndef UNDIRECTED_GRAPH */