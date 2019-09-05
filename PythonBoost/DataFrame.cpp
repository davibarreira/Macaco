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

    std::map<std::string, coluna> df;

    int test=0;

    template <typename T>
    void InserirColuna(char tipo, std::vector<T> valores, std::string nome);

    void AddRow(std::vector<std::variant<int,double, std::string>> row);

    void PrintColunaCpp(std::string nome_coluna);

    void PassColunaInt(std::string tipo, boost::python::list& l, std::string nome);

    // boost::python::list RetunColunaInt(std::string coluna);
    int ReturnColunaInt(std::string nome);

    std::string ExtractKeys();

};

template <typename T>
void DataFrame::InserirColuna(char tipo, std::vector<T> valores, std::string nome){
    coluna coluna1;

    coluna1.tipo = tipo;
    coluna1.pcoluna = &valores;
    df[nome] = coluna1;
    test = (*static_cast<std::vector<int> *>(df[nome].pcoluna))[0];

}

void DataFrame::AddRow(std::vector<std::variant<int,double, std::string>> row){
    int i = 0;
    for( auto const& [key, col] : df ) {
        switch (col.tipo) {
            case 's':
                (*static_cast<std::vector<std::string> *>(col.pcoluna)).push_back(std::get<std::string>(row[i]));
                break;
            case 'i':
                (*static_cast<std::vector<int> *>(col.pcoluna)).push_back(std::get<int>(row[i]));
                break;
            case 'd':
                (*static_cast<std::vector<double> *>(col.pcoluna)).push_back(std::get<double>(row[i]));
                break;
        }
        i++;
    }

}

void DataFrame::PrintColunaCpp(std::string nome_coluna){
    coluna col = df[nome_coluna];
    switch (col.tipo)
    {
        case 's':
            for(auto i: (*static_cast<std::vector<std::string>*>(col.pcoluna)))
                std::cout << i << std::endl;
            break;
        case 'i':
            for(auto i: (*static_cast<std::vector<int>*>(col.pcoluna)))
                std::cout << i << std::endl;
            break;
        case 'd':
            for(auto i: (*static_cast<std::vector<double>*>(col.pcoluna)))
                std::cout << i << std::endl;
            break;
    }
}

void DataFrame::PassColunaInt(std::string tipo, boost::python::list& l, std::string nome){
    char t = tipo[0];
    std::vector<int> w;
    int token;
    for (int i = 0; i < len(l) ; i++){
        token = boost::python::extract<int>(l[i]);
        w.push_back(token);
    }
    InserirColuna(t, w, nome);
}

// boost::python::list DataFrame::RetunColunaInt(std::string coluna){
int DataFrame::ReturnColunaInt(std::string nome){
    // boost::python::list int_vec;
    std::vector<int> valores;
    valores = (*static_cast<std::vector<int> *>(df["coluna"].pcoluna));
    // for (auto i : valores){
    //     int_vec.append(i);
    // }
    return 1;
}

std::string DataFrame::ExtractKeys() {
    std::string retval;
    for( auto const& [key, col] : df ) {
        retval = key;
  }
  return retval;
}


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
    .def_readwrite("df", & DataFrame::df)
    .def("PassColunaInt", & DataFrame::PassColunaInt)
    .def("ReturnColunaInt", & DataFrame::ReturnColunaInt)
    .def("ExtractKeys", & DataFrame::ExtractKeys)
    .def_readwrite("test", & DataFrame::test)
    ;

    // def("pass_ints", pass_ints);

}
