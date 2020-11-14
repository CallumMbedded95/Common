#ifndef NODE_CPP
#define NODE_CPP

#include <iostream>

template<class T>
class Node {
	T data;
	Node* next = nullptr;
public:
	Node(T data_) : data(data_) {}

	inline Node* getNext() {
		return this->next;
	}

	inline void setNext(Node<T>* nextNode) {
		this->next = nextNode;
	}

	inline T getData() {
		return this->data;
	}

	inline void printData() {
		std::cout << this->data << ", ";
	}
};
#endif