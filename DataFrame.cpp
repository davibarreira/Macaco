#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <any>
#include <variant>
#include <tuple>
#include "BST.cpp"

#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include <boost/python/extract.hpp>


class DataFrame{
public:
    std::map<std::string, std::vector<int>> coluna_int;
    std::map<std::string,std::vector<double>> coluna_double;
    std::map<std::string,std::vector<std::string>> coluna_string;
    std::map<std::string,BST<int>> int_trees;
    std::map<std::string,BST<double>> double_trees;
    std::map<std::string,BST<std::string>> string_trees;


    void InserirColunaInt(boost::python::list& l, std::string nome_coluna);
    void InserirColunaDouble(boost::python::list& l, std::string nome_coluna);
    void InserirColunaString(boost::python::list& l, std::string nome_coluna);

    boost::python::list GetColunaInt(std::string nome_coluna);
    boost::python::list GetColunaDouble(std::string nome_coluna);
    boost::python::list GetColunaString(std::string nome_coluna);

    void RemoverColunaInt(boost::python::list& l, std::string nome_coluna);
    void RemoverColunaDouble(boost::python::list& l, std::string nome_coluna);
    void RemoverColunaString(boost::python::list& l, std::string nome_coluna);

    boost::python::list GetLinhaInt(boost::python::list & linhas, std::string nome_coluna);
    boost::python::list GetLinhaDouble(boost::python::list & linhas, std::string nome_coluna);
    boost::python::list GetLinhaString(boost::python::list & linhas, std::string nome_coluna);

    void InserirLinhaInt(boost::python::list& l, std::string nome_coluna);
    void InserirLinhaDouble(boost::python::list& l, std::string nome_coluna);
    void InserirLinhaString(boost::python::list& l, std::string nome_coluna);

    void IndexarColunaInt(boost::python::list& l, std::string nome_coluna);
    void IndexarColunaDouble(boost::python::list& l, std::string nome_coluna);
    void IndexarColunaString(boost::python::list& l, std::string nome_coluna);

    boost::python::list GetNodeRowsInt(boost::python::list & nodes, std::string nome_coluna);
    boost::python::list GetNodeRowsDouble(boost::python::list & nodes, std::string nome_coluna);
    boost::python::list GetNodeRowsString(boost::python::list & nodes, std::string nome_coluna);


	void RemoverLinha(boost::python::list& l);

};

void DataFrame::InserirColunaInt(boost::python::list& l, std::string nome_coluna){
    std::vector<int> w;
    int token;
    for (int i = 0; i < len(l) ; i++){
        token = boost::python::extract<int>(l[i]);
        w.push_back(token);
    }
    coluna_int[nome_coluna] = w;
}
void DataFrame::InserirColunaDouble(boost::python::list& l, std::string nome_coluna){
    std::vector<double> w;
    double token;
    for (int i = 0; i < len(l) ; i++){
        token = boost::python::extract<double>(l[i]);
        w.push_back(token);
    }
    coluna_double[nome_coluna] = w;
}
void DataFrame::InserirColunaString(boost::python::list& l, std::string nome_coluna){
    std::vector<std::string> w;
    std::string token;
    for (int i = 0; i < len(l) ; i++){
        token = boost::python::extract<std::string>(l[i]);
        w.push_back(token);
    }
    coluna_string[nome_coluna] = w;
}

boost::python::list DataFrame::GetColunaInt(std::string nome_coluna){
    boost::python::list l;
    for (auto i: coluna_int[nome_coluna])
    {
        l.append(i);
    }
    return l;
}
boost::python::list DataFrame::GetColunaDouble(std::string nome_coluna){
    boost::python::list l;
    for (auto i: coluna_double[nome_coluna])
    {
        l.append(i);
    }
    return l;
}
boost::python::list DataFrame::GetColunaString(std::string nome_coluna){
    boost::python::list l;
    for (auto i: coluna_string[nome_coluna])
    {
        l.append(i);
    }
    return l;
}

boost::python::list DataFrame::GetLinhaInt(boost::python::list & linhas, std::string nome_coluna){
    boost::python::list saida;
    int linha;
    for (int i = 0; i < len(linhas) ; i++){
        linha = boost::python::extract<int>(linhas[i]);
        saida.append(coluna_int[nome_coluna][linha]);
    }
    return saida;
}

