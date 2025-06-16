#ifndef CIPHER_H
#define CIPHER_H
#include <vector>
#include <string>

using namespace std;

char shiftChar(char c, int shift) {
  if (c >= 'a' && c <= 'z') {
    shift = (shift % 26 + 26)%26;
    return (c - 'a' + shift)%26+'a';
  } else if (c >= 'A' && c <= 'Z') {
    shift = (shift % 26 + 26)%26;
    return (c -'A' + shift)%26+ 'A';
  }
  return c;
}

void reverseString(char* arr, int len) {
  for (int i=0; i<len/2;++i) {
    char tmp = *(arr + i);
    *(arr + i) = *(arr + len - i - 1);
    *(arr + len - i - 1) = tmp;
  }
}

void enkripsiPesan(vector<char>& pesan, int shift) {
  int len = pesan.size();
  if (len % 2 == 0) reverseString(&pesan[0], len);

  for (int i = 0; i < len; i++) {
    char c = pesan[i];
    int s = ((i % 2 == 0) ? shift : shift * 2);
    pesan[i] = shiftChar(c,s);
  }
}

void dekripsiPesan(vector<char>& pesan, int shift) {
  int len = pesan.size();

  for (int i =0; i<len; i++) {
    char c =pesan[i];
    int s =((i % 2 ==0) ? -shift : -2 * shift);
    pesan[i]=shiftChar(c,s);
  }

  if (len % 2 ==0) reverseString(&pesan[0], len);
}
#endif