
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class NumeralSystem
{
private:
  vector<int> a;
  string num;
  int numSysId;
public:
    NumeralSystem();
  	NumeralSystem(string str, string original);
    //Конструктор, содержит 2 параметра: строка исходного числа, исходная система счисления
    void setValues(string str, string original);
    void setNum(string str);
    void setBase(string original);
  	int charToInt(char c);
    //Переводит символ в число, вместо некорректных символов возвращает -1
  	int nextNumber(int newSys);
    //Получает следующую цифру числа в новой системе счисления
  	bool zero();
    //Возвращает true - если массив состоит из одних нулей и false в противном случае
    int StringToInt(string b);
    //перевод строки с числом в тип integer
    char intToChar(int c);
    //перевод элемента вектора в тип char
  	string convertTo(int newSys);
    //перевод в заданную систему исчисления (возвращает строку)NumeralSystem::
    operator int();
    //перевод строки в 10-тичное число типа int
    double doublePconvert();
    //перевод в 64-bit double precision IEE 754 формат
    operator double();
    //перевод строки в 10-тичное число типа double
    ~NumeralSystem()
    {
      a.~vector<int>();
    }
};

NumeralSystem::NumeralSystem()
{
  this->num = "0";
  this->numSysId = 2;
  a.push_back('0');
}
NumeralSystem::NumeralSystem(string str, string original)
//Конструктор, содержит 2 параметра: строка исходного числа, исходная система счисления
{
  this->num = str;
  this->numSysId = stoi(original, nullptr);
  for ( int i=0; i < str.length(); i++ )
  {
    this->a.push_back(charToInt(str[i]));
  }
}

void NumeralSystem::setValues(string str, string original)
{
  this->num = str;
  this->numSysId = stoi(original, nullptr);
  a.clear();
  for ( int i=0; i < str.length(); i++ )
  {
    this->a.push_back(charToInt(str[i]));
  }
}

void NumeralSystem::setNum(string str)
{
  this->num = str;
  a.clear();
  for ( int i=0; i < str.length(); i++ )
  {
    this->a.push_back(charToInt(str[i]));
  }
}

void NumeralSystem::setBase(string original)
{
  this->numSysId = stoi(original, nullptr);
}

int NumeralSystem::charToInt(char c)
//Переводит символ в число, вместо некорректных символов возвращает -1
{
  if ( c >= '0' && c <= '9' && (c - '0') < this->numSysId )
  {
    return c - '0';
  }
  else
  {
    if ( c >= 'A' && c <= 'Z' && (c - 'A') < this->numSysId )
    {
      return c - 'A' + 10;
    }
    else return -1;
  }
}

int NumeralSystem::nextNumber(int newSys)
//Получает следующую цифру числа в новой системе счисления
{
  int temp = 0;
  for ( int i = 0; i<this->a.size(); i++)
  {
    temp = temp*this->numSysId + this->a[i];
    a[i] = temp / newSys;
    temp = temp % newSys;
  }
  return temp;
}

bool NumeralSystem::zero()
//Возвращает true - если массив состоит из одних нулей и false в противном случае
{
  for (int i = 0; i < this->a.size(); i++)
  {
    if ( a[i] != 0 ) return false;
  }
  return true;
}

int NumeralSystem::StringToInt(string b) //перевод строки с числом в тип integer
{
  int result;
  size_t size;

  result = stoi(b, &size);
  return result;
}

char NumeralSystem::intToChar(int c) //перевод элемента вектора в тип char
{
  if ( c >= 0 && c <= 9 )
  {
    return c + '0';
  }
  else return c + 'A' - 10;
}


string NumeralSystem::convertTo(int newSys) //перевод в заданную систему исчисления
{
  vector<int> b;
  int size = 0;
  do
  {
    b.push_back(this->nextNumber(newSys));
    size++;
  }
  while( !this->zero() );
  reverse(b.begin(), b.end());

  string sTemp="";
  for (int i = 0; i <= b.size()-1; i++)
  {
    sTemp += intToChar(b[i]);
  }
  return sTemp;
}

NumeralSystem::operator int()
{
  string s = this->convertTo(10);
  return this->StringToInt(s);
}

double NumeralSystem::doublePconvert() //перевод в 64-bit double precision IEE 754 формат
{
  string s = this->num;
  unsigned long long x = 0;
  for (string::const_iterator it = s.begin(); it != s.end(); ++it)
  {
    x = (x << 1) + (*it - '0');
  }
  double d;
  memcpy(&d, &x, 8);
  return d;
}

NumeralSystem::operator double()
{
  if(numSysId != 2)
  {
    this->num = convertTo(2);
  }
  return this->doublePconvert();
}
