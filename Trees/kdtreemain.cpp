#define _USE_MATH_DEFINES
/*
*   main.cpp
*
*   k-d Tree Project
*	author: Arvind Rao
*   license: GNU
*
*/
#include <iostream>
#include "kdtree.h"
#include <random>
#include <cmath>
#include <vector>
#include <list>
#include <array>
#include <memory>

typedef float numType;
const int _numpts = 20;
const int _dim = 2;

numType testpoints[_numpts][_dim] =
	/*{
		{8.40924, 4.11543}, {8.10499,
		6.50689}, {1.3663, 3.43026},
		{9.7614, 9.8382}, {0.672512,
		0.113181}, {2.22785, 3.46726},
		{5.23381, 4.69416}, {4.74723,
		9.74655}, {0.191659, 1.20641},
		{2.8546, 7.32662}, {8.51895,
		6.21829}, {0.779546, 1.82988},
		{8.83612, 8.70544}, {2.40537,
		6.50697}, {2.70078, 1.93852},
		{3.25474, 5.41287}, {7.77891,
		7.55894}, {1.10809, 9.95432},
		{4.44556, 3.77189}, {7.10244,
		0.78922}, {2.71828, 3.14159}
	};*/
	{
	    {5,4},{2,3},{17,11},{6,9},{9,0},
	    {14,18},{10,7},{1,12},{13,16},{18,15},
	    {3,13},{7,17},{19,14},{15,6},{0,5},
	    {8,2},{4,10},{12,19},{11,1},{16,8}
	};


void print(std::vector<numType> pt)
{
	for( auto i = 0; i < pt.size(); i++)
	{
	    std::cout<< pt[i] << ", ";
	}
	std::cout<<"\n";
}

int main(int argc, char ** argv)
{
	typedef std::vector<numType> vecType;
    int n; // dimension of the point space
    argc = 2;
    if( argc < 2)
    {
        std::cerr<< "Must include a number!!\n";
        return 0;
    }
    // n = std::atoi( argv[1] );
    n = 2;

	// //make a list of vectors out of the testpoints array
	std::list<vecType> point_list;
	for(auto i = 0; i < _numpts; i++ )
	{
		vecType pt;
		for( auto j = 0; j < _dim; j++) pt.push_back( testpoints[i][j] );
		point_list.push_back(pt);
	}

	Kdtree kd;
	Node* head = new Node(2);
	Node* temp = nullptr;
	kd.makeTree(point_list);
	kd.printTree(kd.getRoot());

	std::cout<<"\n\n";
	head = nullptr;

	return 0;
	//print( head->data );
	/*Node head(3, point_list.front());
	std::unique_ptr<Node> a = std::unique_ptr<Node>( new Node(3) );
	std::unique_ptr<Node> b;
	a -> data = head.data;
	print(a->data);
	*/
}
