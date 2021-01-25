#include <iostream>
#include <cstdlib>
#include <typeinfo>

template<typename Key,typename Info>
class DLR {
private:

	int length = 0;

protected:

	struct Node {
		Key key;
		Info info;
		Node * next;
		Node * prev;
	};

	//Node pointer providing access to DLR
	Node * door = nullptr;

public:

	/*
			MEMBER METHODS:

	DLR();
	DLR(int);
	DLR(const DLR<int, int> &)
	~DLR();
	DLR<Key,Info> &operator=(const DLR<Key,Info> &);

			METHODS:

	void pushNext(Key, Info);
	void pushPrev(Key, Info);
	void createRandomNodes(int);
	void displayNode(int)
	void displayRing();
	void clearRing();
	void deleteByKey();

	bool checkKeyInfoType();
	bool containsKey(Key);
	bool isEmpty();

			OVERLOADED OPERATORS:

	DLR<Key, Info> &operator+=(const DLR<Key, Info> &);
	bool operator==(const DLR<Key, Info> &);
	bool operator!=(const DLR<Key,Info> &);
	*/


	//default constructor
	DLR() {};


	//creates DLR using createRandomNodes(number)
	DLR(int number) {

		if (this->checkKeyInfoType()) {
			this->createRandomNodes(number);
		}
		else {
			std::cout << "\nThis constructor allows only Key, Info = int";
		}
	}


	//copy constructor
	DLR(const DLR<int, int> &givenRing) {
		*this = givenRing;
	}


	//destructor using clearRing()
	~DLR() {
		this->clearRing();
	}


	DLR<Key, Info> &operator=(const DLR<Key, Info> &givenRing) {

        if(*this == givenRing) {
            return *this;
        }

		this->clearRing();

		if (givenRing.length == 0) {
			return *this;
		}

		Node * temp = givenRing.door->prev;

		for (int i = 0; i < givenRing.length; i++) {
			this->pushNext(temp->key, temp->info);
			temp = temp->prev;
		}

		return *this;
	}


	//new Node is 'door' and its 'next' pointer points to previous 'door'
	void pushNext(const Key & myKey, const Info & myInfo) {

		Node * temp = new Node;

		temp->key = myKey;
		temp->info = myInfo;

		if (this->isEmpty()) {
			temp->next = temp;
			temp->prev = temp;
			this->door = temp;
			this->length++;
			return;
		}
		else {
			Node * last = this->door->prev;

			this->door->prev = temp;
			temp->next = this->door;
			last->next = temp;
			temp->prev = last;

			this->door = temp;
			this->length++;
		}
	}


	//new Node is 'door' and its 'prev' pointer points to previous 'door'
	void pushPrev(const Key & myKey, const Info & myInfo) {

		Node * temp = new Node;

		temp->key = myKey;
		temp->info = myInfo;

		if (this->isEmpty()) {
			temp->next = temp;
			temp->prev = temp;
			this->door = temp;
			this->length++;
			return;
		}
		else {
			Node * second = this->door->next;

			this->door->next = temp;
			temp->prev = this->door;
			temp->next = second;
			second->prev = temp;

			this->door = temp;
			this->length++;
		}
	}


	//creates randomized Nodes using pushNext()
	void createRandomNodes(int number) {

		if (!this->checkKeyInfoType()) {
			std::cout << "\nOnly int,int types are appropriate (createRandomNodes)";
			return;
		}
		else if (number < 0) {
			std::cout << "\nWrong parameter passed (createRandomNodes)";
			return;
		}
		else {
			for (int i = 0; i < number; i++) {
				int randomKey = rand() % 100 + 1;
				int randomInfo = rand() % 100 + 1;
				this->pushNext(randomKey, randomInfo);
			}
		}
	}


	//displays Node on given position (also takes in negative integers)
	void displayNode(int position) {

		if (this->length == 0) {
			std::cout << "\nThe ring is empty";
			return;
		}

		Node * temp = this->door;

		if (position < 0) {
			for (int i = 0; i > position; i--) {
				temp = temp->prev;
			}
		}
		else if (position > 0) {
			for (int i = 0; i < position; i++) {
				temp = temp->next;
			}
		}

		std::cout << "\n(" << position << ")" << " Key: " << temp->key << "\tInfo: " << temp->info;
	}


	//displays whole ring
	void displayRing() {

		if (this->isEmpty()) {
			std::cout << "\nThe ring is empty";
			return;
		}

		Node * temp = this->door;

		for (int i = 0; i < this->length; i++) {
			std::cout << "\n(" << i << ") Key: " << temp->key << "\tInfo: " << temp->info;
			temp = temp->next;
		}
	}


