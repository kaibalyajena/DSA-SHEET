# include <iostream>
using namespace std;

//by shifting
//tc 0(n)
//sc 0(1)
void rotate(int arr[], int n)
{
    int x = arr[n - 1], i;
    for (i = n - 1; i > 0; i--){
        arr[i] = arr[i - 1];
    }
    arr[0] = x;
}


//by using 2 pointers
//tc 0(n)
//sc 0(1)
void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}
void rotate(int arr[], int n)
{
  int i = 0, j = n - 1;
  while(i != j)
  {
    swap(&arr[i], &arr[j]);
    i++;
  }
}

//by reversal approach
//reverse n-1 elements of the array and then reverse the entire array
//tc 0(n)
//sc 0(1)
// int main()
// {
//     int arr[] = { 1,2,3,4,5};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int k = 1; //No. of rotations
//     int i, j;
     
//     cout << "Given array is \n";
//     for (i = 0; i < n; i++)
//         cout << arr[i] << " ";
         
     
//     // Reverse the first n-1 terms
//     for (i = 0, j = n - k - 1; i < j; i++, j--) {
//         int temp = arr[i];
//         arr[i] = arr[j];
//         arr[j] = temp;
//     }
//     // Reverse the entire array
//     for (i = 0, j = n - 1; i < j; i++, j--) {
//         int temp = arr[i];
//         arr[i] = arr[j];
//         arr[j] = temp;
//     }
 
//     cout << "\nRotated array is\n";
//     for (i = 0; i < n; i++)
//         cout << arr[i] << " ";
 
//     return 0;
// }
 

int main()
{
    int arr[] = {1, 2, 3, 4, 5}, i;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Given array is \n";
    for (i = 0; i < n; i++)
        cout << arr[i] << ' ';
    rotate(arr, n);
    cout << "\nRotated array is\n";
    for (i = 0; i < n; i++)
        cout << arr[i] << ' ';
    return 0;
}