// <plaintext>
//
// AvlTest.cc -- C++ source file to test the AVL Tree Class Library
//

//#include        <stdlib.h>
#include        <iostream>
#include        "Avl.h"
#include <vector>
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
      
    AvlTree tree;
    Comparable * found = NULL;
    Comparable value(10);
    vector< Comparable > values;
    int  i;
    int size;
	int count;
	int preSize;
	int inSize;
	long inOrder[100];
	long toPayam2[100];
	long preOrder[100];
    for(i=0;i<10;i++) {
                      Comparable myComp(i);
                      values.push_back( myComp);
                      }
   // for (i = 0 ; i <10;i++){// NUM_ELEMENTS(TestVals) ; i++)  {
      // cout << "+++ inserting key #" << i+1<<endl ;//<< ": " << TestVals[i] << endl;
      for(i=0;i<10;i++){
                        
                         found = tree.Insert(&(values[i]));//&TestVals[i]);
                         
                         if (found) 
                         cout << "\t(already in tree)\n";
       }
       
        long * toPayam= tree.bsf(size);
		tree.postOrder(count,toPayam2);
		tree.preOrder(preSize,preOrder);
		tree.inOrder(inSize,inOrder);
		
		
        cout<<"sldfjsldf"<<endl;
        for(i=0;i<inSize;i++)  cout<<inOrder[i]<<endl;
       //VerifyTree(tree);
   // }/* for */

   // for (i = 0 ; i < NUM_ELEMENTS(TestVals) ; i++)  {
     //  cout << "+++ searching for key #" << i+1 << ": " << TestVals[i] << endl;
       found = tree.Search(1);
       if (! found) {
          cout << "\t(not found in tree)\n";
       }
       else cout<<" foung";
      /* VerifyTree(tree);
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
    cin>>i;
    return  0;
}/* main */

