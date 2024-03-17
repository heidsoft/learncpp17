#include <iostream>
#include <sstream>
using  namespace std;

enum MySQLType: uint8_t {
    /* Note: During recovery we don't have the compression type
     because the .frm file has not been read yet. Therefore
     we write the recovered pages out without compression.
     注意：在恢复期间我们没有压缩类型
     因为.frm文件还没有被读取。所以
     我们在不压缩的情况下写出恢复的页面。
     */
    /** No compression */
    NONE = 0,

    /** Use ZLib */
    ZLIB = 1,

    /** Use LZ4 faster variant, usually lower compression. */
    LZ4 = 2
};


std::string MySQLTypeToString(MySQLType type) {
    switch (type) {
        case NONE:
            return "NONE";
        case ZLIB:
            return "ZLIB";
        case LZ4:
            return "LZ4";
        default:
            return "UNKNOWN";
    }
}

[[nodiscard]] int foo()
{
    return 42;
}

int main() {
    foo();
    std::ostringstream os;

    os << "测试1  ";
    os << "测试2  ";
    std::string s = os.str();

    std::cout << s << std::endl; // 输出 "Hello, World!"
    MySQLType type1 = NONE;
    cout << ZLIB << std::endl;
    cout << LZ4 << std::endl;
    std::cout << MySQLTypeToString(type1) << std::endl;
    std::cout << MySQLTypeToString(ZLIB) << std::endl;
    std::cout << MySQLTypeToString(LZ4) << std::endl;

    cout<< "Standard Clib:" << __STDC_HOSTED__ << endl;
    cout<< "Standard C:" << __STDC__ << endl;


    return 0;
}