boost::python::list DataFrame::GetLinhaDouble(boost::python::list & linhas, std::string nome_coluna){
    boost::python::list saida;
    int linha;
    for (int i = 0; i < len(linhas) ; i++){
        linha = boost::python::extract<int>(linhas[i]);
        saida.append(coluna_double[nome_coluna][linha]);
    }
    return saida;
}

boost::python::list DataFrame::GetLinhaString(boost::python::list & linhas, std::string nome_coluna){
    boost::python::list saida;
    int linha;
    for (int i = 0; i < len(linhas) ; i++){
        linha = boost::python::extract<int>(linhas[i]);
        saida.append(coluna_string[nome_coluna][linha]);
    }
    return saida;
}

void DataFrame::RemoverColunaInt(boost::python::list& l, std::string nome_coluna){
    coluna_int.erase(nome_coluna);
    if (int_trees.count(nome_coluna))
        int_trees.erase(nome_coluna);
}
void DataFrame::RemoverColunaDouble(boost::python::list& l, std::string nome_coluna){
    coluna_double.erase(nome_coluna);
    if (double_trees.count(nome_coluna))
        double_trees.erase(nome_coluna);
}
void DataFrame::RemoverColunaString(boost::python::list& l, std::string nome_coluna){
    coluna_string.erase(nome_coluna);
    if (string_trees.count(nome_coluna))
        string_trees.erase(nome_coluna);
}

void DataFrame::InserirLinhaInt(boost::python::list& l, std::string nome_coluna){
    for (int i = 0; i < len(l) ; i++){
            coluna_int[nome_coluna].push_back(boost::python::extract<int>(l[i]));
            if (int_trees.count(nome_coluna))
                int_trees[nome_coluna].insert_node_with_row(boost::python::extract<int>(l[i]),coluna_int[nome_coluna].size()-1);
       }
}
void DataFrame::InserirLinhaDouble(boost::python::list& l, std::string nome_coluna){
    for (int i = 0; i < len(l) ; i++){
           coluna_double[nome_coluna].push_back(boost::python::extract<double>(l[i]));
            if (double_trees.count(nome_coluna))
                double_trees[nome_coluna].insert_node_with_row(boost::python::extract<double>(l[i]),coluna_double[nome_coluna].size()-1);
       }
}
void DataFrame::InserirLinhaString(boost::python::list& l, std::string nome_coluna){
    for (int i = 0; i < len(l) ; i++){
           coluna_string[nome_coluna].push_back(boost::python::extract<std::string>(l[i]));
            if (string_trees.count(nome_coluna))
                string_trees[nome_coluna].insert_node_with_row(boost::python::extract<std::string>(l[i]),coluna_string[nome_coluna].size()-1);
       }
}

void DataFrame::RemoverLinha(boost::python::list& l){
    for (int i = 0; i < len(l) ; i++){
            for (auto const& [nome_coluna, val] : coluna_int)
            {
                coluna_int[nome_coluna].erase(coluna_int[nome_coluna].begin() + boost::python::extract<int>(l[i]) - i);
            }
            for (auto const& [nome_coluna, val] : coluna_double)
            {
                coluna_double[nome_coluna].erase(coluna_double[nome_coluna].begin() + boost::python::extract<int>(l[i]) - i);
            }
            for (auto const& [nome_coluna, val] : coluna_string)
            {
                coluna_string[nome_coluna].erase(coluna_string[nome_coluna].begin() + boost::python::extract<int>(l[i]) - i);
            }
       }
}