	//clears ring
	void clearRing() {

		Node * temp = this->door;

		while (!this->isEmpty()) {
			this->door = this->door->next;
			delete temp;
			temp = this->door;
			this->length--;
		}

		this->door = nullptr;
	}


	//deletes nodes with given key
	void deleteByKey(Key myKey) {
		
		if (this->isEmpty()) {
			return;
		}

		DLR<Key, Info> product;
		Node * temp = this->door;

		do {
			if (temp->key != myKey) {
				product.pushNext(temp->key, temp->info);
			}

			temp = temp->prev;
		}
		while (temp != this->door);

		*this = product;
	}


	//ckecks if Key,Info are of type int (used in createRandomNodes())
	bool checkKeyInfoType() {
		if (typeid(Key) == typeid(int) && typeid(Info) == typeid(int)) {
			return true;
		}
		return false;
	}


	//checks if Key is already used
	bool containsKey(Key myKey) {

		if (this->isEmpty()) {
			return false;
		}

		Node* temp = this->door;

		do {
			if (temp->key == myKey) {
				return true;
			}
			temp = temp->next;
		} while (temp->next != this->door);

		return false;
	}


	//checks if the ring is empty
	bool isEmpty() {
		return this->length == 0 ? true : false;
	}


	DLR<Key, Info> &operator+=(const DLR<Key, Info> &givenRing) {

		if (givenRing.length == 0) {
			return *this;
		}

		Node * temp = givenRing.door;

		for (int i = 0; i < givenRing.length; i++) {
			this->pushNext(temp->key, temp->info);
			temp = temp->next;
		}

		return *this;
	}


	bool operator==(const DLR<Key, Info> &givenRing) {

		if (this->length != givenRing.length) {
			return false;
		}
		else if (this->length == 0 && givenRing.length == 0) {
			return true;
		}

		Node * lhs = this->door;
		Node * rhs = givenRing.door;

		do {
			if (lhs->key != rhs->key || lhs->info != lhs->info) {
				return false;
			}
			lhs = lhs->next;
			rhs = rhs->next;
		} while (lhs != this->door);

		return true;
	}


	bool operator!=(const DLR<Key, Info> &givenRing) {
		return !(*this == givenRing);
	}


	/*
	----------------------------------
	---------ITERATOR CLASS-----------
	----------------------------------
	*/


	class Iterator
	{
	private:

		friend class DLR;
		mutable Node * iter;

	public:

		Iterator(Node * node) : iter(node) {}

		Iterator(): iter(nullptr) {}

		Iterator(const Iterator &source) : iter(source.iter) {}

		~Iterator() = default;


		Iterator& operator=(const Iterator &rhs) {
			this->iter = rhs.iter;
			return *this;
		}


		Iterator& operator++() const {
			this->iter = this->iter->next;
			return *this;
		}


		Iterator& operator--() const {
			this->iter = this->iter->prev;
			return *this;
		}


		Iterator operator++(int num) const {
			Iterator temp(*this);
			this->iter = this->iter->next;
			return temp;
		}


		Iterator operator--(int) const {
			Iterator temp(*this);
			this->iter = this->iter->prev;
			return temp;
		}


		Iterator operator+(int rhs) const {

			Iterator temp(*this);

			if (rhs < 0) {
				for (int i = 0; i < rhs; i++) {
					temp.iter = temp.iter->prev;
				}
			}
			else {
				for (int i = 0; i < rhs; i++) {
					temp.iter = temp.iter->next;
				}
			}

			return temp;
		}


		Iterator operator-(int rhs) const {

			Iterator temp(*this);

			if (rhs >= 0) {
				for (int i = 0; i < rhs; i++) {
					temp.iter = temp.iter->prev;
				}
			}
			else {
				for (int i = 0; i < rhs; i++) {
					temp.iter = temp.iter->next;
				}
			}

			return temp;
		}


		bool operator==(const Iterator &rhs) const {
			return this->iter == rhs.iter;
		}


		bool operator!=(const Iterator &rhs) const {
			return this->iter != rhs.iter;
		}


		Key& getKey() {
			return this->iter->key;
		}


		Info& getInfo() {
			return this->iter->info;
		}


		const Key& getKey() const {
			return this->iter->key;
		}


		const Info& getInfo() const {
			return this->iter->info;
		}
	};

	//constructs iterator pointing to 'door'
	Iterator begin() const {
		return Iterator(door);
	}
};
