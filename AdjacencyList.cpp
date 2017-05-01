#include <iostream>
#include "AdjacencyList.hpp"
using namespace std;
using namespace cs202;

int main()
{
	int n ,e,i,j,mode;
	cout<<"Enter the no of vertices"<<endl;
	cin>>n;
	//cout<<"Enter the mode(m,l)"<endl;
	//cin>>mode;
	AdjacencyList<int> obj(n);
	while(true)
	{
		cout<<"1.Add Edge"<<endl<<"2.Delete Edge"<<endl<<"3.Check if edge exists"<<endl<<"4.No of edges"<<endl<<"5.No of vertices"<<"6.Print"<<endl<<"7.Exit"<<endl;
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

			case 6: for(int i=0;i<n;i++)
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

			case 7:return 0;

			default:cout<<"Enter right choice"<<endl;
					break;
		}




	}


}