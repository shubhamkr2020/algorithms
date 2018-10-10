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

bool search(string s) {
    Node *temp = root;
    int i;
    rep(i,0,s.length()) {
        int x = s[i]-'a';
        if(temp->child[x] == NULL) return false;
        temp = temp->child[x];
    }
    if(temp->end)
        return true;
    return false;
}

void del(string s) {
    Node *temp = root;
    int i;
    rep(i,0,s.length()) {
        int x = s[i]-'a';
        if(temp->child[x] == NULL) {
            cout<<"string not found"<<endl;
            return;
        }
        temp = temp->child[x];
    }
    if(temp->end) {
        temp->end = false;
        cout<<"deleted"<<endl;
        return;
    }
    cout<<"string not found"<<endl;
}

void dfs(Node *node) {
    auto it = node->child.begin();
    for(it; it!=node->child.end(); it++) {
        cout<<char(it->first+'a')<<" ";
        dfs(it->second);
    }
    // cout<<endl;
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

    dfs(root);
    cout<<endl;

    cout<<root->child.size()<<endl;

    cout<<search("shubh")<<endl;
    cout<<search("goga")<<endl;
    cout<<search("gogo")<<endl;
    cout<<search("harsha")<<endl;
    cout<<search("")<<endl;

    del("harsh");
    del("harsha");
    del("shubh");
    cout<<search("harsh")<<endl;
    insert("harsh");
    cout<<search("harsh")<<endl;
    del("shubham");
    cout<<search("shubham")<<endl;
    cout<<search("shubhangi")<<endl;
    insert("shubham");
    cout<<search("shubham");

    return 0;
}