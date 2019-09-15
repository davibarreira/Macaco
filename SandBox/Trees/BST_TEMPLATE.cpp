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

    void remove_row(int row){
        remove_row(pRoot, row);
    }
    void print() {
        print(pRoot);
        cout << endl;
    }

    set<int> query(int val, string operador){
        set<int> output;
        if (operador == ">" | operador == ">=")
        query_g(pRoot, val, output, operador);

        if (operador == "<" | operador == "<=")
        query_l(pRoot, val, output, operador);

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

    void find_min(Node<Tc> **&p) {

        while((*p)->pChild[0]){
            p = &((*p)->pChild[0]);
        }
    }

    void remove_row(Node<Tc> *p, int row) {
        if (p) {
            remove_row(p->pChild[1], row);
            (p->rows).erase(row);
            remove_row(p->pChild[0], row);
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


int main(){

    BST<int> tree;
    // tree.printRange(10, 20);

    tree.insert_with_row(10, 10);
    tree.insert_with_row(10, 10);
    tree.insert_with_row(80, 80);
    tree.insert_with_row(88, 88);
    tree.insert_with_row(70, 70);
    tree.insert_with_row(75, 75);
    tree.insert_with_row(5, 5);
    tree.insert_with_row(5, 5);
    tree.insert_with_row(4, 4);
    tree.insert_with_row(2, 2);
    tree.insert_with_row(1, 1);
    tree.insert_with_row(3, 3);
    tree.remove(88);
    tree.remove(70);
    tree.print();
    std::set<int> s = tree.get_node(5);
    std::vector<int> output(s.begin(), s.end());
    cout << tree.get_node(5).size()<<endl;
    cout << tree.get_node(1).size()<<endl;
    cout << tree.get_node(80).size()<<endl;
    tree.remove_row(1);

    set<int> rows_query = tree.query(70,"<");
    std::vector<int> out(rows_query.begin(), rows_query.end());

    for (auto i: out)
    {
        cout << "r"<< i << endl;
    }



    return 0;
}
