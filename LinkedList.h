#include <string>
using namespace std;

class Node{
	private:
		bool used;
		string pName;
		Node *next;
	public: 
		Node();
		Node(bool used);
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

		void insert();
		void remove(bool used, string pName);
		void print();
		bool search(string name);
		int searchRemove(string pName);
		int fragCount();
		bool addWorstProgram(string name, int size);
		bool addBestProgram(string name, int size);
		void clear();

};
