#include <iostream>
#include <string>
#include <vector>

// Template kullanarak, herhangi bir türdeki vektörleri ekrana yazdıran bir fonksiyon
template<typename T>
void printVector(const std::vector<T> &vec, const std::string &str)
{
    std::cout << str << ": ";

    // Ranged Loop: Vektörün her bir öğesini dolaşarak ekrana yazdır
    for (const T &item : vec) {
        std::cout << item << " ";
    }

    std::cout << std::endl;
}

// Bu fonksiyon, farklı yöntemlerle std::vector'leri başlatmayı gösterir.
void vectorInitialization()
{
    // Vector declaration
    // std::vector<T> vector_name;

    // Default Initialization (Varsayılan başlatma)
    std::vector<int> defaultVector;
    printVector(defaultVector, "default initialization");

    // Size Initialization (Boyuta göre başlatma)
    std::vector<int> sizeVector(5);
    printVector(sizeVector, "size initialization");

    // Value Initialization (Değerle Başlatma) -> initializer list
    std::vector<int> valueVector = {1, 2, 3, 4, 5};
    printVector(valueVector, "value initialization");

    // Value Initialization (Değerle Başlatma) -> uniform initialization
    std::vector<int> otherVec{1, 2, 3, 4, 5, 6};
    printVector(otherVec, "value initialization");

    // Range Initialization (Aralıkla Başlatma)
    std::vector<int> rangeVector(otherVec.begin(), otherVec.end());
    printVector(rangeVector, "range initialization");

    // Fill Initialization (Değerle Doldurma)
    std::vector<int> fillVector(5, 12); // {12, 12, 12, 12, 12}
    printVector(fillVector, "fill initialization");

    // Copy Initialization (Kopya İle Başlatma)
    std::vector<int> copyVector(otherVec);
    printVector(copyVector, "copy initialization");

    // Move Initialization (Taşıma İle Başlatma)
    std::vector<int> moveVector(std::move(otherVec));
    printVector(moveVector, "move initialization");

    // otherVec artık boş.
    printVector(otherVec, "otherVec");
}

/**
 * @brief basicVectorOperations:
 * - Add elements
 * - Access elements
 * - Change elements
 * - Remove elements
 */
void basicVectorOperations()
{
    // Add Element to a Vector
    std::vector<int> numbers{1, 2, 3, 4, 5};

    // push_back Vektörün sonuna kopya oluşturarak eleman ekler
    numbers.push_back(6);
    // emplace_back Vektörün sonuna kopya oluşturmadan eleman ekler.
    numbers.emplace_back(7);
    // Belirli bir indis'in arkasına ekler.
    numbers.insert(numbers.begin() + 2, 10);
    // Vektörü yeniden boyutlandırır ve yeni elemanlarla doldurur.
    numbers.resize(10, 5);
    // Vektörü yeniden oluşturma.
    numbers = {1, 2, 10, 3, 4, 5, 6, 7, 5, 5};
    printVector(numbers, "numbers");

    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ===
    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ===

    // Change Vector Element

    // indis tabanlı eleman değiştirme.
    numbers[2] = 10;

    // Hata kontrolü yapar ve geçerli indis dışına erişimde hata fırlatır.
    numbers.at(3) = 12;

    // iterator kullanarak vektör elemanlarını değiştirme.
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        *it = 10; // iterator kullanarak elemanları değiştirme
    }

    for (int &element : numbers) {
        element = 10; // for döngüsü ile elemanları değiştirme
    }

    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ===
}

void vectorElementAccess()
{
    std::vector<int> numbers{1, 2, 3, 4, 5};

    // Access Element of a Vector
    std::cout << "Element at Index 0: " << numbers.at(0) << std::endl; // throws an exception
    std::cout << "Element at Index 0: " << numbers[0] << std::endl;    // gives garbage value

    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        int element = *it; // iterator kullanarak elemanlara erişme
        std::cout << element << " ";
    }

    std::cout << std::endl;

    for (const int &element : numbers) {
        std::cout << element << " "; // for döngüsü ile elemanlara erişme.
    }

    std::cout << std::endl;
}

