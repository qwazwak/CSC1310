/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	Title:		CSC1310 - Lab 10 - Driver
 *	Author(s):	Rus Hoffman
 *	Date:		November 13, 2018
 *	Purpose:		Use the binary tree
 *
 * * * * * * * * * * * * * * * * * * * * * * * */

#include "AT_Cast.h"
#include "BinaryTree.h"
#include <iostream>

using namespace std;

int main () {
	BinaryTree<AT_Cast>* theTree;
	theTree = new BinaryTree<AT_Cast>(new AT_Cast(1021, string("Fin")));
	theTree->createAddNode(new AT_Cast(1057, string("Jake")));
	theTree->createAddNode(new AT_Cast(2486, string("Ice King")));
	theTree->createAddNode(new AT_Cast(3769, string("Princess Bubblegum")));
	theTree->createAddNode(new AT_Cast(1017, string("Lumpy Space Princess")));
	theTree->createAddNode(new AT_Cast(1275, string("Cinnamon Bun")));
	theTree->createAddNode(new AT_Cast(1899, string("Peppermint Butler")));
	theTree->createAddNode(new AT_Cast(4218, string("Marceline")));
	theTree->createAddNode(new AT_Cast(1214, string("BMO")));
	cout << "-----------------    START IN ORDER    -----------------" << "\n";
	theTree->streamOutInorder();
	cout << "-----------------     END IN ORDER     -----------------" << "\n";
	cout << "\n\n\n\n";
	cout << "-----------------    START PREORDER    -----------------" << "\n";
	theTree->streamOutPreorder();
	cout << "-----------------     END PREORDER     -----------------" << "\n";
	cout << "\n\n\n\n";
	cout << "-----------------   START POSTORDER    -----------------" << "\n";
	theTree->streamOutPostorder();
	cout << "-----------------    END POSTORDER     -----------------" << "\n";
	cout << flush;
	return 0;
}
