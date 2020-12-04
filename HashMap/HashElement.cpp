#ifndef HASHELEMENT_CPP
#define HASHELEMENT_CPP

template<typename K, typename V>
class HashElement {
public:
	HashElement(const K &key_, const V &value_) : key(key_), value(value_) {

	}

	~HashElement() {}

	const inline V  getValue() {
		return value;
	}

	void setValue(V value_) {
		this->value = value_;
	}

	void setNext(HashElement* inputElement) {
		this->next = inputElement;
	}

	K getKey() {
		return this->key;
	}

	HashElement<K, V>* getNext() {
		return next;
	}
private:
	K key;
	V value;
	HashElement *next = nullptr;
};
#endif