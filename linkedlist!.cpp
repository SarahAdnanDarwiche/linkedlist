using namespace std;
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "linkedlist!.h"
  
LinkedList::LinkedList() //constructor
{
  head = NULL;
  tail = NULL;
}

LinkedList::~LinkedList() //destructor
{
  delete head;
  delete tail;
}

void printList()
{
  cout << "1: To list all contacts in order" << endl;
  cout << "2: To list all contacts in opposite order" << endl;
  cout << "3: To add Friend and their Birthday" << endl;
  cout << "4: Create a List of people" << endl;
}

void LinkedList::createList()
{
  int array[] = {1,2,3,4,5,6,7,8};
  Node *l = new Node;
  l->value = array[0];
  head = l;
  int i = 1;
  while(i < 8)
    {
      l->next = new Node;
      l->next->value = array[i];
      i++;
      l = l->next;
    }
  tail = l;
  l->next = NULL; 
}

void LinkedList::addHead(int v)
{
  Node *l = new Node();
  l->value = v;
  if(head == NULL)
    {
      head = l;
      head->next = NULL;
      tail = head;
    }
  else
    {
      l->next = head;
      head = l;
    }
}

void LinkedList::addTail(int v)
{
  Node *l = new Node;
  l->value = v;
  l->next = NULL;
  tail->next = l;
  tail = l;
}

void LinkedList::printLinkedList()
{
  Node *tmp;
  for(tmp = head;tmp != NULL;tmp = tmp->next)
    {
      cout << tmp->value << ", ";
    }
  cout << endl;
}

int LinkedList::removeNodeValue(int v)
{
  if(head->value == v)
    return removeHead();

  Node *tmp;
  Node *nodeToRemove;
  for(tmp = head;tmp->next != NULL;tmp = tmp->next)
    {
      if(tmp->next->value == v)
	{
	  nodeToRemove = tmp->next;
	  tmp->next = tmp->next->next;
	  if(tmp->next == NULL)
	    tail = tmp;
	  return nodeToRemove->value;
	}
    }
  cout << "There is no Node with the value " << v << endl;
  return v;
}

int LinkedList::removeHead()
{
  int value = -1;
  if(head == NULL)
    {
      cout << "There is nothing in the Linked List" << endl;
      tail = NULL;
      return value;
    }
  if(head->next == NULL)
    {
      value = head->value;
      delete head;
      head = NULL;
      tail = NULL;
      return value;
    }
  else
    {
      value = head->value;
      head = head->next;
      return value;
    }
}

void LinkedList::removeNodeIndex(int v)
{
  if(v == 1)
    return;
  int i = 1;
  Node *tmp;
  for(tmp = head->next;tmp->next != NULL;tmp = tmp->next)
    ;
  
}
 
void LinkedList::addNodeIndex(int index,int v)
{
  if(index == 1)
    {
      addHead(v);
      return;
    }
  Node *n = new Node;
  n->value = v;
  
  Node *tmp;
  for(tmp = head;index != 2;index--,tmp = tmp->next)
    ;
  n->next = tmp->next;
  if(tmp->next == NULL)
    {
      n->next = NULL;
      tail = n;
    }
  tmp->next = n;

}
 

int main(int argc,char *argv[])
{
  LinkedList *list = new LinkedList(); //object - list
  list->createList();
  list->addHead(0);
  list->addTail(9);
  list->printLinkedList();
  cout << "new list after removing value " << list->removeNodeValue(10) << endl;
  list->printLinkedList();
  list->addTail(10);
  cout << "new list after removing value " << list->removeNodeValue(0) << endl;
  cout << "and adding value 10 to the tail" << endl;
  list->printLinkedList();
  cout << "new list after removing value " << list->removeNodeValue(10) << endl;
  list->printLinkedList();
  cout << "new list after adding 33 to the tail" << endl;
  list->addTail(33);
  list->printLinkedList();
  list->addNodeIndex(2,9);
  list->addNodeIndex(3,10);
  cout << "added a 9 to index 2" << endl;
  cout << "and a 10 to index 3" << endl;
  list->printLinkedList();
  list->addNodeIndex(1,6);
  list->addNodeIndex(14,4);
  cout << "added a 6 to index 1" << endl;
  cout << "and a 4 to index 10" << endl;
  list->printLinkedList();
  list->addTail(22);
  list->printLinkedList();
  cout << "****" << endl;
  LinkedList list2;// = new LinkedList();
  list2.createList();
  list2.printLinkedList();
  list2.addHead(99);
  list2.printLinkedList();

}
