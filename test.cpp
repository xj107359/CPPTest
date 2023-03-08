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

    std::ios_base::fmtflags orig = cout.setf(std::ios_base::fixed);
    std::streamsize prec = std::cout.precision(2);
    cout.setf(std::ios_base::fixed);
    cout.setf(std::ios_base::showpoint);
    //cout.precision(2);
    cout << 3.1415926 << endl;
    cout << 3 << endl;

    //cout.unsetf(std::ios_base::fixed);
    //cout.unsetf(std::ios_base::showpoint);
    std::cout.precision(prec);
    cout.setf(orig);
    cout << 3.1415926 << endl;
    cout << 3 << endl;
}

void init_new_var()
{
    int* pi = new int(6);
    delete pi;
    double* pd = new double(99.99);
    delete pd;
    struct where { double x; double y; double z; };
    where* one = new where{ 2.5, 5.3, 7.2 };
    delete one;
    int* ar = new int[4] {2, 4, 6, 7};
    delete[] ar;
    int* pin = new int{ 6 };
    delete pin;
    double* pdo = new double{ 99.99 };
    delete pdo;
}

class Stock
{
private:
    long m_shares;

public:
    Stock(long shares) { m_shares = shares; }
    void print() const { cout << m_shares << endl; }
};

void init_class()
{
    cout << endl << "=== init_class ===" << endl;
    Stock stock1(9);
    stock1.print();
    Stock stock2{ 10 };
    stock2.print();
}

void init_class_array()
{
    cout << endl << "=== init_class_array ===" << endl;
    Stock stocks[4] = {
        Stock(2),
        Stock(3),
        Stock{4},
        Stock{5},
    };

    for (int i = 0; i < 4; i++)
    {
        stocks[i].print();
    }
}

class Bakery
{
public:
    Bakery() {}
private:
    enum {Months = 12};
    double costs[Months];

    static const int Days = 365;
    double costs2[Days];
};

void class_static_var()
{
    Bakery bakery;
}

void enum_class()
{
    enum class egg { Small, Medium, Large, Jumbo };
    enum class t_shirt { Small, Medium, Large, Xlarge };

    egg choice = egg::Large;
    t_shirt Floyd = t_shirt::Large;
}

//=== class_default_val ===
//10, default
//20, default
//10, Hello
void class_default_val()
{
    class default_val
    {
    public:
        default_val() {};
        default_val(int count):m_count(count){};
        default_val(string text) :m_text(text) {};
        void print() {
            cout << m_count << ", " << m_text << endl;
        }
    private:
        int m_count{ 10 };
        string m_text{ "default" };
    };

    cout << endl << "=== class_default_val ===" << endl;
    default_val val1;
    default_val val2(20);
    default_val val3("Hello");
    val1.print();
    val2.print();
    val3.print();
}

//== = class_enum_const_var == =
//pv: Test, voice : 3
//pv : Test, voice : 4
//pv : Test, voice : 5
//pv : Test, voice : 6
//pv : Test, voice : 0
//pv : Test, voice : 1
//pv : Test, voice : 2
class Singer {
public:
    enum {
        other, alto, contralto, soprano,
        bass, baritone, tenor
    };
    enum { Vtype = 7 };
private:
    char pv[Vtype] {"Test"};
    int voice{ 0 };
public:
    Singer() {}
    Singer(int v = other):voice(v) {}
    Singer& Set()
    { voice += 1; voice %= Vtype; return *this; }
    void Show() const { cout << "pv: " << pv << ", voice: " << voice << endl; }
};
void class_enum_const_var()
{
    cout << endl << "=== class_enum_const_var ===" << endl;
    Singer singer(Singer::contralto);
    for(int i=0; i< Singer::Vtype; i++)
        singer.Set().Show();
}

template<typename T>
using arrtype = std::array< T, 12 >;

void template_using()
{
    typedef std::array<double, 12> arrd;
    typedef std::array<int, 12> arri;
    typedef std::array<std::string, 12> arrstd;
    arrd gallons;
    arri days;
    arrstd months;

    arrtype<double> gallons2;
    arrtype<int> days2;
    arrtype<std::string> months2;
}

//== = init_string == =
//one: Lottery Winner!
//two : $$$$$$$$$$$$$$$$$$$$
//three : Lottery Winner!
//one : Lottery Winner!Oops!
//four : Sorry!That was Pottery Winner!
//five : All's well that ends
//six : well
//seven : well
//eight : That was Pottery
void init_string2()
{
    cout << endl << "=== init_string ===" << endl;
    string one("Lottery Winner!");
    cout << "one: " << one << endl;
    string two(20, '$');
    cout << "two: " << two << endl;
    string three(one);
    cout << "three: " << three << endl;

    one += " Oops!";
    cout << "one: " << one << endl;

    two = "Sorry! That was ";
    three[0] = 'P';
    string four = two + three;
    cout << "four: " << four << endl;

    char alls[] = "All's well that ends well";
    string five(alls, 20);
    cout << "five: " << five << endl;

    string six(alls+6, alls+10);
    cout << "six: " << six << endl;

    string seven(&five[6], &five[10]);
    cout << "seven: " << seven << endl;

    string eight(four, 7, 16);
    cout << "eight: " << eight << endl;
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
    init_new_var();
    init_class();
    init_class_array();
    class_static_var();
    enum_class();
    class_default_val();
    class_enum_const_var();
    template_using();
    init_string2();
}
