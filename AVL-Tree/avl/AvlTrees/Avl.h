// <plaintext>
#ifndef AVL_H
#define AVL_H

//#include <stddef.h>
#include "Comparable.h"
#include <queue>
#include <deque>
using namespace std;

long values[100];


// Indices into a subtree array
//     NOTE: I would place this inside the AvlNode class but 
//           when I do, g++ complains when I use dir_t. Even
//           when I prefix it with AvlNode:: or AvlNode::
//           (If you can get this working please let me know)
//
enum  dir_t { LEFT = 0, RIGHT = 1 };

// AvlNode -- Class to implement an AVL Tree
//

class AvlNode {
      
      private:

   // ----- Private data

   Comparable * myData;  // Data field
   AvlNode    * mySubtree[2];   // Pointers to subtrees
   short      myBal;   // Balance factor

      // Reset all subtrees to null and clear the balance factor
   void Reset(void) {
      myBal = 0 ;
      mySubtree[LEFT] = mySubtree[RIGHT] = NULL ;
   }

   // ----- Routines that do the *real* insertion/deletion

      // Insert the given key into the given tree. Return the node if
      // it already exists. Otherwise return NULL to indicate that
      // the key was successfully inserted.  Upon return, the "change"
      // parameter will be '1' if the tree height changed as a result
      // of the insertion (otherwise "change" will be 0).
   static Comparable * InsertH(Comparable * item,AvlNode * & root,int & change);

      // Delete the given key from the given tree. Return NULL if the
      // key is not found in the tree. Otherwise return a pointer to the
      // node that was removed from the tree.  Upon return, the "change"
      // parameter will be '1' if the tree height changed as a result
      // of the deletion (otherwise "change" will be 0).
   static Comparable * Delete(long key,AvlNode * & root,int & change,cmp_t cmp=EQ_CMP);

   // Routines for rebalancing and rotating subtrees

      // Perform an XX rotation for the given direction 'X'.
      // Return 1 if the tree height changes due to rotation,
      // otherwise return 0.
   static int RotateOnce(AvlNode * & root, dir_t dir);

      // Perform an XY rotation for the given direction 'X'
      // Return 1 if the tree height changes due to rotation,
      // otherwise return 0.
   static int RotateTwice(AvlNode * & root, dir_t dir);

      // Rebalance a (sub)tree if it has become imbalanced
   static int ReBalance(AvlNode * & root);

      // Perform a comparison of the given key against the given
      // item using the given criteria (min, max, or equivalence
      // comparison). Returns:
      //   EQ_CMP if the keys are equivalent
      //   MIN_CMP if this key is less than the item's key
      //   MAX_CMP if this key is greater than item's key
   cmp_t Compare(long key, cmp_t cmp=EQ_CMP) const;


      // Disallow copying and assignment
   AvlNode(const AvlNode &);
   AvlNode & operator=(const AvlNode &);

      
      
public:
       
       static long* bsf(AvlNode* root,int &size);
	   static void postOrder(AvlNode *root,int &size,long *array);
	   static void preOrder(AvlNode *root,int &size,long *array);
	   static void inOrder(AvlNode *root,int &size,long *array);
	  // static long *inOrder(AvlNode *root);
      

      // Return the opposite direction of the given index
   static  dir_t Opposite(dir_t dir) { 
     return dir_t(1 - int(dir));
   }

   // ----- Constructors and destructors: 

   AvlNode(Comparable  * item=NULL);
   virtual ~AvlNode(void);

   // ----- Query attributes:

      // Get this node's data
   Comparable *
   Data() const { return  myData; }

      // Get this node's key field
   long   Key() const { return  myData->Key(); }

      // Query the balance factor, it will be a value between -1 .. 1
      // where:
      //     -1 => left subtree is taller than right subtree
      //      0 => left and right subtree are equal in height
      //      1 => right subtree is taller than left subtree
   short Bal(void) const { return  myBal; }

      // Get the item at the top of the left/right subtree of this
      // item (the result may be NULL if there is no such item).
      //
   AvlNode * Subtree(dir_t dir) const { return  mySubtree[dir]; }

   // ----- Search/Insert/Delete
   //
   //   NOTE: These are all static functions instead of member functions
   //         because most of them need to modify the given tree root
   //         pointer. If these were instance member functions than
   //         that would correspond to having to modify the 'this'
   //         pointer, which is not allowed in C++. Most of the 
   //         functions that are static and which take an AVL tree
   //         pointer as a parameter are static for this reason.
   
      // Look for the given key, return NULL if not found,
      // otherwise return the item's address.
   static Comparable * Search(long key, AvlNode * root, cmp_t cmp=EQ_CMP);

