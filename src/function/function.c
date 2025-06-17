#include <stdio.h>

// ✅ 使用 typedef 定义函数指针类型
typedef int (*OperationFunc)(int, int);           // 运算函数指针类型
typedef void (*CallbackFunc)(int result);         // 回调函数类型

// ✅ 各种运算函数
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divide(int a, int b) {
    return b != 0 ? a / b : 0;
}

// ✅ 回调函数：打印结果
void print_result(int result) {
    printf("\nCallback: Result is %d\n", result);
}

// ✅ 计算函数：接受两个操作数、一个运算函数指针、一个回调函数指针
void calculate(int a, int b, OperationFunc op, CallbackFunc cb) {
    int result = op(a, b);  // 调用运算函数
    if (cb) {
        cb(result);         // 回调处理
    }
}

int main() {
    OperationFunc op = &mul;                       // 定义函数指针变量 &可以省略，函数名会自动“退化”成函数地址
    CallbackFunc cb = print_result;
    CallbackFunc cb1 = cb;                        // 函数指针赋值给同类型函数指针
    // CallbackFunc cb2 =  &cb; 错误写法，不能对指针再次取地址

    // ✅ 使用函数名和函数指针都可以
    calculate(10, 5, add, print_result);          // 直接传函数名
    calculate(20, 4, &sub, cb);                   // 使用 &函数名 也是可以的
    calculate(3, 7, op, cb1);                      // 传函数指针变量
    calculate(8, 0, divide, NULL);                // 没有回调，也可以传 NULL

    return 0;
}
