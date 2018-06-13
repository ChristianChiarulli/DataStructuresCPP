#include <iostream>

using namespace std;

int main(){

  int arr[100];
  int nElems = 0;
  int j;
  int searchKey;

  arr[0] = 77;
  arr[1] = 89;
  arr[2] = 9;
  arr[3] = 00;
  arr[4] = 34;
  arr[5] = 45;
  arr[6] = 32;
  arr[7] = 88;
  arr[8] = 43;
  arr[9] = 78;
  nElems = 10;

  for (j=0; j<nElems; j++)
    cout << arr[j] << " ";
  cout << endl;

  searchKey = 78;
  for (j=0; j<nElems; j++)
    if(arr[j] == searchKey)
      break;

  if(j == nElems){
    cout << "Can't find " << searchKey << endl;
  }
    else{
    cout << "Found " << searchKey << endl;
    }
    
  searchKey = 43;
  cout << "Deleting " << searchKey << endl;
  for (j=0; j<nElems; j++)
    if (arr[j] == searchKey)
      break;
  for (int k=j; k<nElems; k++)
    arr[k] = arr[k+1];
  nElems--;

  for (j=0; j<nElems; j++)
    cout << arr[j] << " ";

  cout << endl;

  return 0;
}
  
