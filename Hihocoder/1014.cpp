#include <iostream>
#include <cstring>

using namespace std;
#define MAX 105

struct tree {
    char val;
    int cnt;
    tree *next[26];
    tree() {
        cnt = 0;
        for (int i=0; i<26; i++)
            next[i] = NULL;
    }
};

tree root;

void insertWord(char *str) {
    tree* head = &root;
    for (int i=0; i<strlen(str); i++) {
        int index = str[i]-'a';
        if (head->next[index]==NULL) {
            tree *node = new tree;
            node->val = str[i];
            head->next[index] = node;
        }
        head = head->next[index];
        head->cnt++;
    }
}

int getMax(char *str) {
    tree *head = &root;
    for (int i=0; i<strlen(str); i++) {
        int index = str[i]-'a';
        if (head->next[index]==NULL)    return 0;
        else
            head = head->next[index];
    }
    return head->cnt;
}

int main() {
    int n, m;
    cin >> n;
    char str[MAX];
    for (int i=0; i<n; i++) {
        cin >> str;
        insertWord(str);
    }
    
    cin >> m;
    while (m--) {
        cin >> str;
        cout << getMax(str) << endl;
    }
    return 0;
}