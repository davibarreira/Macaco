g++ -I /usr/include/python3.6 -fpic -c -o $1.o $1.cpp
g++ -o $1.so -shared $1.o -lboost_python3
