#include <iostream>
#include <iomanip>
#include <vector>
#include <initializer_list>

#include <set>
#include <string>


using namespace std;

template<typename T>
struct Node {
    T data;
    set<int> rows;

    Node *pChild[2];
    Node(T x):data(x) {
        pChild[0] = pChild[1] = nullptr;
    }
};

template<typename Tc>
class BST {


protected:
    Node<Tc> *pRoot;

public:


    BST():pRoot(nullptr) {}

    bool find(Tc x) {
        Node<Tc> **p;
        return find(x, p);
    }

    set<int> get_node(Tc x) {
        Node<Tc> **p;
        find(x, p);
        return (*p)->rows;
    }

    void insert_with_row(Tc x, int row) {
        Node<Tc> **p;
        if (!find(x, p)) {
            *p = new Node<Tc>(x);
        }
        (*p)->rows.insert(row);
    }

    void insert(Tc x) {
        Node<Tc> **p;
        if (!find(x, p)) {
            *p = new Node<Tc>(x);
        }
    }
    void remove(Tc x) {
        Node<Tc> **p;
        if(find(x, p))
            remove(*p);
    }

    void print() {
        print(pRoot);
        cout << endl;
    }

private:
    bool find(Tc x, Node<Tc> **&p) {
        p = &pRoot;
        while(*p) {
            if ((*p)->data==x) return true;

            p = &((*p)->pChild[(*p)->data < x]);
        }

        return false;
    }

    void remove(Node<Tc> *&p) {
        if (!p->pChild[0] || !p->pChild[1])
            p = p->pChild[p->pChild[1]!=nullptr];

        else {
            Node<Tc> **succesor = &(p->pChild[1]);
            find_min(succesor);
            p->data = (*succesor)->data;
            remove(*succesor);
        }
    }

    void find_min(Node<Tc> **&p) {

        while((*p)->pChild[0]){
            p = &((*p)->pChild[0]);
        }
    }

    void print(Node<Tc> *p, int indent=0) {
        if (p) {
            print(p->pChild[1], indent+6);
            cout << setw(indent) << ' ';
            cout<< p->data <<endl;
            print(p->pChild[0], indent+6);
        }
    }
};


int main(){

    BST<int> tree;

    tree.insert(10);
    tree.insert(10);
    tree.insert(1);
    tree.insert(8);
    tree.insert(80);
    tree.insert_with_row(5, 1);
    tree.insert_with_row(5, 1);
    tree.insert_with_row(5, 10);
    tree.insert_with_row(5, 2);
    tree.insert_with_row(1, 1);
    tree.remove(10);
    tree.print();
    std::set<int> s = tree.get_node(5);
    std::vector<int> output(s.begin(), s.end());
    cout << tree.get_node(5).size()<<endl;
    cout << tree.get_node(1).size()<<endl;
    cout << tree.get_node(80).size()<<endl;

    for (auto i: output)
    {
        cout << i << endl;
    }

    return 0;
}
