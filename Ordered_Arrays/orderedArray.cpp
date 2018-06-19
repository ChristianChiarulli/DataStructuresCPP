//demonstrates ordered array class

#include <iostream>
#include <vector>

using namespace std;

class OrdArray{

private:
  vector<double> v;
  int nElems;

public:

  // constructor
  OrdArray(int max) : nElems(0){
    v.resize(max);
  }

  // gets the size of the array
  int getSize(){
    return nElems;
  }

  // returns index given the value (no duplicates)
  int find(double searchKey){
    int lowerBound = 0;
    int upperBound = nElems-1;
    int currIndex;

    while(true){
      currIndex = (lowerBound + upperBound) / 2;
      if (v[currIndex]==searchKey)
	return currIndex;            // found it
      else if (lowerBound > upperBound)
	return nElems;               // can't find it
      else{                          // divide range
	if (v[currIndex] < searchKey)
	  lowerBound = currIndex + 1; // it's in the upper half
	else
	  upperBound = currIndex - 1;
      }
    }
  }

  // insert element into array
  void insert(double value){
    int i;
    for (i=0; i<nElems; i++)        // find where the element goes
      if(v[i] > value)              // linear search
	break;
    for (int k=nElems; k>i; k--)
      v[k] = v[k-1];
    v[i] = value;                   // insert element
    nElems++;                       // increment size
  }

  // searches for element and removes it if it exists
  bool remove(double value){
    int i = find(value);
    if (i == nElems)               // can't find it
      return false;
    else{                           // found it
      for (int k=i; k<nElems; k++)  // move bigger ones down
	v[k] = v[k+1];
      nElems--;                     // decrement size
      return true;
    }
  }

  // display the array
  void display(){
    for (int i=0; i<nElems; i++)
      cout << v[i] << " ";
    cout << endl;
  }
};

int main(){

  int maxSize = 100;
  OrdArray arr(maxSize);

  // insert elements
  arr.insert(77);
  arr.insert(99);
  arr.insert(44);
  arr.insert(55);
  arr.insert(22);
  arr.insert(88);
  arr.insert(11);
  arr.insert(00);
  arr.insert(66);
  arr.insert(33);

  int searchKey = 55;

  if (arr.find(searchKey) != arr.getSize())
    cout << "Found " << searchKey << endl;
  else
    cout << "Can't find " << searchKey << endl;

  arr.display();

  cout << "Deleting 0, 55, and 99" << endl;
  arr.remove(00);
  arr.remove(55);
  arr.remove(99);

  arr.display();
  return 0;
}