void vectorModifiers()
{
    std::vector<int> numbers{1, 2, 3, 4, 5};

    // Add element at the end
    numbers.push_back(6);

    // Delete last element
    numbers.pop_back();

    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ===

    auto position = numbers.begin() + 2;

    /**
       *  @brief  Inserts given value into %vector before specified iterator.
       *  @param  position  A const_iterator into the %vector.
       *  @param  val  Data to be inserted.
       *  @return  An iterator that points to the inserted data.
       *
       *  This function will insert a copy of the given value before
       *  the specified location.  Note that this kind of operation
       *  could be expensive for a %vector and if it is frequently
       *  used the user should consider using std::list.
       */
    // Insert Elements -> single element [copy] (const_iterator position, const value_type &val)
    numbers.insert(position, 12);
    printVector(numbers, "numbers -> single element");

    /**
       *  @brief  Inserts given rvalue into %vector before specified iterator.
       *  @param  position  A const_iterator into the %vector.
       *  @param  val  Data to be inserted.
       *  @return  An iterator that points to the inserted data.
       *
       *  This function will insert a copy of the given rvalue before
       *  the specified location.  Note that this kind of operation
       *  could be expensive for a %vector and if it is frequently
       *  used the user should consider using std::list.
       */
    // Insert Element -> move (const_iterator position, value_type &&val)
    int newElement = 12;
    numbers.insert(position, std::move(newElement));
    printVector(numbers, "numbers -> move");

    /**
       *  @brief  Inserts an initializer_list into the %vector.
       *  @param  position  An iterator into the %vector.
       *  @param  il  An initializer_list.
       *
       *  This function will insert copies of the data in the
       *  initializer_list @a l into the %vector before the location
       *  specified by @a position.
       *
       *  Note that this kind of operation could be expensive for a
       *  %vector and if it is frequently used the user should
       *  consider using std::list.
       */
    // Insert Element -> initializer list (const_iterator position, initializer_list<value_type> il)
    std::initializer_list<int> initList = {10, 20, 30};
    numbers.insert(position, initList);
    printVector(numbers, "numbers -> initializer list");

    /**
       *  @brief  Inserts a number of copies of given data into the %vector.
       *  @param  position  A const_iterator into the %vector.
       *  @param  n  Number of elements to be inserted.
       *  @param  val  Data to be inserted.
       *  @return  An iterator that points to the inserted data.
       *
       *  This function will insert a specified number of copies of
       *  the given data before the location specified by @a position.
       *
       *  Note that this kind of operation could be expensive for a
       *  %vector and if it is frequently used the user should
       *  consider using std::list.
       */
    // Insert Elements -> fill (const_iterator position, size_type n, const value_type& val)
    numbers.insert(position, 3, 100);
    printVector(numbers, "numbers -> fill");

    /**
       *  @brief  Inserts a range into the %vector.
       *  @param  position  A const_iterator into the %vector.
       *  @param  first  An input iterator.
       *  @param  last   An input iterator.
       *  @return  An iterator that points to the inserted data.
       *
       *  This function will insert copies of the data in the range
       *  [__first,__last) into the %vector before the location specified
       *  by @a pos.
       *
       *  Note that this kind of operation could be expensive for a
       *  %vector and if it is frequently used the user should
       *  consider using std::list.
       */
    // Insert Element -> range (const_iterator position, InputIterator first, InputIterator last)
    numbers.insert(position, numbers.begin() + 2, numbers.end());
    printVector(numbers, "numbers -> range");

    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ===

    // Belirli bir indisteki elemanı silmek için.
    numbers.erase(numbers.begin() + 2);
}

void vectorIterators() {}

void vectorFunctions()
{
    // a vector
    std::vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    // removes all the elements of the vector
    numbers.clear();

    // returns the number of elements present in the vector.
    std::cout << "numbers.size: " << numbers.size() << std::endl;

    // returns the first element of the vector
    numbers.front();
    // returns the last element of the vector
    numbers.back();
    // returns 1(true) if the vector is empty
    numbers.empty();
    // check the overall size of a vector
    std::cout << "Numbers Capacity: " << numbers.capacity() << std::endl;
}

int main()
{
    std::cout << std::endl;

    vectorModifiers();

    return EXIT_SUCCESS;
}
