#include <iostream>
#include <limits>

using namespace std;

int main() {
	
    signed char min_signed_char = -127;
    signed char max_signed_char = 128;
    
    unsigned char max_unsigned_char = 255; // 0xFF
    
    char min_char = -127;
    char max_char = 128;

	cout << "CHAR_BIT: " << CHAR_BIT << endl;
    cout << "Size of char (byte): " << sizeof(char) << endl;
    
    cout << "SCHAR_MIN: " << SCHAR_MIN << endl;
    cout << "SCHAR_MAX: " << SCHAR_MAX << endl;
    
    cout << "UCHAR_MAX: " << UCHAR_MAX << " | " << 0xFF << endl;
    
    cout << "CHAR_MIN: " << CHAR_MIN << endl;
    cout << "CHAR_MAX: " << CHAR_MAX << endl;

    cout << endl;
    cout << "==============================" << endl << endl;
    
    cout << "MB_LEN_MAX: " << MB_LEN_MAX << endl;

    cout << "SHRT_MIN: " << SHRT_MIN << endl;
    cout << "SHRT_MAX: " << SHRT_MAX << endl;
    cout << "USHRT_MAX: " << USHRT_MAX << endl; // 0xffff

    cout << endl;
    cout << "==============================" << endl << endl;

    cout << "INT_MIN: " << INT_MIN << endl;
    cout << "INT_MAX: " << INT_MAX << endl;
    cout << "UINT_MAX: " << UINT_MAX << endl;

    cout << endl;
    cout << "==============================" << endl << endl;

    cout << "LONG_MIN: " << LONG_MIN << endl;
    cout << "LONG_MAX: " << LONG_MAX << endl;
    cout << "ULONG_MAX: " << ULONG_MAX << endl;

    cout << endl;
    cout << "==============================" << endl << endl;

    cout << "LLONG_MIN: " << LLONG_MIN << endl;
    cout << "LLONG_MAX: " << LLONG_MAX << endl;
    cout << "ULLONG_MAX: " << ULLONG_MAX << endl;

    cout << endl;
    cout << "==============================" << endl << endl;

    cout << "_I8_MIN: " << _I8_MIN << endl;
    cout << "_I8_MAX: " << _I8_MAX << endl;
    cout << "_UI8_MAX: " << _UI8_MAX << endl;

    cout << endl;
    cout << "==============================" << endl << endl;

    cout << "_I16_MIN: " << _I16_MIN << endl;
    cout << "_I16_MAX: " << _I16_MAX << endl;
    cout << "_UI16_MAX: " << _UI16_MAX << endl;

    cout << endl;
    cout << "==============================" << endl << endl;

    cout << "_I32_MIN: " << _I32_MIN << endl;
    cout << "_I32_MAX: " << _I32_MAX << endl;
    cout << "_UI32_MAX: " << _UI32_MAX << endl;

    cout << endl;
    cout << "==============================" << endl << endl;

    cout << "_I64_MIN: " << _I64_MIN << endl;
    cout << "_I64_MAX: " << _I64_MAX << endl;
    cout << "_UI64_MAX: " << _UI64_MAX << endl;

    cout << endl;
    cout << "==============================" << endl << endl;

    cout << "SIZE_MAX: " << SIZE_MAX << endl;

    cout << "INT_FAST64_MAX: " << INT_FAST64_MAX << endl;

    system("PAUSE");
	return EXIT_SUCCESS;
}
