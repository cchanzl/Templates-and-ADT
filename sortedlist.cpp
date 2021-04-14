#include <iostream>
#include <climits>
#include "extarray.cpp"

// simpleCompare as a default comparison function
template<class T>
int simpleCompare(const T& a, const T& b){
  return a < b ? -1 : a==b ? 0 : 1;
}


// SortedList is a template that inherits from ExtendableArray
template<class T,
	 int (*comp)(const T& a, const T& b) = simpleCompare, // function object
	 const int MAXCAP = INT_MAX>
class SortedList: private ExtendableArray<T, MAXCAP>{
private:
  using Base = ExtendableArray<T>; // alias for parent class
  const T error_value;

  int locate(T value) const {
    int head = 0, tail = getCount(); // getCount() from parent class
    while(head < tail){
      int mid = (head+tail)/2;
      int cp = comp((*this)[mid], value); // using compare function from template argument
      if(cp<0) head = mid+1;
      else if (cp==0) return mid;
      else tail=mid;
    }
    return head;
  }

public:
  int indexOf(T value) const{
    int index = locate(value);
    if(index<getCount()){
      int cp = comp((*this)[index], value);
      if(cp==0) return index; // return index if items are equal
    }
    return -1;
  }

  // constructor
  SortedList(int cap = 10, const T ev = 0)
    : Base(cap), error_value(ev){}

  using Base::getCount;

  void add (T value) {this->insert(value, locate(value));}

  bool removeAt(int index) {return Base::remove(index);}

  T get(int index) const {
    if(0 <= index && index < getCount()) return (*this)[index];
    return error_value;
  }

  void print(){
    std::cout << "{";
    if(getCount() >0){
      std::cout << get(0);
      for ( int i = 1; i < getCount(); i++){
	std::cout << "," << get(i);
      }
    }
    std::cout << "}" << '\n';
  }

};
