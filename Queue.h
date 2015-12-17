class Queue {
public:
	Queue();
	~Queue();
	void push(int val);
	int pop();
	void print();
private:
	class Node {
	public:
		Node(int val);
		~Node();
		int data;
		Node* next;
	};
	void push(int val, Node *pos);
	void print(Node *pos);
	Node *head;
	int size;
};