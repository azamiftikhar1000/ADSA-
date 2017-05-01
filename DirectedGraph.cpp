#include <iostream>
#include "DirectedGraph.hpp"
using namespace std;
using namespace cs202;

int main()
{
	int n ,e,i,j;
	char mode,input;
	cout<<"Enter the no of vertices"<<endl;
	cin>>n;
	cout<<"Enter the mode(m,l)"<<endl;
	cin>>mode;
	cout<<"Do you want to enter the file manually ( Y/N)"<<endl;
	cin>>input;
	DirectedGraph<int> obj(n,mode);
	if(input=='Y' || input =='y')
	{

	while(true)
	{
		cout<<"1.Add Edge"<<endl<<"2.Delete Edge"<<endl<<"3.Check if edge exists"<<endl<<"4.No of edges"<<endl<<"5.No of vertices"<<endl<<"6.Print"<<endl<<"7.indegree"<<endl<<"8.Out Degree"<<endl<<"9.Exit"<<endl;
		cin>>e;
		switch(e)
		{
			case 1: cout<<"Enter (i,j) for which there is an edge"<<endl;
					cin>>i>>j;
					obj.add(i,j);
					break;

			case 2:cout<<"Enter (i,j) for which the existing edge has to be deleted"<<endl;
				   cin>>i>>j;
				   obj.remove(i,j);
				   break;

			case 3:cout<<"Enter (i,j) to check whether there is an existing edge"<<endl;
				   cin>>i>>j;
				   if(obj.edgeExits(i,j))
				   	cout<<"Edge present"<<endl;
				   else
				   	cout<<"Edge Not present"<<endl;
				   break;

			case 4:cout<<"No of edges = \t"<< obj.edges()<<endl;
					break;

			case 5:cout<<"No of vertices = \t"<< obj.vertices()<<endl;
					break;

			case 6: for(i=0;i<n;i++)
					{
						for(j=0;j<n;j++)
						{
							if(obj.edgeExits(i,j))
							{
								cout<<i<<"\t"<<j<<endl;
							}
						}
					}
					break;

			case 7:cout<<"Enter the node i "<<endl;
					cin>>i;
				   cout<<obj.indegree(i)<<endl;
				   break;

			case 8:cout<<"Enter the node i "<<endl;
					cin>>i;
				   cout<<obj.outdegree(i)<<endl;
				   break;

			case 9:obj.bfs(0);
					break;

			case 10:obj.dfs(0);
					break;

			default:cout<<"Enter right choice"<<endl;
					break;
		}
	}

	}

	else if(input=='n' || input=='N')
	{
		cout<<"Enter the file name (and the path) "<<endl;
	}


}