#include <iostream>
#include <string>
#include <vector>

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<int> vector1;
    std::vector<int> vector2;

    vector1.push_back(10);
    vector1.push_back(20);
    vector2.push_back(100);
    vector2.push_back(200);
    std::cout << vector1.at(0) << std::endl;
    std::cout << vector1.at(1) << std::endl;

    std::vector<std::vector<int>> vector2D;
    vector2D.push_back(vector1);
    vector2D.push_back(vector2);
    std::cout << vector2D.at(0).at(1) << std::endl;

    for (auto v: vector2D){
        for (auto val: v) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    std::string nome {"Davi Barreira"};
    std::string nome2 {"Flavio"};

    std::cout << nome << std::endl;
    if (nome < nome2)
        std::cout << nome2 << " é < que " << nome;

    return 0;
}
