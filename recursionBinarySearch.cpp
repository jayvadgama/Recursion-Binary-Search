// -- Advanced sorting --

#include <iostream>
using namespace std;

void merge(int a[], int low, int high, int mid){
	
  int i, j, k, c[50];
	i = low;
	k = low;
	j = mid + 1;

  // Both arrays not empty
	while(i <= mid && j <= high){
		if(a[i] < a[j]){
			c[k] = a[i];
			k++;
			i++;
		}
		else{
			c[k] = a[j];
			k++;
			j++;
		}
	}
  // Second array empty
	while(i <= mid){
		c[k] = a[i];
		k++;
		i++;
	}
	while(j <= high){
		c[k] = a[j];
		k++;
		j++;
	}
	for(i = low; i < k; i++){
		a[i] = c[i];
	}
}

int mergesort(int a[], int low, int high){
	
  int mid;
  
  //while we have more than 2 elements
	if(low < high){
      mid = (low + high)/2;
      mergesort(a, low, mid);
      mergesort(a, mid + 1, high);
      
    // Marks first and second array
      merge(a, low, high, mid);
		}
		return 0;
}

int main() {
	
  int a[2], i;
	
  cout << "Enter the elements:" << endl;
	
  for(i = 0; i < 5 ; i++){
		cin >> a[i];
	}
  
	mergesort(a, 0, 4);
	
  cout << "\nSorted array\n";
	
  for(i = 0;i < 5; i++){
		cout << a[i];
		cout << " ";
	}
	
  return 0;
}