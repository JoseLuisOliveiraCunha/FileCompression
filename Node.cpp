#include "Node.h"


Node::Node(char key, long count, Node* n1, Node* n2)
{
	this->key = key;
	this->count = count;
	this->n1 = n1;
	this->n2 = n2;
}

Node::~Node() = default;

char Node::getKey()
{
	return key;
}

long Node::getCount()
{
	return count;
}

Node* Node::getN1()
{
	return n1;
}

Node* Node::getN2()
{
	return n2;
}

bool operator <(const Node& lhs, const Node& rhs)
{
	return lhs.count > rhs.count;
}
