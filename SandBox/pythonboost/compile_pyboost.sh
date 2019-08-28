g++ -I /usr/include/python3.6 -fpic -c -o hello.o hello.cpp
g++ -o hello.so -shared hello.o -lboost_python3
