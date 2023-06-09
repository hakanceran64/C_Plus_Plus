#include <iostream>
#include <memory>
#include <string>
#include <vector>

// [23.2.4.1] construct/copy/destroy -> 480
// [23.2.4.2] capacity -> 915
// [23.2.4.3] modifiers -> 1175
/**
 * void push_back(const value_type& __x) -> 1187
 * void push_back(const value_type&& __x) -> 1203
 * 
 * reference emplace_back(_Args&&... __args) -> 1212
 * 
 * void pop_back() ->1225
 * 
 * iterator emplace(const_iterator __position, _Args&&... __args) -> 1248
 * 
 * iterator insert(const_iterator __position, const value_type& __x) -> 1263
 * iterator insert(const_iterator __position, value_type&& __x) -> 1293
 * iterator insert(const_iterator __position, initializer_list<value_type> __l) -> 1310
 * iterator insert(const_iterator __position, size_type __n, const value_type& __x) -> 1335
 * iterator insert(const_iterator __position, _InputIterator __first, _InputIterator __last) -> 1379
 * 
 * iterator erase(const_iterator __position) -> 1430
 * iterator erase(const_iterator __first, const_iterator __last) -> 1457
 * 
 * void swap(vector& __x) -> 1480
 * 
 * void clear() -> 1498
 */

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
    // element access
    /**
     * operator[]
     * at
     * front
     * back
     * data
     */

    std::vector<int> numbers{1, 2, 3, 4, 5};

    // reference operator[](size_type n);
    // const_reference operator[](size_type n) const;

    // Access Element of a Vector
    std::cout << "Element at Index 0: " << numbers.at(30) << std::endl; // throws an exception
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
    std::vector<int> otherVec{6, 7, 8, 9, 10, 11};

    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ===

    /**
       *  @brief  Assigns an initializer list to a %vector.
       *  @param  il  An initializer_list.
       *
       *  This function fills a %vector with copies of the elements in the
       *  initializer list @a il.
       *
       *  Note that the assignment completely changes the %vector and
       *  that the resulting %vector's size is the same as the number
       *  of elements assigned.
       */
    numbers.assign({1, 2, 3, 4, 5, 6});
    printVector(numbers, "numbers -> initializer list based assign");

    /**
       *  @brief  Assigns a given value to a %vector.
       *  @param  n  Number of elements to be assigned.
       *  @param  val  Value to be assigned.
       *
       *  This function fills a %vector with @a __n copies of the given
       *  value.  Note that the assignment completely changes the
       *  %vector and that the resulting %vector's size is the same as
       *  the number of elements assigned.
       */
    numbers.assign(5, 100);
    printVector(numbers, "numbers -> value based assign");

    /**
       *  @brief  Assigns a range to a %vector.
       *  @param  first  An input iterator.
       *  @param  last   An input iterator.
       *
       *  This function fills a %vector with copies of the elements in the
       *  range [first, last).
       *
       *  Note that the assignment completely changes the %vector and
       *  that the resulting %vector's size is the same as the number
       *  of elements assigned.
       */
    numbers.assign(otherVec.begin(), otherVec.end());
    printVector(numbers, "numbers -> range based assign");

    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ===

    // Add element at the end
    numbers.push_back(6);
    printVector(numbers, "numbers -> push_back");

    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ===

    /**
       *  @brief  Removes last element.
       *
       *  This is a typical stack operation. It shrinks the %vector by one.
       *
       *  Note that no data is returned, and if the last element's
       *  data is needed, it should be retrieved before pop_back() is
       *  called.
       */
    // Delete last element
    numbers.pop_back();
    printVector(numbers, "numbers -> pop_back");

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
       *  [first, last) into the %vector before the location specified
       *  by @a pos.
       *
       *  Note that this kind of operation could be expensive for a
       *  %vector and if it is frequently used the user should
       *  consider using std::list.
       */
    // Insert Element -> range (const_iterator position, InputIterator first, InputIterator last)
    numbers.insert(numbers.begin() + 2, otherVec.begin(), otherVec.end());
    printVector(numbers, "numbers -> range");

    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ===

    /**
       *  @brief  Remove element at given position.
       *  @param  position  Iterator pointing to element to be erased.
       *  @return  An iterator pointing to the next element (or end()).
       *
       *  This function will erase the element at the given position and thus
       *  shorten the %vector by one.
       *
       *  Note This operation could be expensive and if it is
       *  frequently used the user should consider using std::list.
       *  The user is also cautioned that this function only erases
       *  the element, and that if the element is itself a pointer,
       *  the pointed-to memory is not touched in any way.  Managing
       *  the pointer is the user's responsibility.
       */
    // Belirli bir indisteki elemanı silmek için.
    // iterator erase(const_iterator position)
    numbers.erase(numbers.begin() + 2);
    printVector(numbers, "numbers -> erase");

    /**
       *  @brief  Remove a range of elements.
       *  @param  first  Iterator pointing to the first element to be erased.
       *  @param  last  Iterator pointing to one past the last element to be
       *                  erased.
       *  @return  An iterator pointing to the element pointed to by @a __last
       *           prior to erasing (or end()).
       *
       *  This function will erase the elements in the range
       *  [first, last) and shorten the %vector accordingly.
       *
       *  Note This operation could be expensive and if it is
       *  frequently used the user should consider using std::list.
       *  The user is also cautioned that this function only erases
       *  the elements, and that if the elements themselves are
       *  pointers, the pointed-to memory is not touched in any way.
       *  Managing the pointer is the user's responsibility.
       */
    // Belirli bir aralıktaki elemanları silmek için.
    // iterator erase(const_iterator first, const_iterator last)
    numbers.erase(numbers.begin() + 2, numbers.begin() + 12);
    printVector(numbers, "numbers -> erase");

    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ===

    /**
       *  @brief  Swaps data with another %vector.
       *  @param  x  A %vector of the same element and allocator types.
       *
       *  This exchanges the elements between two vectors in constant time.
       *  (Three pointers, so it should be quite fast.)
       *  Note that the global std::swap() function is specialized such that
       *  std::swap(v1,v2) will feed to this function.
       *
       *  Whether the allocators are swapped depends on the allocator traits.
       */
    // void swap (vector& x);
    printVector(numbers, "numbers before swap");
    printVector(otherVec, "otherVec before swap");
    numbers.swap(otherVec);
    printVector(numbers, "numbers after swap");
    printVector(otherVec, "otherVec after swap");

    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ===

    /**
       *  Erases all the elements.  Note that this function only erases the
       *  elements, and that if the elements themselves are pointers, the
       *  pointed-to memory is not touched in any way.  Managing the pointer is
       *  the user's responsibility.
       */
    numbers.clear();
    printVector(numbers, "numbers -> clear");

    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ===

    numbers.assign({1, 2, 3, 4, 5, 6, 7, 8, 9, 0});

    /**
       *  @brief  Inserts an object in %vector before specified iterator.
       *  @param  position  A const_iterator into the %vector.
       *  @param  args  Arguments.
       *  @return  An iterator that points to the inserted data.
       *
       *  This function will insert an object of type T constructed
       *  with T(std::forward<Args>(args)...) before the specified location.
       *  Note that this kind of operation could be expensive for a %vector
       *  and if it is frequently used the user should consider using
       *  std::list.
       */
    numbers.emplace(numbers.begin() + 2, 100);
    printVector(numbers, "numbers -> emplace");

    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ===

    numbers.emplace_back(250);
    printVector(numbers, "numbers -> emplace_back");
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

using namespace std;

std::vector<int> hakan;

class Hakan;

int main()
{
    std::cout << std::endl;

    std::unique_ptr<int> uniquePtr(new int(42));
    int *rawPtr = uniquePtr.get();
    int value = *uniquePtr;

    std::cout << "Raw Pointer: " << rawPtr << std::endl;
    std::cout << "Value: " << value << std::endl;

    return EXIT_SUCCESS;
}
