#include <iostream>
#include "map.cpp"

// ad hoc class to test SortedLisd of Point

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

// ad hoc class to test Map

class Course{

private:
  const int code;
  const char* const name;

public:
  Course(int code, const char* name)
    : code(code), name(name){}

  int getCode() const {return code;}
  const char* getName() const {return name;}
};

std::ostream& operator<<(std::ostream& o, const Course& c){
  return o << "Course " << c.getCode() << ": " << c.getName();
}

class Textbook{
private:
  const int id;
  const char* const title;

public:
  Textbook(int id, const char* title)
    : id(id), title(title){}

  int getId() const{return id;}
  const char* getTitle() const {return title;}
};

std::ostream& operator<<(std::ostream& o, const Textbook& tb){
  return o << "Textbook " << tb.getId() << ": " << tb.getTitle();
}

// courseComparer for use in template argument
int courseComparer(const Course* const& a, const Course* const& b){
  return a->getCode() - b->getCode();
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

  std::cout << "===========================\n";
  std::cout << "Testing Map                \n";
  std::cout << "===========================\n\n";

  Course* oo = new Course(517, "OO Design & Prog");
  Course* cs = new Course(515, "Computer Systems");
  Course* lg = new Course(518, "Logic");

  Textbook* ps = new Textbook(11, "Problem Solving w/ C++");
  Textbook* ca = new Textbook(33, "Computer Architecture");
  Textbook* mc = new Textbook(55, "Modern C++");

  Map<const Course*, Textbook*, courseComparer> ctm;
  ctm.insert(oo, ps);
  ctm.insert(cs, ca);

  Textbook** result = ctm.get(oo);
  std::cout << "[" << result << "]" << **result << '\n';
  
  return 0;
}
