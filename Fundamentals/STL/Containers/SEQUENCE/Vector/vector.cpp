
#include <iostream>
#include  <cstdlib>
#include <vector>

using namespace std;

int main(int argc, char **argv){

    cout << "Vector.cpp" << endl << endl;

    vector<int> v1;

    cout << "Vector Size: " << v1.size() << endl;
    cout << endl;

    v1.push_back(12);
    v1.push_back(13);
    v1.push_back(14);
    v1.push_back(15);

    for (auto elements : v1){
        cout << "Vector element: " <<  elements << endl;
    }

    cout << endl;

    cout << "Vector Size: " << v1.size() << endl;

    return EXIT_SUCCESS;
}

