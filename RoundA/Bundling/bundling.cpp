#include <bits/stdc++.h>
using namespace std;
struct TrieNode {
    struct TrieNode *children[26];
    bool flag;
    int freq;
};
struct TrieNode *getNode(){
    struct TrieNode *node = new TrieNode;
    node->freq = 1;
    node->flag = false;
    for(int i=0;i<26;i++){
        node->children[i]=NULL;
    }
    return node;
}
void insert(struct TrieNode *root,string word){
    struct TrieNode *ptr = root;
    for(int i=0;i<word.length();i++){
        int index = word[i] - 'A';
        if(!ptr->children[index])
            ptr->children[index] = getNode();
        else
            ptr->children[index]->freq++;
        ptr = ptr->children[index];
    }
}
int getAns(struct TrieNode *root,int k,int count) {
    struct TrieNode *ptr = root;
    for(int i=0;i<26;i++){
        if(ptr->children[i]!=NULL && !ptr->children[i]->flag){
            ptr->children[i]->flag = true;
            count += ptr->children[i]->freq/k;
            count = getAns(ptr->children[i],k,count);
        }
    }
    return count;
}
int main() {
    int t, c = 0;
    cin>>t;
    while(c!=t) {
        c++;
        int n,k;
        cin>>n>>k;
        string words[n];
        struct TrieNode *root = getNode();
        for(int i=0;i<n;i++){
            cin>>words[i];
            insert(root,words[i]);
        }
        cout<<"Case #"<<c<<": "<<getAns(root,k,0)<<endl;   
    }
    return 0;
}
