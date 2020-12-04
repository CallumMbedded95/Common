#ifndef HASHMAP_CPP
#define HASHMAP_CPP
#include "HashElement.cpp"
#include <cstddef>
#include <iostream>

template<typename K, typename V, size_t Len>
class HashMap {
public:
	HashMap() : 
		HashTable() { // HashTable() initialises all array values to nullptr 
		
	}
	~HashMap() {}

	bool get(const K &key, V &value) {
		unsigned long hashValue = hashFunc(key);
		HashElement<K, V>* tmp = HashTable[hashValue];

		// Loop through
		while (tmp != nullptr ) {
			if (tmp->getKey() == key) {
				break;
			}

			tmp = tmp->getNext();
		}

		if (tmp != nullptr) {
			value = tmp->getValue();
			return true;
		}
		else {
			return false;
		}
	}
	
	void put(const K &key, const V &value) {
		unsigned long hashValue = hashFunc(key);
		//std::cout << hashValue << std::endl;
		HashElement<K, V>* KVPair = new HashElement<K, V>(key, value);
		HashElement<K, V>* tmp = HashTable[hashValue];
		HashElement<K, V>* tmpPrev = nullptr;

		if (tmp == nullptr) {
			HashTable[hashValue] = KVPair;
			return;
		}

		//Loop through
		while (tmp != nullptr) {
			tmpPrev = tmp;
			tmp = tmp->getNext();
		}

		tmpPrev->setNext(KVPair);	
	}

	long unsigned hashFunc(const K &key) {
		return static_cast<unsigned long>(key % Len);
	}
private:
	HashElement<K, V>* HashTable[Len]; 
	//F hashF;
};
#endif