#include<bits/stdc++.h>
using namespace std;

#define rep(i,j,k) for(i=j;i<k;i++)

struct Node {
    bool end;
    map<int, Node*> child;
};
Node *root;

Node* newNode() {
    Node *node = new Node;
    node->end = false;
    return node;
}

void insert(string s) {
    int i;
    Node *temp = root;
    rep(i,0,s.length()) {
        int x = s[i]-'a';
        if(temp->child[x] == NULL) temp->child[x] = newNode();
        temp = temp->child[x];
        if(i == s.length()-1) temp->end = true;
    }
}

void dfs(Node *node, string &s, string str) {
    auto it = node->child.begin();
    if(node->end) cout<<str<<endl;
    str += char('a');
    for(it; it!=node->child.end(); it++) {
        str[str.length()-1] = char(it->first+'a');
        dfs(it->second, s, str);
    }
}

void autocom(string s) {
    Node *temp = root;
    int i;
    rep(i,0,s.length()) {
        int x = s[i] - 'a';
        if(temp->child[x] == NULL) {
            cout<<"No strings";
            return ;
        }
        temp = temp->child[x];
    }
    dfs(temp, s, s);
}

int main() {

    root = newNode();
    
    // Driver Program;
    insert("shubham");
    insert("harsh");
    insert("romit");
    insert("shivam");
    insert("shubhangi");
    insert("rakesh");
    insert("raka");
    insert("subham");
    insert("goga");

    autocom("sh");


    return 0;
}