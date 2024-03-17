#include <iostream>

void testNoExcept() noexcept {
    std::cout << "testNoExcept() is called" << std::endl;
}

void testNoExcept2()  {
    // 这行代码会抛出一个异常
    throw std::runtime_error("这是一个异常");
}

/**
 * 关键字noexcept
 * 可以使用 noexcept 关键字来表明一个函数不会抛出异常。
 * 如果函数在运行时抛出异常，那么程序将会崩溃。
 * @return
 */
int main() {
    testNoExcept();
    try {
        //抛出异常测试
        testNoExcept2();
    } catch (const std::exception& e) {
        std::cout << "An exception was thrown: " << e.what() << std::endl;
    }

    return 0;
}