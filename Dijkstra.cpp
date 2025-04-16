#include "Graph.h"
#include "BetterPriorityQueue.h"
#include "Dijkstra.h"

#include <iostream>
#include <cassert>

using namespace std;

int dijkstra(nodekey_t start, nodekey_t end, const Graph *g){
    BetterPriorityQueue BPQNodes;
    // for(const auto& i:g->GetNodes()){
    //     BPQNode tem;
    //     tem.gnode=i;
    //     BPQNodes.push(tem);
    // }

    BPQNode cur;
    cur.gnode=start;
    cur.pri=0;
    BPQNodes.push(cur);
    vector<nodekey_t> nodes_stack;
    nodes_stack.push_back(start);
    while(!nodes_stack.empty()){
        BPQNode tem;
        tem.gnode=nodes_stack.back();
        nodes_stack.pop_back();
        tem.pri=BPQNodes.FindPri(tem.gnode);
        for(const auto& i:g->GetOutwardEdgesFrom(tem.gnode)){
            BPQNode tem2;
            tem2.gnode=i->to;
            tem2.pri=i->weight+tem.pri;
            if(!BPQNodes.Contains(tem2)){
                //cout<<"add:"<<tem2.gnode<<":"<<tem2.pri<<", W:"<<i->weight<<"+"<<tem.gnode<<":"<<tem.pri<<endl;
                BPQNodes.push(tem2);
                nodes_stack.push_back(i->to);
            }else{
                //cout<<"update:"<<tem2.gnode<<":"<<tem2.pri<<", W:"<<i->weight<<"+"<<tem.gnode<<":"<<tem.pri<<endl;
                if(BPQNodes.Update(tem2)){
                    //cout<<"after_update:"<<BPQNodes.FindPri(tem2.gnode)<<endl;
                    nodes_stack.push_back(i->to);
                }
            }
        }
    }
    return BPQNodes.FindPri(end);
}