      // Insert the given key, return NULL if it was inserted,
      // otherwise return the existing item with the same key.
    static Comparable * Insert(Comparable * item, AvlNode * & root);//{
                   //     int  change;
         //return  InsertH(item, root, change);
                        
         //               }

      // Delete the given key from the tree. Return the corresponding
      // node, or return NULL if it was not found.
   static Comparable * Delete(long key, AvlNode * & root, cmp_t cmp=EQ_CMP);

   // Verification 

      // Return the height of this tree
  // int Height() const;

      // Verify this tree is a valid AVL tree, return TRUE if it is,
      // return FALSE otherwise
   //int Check() const;

      // If you want to provide your own allocation scheme than simply
      // #define the preprocessor manifest constant named CUSTOM_ALLOCATE
      // and make sure you provide and link with your own overloaded
      // versions of operators "new" and "delete" for this class.
//#ifdef CUSTOM_ALLOCATE
  // void * operator  new(size_t);

   //void
   //operator  delete(void *);
//#endif  /* CUSTOM_ALLOCATE */



};


   // Class AvlTree is a simple container object to "house" an AvlNode
   // that represents the root-node of and AvlTree. Most of the member
   // functions simply delegate to the root AvlNode.

class AvlTree {
private:
      // Disallow copying and assingment
   AvlTree(const AvlTree &);
   AvlTree & operator=(const AvlTree &);

      // Member data
   AvlNode * myRoot;   // The root of the tree

public:
      // Constructor and destructor
   AvlTree() : myRoot(NULL) {};
   ~AvlTree() { if (myRoot)  delete myRoot; }

      // Dump the tree to the given output stream
   //void
   //DumpTree(ostream & os) const;

      // See if the tree is empty
  // int
   //IsEmpty() const {
     // return  (myRoot == NULL);
   //}

      // Search, Insert, Delete, and Check
   Comparable *   Search(long key, cmp_t cmp=EQ_CMP) {
      return  AvlNode::Search(key, myRoot, cmp);
   }

   Comparable *  Insert(Comparable * item) {
      return  AvlNode::Insert(item, myRoot);
   }

   Comparable *
   Delete(long key, cmp_t cmp=EQ_CMP) {
      return  AvlNode::Delete(key, myRoot, cmp);
   }

    
    long* bsf(int &size){
             
             return AvlNode::bsf(myRoot,size);
             }
			 
	void postOrder(int &size,long *array){
	
		return AvlNode::postOrder(myRoot,size,array);
	}
	
	void preOrder(int &size,long *array){
	
		return AvlNode::preOrder(myRoot,size,array);
	}
	
	void inOrder(int &size,long *array){
	
		return AvlNode::inOrder(myRoot,size,array);
	}
    
    
 //  int
   //Check() const {
     // return  (myRoot) ? myRoot->Check() : 1;
   //}
};

// ---------------------------------------------------------------- Definitions

   // Return the minumum of two numbers
inline static int
MIN(int a, int b) {
   return  (a < b) ? a : b;
}

   // Return the maximum of two numbers
inline static int
MAX(int a, int b) {
   return  (a > b) ? a : b;
}

   // Use mnemonic constants for valid balance-factor values
enum balance_t { LEFT_HEAVY = -1, BALANCED = 0, RIGHT_HEAVY = 1 };

   // Use mnemonic constants for indicating a change in height
enum height_effect_t { HEIGHT_NOCHANGE = 0, HEIGHT_CHANGE = 1 };

   // Return true if the tree is too heavy on the left side
inline static int
LEFT_IMBALANCE(short bal) {
   return (bal < LEFT_HEAVY);
}

   // Return true if the tree is too heavy on the right side
inline static int
RIGHT_IMBALANCE(short bal) {
   return (bal > RIGHT_HEAVY);
}

// ----------------------------------------------- Constructors and Destructors


AvlNode::AvlNode(Comparable * item)
   : myData(item), myBal(0)
{
   Reset();
}


AvlNode::~AvlNode(void) {
   if (mySubtree[LEFT])  delete  mySubtree[LEFT];
   if (mySubtree[RIGHT]) delete  mySubtree[RIGHT];
}

// ------------------------------------------------- Rotating and Re-Balancing


