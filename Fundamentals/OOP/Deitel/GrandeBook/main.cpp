#include <stdio.h>
#include "GradeBook.h"

int main()
{
    // MAX ARRAY SIZE
    int dizi[1][2][3][4][5][6][7][8][9] = {0};

    GradeBook gradeBook("Data Structures in C++");
    cout << "gradeBook created for course: " << gradeBook.getCourseName() << endl;

    return EXIT_SUCCESS;
}