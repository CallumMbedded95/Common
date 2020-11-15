#include "Node.cpp"
#include "LinkedList.cpp"

int main() {
	LinkedList<int>* ll = new LinkedList<int>(new Node<int>(5));

	ll->addNode(new Node<int>(2));
	ll->addNode(new Node<int>(7));
	ll->addNode(new Node<int>(8));
	ll->addNode(new Node<int>(3));
	ll->addNode(new Node<int>(6));
	ll->addNode(new Node<int>(1));
	ll->addNode(new Node<int>(4));

	// Run selection sort -- fix api structure later
	Node<int>* newHead = ll->SelectionSort(ll->getHead());

	ll->printList(newHead);

	delete(ll);

	return 1;
}