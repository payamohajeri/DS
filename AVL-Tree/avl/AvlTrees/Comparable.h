// <plaintext>
#ifndef COMPARABLE_H
#define COMPARABLE_H



// cmp_t is an enumeration type indicating the result of a
// comparison.
//     NOTE: I would place this inside the Comparable class but 
//           when I do, g++ complains when I use cmp_t. Even
//           when I prefix it with Comparable:: or Comparable<long>::
//           (If you can get this working please let me know)
//
enum  cmp_t {
   MIN_CMP = -1,   // less than
   EQ_CMP  = 0,    // equal to
   MAX_CMP = 1     // greater than
};

// Class "Comparable" corresponds to an arbitrary comparable element
// with a keyfield that has an ordering relation. The template parameter
// long is the "type" of the keyfield
//

class Comparable {
private:
   long  myKey;

public:
   Comparable(long  key) : myKey(key) {};

   // Use default copy-ctor, assignment, & destructor

      // Compare this item against the given key & return the result
   cmp_t Compare(long  key) const {
      return (key == myKey) ? EQ_CMP
                            : ((key < myKey) ? MIN_CMP : MAX_CMP);
   }

     // Get the key-field of an item
   long Key() const { return  myKey; }

     // Print on output stream
  /* ostream &
   Print(ostream & os) const { 
      os << myKey;
      return  os;
   }*/
};
/*
template <class long>
inline ostream & operator<<(ostream & os, Comparable<long> item) {
   return  item.Print(os);
}*/

#endif  /* COMPARABLE_H */
