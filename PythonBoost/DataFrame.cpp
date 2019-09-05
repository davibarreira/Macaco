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

    template <typename T>
    void InserirColuna(char tipo, std::vector<T> valores, std::string nome);

    void AddRow(std::vector<std::variant<int,double, std::string>> row);

    void PrintColunaCpp(std::string nome_coluna);

};

template <typename T>
void DataFrame::InserirColuna(char tipo, std::vector<T> valores, std::string nome){
    coluna coluna1;

    coluna1.tipo = tipo;
    coluna1.pcoluna = &valores;
    df[nome] = coluna1;
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

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(DataFrame)
{
    class_<DataFrame>("DataFrame",init<>())
    .def_readwrite("df", & DataFrame::df)
    .def("InserirColuna", & DataFrame::InserirColuna<int>)
    ;

}
