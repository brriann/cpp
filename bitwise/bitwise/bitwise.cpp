#include <iostream>

using std::cout;
using std::endl;

int main()
{
   unsigned char bitChar[8];

   for (int i = 0; i < 8; i += 2) {
      bitChar[i] = 1;
      cout << bitChar << endl;
   }
   for (int i = 0; i < 8; ++i) {
      cout << (bitChar[i] == 1 ? "1" : "0");
   }

   unsigned char bitChar2= 10; // 0000 1010
   bitChar2 <<= 2; //0010 1000 , 40 in base10

   unsigned char bitChar3 = 10; // 0000 1010
   unsigned char bitChar4 = 11; // 0000 1011
   unsigned char bitChar5 = bitChar3 & bitChar4; // 0000 1010 or 10 base10
   return 0;
}