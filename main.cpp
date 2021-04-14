#include <iostream>
#include "sortedlist.cpp"

struct Point{
  int x, y;

  Point (int x = 0, int y = 0) : x(x), y(y){};

  static int compare(const Point& a, const Point &b){
    int comp = a.x - b.x;
    if(comp!=0) return comp;
    return a.y - b.y; // if x is 0, check y. else x takes precedence
  }
};

std::ostream& operator<<(std::ostream& o, const Point& p){
  return o << "P[" << p.x << "," << p.y << "]";
}


int main(){

  std::cout << "=======================\n";
  std::cout << "Testing ExtendableArray\n";
  std::cout << "=======================\n\n";

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

  std::cout << std::endl;
  
  std::cout << "=======================\n";
  std::cout << "Testing SortedList     \n";
  std::cout << "=======================\n\n";

  SortedList<char> sl(10, '@');
  sl.add('c');
  sl.print();

  sl.add('e');
  sl.print();

  sl.add('a');
  sl.print();

  sl.add('b');
  sl.print();

  sl.add('d');
  sl.print();

  sl.add('c');
  sl.print();

  std::cout << sl.get(7) << '\n';

  sl.removeAt(1);
  sl.removeAt(4);
  sl.removeAt(0);
  sl.print();

  std::cout << std::endl;
  
  std::cout << "===========================\n";
  std::cout << "Testing Template Functions \n";
  std::cout << "===========================\n\n";

  SortedList<Point, Point::compare> slp; // add comp to be from Point
  slp.add(Point(3,2));
  slp.print();

  slp.add(Point(2,1));
  slp.print();

  slp.add(Point(2,3));
  slp.print();

  std::cout << slp.get(3) << '\n';

  return 0;
}
