#include "Graph.h"
#include "BetterPriorityQueue.h"

const bool BetterPriorityQueue::Contains(const BPQNode &node){
    //how to using auto:https://learn.microsoft.com/en-us/cpp/cpp/auto-cpp?view=msvc-170
    for(const auto& i:this->c){
        if(i.gnode==node.gnode){
            return true;
        }
    }
    return false;
}

bool BetterPriorityQueue::Update(const BPQNode node){
    for(auto& i:this->c){
        if(i.gnode==node.gnode && i.pri>node.pri){
            i.pri=node.pri;
            return true;
        }
    }
    return false;
}

//[(1, pri: 0), (2, pri: 1), (6, pri: 0), (4, pri: 3), (5, pri: 4), (3, pri: 2)]
const string BetterPriorityQueue::ToString(){
    string str="[";
    for (size_t i = 0; i < this->c.size(); i++) {
        if (i != 0) str += ", ";
        str += BPQNodeToString(this->c[i]);
    }
    str+="]";
    return str;
}

const string BetterPriorityQueue::BPQNodeToString(const BPQNode &node){
    return "(" + to_string(node.gnode) + ", pri:" + to_string(node.pri) + ")";
}

const int BetterPriorityQueue::FindPri(const nodekey_t target){
    for(const auto& i:this->c){
        if(i.gnode==target){
            return i.pri;
        }
    }
    throw exception();//error
}