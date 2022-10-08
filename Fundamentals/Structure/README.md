# Structure

## Source

- [Aggregate initialization](https://en.cppreference.com/w/cpp/language/aggregate_initialization)
- [Struct Aggregate Initialization](https://www.learncpp.com/cpp-tutorial/struct-aggregate-initialization/)
- [W3 Schools](https://www.w3schools.com/cpp/cpp_structs.asp)
- [Bilgi Günlüğüm](https://www.bilgigunlugum.net/prog/cppprog/cpp_yapi)

---

Struct'ları tükçe olarak yapı veya küme olarak düşünebiliriz.

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

## Alt Küme

~~~C++

    struct Person
    {
        int id;
        int age;
        string name;
        string surname;

        struct Employee
        {
            double wage;
        } CERAN;

    };

    Person hakanceran;
    hakanceran.CERAN.wage;

~~~

~~~C++

    struct animal {
        int animalId;
    } animals[10];

    struct dog : animal {
        int dogId;
    } dogs = {12};

    dog pasa;
    pasa.animalId;
    pasa.dogId;

~~~
