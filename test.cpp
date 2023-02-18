// test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <cctype>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::array;

void auto_usage()
{
    std::vector<double> scores;
    std::vector<double>::iterator pv = scores.begin();
    auto pv2 = scores.end();
}

void init_array()
{
    double earning[4]{ 1.2e4, 1.6e4, 1.1e4, 1.7e4 };
    float balances[100]{};
    char tlifs[4]{ 'h', 'i', 112, '\0' };
}

void init_string()
{
    char first_date[]{ "The Blegant Plate" };
    string second_date { "Hank's Fine Eats" };
}

//== = raw_string == =
//Jim "King" Tutt uses "\n" instead of endl.
//"(Who wouldn't?)", she whispered.
void raw_string()
{
    cout << "=== raw_string ===" << endl;
    cout << R"(Jim "King" Tutt uses "\n" instead of endl.)" << endl;
    cout << R"+*("(Who wouldn't?)", she whispered.)+*" << endl;
}

void init_struct()
{
    struct inflatable
    {
        char name[20];
        float volume;
        double price;
    };

    inflatable duck{ "Daphne", 0.12f, 9.98 };
}

//== = vector_array == =
//a1[2]: 3.6 at 0000000756FFF518
//a2[2] : 0.142857 at 000001F614275350
//a3[2] : 1.62 at 0000000756FFF598
//a4[2] : 1.62 at 0000000756FFF5D8
void vector_array()
{
    cout << endl << "=== vector_array ===" << endl;
    double a1[4]{ 1.2, 2.4, 3.6, 4.8 };

    vector<double> a2(4);
    a2[0] = 1.0 / 3.0;
    a2[1] = 1.0 / 5.0;
    a2[2] = 1.0 / 7.0;
    a2[3] = 1.0 / 9.0;

    array<double, 4> a3{ 3.14, 2.72, 1.62, 1.41 };
    array<double, 4> a4;
    a4 = a3;

    cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
    cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
}

//== = for_range == =
//3.992
//8.792
//5.496
//6.392
//6.792
//3
//5
//2
//8
//6
void for_range()
{
    cout << endl << "=== for_range ===" << endl;
    double prices[5]{ 4.99, 10.99, 6.87, 7.99, 8.49 };
    for (auto &x : prices)
        x *= 0.8;
    for (auto x : prices)
        cout << x << endl;

    for (int x : {3, 5, 2, 8, 6})
        cout << x << endl;
}

//== = cctype_usage == =
//isalpha('a') : 1
//isspace(' ') : 1
//isdigit('6') : 1
//ispunct(',') : true
//isalnum('1') : true
//islower('w') : true
//isupper('W') : 1
//isxdigit('F') : 1
void cctype_usage()
{
    cout << endl << "=== cctype_usage ===" << endl;
    cout << R"(isalpha('a'): )" << bool(isalpha('a')) << endl;
    cout << R"(isspace(' '): )" << bool(isspace(' ')) << endl;
    cout << R"(isdigit('6'): )" << bool(isdigit('6')) << endl;
    cout.setf(std::ios_base::boolalpha);
    cout << R"(ispunct(','): )" << bool(ispunct(',')) << endl;
    cout << R"(isalnum('1'): )" << bool(isalnum('1')) << endl;
    cout << R"(islower('w'): )" << bool(islower('w')) << endl;
    cout.unsetf(std::ios_base::boolalpha);
    cout << R"(isupper('W'): )" << bool(isupper('W')) << endl;
    cout << R"(isxdigit('F'): )" << bool(isxdigit('F')) << endl;
}

//== = cout_precision == =
//3.14159
//3
//3.14
//3
//3.14159
//3
void cout_precision()
{
    cout << endl << "=== cout_precision ===" << endl;
    cout << 3.1415926 << endl;
    cout << 3 << endl;

    std::streamsize ss = std::cout.precision();
    cout.setf(std::ios_base::fixed);
    cout.setf(std::ios_base::showpoint);
    cout.precision(2);
    cout << 3.1415926 << endl;
    cout << 3 << endl;

    cout.unsetf(std::ios_base::fixed);
    cout.unsetf(std::ios_base::showpoint);
    std::cout.precision(ss);
    cout << 3.1415926 << endl;
    cout << 3 << endl;
}

int main()
{
    std::cout << "Hello World!\n";
    auto_usage();
    init_array();
    init_string();
    raw_string();
    init_struct();
    vector_array();
    for_range();
    cctype_usage();
    cout_precision();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
