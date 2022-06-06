// BT.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
	cout << "Hello 20180622 천범수\n" << endl;
	typedef BinaryTree < char > charTree;  
	typedef charTree* charTreePtr;

	// Create tree from Figure 11-2

	// Create left subtree (rooted at B)
// Create B's left subtree 
	charTreePtr bt1(new charTree);  bt1->insert('D');

// Create B's right subtree
	charTreePtr bt2(new charTree);  bt2->insert('E');

// Create node containing B, and link
// up to subtrees
	charTreePtr bt3(new charTree);  bt3->insert('B');
	bt3->makeLeft(bt1);  bt3->makeRight(bt2);
	// ** done creating left subtree
// Create right subtree

// Create C's right subtree
	charTreePtr bt4(new charTree);  bt4->insert('F');

// Create node containing C, and link
// up its right subtree
	charTreePtr bt5(new charTree);  bt5->insert('C');
	bt5->makeRight(bt4);
	// ** done creating right subtree
// Create the root of the tree, and link together
	charTreePtr bt6(new charTree);
	bt6->insert('A');
	bt6->makeLeft(bt3);  bt6->makeRight(bt5);

	// print out the root
	cout << "Root contains: " << bt6->getData() << endl;

	// print out root of left subtree
	cout << "Left subtree root: " << bt6->left()->getData() << endl;

	// print out root of right subtree
	cout << "Right subtree root: " << bt6->right()->getData() << endl;
	// print out leftmost child in tree  
	cout << "Leftmost child is: " << bt6->left()->left()->getData() << endl;

	// print out rightmost child in tree 
	cout << "Rightmost child is: " << bt6->right()->right()->getData() << endl;
	cout << "--------------------------------------" << endl;

	typedef BinaryTree < char > charTree2;
	typedef charTree2* charTreePtr2;

	charTreePtr2 bit1(new charTree2);  bit1->insert('G');
	charTreePtr2 bit2(new charTree2);  bit2->insert('E');
	charTreePtr2 bit3(new charTree2);  bit3->insert('F');
	bit1->makeLeft(bit2); bit1->makeRight(bit3);
	charTreePtr2 bit4(new charTree2);  bit4->insert('A');
	charTreePtr2 bit5(new charTree2);  bit5->insert('B');
	bit2->makeLeft(bit4); bit2->makeRight(bit5);
	charTreePtr2 bit6(new charTree2);  bit6->insert('C');
	charTreePtr2 bit7(new charTree2);  bit7->insert('D');
	bit3->makeLeft(bit6); bit3->makeRight(bit7);

	cout << "Root contains: " << bit1->getData() << endl;
	cout << "Left subtree Root: " << bit1->left()->getData() << endl;
	cout << "Right subtree Root: " << bit1->right()->getData() << endl;
	cout << "Left child of Left subtree: " << bit1->left()->left()->getData() << endl;
	cout << "Right child of Left subtree: " << bit1->left()->right()->getData() << endl;
	cout << "Left child of Right subtree: " << bit1->right()->left()->getData() << endl;
	cout << "Right child of Right subtree: " << bit1->right()->right()->getData() << endl;

	return 0;
}
