# Structure

## Source

- [Aggregate initialization](https://en.cppreference.com/w/cpp/language/aggregate_initialization)
- [Struct Aggregate Initialization](https://www.learncpp.com/cpp-tutorial/struct-aggregate-initialization/)
- [W3 Schools](https://www.w3schools.com/cpp/cpp_structs.asp)

## Create Structure

~~~C++
    
    struct {
        string brand;
        string model;
        int year;
    } myCar1, myCar2;

~~~

## Create Named Structure

~~~C++

    struct car {
        string brand;
        string model;
        int year;
    };

    car myCar;

    myCar.year = 2020;

~~~