int
AvlNode::RotateOnce(AvlNode * & root, dir_t dir)
{
   dir_t  otherDir = Opposite(dir);
   AvlNode * oldRoot = root;

      // See if otherDir subtree is balanced. If it is, then this
      // rotation will *not* change the overall tree height.
      // Otherwise, this rotation will shorten the tree height.
   int  heightChange = (root->mySubtree[otherDir]->myBal == 0)
                          ? HEIGHT_NOCHANGE
                          : HEIGHT_CHANGE;

      // assign new root
   root = oldRoot->mySubtree[otherDir];

      // new-root exchanges it's "dir" mySubtree for it's parent
   oldRoot->mySubtree[otherDir] = root->mySubtree[dir];
   root->mySubtree[dir] = oldRoot;

      // update balances
   oldRoot->myBal = -((dir == LEFT) ? --(root->myBal) : ++(root->myBal));

   return  heightChange;
}


int
AvlNode::RotateTwice(AvlNode * & root, dir_t dir)
{
   dir_t  otherDir = Opposite(dir);
   AvlNode * oldRoot = root;
   AvlNode * oldOtherDirSubtree = root->mySubtree[otherDir];

      // assign new root
   root = oldRoot->mySubtree[otherDir]->mySubtree[dir];

      // new-root exchanges it's "dir" mySubtree for it's grandparent
   oldRoot->mySubtree[otherDir] = root->mySubtree[dir];
   root->mySubtree[dir] = oldRoot;

      // new-root exchanges it's "other-dir" mySubtree for it's parent
   oldOtherDirSubtree->mySubtree[dir] = root->mySubtree[otherDir];
   root->mySubtree[otherDir] = oldOtherDirSubtree;

      // update balances
   root->mySubtree[LEFT]->myBal  = -MAX(root->myBal, 0);
   root->mySubtree[RIGHT]->myBal = -MIN(root->myBal, 0);
   root->myBal = 0;

      // A double rotation always shortens the overall height of the tree
   return  HEIGHT_CHANGE;
}


int AvlNode::ReBalance(AvlNode * & root) {
   int  heightChange = HEIGHT_NOCHANGE;

   if (LEFT_IMBALANCE(root->myBal)) {
         // Need a right rotation
      if (root->mySubtree[LEFT]->myBal  ==  RIGHT_HEAVY) {
            // RL rotation needed
         heightChange = RotateTwice(root, RIGHT);
      } else {
            // RR rotation needed
         heightChange = RotateOnce(root, RIGHT);
      }
   } else if (RIGHT_IMBALANCE(root->myBal)) {
         // Need a left rotation
      if (root->mySubtree[RIGHT]->myBal  ==  LEFT_HEAVY) {
            // LR rotation needed
         heightChange = RotateTwice(root, LEFT);
      } else {
            // LL rotation needed
         heightChange = RotateOnce(root, LEFT);
      }
   }

   return  heightChange;
}

// ------------------------------------------------------- Comparisons


cmp_t
AvlNode::Compare(long key, cmp_t cmp) const
{
   switch (cmp) {
      case EQ_CMP :  // Standard comparison
         return  myData->Compare(key);

      case MIN_CMP :  // Find the minimal element in this tree
         return  (mySubtree[LEFT] == NULL) ? EQ_CMP : MIN_CMP;

      case MAX_CMP :  // Find the maximal element in this tree
         return  (mySubtree[RIGHT] == NULL) ? EQ_CMP : MAX_CMP;
   }
}

// ------------------------------------------------------- Search/Insert/Delete


Comparable *
AvlNode::Search(long key, AvlNode * root, cmp_t cmp)
{
   cmp_t result;
   while (root  &&  (result = root->Compare(key, cmp))) {
      root = root->mySubtree[(result < 0) ? LEFT : RIGHT];
   }
   return  (root) ? root->myData : NULL;
}


Comparable * AvlNode::Insert(Comparable *   item, AvlNode    * & root)
{
   int  change;
   return  InsertH(item, root, change);
}


Comparable *
AvlNode::Delete(long key, AvlNode * & root, cmp_t cmp)
{
   int  change;
   return  Delete(key, root, change, cmp);
}


Comparable * AvlNode::InsertH(Comparable *   item, AvlNode * & root, int   & change)
{
      // See if the tree is empty
   if (root == NULL) {
         // Insert new node here 
      root = new AvlNode(item);
      change =  HEIGHT_CHANGE;
      return  NULL;
   }

      // Initialize
   Comparable * found = NULL;
   int  increase = 0;

      // Compare items and determine which direction to search
   cmp_t  result = root->Compare(item->Key());
   dir_t  dir = (result == MIN_CMP) ? LEFT : RIGHT;

   if (result != EQ_CMP) {
         // Insert into "dir" subtree 
      found = InsertH(item, root->mySubtree[dir], change);
      if (found)  return  found;   // already here - dont insert
      increase = result * change;  // set balance factor increment
   } else  {   // key already in tree at this node
      increase = HEIGHT_NOCHANGE;
      return  root->myData;
   }

   root->myBal += increase;    // update balance factor 

  // ----------------------------------------------------------------------
  // re-balance if needed -- height of current tree increases only if its
  // subtree height increases and the current tree needs no rotation.
  // ----------------------------------------------------------------------

   change =  (increase && root->myBal)
                  ? (1 - ReBalance(root))
                  : HEIGHT_NOCHANGE;
   return  NULL;
}



