/**
  数组名在大多数表达式中自动转换为指向其首元素的指针
  但是有以下两个例外，数组不会自动转换为指针：
    sizeof(arr)：返回整个数组大小（单位是字节）
    &arr：返回的是整个数组的地址，类型是 int (*)[5]
*/

#include "stdio.h"

void printArray(int arr[], int size) {  // 等同于 (int *arr, int size) ,接收到的其实就是 arr 的首地址（即指向 int 的指针）
  printf("arr size %d \n", sizeof(arr)); // 在函数体内 sizeof(arr) 得到的是指针大小（不是数组大小）。
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]); 
    printf("%d  \n", *(arr+i) ); // 数组名arr 当作指针使用
  }
}


void main(){
  int myArray[5] = {10, 20, 30, 40, 50};
  int * ptr = myArray; // 相当于 int *ptr = &myArray[0]

  printf("myArray size %d \n", sizeof(myArray));
  printf("ptr size %d \n", sizeof(ptr));

  printArray(myArray, 5);
  printf("\n------------\n");
  printArray(ptr, 5);
}