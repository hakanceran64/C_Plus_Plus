#include <iostream>

using namespace std;

template<typename T>
void mySwap(T &r1, T &r2)
{
    T temp(r1);
    r1 = r2;
    r2 = temp;
}

template<typename T>
void add(T number_1, T number_2)
{
    T result = number_1 + number_2;

    cout << "Result: " << result << endl;
}

int main()
{
    // Her iki değişken tipi de aynıysa.
    int x = 10;
    int y = 20;

    cout << "mySwap() for int" << endl;
    cout << "before x: " << x << " before y: " << y << endl;
    mySwap(x, y);
    cout << "after x: " << x << " after y: " << y << endl << endl;

    double w = 10.2;
    double k = 20.4;
    
    cout << "mySwap() for double" << endl;
    cout << "before w: " << x << " before k: " << y << endl;
    mySwap(x, y);
    cout << "after w: " << x << " after k: " << y << endl << endl;

    // İki değişken tipinin birbirinden farklı olması durumu.
    int number_1 = 3;
    double number_2 = 2.3;

    add<double>(number_1, number_2);

    return 0;
}