Comparable *
AvlNode::Delete(long              key,
                         AvlNode * & root,
                         int                & change,
                         cmp_t                cmp)
{
      // See if the tree is empty
   if (root == NULL) {
         // Key not found
      change = HEIGHT_NOCHANGE;
      return  NULL;
   }

      // Initialize
   Comparable * found = NULL;
   int  decrease = 0;

      // Compare items and determine which direction to search
   cmp_t  result = root->Compare(key, cmp);
   dir_t  dir = (result == MIN_CMP) ? LEFT : RIGHT;

   if (result != EQ_CMP) {
         // Delete from "dir" subtree 
      found = Delete(key, root->mySubtree[dir], change, cmp);
      if (! found)  return  found;   // not found - can't delete
      decrease = result * change;    // set balance factor decrement
   } else  {   // Found key at this node
      found = root->myData;  // set return value

      // ---------------------------------------------------------------------
      // At this point we know "result" is zero and "root" points to
      // the node that we need to delete.  There are three cases:
      //
      //    1) The node is a leaf.  Remove it and return.
      //
      //    2) The node is a branch (has only 1 child). Make "root"
      //       (the pointer to this node) point to the child.
      //
      //    3) The node has two children. We swap items with the successor
      //       of "root" (the smallest item in its right subtree) and delete
      //       the successor from the right subtree of "root".  The
      //       identifier "decrease" should be reset if the subtree height
      //       decreased due to the deletion of the successor of "root".
      // ---------------------------------------------------------------------

      if ((root->mySubtree[LEFT] == NULL) &&
          (root->mySubtree[RIGHT] == NULL)) {
             // We have a leaf -- remove it
         delete  root;
         root = NULL;
         change = HEIGHT_CHANGE;    // height changed from 1 to 0
         return  found;
      } else if ((root->mySubtree[LEFT] == NULL) ||
                 (root->mySubtree[RIGHT] == NULL)) {
            // We have one child -- only child becomes new root 
         AvlNode * toDelete = root;
         root = root->mySubtree[(root->mySubtree[RIGHT]) ? RIGHT : LEFT];
         change = HEIGHT_CHANGE;    // We just shortened the subtree
            // Null-out the subtree pointers so we dont recursively delete
         toDelete->mySubtree[LEFT] = toDelete->mySubtree[RIGHT] = NULL;
         delete  toDelete;
         return  found;
      } else {
            // We have two children -- find successor and replace our current
            // data item with that of the successor
         root->myData = Delete(key, root->mySubtree[RIGHT],
                               decrease, MIN_CMP);
      }
   }

   root->myBal -= decrease;       // update balance factor 

   // ------------------------------------------------------------------------
   // Rebalance if necessary -- the height of current tree changes if one
   // of two things happens: (1) a rotation was performed which changed
   // the height of the subtree (2) the subtree height decreased and now
   // matches the height of its other subtree (so the current tree now
   // has a zero balance when it previously did not).
   // ------------------------------------------------------------------------
   //change = (decrease) ? ((root->myBal) ? balance(root) : HEIGHT_CHANGE)
   //                    : HEIGHT_NOCHANGE ;
   if (decrease) {
      if (root->myBal) {
         change = ReBalance(root);  // rebalance and see if height changed
      } else {
         change = HEIGHT_CHANGE;   // balanced because subtree decreased
      }
   } else {
      change = HEIGHT_NOCHANGE;
   }

   return  found;
}

