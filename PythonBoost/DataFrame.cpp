#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <any>
#include <variant>
#include <tuple>

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



    int test=0;
    char t='x';


    void PassColunaInt(boost::python::list& l, std::string nome_coluna);

    // boost::python::list RetunColunaInt(std::string coluna);
    int ReturnColunaInt(std::string nome_coluna);

    std::string ExtractKeys();

};


void DataFrame::PassColunaInt(boost::python::list& l, std::string nome_coluna){
    std::vector<int> w;
    int token;
    for (int i = 0; i < len(l) ; i++){
        token = boost::python::extract<int>(l[i]);
        w.push_back(token);
    }
    coluna_int[nome_coluna] = w;

}

// boost::python::list DataFrame::RetunColunaInt(std::string coluna){
int DataFrame::ReturnColunaInt(std::string nome_coluna){
    // boost::python::list int_vec;
    // std::vector<int> valores;
    int valor;

    valor = coluna_int[nome_coluna][0];
    return valor;
}

// std::string DataFrame::ExtractKeys() {
//     std::string retval;
//     for( auto const& [key, col] : df ) {
//         retval = key;
//   }
//   return retval;
// }


// example of returning a python list
boost::python::list get_chars(){
    std::string word;
    boost::python::list char_vec;
    for (auto c : word){
        char_vec.append(c);
    }
    return char_vec;
}

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(DataFrame)
{
    class_<DataFrame>("DataFrame",init<>())
    .def("PassColunaInt", & DataFrame::PassColunaInt)
    .def("ReturnColunaInt", & DataFrame::ReturnColunaInt)
    .def_readwrite("test", & DataFrame::test)
    .def_readwrite("coluna_int", & DataFrame::coluna_int)
    ;

    // def("pass_ints", pass_ints);

}