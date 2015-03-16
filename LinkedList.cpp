#include <iostream>
#include "LinkedList.h"
#include <string>

using namespace std;

//publid Node Methods
//constructor
Node::Node() {
	this->used = false;
	this->pName = "";
	this->next = NULL;
	
}

//deconstructor
Node::~Node(){
	this->next = NULL;
}

bool Node::getUsed(){
	return this->used;
}

void Node::setUsed(bool used){
	this->used = used;
}

string Node::getName(){
	return this->pName;
}

void Node::setName(string pName){
	this->pName = pName;
}

Node * Node::getNext() {
	return this->next;
}

void Node::setNext(Node *next){
	this->next = next;
}

//public LinkedList methods
LinkedList::LinkedList(){
	this->head = NULL;
}

LinkedList::LinkedList(Node *head){
	this->head = head;
}

LinkedList::~LinkedList(){
	clear();
}

Node * LinkedList::getHead(){
	return this->head;
}

void LinkedList::setHead(Node *head){
	this->head = head;
}

void LinkedList::insert(){
	//because all initialized the same, no need to input variables
	Node * newNode = new Node();
	//if none, creates new head
	if(head == NULL) {
		head = newNode;
		return;
	}
	Node * temp = head;
	while(temp->getNext() != NULL) {
		temp = temp->getNext();
	}
	temp->setNext(newNode);
}

void LinkedList::print(){
	//checks if LinkedList exists
	if(head == NULL) {
		cout << "LinkedList is empty" <<endl;
	}
	Node * temp = head;
	int count = 0;
	cout<<endl;
	while(temp != NULL){
		if(temp->getUsed() == true){
			cout<< temp->getName() << "\t";
			temp = temp->getNext();
			count++;
		}
		else { 
			cout<< "Free" << "\t";
			temp = temp->getNext();
			count++;	
		}
		if(count%8 == 0 && count != 32){
			cout<< endl;
		}
	}
	
}

bool LinkedList::search(string name){
	Node *temp = head;
	while(temp != NULL){
		if(temp->getName().compare(name) == 0) return true;
		temp = temp->getNext();
	}
	return false;
}

int LinkedList::searchRemove(string value){
		Node *temp = head;
		int count = 0;
		while (temp != NULL) {
			if (temp->getName().compare(value) == 0){
				temp->setName("");
				temp->setUsed(false);
				count++;
				temp = temp->getNext();
			}
			else temp = temp->getNext();
		}
		return count;
}

int LinkedList::fragCount(){
	Node *temp = head;
	int count = 0;
	Node *last = temp;
	
	while(temp != NULL){
		bool used = temp->getUsed();
		if(!used){
			Node *next = temp->getNext();
			if(next != NULL){
				if(next->getUsed()){
				count++;
				}
			}
		}
		last = temp;
		temp = temp->getNext();
	}
	bool lastUsed = false;
	lastUsed = last->getUsed();
	if(lastUsed) return count;
	return count + 1;
}

bool LinkedList::addWorstProgram(string name, int size){
	//initializing pseudo-head
	Node *temp = head;
	Node *greatest = temp;
	int maxCount = 0;
	int count = 0;
	Node *firstNode = temp;
	bool success = false;
	
	while (temp != NULL){
		
		bool used = temp->getUsed();
		Node *next = temp->getNext();
		//check if space is not used
		if(!used){
			count++;
			//check if it is proper end empty space
			if(next == NULL && count > maxCount && count >= size){
				count++;
				maxCount = count;
				greatest = firstNode;
				break;
			}
			
			temp = temp->getNext();
			
			
		}
		
		//if it is empty
		else{
			count++;
			if(count > maxCount && count > size){
				
				maxCount = count;
				greatest = firstNode;
				count = 0;
				temp = temp->getNext();
				firstNode = temp;
			}
			else{
				count = 0;
				temp = temp->getNext();
				firstNode = temp;
			}
		}
	}
		Node *start = greatest;
	//check if available size is larger than size needed
	if(maxCount <= size){
		success = false;
	}
	else{
	for(int i = 0; i < size; i++){
		
		start->setUsed(true);
		start->setName(name);
		success = true;
		start = start->getNext();
	}
	}
	return success;
}

bool LinkedList::addBestProgram(string name, int size){
	//initializing pseudo-head
	Node *temp = head;
	Node *greatest = temp;
	int minCount = 33;
	int count = 0;
	Node *firstNode = temp;
	bool success = false;
	
	
	while (temp != NULL){
		
		bool used = temp->getUsed();
		Node *next = temp->getNext();
		//check if space is not used
		if(!used){
			count++;
			//check if it is proper end empty space
			if(next == NULL && count < minCount && count >= size){
				count++;
				minCount = count;
				greatest = firstNode;
				break;
			}
			
			temp = temp->getNext();
			
		}
		
		//if it is empty
		else{
			count++;
			if(count < minCount && count > size){
				
				minCount = count;
				greatest = firstNode;
				count = 0;
				temp = temp->getNext();
				firstNode = temp;
			}
			else{
				count = 0;
				temp = temp->getNext();
				firstNode = temp;
			}
		}
	}
		Node *start = greatest;
	//check if available size is larger than size needed
	if(minCount <= size){
		success = false;
	}
	else{
	for(int i = 0; i < size; i++){
		
		start->setUsed(true);
		start->setName(name);
		success = true;
		start = start->getNext();
	}
	}
	return success;
}

void LinkedList::clear(){
	Node * curr = head;
	Node * next = NULL;
	while(curr != NULL){
		next = curr->getNext();
		delete curr;
		curr = next;
	}
}




	
	
