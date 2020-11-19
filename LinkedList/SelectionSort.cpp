#ifndef SELECTIONSORT_CPP
#define SELECTIONSORT_CPP
#include "Node.cpp"

template<class T>
class SelectionSort {
public:
	SelectionSort() {}
	~SelectionSort() {}
	// Unoptimised sort
	static Node<T>* SelectionSort_(Node<T>* head) {
		Node<T>* tmp = head;		

		if (tmp != nullptr) {
			SortOnHead(&tmp);
			head = tmp;			
			head->setNext(SelectionSort_(tmp->getNext()));
		}

		return head;
	}
	
private:
	static void SortOnHead(Node<T>** head) {
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
	}
};
#endif