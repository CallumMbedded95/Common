#ifndef MERGESORT_CPP
#define MERGESORT_CPP
#include "Node.cpp"

template<class T>
class MergeSort {
public:
	MergeSort() {}
	~MergeSort() {}
	static void MergeSort_(Node<T>** head) {
		Node<T>* midpoint = nullptr;

		if (*head != nullptr && (*head)->getNext() != nullptr){
			Split(head, &midpoint);

			MergeSort_(head);
			MergeSort_(&midpoint);

			*head = SortedMerge(*head, midpoint);
		}
	}

	static Node<T>* SortedMerge(Node<T>* left, Node<T>* right) {
		Node<T>* result = nullptr;

		// Get first index
		if (left == nullptr)
			return right;
		else if (right == nullptr)
			return left;

		if (left->getData() > right->getData()) {
			result = right;
			result->setNext(SortedMerge(left, right->getNext()));
		}
		else {
			result = left;
			result->setNext(SortedMerge(left->getNext(), right));
		}

		return result;
	}

	static void Split(Node<T>** head, Node<T>** midpoint) {
		Node<T>* halfwayPt = *head;
		Node<T>* fullPt = *head;
		while (fullPt != nullptr) {			
			fullPt = fullPt->getNext();			
			
			if (fullPt != nullptr && fullPt->getNext() != nullptr) {
				fullPt = fullPt->getNext();
				halfwayPt = halfwayPt->getNext();
			}
		}

		if (halfwayPt != nullptr) {
			(*midpoint) = halfwayPt->getNext();
			halfwayPt->setNext(nullptr);
		}
	}

	static void printList(Node<T>* head) {
		Node<T>* tmp = head;

		while (tmp != nullptr) {
			if (tmp != nullptr)
				tmp->printData();
			tmp=tmp->getNext();
		}
		std::cout << std::endl;
	}
};
#endif