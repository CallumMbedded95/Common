#include "Node.cpp"
#include "LinkedList.cpp"
#include "SelectionSort.cpp"
#include "MergeSort.cpp"

int main() {
	/*
	// Sort test block :: Start
	*/
	LinkedList<int>* ll = new LinkedList<int>(new Node<int>(5));

	ll->addNode(new Node<int>(2));
	ll->addNode(new Node<int>(7));
	ll->addNode(new Node<int>(8));
	ll->addNode(new Node<int>(1));
	ll->addNode(new Node<int>(3));
	ll->addNode(new Node<int>(6));
	ll->addNode(new Node<int>(1));
	ll->addNode(new Node<int>(4));

	// Selection sort
	//Node<int>* newHead = SelectionSort<int>::SelectionSort_(ll->getHead());

	// Merge sort
	Node<int>* headThing = ll->getHead();
	MergeSort<int>::MergeSort_(&headThing);

	ll->printList(headThing);

	delete(ll);
	// End Sort test block :: End

	return 1;
}