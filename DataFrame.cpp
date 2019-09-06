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


struct coluna{
    char tipo;
    void * pcoluna;

};

class DataFrame{
public:
    std::map<std::string, std::vector<int>> coluna_int;
    std::map<std::string,std::vector<double>> coluna_double;
    std::map<std::string,std::vector<std::string>> coluna_string;

    std::string check = "nada";

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
}
void DataFrame::RemoverColunaDouble(boost::python::list& l, std::string nome_coluna){
    coluna_double.erase(nome_coluna);
}
void DataFrame::RemoverColunaString(boost::python::list& l, std::string nome_coluna){
    coluna_string.erase(nome_coluna);
}

void DataFrame::InserirLinhaInt(boost::python::list& l, std::string nome_coluna){
    for (int i = 0; i < len(l) ; i++){
           coluna_int[nome_coluna].push_back(boost::python::extract<int>(l[i]));
       }
}
void DataFrame::InserirLinhaDouble(boost::python::list& l, std::string nome_coluna){
    for (int i = 0; i < len(l) ; i++){
           coluna_double[nome_coluna].push_back(boost::python::extract<double>(l[i]));
       }
}
void DataFrame::InserirLinhaString(boost::python::list& l, std::string nome_coluna){
    for (int i = 0; i < len(l) ; i++){
           coluna_string[nome_coluna].push_back(boost::python::extract<std::string>(l[i]));
       }
}


#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(DataFrame)
{
    class_<DataFrame>("DataFrame",init<>())
    .def_readwrite("check", & DataFrame::check)
    .def("InserirColunaInt", & DataFrame::InserirColunaInt)
    .def("InserirColunaDouble", & DataFrame::InserirColunaDouble)
    .def("InserirColunaString", & DataFrame::InserirColunaString)
    .def("GetColunaInt", & DataFrame::GetColunaInt)
    .def("GetColunaDouble", & DataFrame::GetColunaDouble)
    .def("GetColunaString", & DataFrame::GetColunaString)
    .def("RemoverColunaInt", & DataFrame::RemoverColunaInt)
    .def("RemoverColunaDouble", & DataFrame::RemoverColunaDouble)
    .def("RemoverColunaString", & DataFrame::RemoverColunaString)
    .def("GetLinhaInt", & DataFrame::GetLinhaInt)
    .def("GetLinhaDouble", & DataFrame::GetLinhaDouble)
    .def("GetLinhaString", & DataFrame::GetLinhaString)
    .def("InserirLinhaInt", & DataFrame::InserirLinhaInt)
    .def("InserirLinhaDouble", & DataFrame::InserirLinhaDouble)
    .def("InserirLinhaString", & DataFrame::InserirLinhaString)
    .def_readwrite("coluna_int", & DataFrame::coluna_int)
    ;

    // def("pass_ints", pass_ints);

}