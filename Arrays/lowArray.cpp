//demonstrate class with low-level interface

#include <iostream>
#include <vector>

using namespace std;

class LowArray{

private:
  vector<double> v;

public:

  // Constructor pass in size when creating object
  LowArray(int max){
    v.resize(max);
  }

  // Set value pass the index and the value
  void setElem(int index, double value){
    v[index] = value;
  }

  // Get element from vector at array index
  double getElem(int index){
    return v[index];
  }
};// end of class

  int main(){
    // instantiate object
    LowArray arr(100);
    int nElems = 0;
    int i;

    arr.setElem(0, 77);
    arr.setElem(1, 89);
    arr.setElem(2, 99);
    arr.setElem(3, 45);
    arr.setElem(4, 26);
    arr.setElem(5, 55);
    arr.setElem(6, 78);
    arr.setElem(7, 93);
    arr.setElem(8, 84);
    arr.setElem(9, 32);

    nElems = 10;

    // Print out elements of the array
    for (i=0; i<nElems; i++)
      cout << arr.getElem(i) << " ";
    cout << endl;

    int searchKey = 26;

    // Search array for key
    for (i=0; i<nElems; i++)
      if (arr.getElem(i) == searchKey)
	break;

    // Print to terminal whether the element exists
    if (i == nElems){
      cout << "Can't find " << searchKey << endl;
    }
    else{
	cout << "Found " << searchKey << endl;
    }
    
    double deleteKey = 55; 
    cout << "Deleting element " << deleteKey << endl;

    // Find element to delete
    for (i=0; i<nElems; i++)
      if (arr.getElem(i) == deleteKey)
	break;

    // 'i' will now represent the index to be deleted
    // now setting 'k' = 'i'
    // and shift the array back overwriting 'i' and each subsequent position with its successor
    for (int k=i; k<nElems; k++)
      arr.setElem(k, arr.getElem(k+1));
    nElems--;

    // Display Items to view resulting operation
    for (i=0; i<nElems; i++)
      cout << arr.getElem(i) << " ";
    cout << endl;

    return 0;
  
}
