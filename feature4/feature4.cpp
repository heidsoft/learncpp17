//
// Created by Jake liu on 2024/3/17.
//
class MyClass {
public:
    MyClass(int value) : m_value(value) {}

private:
    int m_value;
};

/**
 * 定义了一个MyClass类，它有一个构造函数，接受一个整数参数。
 * 然后，我们定义了两个函数createMyClass和createMyClassExplicit，
 * 分别用于创建MyClass对象。
 * 其中，createMyClass函数没有使用explicit关键字，
 * 允许隐式转换；
 * 而createMyClassExplicit函数使用了explicit（明确的）关键字，
 * 不允许隐式转换。
 * @param value
 * @return
 */

// 允许隐式转换
MyClass createMyClass(int value) {
    return MyClass(value);
}

// 不允许隐式转换
MyClass createMyClassExplicit(int value) {
    return explicit MyClass(value);
}

int main() {
    MyClass obj1 = createMyClass(10);
    MyClass obj2 = createMyClassExplicit(10);

    return 0;
}