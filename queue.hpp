/*
 * queue.hpp
 *
 * define your methods in coherence with the following
 * function signatures
 * 
 * use the abstraction of linked lists
 * to implement the functionality of queues
 * 
 */

#ifndef QUEUE_HPP_
#define QUEUE_HPP_
#include "list.hpp"
using namespace std;
using namespace cs202 ;
namespace cs202 
{
  template <class Item>
    class queue
    {

      private:
        listnode<Item> *head ; 
        listnode<Item> *tail ;  
        int len ;

      public:
        /*
         * Constructs a new queue.
         */
        queue();

         /*
         * Destructor
         * Fress the memory occupied by the queue elements.
         */
        ~queue();
        /*
         * Pushes t to at the back of the queue.
         */
        void push(const Item& t);
        /*
         * Returns the element at the front of the queue.
         * Also removes the front element from the queue.
         */
        Item pop();
        /*
         * Returns the element at the front of the queue.
         * Does not remove the front element.
         */
        Item front();
        /*
         * Returns the number of elements currently in the queue.
         */
        inline int size();
        /*
         * Returns a boolean indicating whether the queue is empty or not.
         */
        inline bool empty();
        
        void print();
       
    };

    template<typename Item> 
    queue<Item>::queue()
    {
        head = NULL ;
        tail  = NULL ;
        len   = 0 ;
    }

    template<typename Item>
    queue<Item>::~queue()
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
    void queue<Item>::push(const Item& t)
    {
        listnode<Item>* newnode = new listnode<Item> ;
        if(head == NULL)
        {       
            newnode->data = t;
            newnode->link = NULL;
            head = newnode;
            tail = newnode;
        }
        else
        {
            newnode->data = t;
            newnode->link = NULL;
            tail->link = newnode ;
            tail = newnode ;
        }
        len++ ;
    } 

    template<typename Item> 
    inline int queue<Item>::size()
    {
        return len ;
    }

    template<typename Item> 
     inline bool queue<Item>::empty()
    {
        return !len;
    }  
    
    template<typename Item> 
    Item queue<Item>:: pop()
    {
        Item data = head->data ;  
        listnode<Item>* tmp ;
        tmp = head->link ;
        delete head ;
        head = tmp ;
        len--;
        return data ; 
    } 

    template<typename Item> 
    Item queue<Item>:: front()
    {
        return head->data ;
    }
    
    template<typename Item>
     void queue<Item>::print()
    {
        listnode<Item>* tmp ;
        tmp=head ;
        while(tmp)
        {
            cout<<tmp->data<<"  ";
            tmp = tmp->link ;
        }
        cout<<endl;
    }
}
#endif