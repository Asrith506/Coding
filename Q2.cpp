// find number of strings with given prefix in sorted array of strings

#include<bits/stdc++.h>
using namespace std;

int comparePrefix(string s,string p) {
    int i=0,n=min(p.size(),s.size());
    while(i<n) {
        if(s[i] == p[i]) i++;
        else if(s[i] > p[i]) return 1;
        else return -1;
    }
    return i==p.size() ? 0 : -1;
}

int numStringsWithPrefix(vector<string> &strings,string &prefix) {
    int l=0,r=strings.size()-1,start,end;
    while(l<=r) {
        int mid = (l+r)/2;
        int flag = comparePrefix(strings[mid],prefix);
        if(flag>=0) {
            r=mid-1;
            if(flag == 0) start = mid;
        }
        else if(flag<0) l=mid+1;
    }
    l=0,r=strings.size()-1;
    while(l<=r) {
        int mid = (l+r)/2;
        int flag = comparePrefix(strings[mid],prefix);
        if(flag>0) r=mid-1;
        else if(flag<=0) {
            l=mid+1;
            if(flag == 0) end = mid;
        }
    }
    return end-start+1;
}

int main() {
    vector<string> strings{"a", "ab","acd","b"};
    string prefix = "a";
    cout << numStringsWithPrefix(strings,prefix) << endl;
    return 0;
}

// Trie implementation for follow-up question

#include<bits/stdc++.h>
using namespace std;

struct Node {
    public:
        Node* arr[26];
        bool isWord=false;
        int prefixWords=0;
        bool contains(char c) {
            return arr[c-'a'] != NULL;
        }
        void add(char c, Node *node) {
            arr[c-'a'] = node;
        }
        Node* get(char c) {
            return arr[c-'a'];
        }
        void setIsWord(bool flag) {
            isWord = flag;
        }
        bool getIsWord(bool flag) {
            return isWord;
        }
        void increasePrefixWords() {
            prefixWords++;
        }
        void decreasePrefixWords() {
            prefixWords--;
        }
        int getPrefixWords() {
            return prefixWords;
        }
};

class Trie {
    public:
        Node *root;
        Trie() {
            root = new Node();
        }

        void addString(string word) {
            Node *head = root;
            for(char c: word) {
                if(!head->contains(c)) head->add(c, new Node());
                head = head->get(c);
                head->increasePrefixWords();
            }
            head->setIsWord(true);
        }

        int getNumWordsWithPrefix(string prefix) {
            Node *head = root;
            for(char c: prefix) {
                if(!head->contains(c)) return 0;
                head = head->get(c);
            }
            return head->getPrefixWords();
        }

        void removeWord(string word) {
            Node *head = root;
            Node *prev=root;
            for(char c: word) {
                if(!head->contains(c)) return;
                prev = head;
                head = head->get(c);
                head->decreasePrefixWords();
                if(head->getPrefixWords() == 0) {
                    prev->add(c,NULL);
                    break;
                }
            }
        }
};

int numStringsWithPrefix(vector<string> &strings,string &prefix) {
    Trie *trie = new Trie();
    Node *head = trie->root;
    for(string s: strings) trie->addString(s);
    trie->removeWord("abs");
    return trie->getNumWordsWithPrefix(prefix);
}

int main() {
    vector<string> strings{"a","ab","abc"};
    string prefix = "a";
    cout << "Answer: ";
    cout << numStringsWithPrefix(strings,prefix) << endl;
    return 0;
}