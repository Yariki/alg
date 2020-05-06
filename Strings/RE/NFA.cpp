//
// Created by ADMIN on 05/05/2020.
//

#include "NFA.h"
#include "..\..\DS\Graph\DepthSearch.h"

NFA::NFA(string regex):re(regex) {
    buildNFAGraph();
}

NFA::~NFA() {
 delete G;
}

bool NFA::isMatch(string txt) {
    vector<int> pc;
    auto dfs = new DepthSearch(G,0);
    for (int v = 0; v < G->getV(); ++v) {
        if(dfs->marked(v))
            pc.push_back(v);
    }

    for (int i = 0; i < txt.size(); ++i) {
        vector<int> match;
        for(auto v : pc){
            if(v < M)
                if(re[v] == txt[i] || re[v] == '.')
                    match.push_back(v+1);
        }
        pc.clear();
        delete dfs;
        dfs = new DepthSearch(G,match);
        for (auto v = 0; v < G->getV(); ++v) {
            if(dfs->marked(v))
                pc.push_back(v);
        }
    }
    for(auto i : pc) if (i == M ) return true;
    return false;
}



void NFA::buildNFAGraph() {
    M = re.size();
    stack<int> ops;
    G = new Digraph();
    G->init(M + 1);

    for (int i = 0; i < M; ++i) {
        auto lp = i;

        if(re[i] == '(' || re[i] == '|')
            ops.push(i);
        else if(re[i] == ')'){
            auto orr = ops.top(); ops.pop();
            if(re[orr] == '|'){
                lp = ops.top();ops.pop();
                G->addEdge(lp,orr+1);
                G->addEdge(orr, i);
            }
            else lp = orr;
        }
        if(i < M - 1 && re[i + 1] == '*'){
            G->addEdge(lp,i + 1);
            G->addEdge(i + 1, lp);
        }
        if(re[i] == '(' || re[i] == '*' || re[i] == ')'){
            G->addEdge(i, i + 1);
        }
    }
}
