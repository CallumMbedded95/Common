#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include "Node.cpp"
#include <iostream>

template<class T>
// Acts as a stack, push/pop
class LinkedList {
	Node<T>* head;
public:
	LinkedList(Node<T>* head_) : head(head_) {}

	~LinkedList() {
		// Free memory
		Node<T>* tmp = this->head;

		while (this->head != nullptr) {
			tmp = this->head;
			this->head=this->head->getNext();
			delete(tmp);
			tmp = nullptr;
		}
	}

	inline Node<T>* getHead() {
		return this->head;
	}

	inline void setHead(Node<T>* newHead) {
		this->head = newHead;
	}

	void printList() {
		Node<T>* tmp = this->head;

		while (tmp != nullptr) {
			tmp->printData();
			tmp=tmp->getNext();
		}
		std::cout << std::endl;
	}

	void printList(Node<T>* head) {
		Node<T>* tmp = head;

		while (tmp != nullptr) {
			tmp->printData();
			tmp=tmp->getNext();
		}
		std::cout << std::endl;
	}

	// Performs a 'push'
	void addNode(Node<T>* newNode) {
		Node<T>* tmp = head;
		head = newNode;
		newNode->setNext(tmp);
	}

	// Performs a 'pop'
	void removeNode() {
		Node<T>* tmp = head;
		head = head->getNext();
		delete(tmp); // delete heap allocated objects
		tmp = nullptr;
	}

	// Unoptimised sort
	Node<T>* SelectionSort(Node<T>* head) {
		Node<T>* tmp = head;		

		if (tmp != nullptr) {
			SortOnHead(&tmp);
			head = tmp;			
			head->setNext(SelectionSort(tmp->getNext()));

			/// Test Block
			// tmp = tmp->getNext();
			// SortOnHead(&tmp);
			// head->setNext(tmp);

			// tmp = tmp->getNext();
			// SortOnHead(&tmp);
			// head->setNext(tmp);

			// 			tmp = tmp->getNext();
			// SortOnHead(&tmp);
			// head->setNext(tmp);
			////
		}

		return head;
	}

	void SortOnHead(Node<T>** head) {
		Node<T>* tmp = *head;
		Node<T>* lowestValue = *head;
		Node<T>* prevLowNode = nullptr;
		Node<T>* prevNode = nullptr;

		while (tmp != nullptr) {
			if (lowestValue->getData() > tmp->getData()) {
				lowestValue = tmp;
				prevLowNode = prevNode;		
			}
			prevNode = tmp;		
			tmp = tmp->getNext();
		}

		// Swap indexes if a lower value was found
		if (lowestValue != *head) {			
			Node<T>* oldHead = *head;
			Node<T>* tmpLowest = lowestValue->getNext();
			if (tmpLowest != nullptr)			
				prevLowNode->setNext(tmpLowest);
			else
				prevLowNode->setNext(nullptr);

			(*head) = lowestValue;
			(*head)->setNext(oldHead);
		}

		printList(*head);
	}
};
#endif