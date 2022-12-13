#ifndef __BST_2_H__
#define __BST_2_H__

#include <iostream>
#include <string>

using namespace std;

class BSTNode {

    public:
        string get() const { return data; }

        friend class BST;

    private:
        string data;
        BSTNode *left;
        BSTNode *right;

        BSTNode(string x) {
            data = x;
            left = NULL;
            right = NULL;
        }

        // disallow copy ctor & op=()
        BSTNode(const BSTNode&);
        BSTNode& operator=(const BSTNode&);
};

class BST {

    public:
        BST() : root(NULL) {}
        ~BST();
        BST(const BST&);
        BST& operator=(const BST&);

        void insert(string x);
        void remove(string x);

        typedef BSTNode Node;

        const Node *lookup(string x) const;

        void draw();
		void draw2();

        void traverse_inorder(void (*f)(Node *));
		
		int count() const;
        int height() const;
        const Node *find_min() const;
        const Node *find_max() const;
	
    private:
        Node *root;

        Node *insert(string x, Node *node);
        void remove(string x, Node*& node);
        const Node *lookup(string x, const Node *node) const;

        void remove_all_nodes(Node *node);

        void draw(Node *node, int depth, const char *edge);
		void draw2(Node *node, int depth, const char *edge);

        void traverse_inorder(Node *node, void (*f)(Node *));
		
		int count(const Node *node) const;
        int height(const Node *node) const;
        const Node *find_min(const Node *node) const;
        const Node *find_max(const Node *node) const;

        Node *clone(const Node *) const;
};

#endif /* #ifndef __BST_2_H__ */
