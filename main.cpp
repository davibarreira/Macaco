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

void add_row(std::map<std::string, coluna> &dataframe, std::vector<std::variant<int,double, std::string>> row){
    int i = 0;
    for( auto const& [key, col] : dataframe ) {
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




void print_col(coluna col){
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



int main() {

    std::map<std::string, coluna> df;

    std::vector<int> idade {11,10,2};
    std::vector<double> preco {1.0,5.2,2.2};
    std::vector<std::string> nomes {"Davi","Flavio"};

    coluna coluna1;
    coluna1.tipo = 'i';
    coluna1.pcoluna = &idade;
    df["Col1"] = coluna1;

    coluna coluna2;
    coluna2.tipo = 'd';
    coluna2.pcoluna = &preco;
    df["Col2"] = coluna2;

    coluna coluna3;
    coluna3.tipo = 's';
    coluna3.pcoluna = &nomes;
    df["Col3"] = coluna3;

    std::vector<std::variant<int,double, std::string>> row {77,57.2,"Teste"};


    add_row(df, row);
    print_col(df["Col1"]);
    print_col(df["Col2"]);
    print_col(df["Col3"]);



    return 0;
}
