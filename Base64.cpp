#include "Base64.h"
#include <sstream>

using namespace std;

string Base64::alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

string Base64::Binary(int a, int b)
{
    string result = "";
    while(a != 0)
    {
        if((a%2) == 0)
            result += '0';
        else
            result += '1';
        a = a/2;
    }

    Complete(result, b);
    Reverse(result);
    return result;
}

string Base64::Encode(string a)
{
    string binario = TextToBin(a, 8);
    stringstream ret;
    string *buffer;

    int padding;
    int alt = binario.length()%6;
    int aux;

    if(alt == 0)
    {
        int numcadenas = binario.length() / 6;
        buffer = new string[numcadenas];
        if(buffer != NULL)
        {
            for(int i = 0; i < numcadenas; i++)
            {
                buffer[ i ] = binario.substr(i*6, 6);
                aux = BinToInt(buffer[ i ]);
                ret << alfabeto.at(aux);
            }

            delete[] buffer;
        }
    }
    else
    {
        padding = (6 - alt) / 2;
        Complete(binario, binario.length() + (6-alt));
        int numcadenas = binario.length() / 6;
        buffer = new string[numcadenas];
        if(buffer != NULL)
        {
            int i;
            for(i = 0; i < numcadenas; i++)
            {
                buffer[ i ] = binario.substr(i*6, 6);
                aux = BinToInt(buffer[ i ]);
                ret << alfabeto.at(aux);
            }

            for(i = 0; i < padding; i++)
                ret<<"=";

            delete[] buffer;
        }
    }

    return ret.str();
}

string Base64::Decode(string a)
{
    string binario;
    string cadena;
    stringstream delpadding;

    int i;

    for(i = 0; i < a.length(); i++)
    {
        if(a.at(i) != '=')
            delpadding<<a.at(i);
    }

    cadena = delpadding.str();
    binario = TextToBinBase(cadena, 6);

    stringstream ret;
    string *buffer;

    int padding;
    int alt = binario.length()/8;
    int aux;

    buffer = new string[alt];

    if(buffer != NULL)
    {
        for(i = 0; i < alt; i++)
        {
            buffer[ i ] = binario.substr(i*8, 8);
            aux = BinToInt(buffer[ i ]);
            ret << (char)aux;
        }
        cout<<endl;
        delete[] buffer;
    }

    return ret.str();
}

string Base64::TextToBin(string a, int b)
{
    stringstream c;
    for(int i = 0; i < a.length(); i++)
    {
        c<<Binary((int)a.at(i), b);
    }
    return c.str();
}

string Base64::TextToBinBase(string a, int b)
{
    stringstream c;
    for(int i = 0; i < a.length(); i++)
    {
        int pos = (int)alfabeto.find(a.at(i));
        c<<Binary(pos, b);
    }
    return c.str();
}

void Base64::Reverse(string& a)
{
    string aux = "";
    for(int i = 0; i < a.length(); i++)
        aux += a.at(a.length() - i - 1);
    a = aux;
}

void Base64::Complete(string &a, int b)
{
    if(a.length() < b)
    {
        int fin = b - a.length();
        a.append(fin, '0');
    }
}

int Base64::BinToInt(string a)
{
    int aux = 0;

    for(int i = 0; i < a.length(); i++)
    {
        if(a.at(i) == '1')
        {
            float ex = a.length() -i -1;
            aux += (int)pow(2, ex);
        }
    }

    return aux;
}