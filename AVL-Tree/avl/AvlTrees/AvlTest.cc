// <plaintext>
//
// AvlTest.cc -- C++ source file to test the AVL Tree Class Library
//

//#include        <stdlib.h>
#include        <iostream>
#include        "Avl.h"
using namespace std;
//#include        "TestVals.h"

/*void VerifyTree(AvlTree<long> & tree) {
   if (! tree.Check()) {
      tree.DumpTree(cout);
      exit(2);
   }
}*/

main()
{
    AvlTree<long> tree;
    Comparable<long> * found = NULL;
    Comparable<long> value(10);
    int  i;
   // for (i = 0 ; i <10;i++){// NUM_ELEMENTS(TestVals) ; i++)  {
      // cout << "+++ inserting key #" << i+1<<endl ;//<< ": " << TestVals[i] << endl;
       found = tree.Insert(&value);//&TestVals[i]);
       if (found) {
          cout << "\t(already in tree)\n";
       }
       
      
       //VerifyTree(tree);
   // }/* for */

   /* for (i = 0 ; i < NUM_ELEMENTS(TestVals) ; i++)  {
       cout << "+++ searching for key #" << i+1 << ": " << TestVals[i] << endl;
       found = tree.Search(TestVals[i].Key());
       if (! found) {
          cout << "\t(not found in tree)\n";
       }
       VerifyTree(tree);
    }

    for (i = 0 ; i < NUM_ELEMENTS(DelVals) ; i++)  {
       cout << "+++ deleting key #" << i+1 << ": " << DelVals[i] << endl;
       found = tree.Delete(DelVals[i]);
       if (! found) {
          cout << "\t(not found in tree)\n";
       }
       VerifyTree(tree);
    } 

    cout << endl << "Deallocating tree ..." << endl;
    while (! tree.IsEmpty()) {
       found = tree.Delete(0, MAX_CMP);
       if (! found) {
          cout << "+++ max element not found in tree +++\n";
       } else {
          cout << "+++ deleted max element " << found->Key() << " +++\n";
       }
       delete found;
       VerifyTree(tree);
    }*/
    cout << "DONE!" << endl;
    return  0;
}/* main */

