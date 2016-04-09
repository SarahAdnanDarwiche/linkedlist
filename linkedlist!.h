class Node { 
  
	public:
		int get_val(){return value;}
		void set_val(int v){ value = v;}
  
		Node* get_next(){return this->next;}
		//void set_next(int value){this->next = value;}
  
  		Node* get_prev(){return this->prev;}
		//void set_prev(int value){this->prev = value;}
		
	//private: 
		int value; 
		Node *next;  
		Node *prev;  

};


class LinkedList { 

public:
  Node *head;
  Node *tail;
  LinkedList();  //default constructor
  LinkedList(int v); //constructor
  ~LinkedList();  
  void addHead(int v); 
  void addTail(int v);  
  void removeNodeIndex(int v);
  int removeNodeValue(int v);
  void addNodeIndex(int indext,int v);
  int removeHead();
  int removeTail();
  void createList();
  void printLinkedList();
};