#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

template < typename... T >
using table_type = std::vector< std::tuple<T...> > ;

template < typename... T, typename... ARGS >
void add_row_flexible( table_type<T...>& table, ARGS&&... args )
{ table.push_back( std::tuple<T...>( std::forward<ARGS>(args)... ) ) ; }

template < typename... T >
void add_row_rigid( table_type<T...>& table, T&&... args )
{ table.push_back( std::tuple<T...>( std::forward<T>(args)... ) ) ; }

int main()
{
    struct A { A(bool) {} /* converting constructor */ } ;

    table_type< A, double, bool > table ;

    add_row_flexible( table, false, 2.3, true ) ; // fine
    add_row_flexible( table, "hello", -21.4, false ) ; // fine

    auto i = table.at(0);

    std::cout<< std::get<1>(i);



//    add_row_rigid( table, false, 2.3, true ) ; // *** error: conflicting types for parameter 'T'

    return 0;
}


//int *create_array(size_t size, int init_value=0){
//    int *new_storage {nullptr};
//
//    new_storage = new int[size];
//    for (int i = 0; i < size; ++i) {
//        new_storage[i] = init_value;
//    }
//
//    return new_storage;
////
//}
//
//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    std::vector<int> vector1;
//    std::vector<int> vector2;
//
//    vector1.push_back(10);
//    vector1.push_back(20);
//    vector2.push_back(100);
//    vector2.push_back(200);
//    std::cout << vector1.at(0) << std::endl;
//    std::cout << vector1.at(1) << std::endl;
//
//    std::vector<std::vector<int>> vector2D;
//    vector2D.push_back(vector1);
//    vector2D.push_back(vector2);
//    std::cout << vector2D.at(0).at(1) << std::endl;
//
//    for (auto v: vector2D){
//        for (auto val: v) {
//            std::cout << val << " ";
//        }
//        std::cout << std::endl;
//    }
//
//    std::string nome {"Davi Barreira"};
//    std::string nome2 {"Flavio"};
//
//    std::cout << nome << std::endl;
//    if (nome < nome2)
//        std::cout << nome2 << " é < que " << nome << std::endl;
//
//    int *arr {nullptr};
//    arr = create_array(5,1);
//
//
//    for (int i = 0; i < 5; ++i) {
//        std::cout << arr[i] << " ";
//    }
//
//    delete [] arr;
//
//    return 0;
//}