#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <any>
#include <variant>


struct coluna{
    char tipo;
    void * pcoluna;

};

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

    coluna coluna1;
    coluna1.tipo = 'i';
    coluna1.pcoluna = &idade;
    df["Col1"] = coluna1;
    print_col(df["Col1"]);


    return 0;
}
