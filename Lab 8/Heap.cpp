#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root) {
   int largest = root;  // Initialize largest as root
   int left = 2*root + 1;  // left child
   int right = 2*root + 2;  // right child
 
   // If left child is larger than root
   if (left < n && arr[left] > arr[largest])
      largest = left;
 
   // If right child is larger than largest so far
   if (right < n && arr[right] > arr[largest])
      largest = right;
 
   // If largest is not root
   if (largest != root){
      swap(arr[root], arr[largest]);

      // Recursively heapify the affected sub-tree
      heapify(arr, n, largest);
   }
}

 
void heapSort(int arr[], int n) {
   // Build heap
   for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
 
   // Extracting elements from heap one by one
   for (int i = n - 1; i >= 0; i--) {
      // Move current root to end
      swap(arr[0], arr[i]);
 
      // call heapify on the reduced heap
      heapify(arr, i, 0);
   }
}

  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main() {
   int n;
   cout << "Enter the size of the array: ";
   cin >> n; // input the size of an array
   int heap_arr[n]; 

   // input the array
   cout << "Enter elements: ";
   for (int i = 0; i < n; i++) {
      cin >> heap_arr[i];
   }

   cout<<"Input array"<<endl;
   displayArray(heap_arr,n); // Display the input array
  
   heapSort(heap_arr, n); // sort the array using heap sort
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n); // Display the sorted array
}
