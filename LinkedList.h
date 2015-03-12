class Node{
	private:
		bool used;
		string pName;
		Node *next;
	public: 
		Node();
		Node(bool used, string pName);
		Node(bool used, string pName, Node *next);
		~Node();
		bool getUsed();
		void setUsed(bool used);
		string getName();
		void setName(string pName);
		Node *getNext();
		void setNext(Node *next);
};

class LinkedList {
	private: 
		Node *head;
	public:
		LinkedList();
		LinkedList(Node *head);
		~LinkedList();
		Node *getHead();
		void setHead(Node *head);

		void insert(bool used, string pName);
		void remove(bool used, string pName);
		void print();
		bool search(bool used, string pName);
		void clear();

};
