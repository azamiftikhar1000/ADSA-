#ifndef SEQLINEARLIST_HPP
#define SEQLINEARLIST_HPP
#include <iostream>
#include <string.h>
using namespace std;

template<class Item>
class LinearList{
	private:
		int MaxSize;
		Item *element;    // 1D dynamic array
        int len;
	public:
		/* Default constructor. 
		 * Should create an empty list that not contain any elements*/
		LinearList();

		/* This constructor should create a list containing MaxSize elements. You can intialize the elements with any values.*/
		LinearList(const int& MaxListSize)
		{
			MaxSize=MaxListSize;
			element = new Item[MaxSize];
			len=0;
		}
		

		/* Destructor. 
		 * Must free all the memory contained by the list */
		~LinearList()
		{
			delete(element);
			cout<<"Memory freed"<<endl;
		}

		/* Indexing operator.
     		 * It should behave the same way array indexing does. i.e,
     		 * LinearList L;
     		 * L[0] should refer to the first element;
     		 * L[1] to the second element and so on.
     		 * */
		Item& operator[](const int& i)//return i'th element of list
		{
				//return *(element+i);
				return element[i];
		}
		

		/* Returns true if the list is empty, false otherwise.
     		 * */
		bool isEmpty()
		{

			if (len == 0) 
				return true;
			else 
				return false;
		}

		/* Returns the actual length (number of elements) in the list.
     		 * */
		int  length()
		{
			return len;
		}

		/* Returns the maximum size of the list.
     		 * */
		int  maxSize()
		{
			return MaxSize ;
		}

		/* Returns the k-th element of the list. 
		 * */
		Item  returnListElement(const int k)
		{
			return element[k-1];
		}

		/* Set x to the k-th element and 
		 * return true if k-th element is present otherwise return false.
		 * */
		bool find(const int k, Item& x)
		{
			if(k<=len && k>=0)
			{
				x=element[k-1];
				return true;
			}

			else 
				return false;

		}

		/* Search for x and 
		 * return the position if found, else return 0.
		 * */
		int  search(Item& x)
		{
			int i;
			for(i=0;i<=len;i++)
			{
				if(element[i]==x)
				{
					return i+1 ;
				}
			}
				return 0;
		}
		/* Set x to the k-th element and delete that k-th element.
		 * */
		void  deleteElement(const int  k, Item& x)

		{
			x=element[k];
			int i;

			for(i=k;i<=len-2;i++)
			{
				element[i]=element[i+1];
			}
			len --;
		}

	
		void display()
		{
			int i;
			for(i=0;i<len;i++)
				cout<<element[i]<<endl;
		}

		/* Insert x after k-th element.
		 * */
		void  insert(const int  k, Item& x)
		{

			int i;
		if(k>len||k<0 ) 
			{
				cout<<"Cannot insert .. Error"<<endl; 
				return;
			}
			else if(len==MaxSize) 
				{
					cout<<"No space to insert"<<endl; 
					return;
				}
			else if(len==0) 
				{
					element[0]=x;
					len=1;
					cout<<"Insert Completed "<< x <<endl;return;
				}
			else 
				{   	
					for(i=len-1;i>=k;i--)
					{

						element[i+1]=element[i];
					}
					element[k]=x;

					len++;
					cout<<"Insert Completed "<<x<<endl;
					return;
				}
		}
};


#endif
