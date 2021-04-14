#include<climits>
#include "sortedlist.cpp"

template<class TKey, class TVal,
	 int (*keyComp)(TKey const& a, TKey const& b) = simpleCompare>
class Map{
  struct KVP{
    TKey key;
    TVal val;

    KVP(TKey key) : key(key){};
    KVP(TKey key, TVal val) : key(key), val(val){};

    static int comp(KVP* const& a, KVP* const& b){
      return keyComp(a->key, b->key);
    }
  }; // end KVP

  SortedList<KVP*, KVP::comp> base;

  // rely on inherited function to locate index
  int locate(const TKey& key) const{
    KVP dummy(key);
    return base.indexOf(&dummy); // SortedList only takes KVP hence a dummy is required
  }

public:
  void insert(const TKey& key, const TVal& val){
    int idx = locate(key);
    if(idx==-1) base.add(new KVP(key, val)); // again note that add() takes only KVP as argument
    else base.get(idx)->val = val;
  }

  TVal* get(const TKey& key) const{
    int idx = locate(key);
    if(idx==-1) return nullptr;
    return &(base.get(idx)->val); // return member val of KVP
  }

  bool remove(const TKey& key){
    int idx = locate(key);
    if(idx == -1) return false; // cannot locate index
    delete base.get(idx);
    base.removeAt(idx);
    return true;
  }

  // virtual destructor
  virtual ~Map(){
    for(int i =0; i < base.getCount(); i++){
      delete base.get(i);
    }
  }
  

  
};
