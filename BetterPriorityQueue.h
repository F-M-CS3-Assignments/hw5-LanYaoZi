#ifndef BETTERPRIORITYQUEUE_H
#define BETTERPRIORITYQUEUE_H


#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct BPQNode {
	int pri = INT_MAX;
	bool visited = false;
	nodekey_t gnode = INVALID_NODE_KEY;
	
	bool operator<(const BPQNode &other) const {
		return pri < other.pri;
	}

	bool operator>(const BPQNode &other) const {
		return pri > other.pri;
	}
	
	bool operator==(const BPQNode &other) const {
		return this->gnode == other.gnode;
	}
};

class BetterPriorityQueue: public priority_queue<BPQNode, vector<BPQNode>, greater<BPQNode>>::priority_queue { 
    public:
        const bool Contains(const BPQNode &node) ;
        bool Update(const BPQNode node);
        const string ToString();
        const string BPQNodeToString(const BPQNode &node);
		const int FindPri(const nodekey_t target);
};

#endif