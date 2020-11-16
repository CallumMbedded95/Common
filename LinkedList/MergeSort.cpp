#ifndef MERGESORT_CPP
#define MERGESORT_CPP
#include "Node.cpp"

template<class T>
class MergeSort {
public:
	MergeSort() {}
	~MergeSort() {}
	static Node<T>* MergeSort_(Node<T>* head) {
		Split(&head);
	}

	static void Split(Node<T>** head) {
		Node<T>* halfwayPt = *head;
		Node<T>* fullPt = *head;
		while (fullPt != nullptr) {			
			fullPt = fullPt->getNext();			
			
			if (fullPt != nullptr) {
				fullPt = fullPt->getNext();
				halfwayPt = halfwayPt->getNext();
			}
		}

		Node<T>* tmpHalf= halfwayPt->getNext();
		halfwayPt->setNext(nullptr);

		printList(tmpHalf);		
		printList(*head);
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