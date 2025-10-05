#include <iostream>
using namespace std;

int main()
{
    // Bitwise AND
    int a = 5;                                  // 0101 in binary
    int b = 3;                                  // 0011 in binary
    cout << "Bitwise AND: " << (a & b) << endl; // Output: 1 (0001 in binary)

    // Bitwise OR
    cout << "Bitwise OR: " << (a | b) << endl; // Output: 7 (0111 in binary)

    // Bitwise XOR
    cout << "Bitwise XOR: " << (a ^ b) << endl; // Output: 6 (0110 in binary)

    // Bitwise NOT
    cout << "Bitwise NOT of a: " << (~a) << endl; // Output: -6 (inverts all bits of a)

    return 0;
}