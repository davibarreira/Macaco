
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <any>
#include <variant>
#include <tuple>



struct coluna{
    char tipo;
    void * pcoluna;

};

class DataFrame{
private:


public:

    std::map<std::string, std::vector<int>> coluna_int;
    std::map<std::string,std::vector<double>> coluna_double;
    std::map<std::string,std::vector<std::string>> coluna_string;



    void InserirColunaInt(std::string coluna, std::vector<int> valores);
    void InserirColunaDouble(std::string coluna, std::vector<double> valores);
    void InserirColunaString(std::string coluna, std::vector<std::string> valores);

    void RemoverColunaInt(std::string nome_coluna);

};

void DataFrame::InserirColunaInt(std::string coluna, std::vector<int> valores){
    coluna_int[coluna] = valores;
}

void DataFrame::InserirColunaDouble(std::string coluna, std::vector<double> valores){
    coluna_double[coluna] = valores;
}

void DataFrame::InserirColunaString(std::string coluna, std::vector<std::string> valores){
    coluna_string[coluna] = valores;
}

void DataFrame::RemoverColunaInt(std::string nome_coluna){
    coluna_int.erase(nome_coluna);
}
//
//void DataFrame::AddRow(std::vector<std::variant<int,double, std::string>> row){
//    int i = 0;
//    for( auto const& [key, col] : df ) {
//        switch (col.tipo) {
//            case 's':
//                (*static_cast<std::vector<std::string> *>(col.pcoluna)).push_back(std::get<std::string>(row[i]));
//                break;
//            case 'i':
//                (*static_cast<std::vector<int> *>(col.pcoluna)).push_back(std::get<int>(row[i]));
//                break;
//            case 'd':
//                (*static_cast<std::vector<double> *>(col.pcoluna)).push_back(std::get<double>(row[i]));
//                break;
//        }
//        i++;
//    }
//
//}
//
//void DataFrame::PrintColuna(std::string nome_coluna){
//    coluna col = df[nome_coluna];
//    switch (col.tipo)
//    {
//        case 's':
//            for(auto i: (*static_cast<std::vector<std::string>*>(col.pcoluna)))
//                std::cout << i << std::endl;
//            break;
//        case 'i':
//            for(auto i: (*static_cast<std::vector<int>*>(col.pcoluna)))
//                std::cout << i << std::endl;
//            break;
//        case 'd':
//            for(auto i: (*static_cast<std::vector<double>*>(col.pcoluna)))
//                std::cout << i << std::endl;
//            break;
//    }
//}


int main() {



    std::vector<int> idade {11,10,NULL};
    std::vector<int> qtd {5,7,8};
    std::vector<double> preco {1.0,5.2,2.2};
    std::vector<std::string> nomes {"Davi","Flavio",""};


    DataFrame davi;

    davi.InserirColunaInt("idade",idade);
    davi.InserirColunaInt("outro",idade);
    davi.InserirColunaString("nomes",nomes);

    std::cout << davi.coluna_int["idade"][0];

    davi.RemoverColunaInt("idade");

    std::cout << davi.coluna_int["idade"][0];

    return 0;
}