// --------------------------------------------------------------- Verification
/*
template <class long>
int
AvlNode::Height() const {
   int  leftHeight  = (mySubtree[LEFT])  ? mySubtree[LEFT]->Height()  : 0;
   int  rightHeight = (mySubtree[RIGHT]) ? mySubtree[RIGHT]->Height() : 0;
   return  (1 + MAX(leftHeight, rightHeight));
}

template <class long>
int
AvlNode::Check() const {
   int  valid = 1;

      // First verify that subtrees are correct
   if (mySubtree[LEFT])   valid *= mySubtree[LEFT]->Check();
   if (mySubtree[RIGHT])  valid *= mySubtree[RIGHT]->Check();

      // Now get the height of each subtree
   int  leftHeight  = (mySubtree[LEFT])  ? mySubtree[LEFT]->Height()  : 0;
   int  rightHeight = (mySubtree[RIGHT]) ? mySubtree[RIGHT]->Height() : 0;

      // Verify that AVL tree property is satisfied
   int  diffHeight = rightHeight - leftHeight;
   if (LEFT_IMBALANCE(diffHeight) || RIGHT_IMBALANCE(diffHeight)) {
      valid = 0;
      cerr << "Height difference is " << diffHeight
           << " at node " << Key() << endl;
   }

      // Verify that balance-factor is correct
   if (diffHeight != myBal) {
      valid = 0;
      cerr << "Height difference " << diffHeight
           << " doesnt match balance-factor of " << myBal
           << " at node " << Key() << endl;
   }

      // Verify that search-tree property is satisfied
   if ((mySubtree[LEFT])
            &&
       (mySubtree[LEFT]->Compare(Key()) == MIN_CMP)) {
      valid = 0;
      cerr << "Node " << Key() << " is *smaller* than left subtree"
           << mySubtree[LEFT]->Key() << endl;
   }
   if ((mySubtree[RIGHT])
            &&
       (mySubtree[RIGHT]->Compare(Key()) == MAX_CMP)) {
      valid = 0;
      cerr << "Node " << Key() << " is *greater* than right subtree"
           << mySubtree[RIGHT]->Key() << endl;
   }

   return  valid;
}
*/
//----------------------------------------------- Routines for dumping the tree
/*
static inline ostream &
Indent(ostream & os, int len) {
   for (int i = 0; i < len; i++) {
      os << ' ';
   }
   return  os;
}

enum TraversalOrder { LTREE, KEY, RTREE };

template <class long>
static void
Dump(ostream & os,
     TraversalOrder order,
     const AvlNode * node,
     int level=0)
{
    unsigned  len = (level * 5) + 1;
    if ((order == LTREE) && (node->Subtree(LEFT) == NULL)) {
       Indent(os, len) << "     **NULL**" << endl;
    }
    if (order == KEY) {
       Indent(os, len) << node->Key() << ":" << node->Bal() << endl;
    }
    if ((order == RTREE) && (node->Subtree(RIGHT) == NULL)) {
       Indent(os, len) << "     **NULL**" << endl;
    }
}

template <class long>
static void
Dump(ostream & os, const AvlNode * node, int level=0)
{
   if (node == NULL) {
      os << "***EMPTY TREE***" << endl;
   } else {
      Dump(os, RTREE, node, level);
      if (node->Subtree(RIGHT)  !=  NULL) {
         Dump(os, node->Subtree(RIGHT), level+1);
      }
      Dump(os, KEY, node, level);
      if (node->Subtree(LEFT)  !=  NULL) {
         Dump(os, node->Subtree(LEFT), level+1);
      }
      Dump(os, LTREE, node, level);
   }// if non-empty tree
}

template <class long>
void
AvlTree<long>::DumpTree(ostream & os) const {
   Dump(os, myRoot);
}*/


long * AvlNode:: bsf (AvlNode * root,int &size){
    
    int counter=0;
    AvlNode * temp;
    queue<AvlNode *> q;
    q.push(root);
    while(!(q.empty())){
                        temp=q.front();
                        
                         
                         if(temp != NULL){
                                  q.push(temp->mySubtree[LEFT]);
                                  q.push(temp->mySubtree[RIGHT]);
                                  long a=temp->myData->Key();
                                  values[counter]=a;
                                  }     
                                  
                          else values[counter]=-1000;
                          counter++;                  
                        
                        q.pop();
                        }
						
                        size=counter;
						return values;
}

void AvlNode::postOrder(AvlNode *root,int &size,long *array)
{
	if(root==NULL)return;
	postOrder(root->mySubtree[LEFT],size,array);
	postOrder(root->mySubtree[RIGHT],size,array);
	
	array[size]=root->myData->Key();
    size++;


}

void AvlNode::preOrder(AvlNode *root,int &size,long *array)
{
	if(root==NULL)return;
	array[size]=root->myData->Key();
	size++;
	
	preOrder(root->mySubtree[LEFT],size,array);
	preOrder(root->mySubtree[RIGHT],size,array);
}

void AvlNode::inOrder(AvlNode *root,int &size,long *array)
{

	if(root==NULL)return;
	inOrder(root->mySubtree[LEFT],size,array);
	 array[size]=root->myData->Key();
	 size++;
	 inOrder(root->mySubtree[RIGHT],size,array);
}
#endif  /* AVL_H */
