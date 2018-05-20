#include <iostream>
#include <string>
#include <math.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Base64
{
private:
    static string alfabeto;
    static string TextToBinBase(string a, int b);
    static void Reverse(string &a);
    static void Complete(string &a, int b);
public:
    static string Encode(string a);
    static string Decode(string a);
    static string Binary(int a, int b);
    static int BinToInt(string a);
    static string TextToBin(string a, int b);

};