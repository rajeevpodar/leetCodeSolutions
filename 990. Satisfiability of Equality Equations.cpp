//https://leetcode.com/problems/satisfiability-of-equality-equations/
/**
    1. Create a nodes for each char and if the equation is == then make them children of each other.
    2. Update there uid, all different connected components have unique uid associated with them.
    3. For each != equation check if those char belongs to same uid then result is False.
    
**/
class Solution {
    struct Node {
        char _ch;
        list<Node*> _kids;
        int _uid{0};
        Node(char ch):_ch(ch)
        {}
    };
    map<char,Node*> _nodes;
    void printNodes() const {
        for(auto it = _nodes.begin(); it != _nodes.end(); ++it) {
            cout<<it->first<<" : "<<it->second->_uid<<endl;
        }
    }
    void createGraph(const vector<string>& equations) {
        for(auto word: equations) {
            auto it1 = _nodes.find(word[0]);
            auto it2 = _nodes.find(word[3]);
            Node* n1 = (it1 == _nodes.end()) ? new Node(word[0]): it1->second;
            Node* n2 = (it2 == _nodes.end()) ? new Node(word[3]): it2->second;
            // Connect nodes if they has to be ==,
            // else they need to be part of different connected components.
            if ( word[1] != '!') {
                n1->_kids.push_back(n2);
                n2->_kids.push_back(n1);
            }
            _nodes[word[0]] = n1;
            _nodes[word[3]] = n2;
        }
    }
    
    void updateColoringComponents() {
        int uid = 0;
        for(auto it = _nodes.begin(); it != _nodes.end(); ++it) {
            ++uid;
            if ( it->second->_uid > 0 ) {
                continue;
            }
            stack<Node*> myStack;
            myStack.push(it->second);
            while(!myStack.empty()) {
                auto cNode = myStack.top();
                myStack.pop();
                cNode->_uid = uid;
                for(auto kid : cNode->_kids) {
                    if ( kid->_uid == 0) {
                        myStack.push(kid);
                        kid->_uid = uid;
                    }
                }
            }
        }
    }
    
public:
    bool equationsPossible(vector<string>& equations) {
        bool result = true;
        createGraph(equations);
        updateColoringComponents();
        //printNodes();
        // Check for != equations.
        for(auto word: equations) {
            if ( word[1] == '=') {
                continue;
            }
            auto it1 = _nodes.find(word[0]);
            auto it2 = _nodes.find(word[3]);
            if ( it1 != _nodes.end() && it2 != _nodes.end()) {
                if ( it1->second->_uid == it2->second->_uid) {
                    result = false;
                    break;
                }
            }
        }
        return result;    
    }
};
