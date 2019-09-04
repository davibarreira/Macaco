#include <iostream>
#include <iomanip>
#include <vector>
#include <initializer_list>
#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include <boost/python/extract.hpp>


#include <string>


using namespace std;

template<typename T>
struct Node {
    T data;
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

    std::string greet(){
        return "Hello";
    }

    bool find(Tc x) {
        Node<Tc> **p;
        return find(x, p);
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

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(BST)
{
    class_<BST<int>>("BST",init<>())
    .def("greet",&BST<int>::greet)
    .def("insert",&BST<int>::insert)
    ;

}
