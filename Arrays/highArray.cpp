//highArray.cpp
// higher level interface

#include <iostream>
#include <vector>

using namespace std;

class HighArray{

private:
  vector<double> v;
  int nElems;

public:
  // default constructor
  // the colon after the constructor is used initialize the private data nElems
  HighArray() : nElems(0){
  }
  
  // 1 argument constructor also passing the size of the vector
  HighArray(int max) : nElems(0){
    v.resize(max);
  }

  // find specified value
  bool find(double searchKey){
    int i;

    // move through array stop if element found
    // if the entire array has been searched item does not exist
    for (i=0; i<nElems; i++)
      if (v[i] == searchKey)
	break;
    if (i == nElems)
      return false;
    else
      return true;
  }

  // insert item into array
  // increment array by 1
  void insert(double value){
    v[nElems] = value;
    nElems++;
  }

  // delete element from array
  bool remove(double value){
    int i;

    for (i=0; i<nElems; i++)
      if (value == v[i])
	break;
    if (i == nElems)

      return false;
    else{

      for (int k=i; k<nElems; k++)
	v[k] = v[k+1];
      nElems--;
      return true;
    }
  }

  // display array
  void display(){
    for (int i=0; i<nElems; i++)
      cout << v[i] << " ";
    cout << endl;
  }
};

int main(){

  int maxSize = 100;
  HighArray arr(maxSize);

  arr.insert(77);
  arr.insert(99);
  arr.insert(44);
  arr.insert(55);
  arr.insert(78);
  arr.insert(34);
  arr.insert(67);
  arr.insert(58);
  arr.insert(46);
  arr.insert(93);

  arr.display();

  int searchKey = 35;
  if (arr.find(searchKey))
    cout << "Found " << searchKey << endl;
  else
    cout << "Can't find " << searchKey << endl;

  cout << "Deleting 67, 55, and 99" << endl;

  arr.remove(67);
  arr.remove(55);
  arr.remove(99);

  arr.display();
  return 0;
  
}
