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

    void query(int val){
        set<int> output;
        query(pRoot, val, output);
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


    void query(Node<Tc> *root, Tc value, set<int>& output)
    {
        if ( !root ){
            return ;
        }

        if ( value < root->data )
            query(root->pChild[0], value, output);

        // Condicao
        // if ( k1 <= root->data && k2 >= root->data )
        //     cout<<root->data<<" ";

        if ( value <= root->data)
            cout<<root->data<<" ";

//        if ( value > root->data )
            query(root->pChild[1], value, output);
    }
    // set<int> query(Node<Tc> *root, Tc k1, Tc k2)  
    // {  
    //     set<int> output;
    //     if ( !root ){
    //         output.insert((root->rows).begin(), (root->rows).end());
    //         return output;  
    //     }

    //     if ( k1 < root->data )  
    //         query(root->pChild[0], k1, k2);  

    //     // Condicao 
    //     // if ( k1 <= root->data && k2 >= root->data )  
    //     //     cout<<root->data<<" ";  

    //     if ( k1 <= root->data)  
    //         cout<<root->data<<" ";  

    //     if ( k2 > root->data )  
    //         query(root->pChild[1], k1, k2);  
    // }
};


int main(){

    BST<int> tree;
    // tree.printRange(10, 20);

    tree.insert(10);
    tree.insert(10);
    tree.insert(1);
    tree.insert(8);
    tree.insert(80);
    tree.insert(88);
    tree.insert(70);
    tree.insert(75);
    tree.insert_with_row(5, 1);
    tree.insert_with_row(5, 1);
    tree.insert_with_row(5, 10);
    tree.insert_with_row(5, 2);
    tree.insert_with_row(4, 2);
    tree.insert_with_row(2, 2);
    tree.insert_with_row(1, 1);
    tree.remove(10);
    tree.print();
    std::set<int> s = tree.get_node(5);
    std::vector<int> output(s.begin(), s.end());
    cout << tree.get_node(5).size()<<endl;
    cout << tree.get_node(1).size()<<endl;
    cout << tree.get_node(80).size()<<endl;

    set<int> rows_query;
    tree.query(70);


    return 0;
}
