//
// Created by eagle on 2022/4/18.
//

#include <iostream>

using namespace std;

int main() {
    // 定义简单的lambda表达式
    auto basicLambda = [] { cout << "Hello, world!" << endl; };
    basicLambda();
    // 指明返回类型
    auto add = [](int a, int b) -> int { return a + b; };
    // 自动推断返回类型
    auto multiply = [](int a, int b) { return a * b; };
    int sum = add(2, 5);   // 输出：7
    int product = multiply(2, 5);  // 输出：10
    cout << "sum " << sum << " product " << product << endl;
    int i = 1024;
    auto func = [=] {  // [=] 表明将外部的所有变量拷贝一份到该Lambda函数内部
        cout << i << endl;
    };
    func();
    int j = 2048;
    cout << "i:" << &i << endl;
    cout << "j:" << &j << endl;
    auto fun1 = [=, &i] { // 默认拷贝外部所有变量，但引用变量 i
        cout << "i:" << &i << endl;
        cout << "j:" << &j << endl;
    };
    fun1();
}