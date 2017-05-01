/* 
 * stack.hpp
 * 
 * define your methods in coherence with the following
 * function signatures
 * 
 * use the abstraction of linked lists
 * to implement the functionality of stacks
 * 
 */

#ifndef SItemACK_HPP_
#define SItemACK_HPP_
#include "list.hpp"
using namespace std;
using namespace cs202 ;
namespace cs202
{
  template<typename Item>
    class stack
    {
      private:
        listnode<Item>* front ;  
        int len;

      public:
         /*
         * Constructs a new stack.
         */
        stack();

         /*
         * Destructor
         * Fress the memory occupied by the stack elements.
         */
         ~stack();
        /*
         * Pushes t to on the top of the stack.
         */
        void push(const Item& t);
         /*
         * Returns the element at the top of the stack.
         * Also removes the top element from the stack.
         */
        Item pop();

        /*
         * Returns the element at the top of the stack.
         * Does not remove the top element.
         */
        Item top();
         /*
         * Returns the number of elements currently in the stack.
         */
        int size();
        /*
         * Returns a boolean indicating whether the stack is empty or not.
         */
        inline bool empty();

       
        void print();

    };
    

    template<typename Item> 
    stack<Item>::stack()
    {
        front = NULL ;
        len   = 0 ;
    }


    template<typename Item> 
    stack<Item>::~stack()
    {
        listnode<Item> *temp ;
        while(front)
        {
            temp = front ;
            front = front->link ;
            delete temp ;
        }
        len=0 ; 
    }



    template<typename Item> 
    void stack<Item>::push(const Item& t)
    {
        listnode<Item>* newnode = new listnode<Item> ;
        if(front == NULL)
        {       
            newnode->data = t;
            newnode->link = NULL;
            front = newnode ;
        }
        else
        {
            newnode->data = t;
            newnode->link = front;
            front = newnode ;
        }
        len++ ;
    }
    

    template<typename Item> 
    Item stack<Item>::pop()
    {
        Item data =  front->data ;
        listnode<Item>* temp;
        temp = front ;
        front = front ->link ; 
        delete temp ;
        len -- ;
        return data ;

    }


    template<typename Item> 
    Item stack<Item>::top()
    {
        return front->data ;
    }

    template<typename Item>
     int stack<Item>::size()
    {
        return len ;
    }

    template<typename Item>
     bool stack<Item>::empty()
    {
         return !len;
    }


    template<typename Item> void stack<Item>::print()
    {
        listnode<Item>* tmp ;
        tmp=front ;
        while(tmp)
        {
            cout<<tmp->data<<"  ";
            tmp = tmp->link ;
        }
        cout<<endl;
    }

}

#endif