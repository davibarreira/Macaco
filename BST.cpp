#include <iostream>
#include <iomanip>
#include <vector>
#include <initializer_list>
#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include <boost/python/extract.hpp>

#include <string>
#include <set>


using namespace std;

template<typename T>
struct Node {
    T data;
    std::set<int> rows;

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

    bool find_node(Tc x) {
        Node<Tc> **p;
        return find(x, p);
    }

    std::set<int> get_node_rows(Tc x) {
        Node<Tc> **p;
        find(x, p);
        return (*p)->rows;
    }

    void insert_node_with_row(Tc x, int row) {
        Node<Tc> **p;
        if (!find(x, p)) {
            *p = new Node<Tc>(x);
        }
        (*p)->rows.insert(row);
    }

    void insert_node(Tc x) {
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

    void remove_row(int row){
        remove_row(pRoot, row);
    }

    void print() {
        print(pRoot);
        cout << endl;
    }

    set<int> query(Tc val, string operador){
        set<int> output;
        if (operador == ">" | operador == ">=")
        query_g(pRoot, val, output, operador);

        if (operador == "<" | operador == "<=")
        query_l(pRoot, val, output, operador);

        if (operador == "==")
        output = get_node_rows(val);

        return output;
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
    
    void remove_row(Node<Tc> *p, int row) {
        if (p) {
            remove_row(p->pChild[1], row);
            (p->rows).erase(row);
            remove_row(p->pChild[0], row);
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

    void query_g(Node<Tc> *root, Tc value, set<int>& output, string op)
    {
        if ( !root )
            return ;

        if ( value < root->data )
            query_g(root->pChild[0], value, output, op);

        if (op == ">=")
        if ( value <= root->data){
            output.insert((root->rows).begin(),(root->rows).end());
        }

        if (op == ">")
            if ( value < root->data){
                output.insert((root->rows).begin(),(root->rows).end());
            }

            query_g(root->pChild[1], value, output, op);
    }

    void query_l(Node<Tc> *root, Tc value, set<int>& output, string op)
    {
        if ( !root )
            return ;

        query_l(root->pChild[0], value, output, op);

        if (op == "<=")
            if ( value >= root->data){
                output.insert((root->rows).begin(),(root->rows).end());
            }

        if (op == "<")
            if ( value > root->data){
                output.insert((root->rows).begin(),(root->rows).end());
            }

        if ( value > root->data )
        query_l(root->pChild[1], value, output, op);
    }
};