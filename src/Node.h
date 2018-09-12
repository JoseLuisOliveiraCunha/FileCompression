#pragma once
class Node
{
private:
	char key;
	long count;
	Node* n1;
	Node* n2;

public:
	Node(char key, long count, Node* n1, Node* n2);
	~Node();
	char getKey();
	long getCount();
	Node* getN1();
	Node* getN2();
	friend bool operator <(const Node& l, const Node& r);
};

