#ifndef GEN_BST
#define GEN_BST
#include "dlinkedlist.h"
#include <string>

template<typename T>
class FacutlyTreeNode{ //creating nodes for tree
	public:
		FacultyTreeNode(); // constructor
		FacultyTreeNode(int fID); //overloaded constructor for node 
		FacutlyTreeNode(int fID, string fName, string fDepartment, string fLevel, DoublyLinkedList<int> fStudents); //overloaded constructor for filling node
		virtual ~FacultyTreeNode(); //destructor
		
		//Variables
		int facultyID; //key value used to sort on is object ID
		string facultyName; //faulty member name
		string facultyDepartment; //department faculty belongs to
		string facultyLevel; //faculty position
		DoublyLinkedList<int> students; //DlinkedList of students assigned to faculty
		
		//Node children
		TreeNode<T> *left; //left child
		TreeNode<T> *right; //right child
};

template<typename T>
TreeNode<T>::TreeNode(){
	left = NULL;
	right = NULL;
}

template<typename T>
FacultyTreeNode<T>::FacultyTreeNode(int fID){
	facultyID = fID;
	left = NULL;
	right = NULL;
}

template<typename T>
FacultyTreeNode<T>::FacultyTreeNode(int fID, string fName, string fDepartment, string fLevel, DoublyLinkedList<int> fStudents){
	facutlyID = fID;
	facultyName = fName;
	facultyDepartment = fDepartment;
	facultyLevel = fLevel;
	students = fStudents;
	left = NULL;
	right = NULL;
}

template<typename T>
FacultyTreeNode<T>::~FacultyTreeNode(){
	if (right != NULL)
		delete right;
	if (left != NULL)
		delete left;
}

/*___________________________________________________________________________________*/
//Facutly BST
/*___________________________________________________________________________________*/

template <typename T>
class FacultyBST{
	public:
		FacultyBST(); //default constructor
		~FacultyBST(); //destructor
		FacultyNode<T>* getFRoot(); //return root node of BST
		FacultyNode<T>* getSuccessor(FacultyNode<T> *pNode); //return child of node to be deleted
		void insertFaculty(int fID); //insert node given faculty ID
		void insertFacultyInfo(int fID, string fName, string fDepartment, string fLevel, DoublyLinkedList<int> fStudents);
		FacultyNode<T>* searchFaculty(int fID);
		bool deleteFacultyNode(int fID);
		int getAdvisee(int studID);
		bool isEmpty();
		bool containsFaculty(int fID);
		void traverseFaculty(FacultyNode<T>* fNode);

		//helpers
		int getFacultyID(int fID);
		string getFacultyName(int fID);
		string getFacultyDepartment(int fID);
		string getFacultyLevel(int fID);
		DoublyLinkedList<int> getAdvisees(int fID);

	private:
		FacultyTreeNode *root;
};

template <typename T>
FacultyBST<T>::FacultyBST(){
	root = NULL;
}

template <typename T>
FacultyBST<T>::~FacultyBST(){
//building character	
}

template <typename T>
FacultyNode<T>* FacultyBST<T>::getFRoot(){
	return root;
}

template <typename T>
FacultyNode<T>* FacultyBST<T>::getSuccessor(FacultyNode<T> *pNode){
	FacultyNode *sp = pNode;
	FacultyNode *suc = pNode;
	//find successor that is one righ and all the way down
	FacultyNode *curr = pNode -> right;
	while(curr != NULL){
		sp = succ;
		suc = curr;
		curr = curr -> left;
	}
	if(succ != pNode -> right){
		sp -> left = succ -> right;
		suc -> right = pNode -> right;
	}
	return suc;
}

template <typename T>
void FacultyBST<T>::insertFaculty(int fID){
	FacultyNode<T>* node = new FacultyNode<T>(fID);

	if (root == NULL) //check if tree empty, if true insert as root
		root = node;
	else{
		FacultyNode<T>* curr= root;
		FacultyNode<T>* parent;
		bool leafReached;
		while(!leafReached){ //runs until leaf node reached
			parent = curr;
			if(fID < curr -> fID){
				curr = curr -> left; //curr shifts to left child
				if(curr == NULL){ //leaf reached 
					parent -> left = node;
					leafReached = true;
				}
			}
			else { //id larger than curr
				curr = curr -> right; //curr shifts to right child
				if(curr == NULL){ //leaf reached
					parent -> right = node;
					leafReached = true;
				}
			}
		}
	}
}

template <typename T>
void FacultyBST<T>::insertFaculty(int fID, string fName, string fDepartment, string fLevel, DoublyLinkedList<int> fStudents){
	FacultyNode<T>* node = new FacultyNode<T>(fID, fName, fDepartment, fLevel, fStudents);       
	if (root == NULL) //check if tree empty, if true insert as root
                root = node;
        else{
                FacultyNode<T>* curr= root;
                FacultyNode<T>* parent;
                bool leafReached;
                while(!leafReached){ //runs until leaf node reached
                        parent = curr;
                        if(fID < curr -> fID){
                                curr = curr -> left; //curr shifts to left child
                                if(curr == NULL){ //leaf reached
                                        parent -> left = node;
                                        leafReached = true;
                                }
                        }
                        else { //id larger than curr
                                curr = curr -> right; //curr shifts to right child
                                if(curr == NULL){ //leaf reached
                                        parent -> right = node;
                                        leafReached = true;
                                }
                        }
                }
        }
}