void DataFrame::IndexarColunaInt(boost::python::list & l,std::string nome_coluna){
    BST<int> tree;
    for (int i = 0; i < coluna_int[nome_coluna].size(); ++i)
    {
        tree.insert_node_with_row(coluna_int[nome_coluna][i],i);
    }
    int_trees[nome_coluna] = tree;
}
void DataFrame::IndexarColunaDouble(boost::python::list & l,std::string nome_coluna){
    BST<double> tree;
    for (int i = 0; i < coluna_double[nome_coluna].size(); ++i)
    {
        tree.insert_node_with_row(coluna_double[nome_coluna][i],i);
    }
    double_trees[nome_coluna] = tree;
}
void DataFrame::IndexarColunaString(boost::python::list & l,std::string nome_coluna){
    BST<std::string> tree;
    for (int i = 0; i < coluna_string[nome_coluna].size(); ++i)
    {
        tree.insert_node_with_row(coluna_string[nome_coluna][i],i);
    }
    string_trees[nome_coluna] = tree;
}

boost::python::list DataFrame::GetNodeRowsInt(boost::python::list & nodes, std::string nome_coluna){
    std::vector<int> output;
    std::set<int> s;
    int w;
    boost::python::list saida;

    for (int i = 0; i < len(nodes) ; i++){
        w = boost::python::extract<int>(nodes[i]);
        s = int_trees[nome_coluna].get_node_rows(w);
        output.insert(output.end(), s.begin(), s.end());
    }
    for (int i = 0; i < output.size() ; i++)
    {
        saida.append(output[i]);
    }
    return saida;
}

boost::python::list DataFrame::GetNodeRowsDouble(boost::python::list & nodes, std::string nome_coluna){
    std::vector<int> output;
    std::set<int> s;
    double w;
    boost::python::list saida;

    for (int i = 0; i < len(nodes) ; i++){
        w = boost::python::extract<double>(nodes[i]);
        s = double_trees[nome_coluna].get_node_rows(w);
        output.insert(output.end(), s.begin(), s.end());
    }
    for (int i = 0; i < output.size() ; i++)
    {
        saida.append(output[i]);
    }
    return saida;
}
boost::python::list DataFrame::GetNodeRowsString(boost::python::list & nodes, std::string nome_coluna){
    std::vector<int> output;
    std::set<int> s;
    std::string w;
    boost::python::list saida;

    for (int i = 0; i < len(nodes) ; i++){
        w = boost::python::extract<std::string>(nodes[i]);
        s = string_trees[nome_coluna].get_node_rows(w);
        output.insert(output.end(), s.begin(), s.end());
    }
    for (int i = 0; i < output.size() ; i++)
    {
        saida.append(output[i]);
    }
    return saida;
}


#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(DataFrame)
{
    class_<DataFrame>("DataFrame",init<>())
    .def("InserirColunaInt", & DataFrame::InserirColunaInt)
    .def("InserirColunaDouble", & DataFrame::InserirColunaDouble)
    .def("InserirColunaString", & DataFrame::InserirColunaString)
    .def("GetColunaInt", & DataFrame::GetColunaInt)
    .def("GetColunaDouble", & DataFrame::GetColunaDouble)
    .def("GetColunaString", & DataFrame::GetColunaString)
    .def("RemoverColunaInt", & DataFrame::RemoverColunaInt)
    .def("RemoverColunaDouble", & DataFrame::RemoverColunaDouble)
    .def("RemoverColunaString", & DataFrame::RemoverColunaString)
    .def("RemoverLinha", & DataFrame::RemoverLinha)
    .def("GetLinhaInt", & DataFrame::GetLinhaInt)
    .def("GetLinhaDouble", & DataFrame::GetLinhaDouble)
    .def("GetLinhaString", & DataFrame::GetLinhaString)
    .def("InserirLinhaInt", & DataFrame::InserirLinhaInt)
    .def("InserirLinhaDouble", & DataFrame::InserirLinhaDouble)
    .def("InserirLinhaString", & DataFrame::InserirLinhaString)
    .def("IndexarColunaInt", & DataFrame::IndexarColunaInt)
    .def("IndexarColunaDouble", & DataFrame::IndexarColunaDouble)
    .def("IndexarColunaString", & DataFrame::IndexarColunaString)
    .def("GetNodeRowsInt", & DataFrame::GetNodeRowsInt)
    .def("GetNodeRowsDouble", & DataFrame::GetNodeRowsDouble)
    .def("GetNodeRowsString", & DataFrame::GetNodeRowsString)
    .def_readwrite("coluna_int", & DataFrame::coluna_int)
    ;

    // def("pass_ints", pass_ints);

}