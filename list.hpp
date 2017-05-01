#ifndef LIST_HPP
#define LIST_HPP 1
#include <iostream>
using namespace std;
namespace cs202
{

    template<class Item2>
    class listnode
    {
        template<typename Item> friend class list;
        template<typename Item> friend class stack;
        template<typename Item> friend class queue; 
        private:
            Item2 data;
            listnode<Item2> *link;    
    };

    template<class Item>
    class list
    {
      private:
        listnode<Item> *head ; 
        listnode<Item> *tail ;  
        int len ;
 
      public:
         /*
         * Primary contructor.
         * Should construct an empty list.
         * Size of the created list should be zero.
         */

        list();

         /*
         * Seondary constructor.
         * Creates a new list which is a copy of the provided list.
         */
        list(const list<Item> & x);

        /*
         * Destructor.
         * Frees all the memory acquired by the list.
         */
        ~list();

         /*
         * adds value at the end of the list.
         */
        void append(const Item& value);

         /*
         * Returns the length of the list.
         */
        inline int length();
        /*
         * Returns a boolean indicating whether the list is empty.
         */


        inline bool empty();
        /*
         * Adds a value to the front of the list.
         */
        void cons(const Item& value);

        /*
         * Removes the first occurence of the value from list.
         */
        void remove(const Item & x);

        /*
         * Appends the given list x at the end of the current list.
         */
        void append(list<Item>& x);

        void print();

        bool search(const Item &x);
    };

    template<typename Item> list<Item>::list()
    {
        head = NULL ;
        tail  = NULL ;
        len   = 0 ;
    }

    template<typename Item> list<Item>::~list()
    {
        listnode<Item>* tmp ;

        while(head)
        {
            tmp =head->link ;
            delete head ;
            head = tmp ;
        }
    }
    
    template<typename Item> 
	list<Item>::list(const list<Item> & x)
    {
        
        listnode<Item> *temp = x.head;
        while(temp)
        {
            this->append(temp->data);
            temp =temp->link ; 
        }
    }
    template<typename Item> void list<Item>::append(const Item& value)
    {
        listnode<Item>* newnode = new listnode<Item> ;
        if(head == NULL)
        {       
            newnode->data = value;
            newnode->link = NULL;
            head = newnode;
            tail = newnode;
        }
        else
        {
            newnode->data = value;
            newnode->link = NULL;
            tail->link = newnode ;
            tail = newnode ;
        }
        len++ ;
    } 

    template<typename Item> inline int list<Item>::length()
    {
        return len ;
    }
    template<typename Item>  inline bool list<Item>::empty()
    {
       return !len;
    }  
    
    template<typename Item> void list<Item>:: remove(const Item & x)
    {
        if(head!=NULL)
      {
        listnode<Item>* tmp ;
        if(head->data == x )
        {
            tmp = head->link ;
            delete head ;
            head = tmp ;
            len--;
            if(head==NULL)
                tail==NULL ;
            return ; 
        }
        tmp = head ;
        while(tmp->link)
        {
            if(tmp->link->data == x)
            {
                delete tmp->link ;
                tmp->link = tmp->link->link;
                if(tmp->link == NULL)
                {
                    tail = tmp;
                }
                
                len--;
                return  ;
            }
            else
                tmp=tmp->link ;
        }
      }
    } 

    template<typename Item> void list<Item>::cons(const Item& value)
    {
        listnode<Item>* newnode = new listnode<Item> ;
        if(head == NULL)
        {       
            newnode->data = value;
            newnode->link = NULL;
            head = newnode;
            tail = newnode;
        }
        else
        {
            newnode->data = value;
            newnode->link = head;
            head = newnode ; 
        }
        len++;
    }
      
    template<typename Item> void list<Item>::append(list<Item>& x)
    {
        tail->link = x.head;
        len+=x.length();
        tail = x.tail;
    }

    template<typename Item> void list<Item>::print()
    {
        listnode<Item>* tmp ;
        tmp=head ;
        while(tmp)
        {
            cout<<tmp->data<<" ";
            tmp = tmp->link ;
        }
        cout<<endl;
    }

     template<typename Item> 
    bool list<Item>:: search(const Item & x)
    {
        if(head!=NULL)
        {
            listnode<Item>* tmp ;
            if(head->data == x )
                return true;
        else
        {
            tmp = head ;
            while(tmp->link)
            {
                if(tmp->link->data == x)
                return true ;

                tmp=tmp->link;
            }

            return false;
       }
        }

        else
        return false;

    } 


}
#endif