template <typename T>
FacultyNode<T>* FacultyBST<T>::searchFaculty(int fID){
	if (root == NULL)
		return NULL;
	else{
		FacultyNode<T>* curr = root;
		while(curr -> facultyID != fID){
			if(fID < curr -> facultyID)
				curr = curr -> left;
			else
				curr = curr -> right;
		}
		return curr;
	}
}

template <typename T>
bool FacultyBST<T>::deleteFacultyNode(int fID){
	if(root == NULL)
		return false;
	FacultyNode<T>* curr = root;
	FacultyNode<T>* parent = root;
	bool isLeft = true;
	while(current -> facultyID != fID){
		parent = curr;
		if (fID < curr -> facultyID){ //id less than current ID
			isLeft = true;
			curr = curr-> left;
		}
		else{
			isLeft = false;
			curr = curr -> right;
		}

		if (curr == NULL) //node not found in BST
			return false;
	}
	if (curr -> left == NULL && curr -> right == NULL){ //no children
		if(curr == root)
			root == NULL;
		else if(isLeft)
			parent -> left = NULL;
		else
			parent -> right = NULL;
	}
	else if (curr -> right == NULL){ //one child no right child
		if(curr == root)
			root = curr -> left;
		else if(isLeft)
			parent -> left = curr -> left;
		else
			parent -> right = curr -> left;
	}
	else if (curr -> right == NULL){ //one child no left child
		if(curr == root)
			root = curr -> left;
		else if(isLeft)
			parent -> left = curr -> right;
		else
			parent -> right = curr -> right;
	}
	else{ //2 children
		FacultyNode<T>* suc = getSuccessor(curr);
		if (curr == root) 
			root = suc;
		else if(isLeft)
			parent -> left = suc;
		else 
			parent -> right = suc;
		suc -> left = curr -> left;
	}
	return true;
}

template <typename T>
int FacultyBST<T>::getFacultyID(int fID){
	if(root == NULL)
		return NULL;
	else if(containsFaculty(fID)){ //checks if node with same ID exists
                FacultyNode<T> *curr = root;
                while (curr->facultyID != fID){
                        if(fID < curr-> facultyID)
                                curr = curr -> left;
                        else
                                curr = curr -> right;
                }
                return curr -> facultyID;
        }
        else
                return NULL;
}

template <typename T>
string FacultyBST<T>::getFacultyName(int fID){
	if(root == NULL)
                return NULL;
        else if(containsFaculty(fID)){ //checks if node with same ID exists
                FacultyNode<T> *curr = root;
                while (curr->facultyID != fID){
                        if(fID < curr-> facultyID)
                                curr = curr -> left;
                        else
                                curr = curr -> right;
                }
                return curr -> facultyName;
        }
        else
                return NULL;
}

template <typename T>
string FacultyBST<T>::getFacultyDepartment(int fID){
	if(root == NULL)
                return NULL;
        else if(containsFaculty(fID)){ //checks if node with same ID exists
                FacultyNode<T> *curr = root;
                while (curr->facultyID != fID){
                        if(fID < curr-> facultyID)
                                curr = curr -> left;
                        else
                                curr = curr -> right;
                }
                return curr -> facultyDepartment;
        }
        else
                return NULL;
}

template <typename T>
string FacultyBST<T>::getFacultyLevel(int fID){
	if(root == NULL)
                return NULL;
        else if(containsFaculty(fID)){ //checks if node with same ID exists
                FacultyNode<T> *curr = root;
                while (curr->facultyID != fID){
                        if(fID < curr-> facultyID)
                                curr = curr -> left;
                        else
                                curr = curr -> right;
                }
                return curr -> facultyLevel;
        }
        else
                return NULL;
}


template <typename T>
DoublyLinkedList<int> FacultyBST<T>::getAdvisees(int fID){
	if (root == NULL)
		return NULL;
	else if(containsFaculty(fID)){ //checks if node with same ID exists 
		FacultyNode<T> *curr = root;
		while (curr->facultyID != fID){
			if(fID < curr-> facultyID)
				curr = curr -> left;
			else
				curr = curr -> right;
		}
		return curr -> students;
	}
	else
		return NULL;
}

template <typename T>
bool FacultyBST<T>::isEmpty(){
	if(root == NULL)
		return true;
	else{
		return false;
	}
}

template <typename T>
bool FacultyBST<T>::containsFaculty(int fID){
	if (root == NULL)
		return false;
		
	else{
		FacultyNode<T> *curr = root;
		while (curr -> facultyID != fID){
			if(fID < curr -> facultyID)
				curr = curr -> left;
			else
				curr = curr -> right;
			if(curr == NULL)
				return false;
		}
		return true;
	}
}




