#include <iostream>

template<class T, const int MAXCAP = INT_MAX>
class ExtendableArray{
private:
  int count, capacity;

  T* store;

  void resizeStore(){
    T* new_store = new T[capacity];
    for ( int i = 0; i < count; i++) new_store[i] = store[i];
    delete[] store;  // deallocate old store
    store = new_store;
  }

public:
  // constructor
  ExtendableArray(int cap = 10): ount(0){
    if ( cap < 0 )cap = 0;
    else if (cap > MAXCAP) cap = MAXCAP;
    capacity = cap;
    store = new T[cap];
  }

  // virtual destructor
  virtual ~ExtendableArray(){
    delete[] store;
  }

  int getCount() const{
    return count;
  }

  int getCapacity() const{
    return capacity;
  }

  T& operator[](int index){
    return store[index];
  }

  bool ensureCapacity(int cap){
    if (cap>MAXCAP) return false;

    if (capacity<cap){
      while(capacity<cap){
	if(capacity<MAXCAP/2) (capacity *= 2)++;
      	else {
	  capacity = MAXCAP;
	  break;
	}
      }
      resizeStore();
    }
    return true;
  }

  bool insert(T value, int index){
    if(index<0) return false;
    int new_count;
    if(index>count) new_count = index; // if index is larger than array size, set count as index
    else new_count = count;
    new_count++;
    if(!ensureCapacity(new_count)) return false; // unable to expand beyond MAXCAP

    for(int i=count; i > index; i--){
      store[i] = store[i-1];  // shift all elements after index one to the right
    }

    store[index] = value;
    count = new_count;
    return true;
  }

  bool append(T value){
    return insert(value, count); // insert at the end
  }

  bool remove(int index){
    if(index<0 or index>count)return false; // incorrect index position

    for(int i = index+1; i < count; i++){
      store[i-1] = store[i]; // shift all elements after index to the left
    }
    count--;
    return true;    
  }
 
};
