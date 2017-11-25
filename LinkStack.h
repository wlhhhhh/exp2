#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include<iostream>
#include<stdlib.h>

using namespace std;

template<class E>
struct Node
{
    E data;
    Node<E> * next;

    Node()
    {
        next = NULL;
    }
    Node(E item,Node<E>*link = NULL)
    {
        data = item;
        next = link;
    }
};

template<class E>
class LinkStack
{
protected:
    Node<E>* top;


    void Init();

public:
    LinkStack();
    virtual ~LinkStack();
    int Length() const;
    bool Empty() const;
    void Clear();
    void Traverse(void(*visit)(const E &)) const;
    bool Push(const E &e);
    bool Top(E &e) const;
    bool Pop(E &e);
    LinkStack(const LinkStack<E>&copy);
    //LinkStack<E>&operator=(const LinkStack<E>&copy);
};

template<class E>
void LinkStack<E>::Init()
{
    top = NULL;
}

template<class E>
LinkStack<E>::LinkStack()
{
    Init();
}

template<class E>
LinkStack<E>::~LinkStack()
{
    Clear();
}

template<class E>
int LinkStack<E>::Length() const
{
    int count = 0;
    for(Node<E>*Ptr = top;Ptr!=NULL;Ptr = Ptr->next)
    {
        count++;
    }
    return count;
}

template<class E>
bool LinkStack<E>::Empty() const
{
    return top == NULL;

}

template<class E>
void LinkStack<E>::Clear()
{
    E tmpElem;
    while(!Empty())
        Pop(tmpElem);
}

template<class E>
void LinkStack<E>::Traverse(void(*visit)(const E &)) const
{
    Node<E> * tmpPtr;
    LinkStack<E> tmps;
    for(tmpPtr = top;tmpPtr!=NULL;tmpPtr=tmpPtr->next)
    {
        tmps.Push(tmpPtr->data);
    }

    for(tmpPtr=tmps.top;tmpPtr!=NULL;tmpPtr=tmpPtr->next)
    {
        (*visit)(tmpPtr->data);
    }
}

template<class E>
bool LinkStack<E>::Push(const E &e)
{
    Node<E> * new_top = new Node<E>(e,top);
    if(new_top==NULL)
    {
        return false;
    }
    else
    {
        top = new_top;
        return true;
    }
}

template<class E>
bool LinkStack<E>::Top(E &e) const
{
    if(Empty())
    {
        return false;
    }
    else
    {
        e = top->data;
        return true;
    }
}

template<class E>
bool LinkStack<E>::Pop(E &e)
{
    if(Empty())
    {
        return false;
    }
    else
    {
        Node<E> * old_top = top;
        e = old_top->data;
        top = old_top->next;
        delete old_top;
        return true;
    }
}

template<class E>
LinkStack<E>::LinkStack(const LinkStack<E>&copy)
{
    if(copy.Empty())
    {
        Init();
    }
    else
    {
        top = new Node<E>(copy.top->data);
        Node<E> * buttomPtr = top;
        for(Node<E>*tmpPtr = copy.top->next;tmpPtr!=NULL;tmpPtr=tmpPtr->next)
        {
            buttomPtr->next = new Node<E>(tmpPtr->data);
            buttomPtr = buttomPtr->next;
        }
    }
}

//template<class E>
//LinkStack<E>::LinkStack<E>&operator=(const LinkStack<E>&copy)
//{
//    if(&copy!=this)
//    {
 //       if (copy.Clear())
 //       {
  //          Init();
 //       }
    //    else
  //      {
     //       Clear();
     //       top = new Node<E>(copy.top->data);
      //      for(Node<E>*tmpPtr = copy.top->next;tmpPtr!=NULL;tmpPtr=tmpPtr->next)
        //    {
   //             buttomPtr->next = new Node<T>(tmpPtr->data);
        //        buttomPtr = buttomPtr->next;
       //     }
       // }
  //  }
//}


#endif // CALCULATOR_H_INCLUDED
