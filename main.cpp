#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <any>
#include <variant>

int main() {

    std::map<std::string, std::variant<std::vector<int>, std::vector<char>, std::vector<std::string>,std::vector<double>>> m;
    std::vector<int> v {1,0,10};
    m["Col1"] = v;
    m["Col2"] = std::vector<int> {1, 2, 2, 2};

    auto i = m["Col1"];

    std::cout << std::get<std::vector<int>>(m["Col1"])[0] << std::endl;

    std::map<std::string, std::vector<std::any>> D{
            {"Coluna",{10.0,10.0}}
    };
    D["Coluna"].push_back(20.0);

    for (auto j: D["Coluna"]) {
        if (typeid(double) == j.type() ) {
            std::cout << std::any_cast<double>(j) << std::endl;
            std::cout << j.type().name() << std::endl;
        }
    }
//    m["Coluna2"] = {"Davi"};
//    auto i = m.at("Coluna");

//    std::cout << m.at("Coluna")[0].type().name();


    return 0;


}













//#include <iostream>
//#include <string>
//#include <vector>
//#include <variant>
//#include <map>
//#include <iterator>
//#include <boost/operators.hpp>
//#include <any>
//
//template <typename T>
//void display(std::vector<T> v){
//    for (auto i: v) {
//       std::cout << i << std::endl;
//    }
//    std::cout << std::endl;
//}
//
//template <typename T>
//using table_type = std::map<std::string, std::vector<T>>;
//
//template <class Type>
//class Pilha
//{
//public:
//    std::vector<Type> *coluna;
//
//};
//
//template <typename tipo>
//void disp(tipo v){
//
//
//    return;
////    std::cout << std::get<tipo>(v);
//}
//
////template < typename... T, typename... ARGS >
//int main(){
//
//    std::map<std::string, std::vector<std::variant< int, std::string >>> m;
//    m["Coluna"] = {1,2,2,2};
//    m["Coluna2"] = {"Davi"};
//    auto i = m.at("Coluna");
//
//    std::vector<int> v;
//
//    std::cout << std::get<int>(i[0]);
////    std::cout << std::get<std::vector<int>>(m["Coluna"]);
////    std::cout << i[0]["contained value"];
////    auto v = std::get<std::vector<int>>(m.at("Coluna"));
////    disp(i[0]);
//
//
//
//
//
//
//
//
//
////    std::map<std::string, std::any> m;
////    m["Q"] = 1;
////    m["L"] = "davi";
//
////    std::cout << std::any_cast<std::string>(m["L"]);
//
////
////
////    table_type<int> table;
////    Pilha<std::string> p;
////
//////    p.coluna = {"Davi"};
////
////
//////    std::vector variant {"c1","c2","c3"};
//////    std::vector<std::string> temp {"c1","c2","c3"};
////
////
//////    m["Col3"] = {1,2,4};
//////    m["Col3"].push_back(2);
//////
//////    display(m["Coluna"]);
//////    display(m.at("Coluna"));
//
//    return 0;
//}









//#include <iostream>
//#include <string>
//#include <vector>
//#include <iostream>
//#include <string>
//#include <tuple>
//#include <vector>
//
//template < typename... T >
//using table_type = std::vector< std::tuple<T...> > ;
//
//template < typename... T, typename... ARGS >
//void add_row_flexible( table_type<T...>& table, ARGS&&... args )
//{ table.push_back( std::tuple<T...>( std::forward<ARGS>(args)... ) ) ; }
//
//template < typename... T >
//void add_row_rigid( table_type<T...>& table, T&&... args )
//{ table.push_back( std::tuple<T...>( std::forward<T>(args)... ) ) ; }
//
//int main()
//{
//    struct A { A(bool) {} /* converting constructor */ } ;
//
//    table_type< A, double, bool > table ;
//
//    add_row_flexible( table, false, 2.3, true ) ; // fine
//    add_row_flexible( table, "hello", -21.4, false ) ; // fine
//
//    auto i = table.at(0);
//
//    std::cout<< std::get<1>(i);
//
//
//
////    add_row_rigid( table, false, 2.3, true ) ; // *** error: conflicting types for parameter 'T'
//
//    return 0;
//}
//
//
////int *create_array(size_t size, int init_value=0){
////    int *new_storage {nullptr};
////
////    new_storage = new int[size];
////    for (int i = 0; i < size; ++i) {
////        new_storage[i] = init_value;
////    }
////
////    return new_storage;
//////
////}
////
////int main() {
////    std::cout << "Hello, World!" << std::endl;
////    std::vector<int> vector1;
////    std::vector<int> vector2;
////
////    vector1.push_back(10);
////    vector1.push_back(20);
////    vector2.push_back(100);
////    vector2.push_back(200);
////    std::cout << vector1.at(0) << std::endl;
////    std::cout << vector1.at(1) << std::endl;
////
////    std::vector<std::vector<int>> vector2D;
////    vector2D.push_back(vector1);
////    vector2D.push_back(vector2);
////    std::cout << vector2D.at(0).at(1) << std::endl;
////
////    for (auto v: vector2D){
////        for (auto val: v) {
////            std::cout << val << " ";
////        }
////        std::cout << std::endl;
////    }
////
////    std::string nome {"Davi Barreira"};
////    std::string nome2 {"Flavio"};
////
////    std::cout << nome << std::endl;
////    if (nome < nome2)
////        std::cout << nome2 << " é < que " << nome << std::endl;
////
////    int *arr {nullptr};
////    arr = create_array(5,1);
////
////
////    for (int i = 0; i < 5; ++i) {
////        std::cout << arr[i] << " ";
////    }
////
////    delete [] arr;
////
////    return 0;
////}