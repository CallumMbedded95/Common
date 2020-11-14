#include "Node.cpp"
#include "LinkedList.cpp"

int main() {
	LinkedList<int>* ll = new LinkedList<int>(new Node<int>(5));

	ll->addNode(new Node<int>(7));
	ll->addNode(new Node<int>(2));
	ll->printList();
	ll->removeNode();
	ll->printList();

	delete(ll);

	return 1;
}