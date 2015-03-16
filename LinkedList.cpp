#include <iostream>
#include "LinkedList.h"
#include <string>

using namespace std;

Node::Node() {
	this->used = false;
	this->pName = "";
	this->next = NULL;
	
}

/*
Node::Node(boolean used){
	this->used = used;
	this->pName = "";
	this->next = NULL;
}

Node::Node(boolean used, string pName) {
	this->used = used;
	this->pName = pName;
	this->next = NULL;
	
}

Node::Node(boolean used, string pName, Node *next) {
	this->used = used;
	this->pName = pName;
	this->next = next;
	
}  */

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

//public methods for LinkedList

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
	Node * newNode = new Node();
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

/*
void LinkedList::remove(bool used, string pName){
	Node * newHead = new Node(false, "", head);
	Node * prev = newHead;
	Node * curr = head;
	while(curr != NULL){
		if(curr->getName() == pName){
			prev->setNext(curr->getNext());
			delete curr;
			curr = prev->getNext();
		} else {
			curr = curr->getNext();
			prev = prev->getNext();
	}
	head = newHead->getNext();
	delete newHead;
}
} */

void LinkedList::print(){
	if(head == NULL) {
		cout << "LinkedList is empty" <<endl;
	}
	Node * temp = head;
	int count = 0;
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
		if(count%8 == 0){
			cout<< endl;
		}
	}
	cout<< endl;
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
		}
		return count;
}

int LinkedList::fragCount(){
	Node *temp = head;
	int count = 0;
	
	while(temp != NULL){
		bool used = temp->getUsed();
		if(!used){
			Node *next = temp->getNext();
			if(next->getUsed()){
				count++;
			}
		}
		temp = temp->getNext();
	}
	return count++;
}

bool LinkedList::addProgram(string name, int size){
	Node *temp = head;
	Node *greatest = temp;
	int maxCount = 0;
	int count = 0;
	Node *firstNode = temp;
	bool success = false;
	
	//worst
	while (temp != NULL){
		bool used = temp->getUsed();
		if(!used){
			count++;
			temp = temp->getNext();
		}
		else{
			if(count > maxCount && count < size){
				maxCount = count;
				greatest = firstNode;
			}
			else{
				count = 0;
				temp = temp->getNext();
				firstNode = temp;
			}
		}
	}
	for(int i = 0; i < size; i++){
		Node *start = greatest;
		start->setUsed(true);
		start->setName(name);
		success = true;
		start = start->getNext();
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




	
	
