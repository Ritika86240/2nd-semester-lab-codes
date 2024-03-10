// input array of n elements double size of array and make all elements zero except last element
// 0 0 0 0 0 0 0 0 0 9
#include<stdio.h>
void show(int a[], int n) { // display function
    for(int i=0; i<n; i++) { // loop to display the array
        printf("%d ", a[i]); 
    }
}
void elementsdouble(int a[], int n) {
    for(int i=n; i<2*n; i++) {
        a[i]=0;
    }
    a[2*n-1]=a[n-1];
    for(int i=0; i<n; i++) {
        a[i]=0;
    }
}
int main() {
    int n, arr[1000];
    printf("Enter the number of elements :\n");
    scanf("%d", &n);
    printf("Enter %d elements :\n", n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]); 
    }
    elementsdouble(arr, n);
    printf("Array after doubling the size and making all elements zero except last element is :\n");
    show(arr, 2*n);
    return 0;
}