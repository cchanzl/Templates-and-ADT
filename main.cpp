#include <iostream>
#include "extarray.cpp"

int main(){

  /**************************
   *
   *   Test ExtendableArray
   *
   **************************/

  ExtendableArray<char, 8> array(1);
  array.append('a');
  array.print();

  array.append('b');
  array.print();

  array.append('c');
  array.print();

  array.append('d');
  array.print();

  array.append('e');
  array.print();

  array.append('f');
  array.print();

  array.append('g');
  array.print();

  array.insert('X', 5);
  array.print();

  array.insert('Z', 2);
  array.print();
  
  array.remove(7);
  array.print();
  
  array.remove(-3);  
  array.print();

  /**************************
   *
   *   Test ExtendableArray
   *
   **************************/


  
  return 0;
}
