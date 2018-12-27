#include <iostream>
#include <cstring>
#include "numSys.h"
#include "Error.h"
using namespace std;

int main()
{
  NumeralSystem conv1("0", "2");
  NumeralSystem conv2("3160", "8");
  NumeralSystem conv3("16B860", "16");
  NumeralSystem conv4("0011111111101111111101111100111011011001000101101000011100101011", "2");
  NumeralSystem conv5("377577574733105504000", "8" );
  NumeralSystem conv6("3FEFF7CED916872B", "16");
  cout << int(conv1) << "\n";
  cout << int(conv2) << "\n";
  cout << int(conv3) << "\n";
  cout << double(conv4) << "\n";
  cout << double(conv5) << "\n";
  cout << double(conv6) << "\n";

  NumeralSystem conv;
  string num, numSysId, convType;
  bool f = false;
  char answer;

  while (f == false)
  {
    try
    {
      cout << "Enter the number: ";
      cin >> num;
      if (correctNum(num) == false )
      {
        throw NumError(num);
      }
      else
      {
        cout << "entered: " << num << endl;
        conv.setNum(num);
      }

      cout << "Enter the base: ";
      cin >> numSysId;
      if(numSysId != "16")
      {
        if(numSysId != "2" && numSysId != "8")
        {
          throw IdError(numSysId);
        }
        else if(correctId(num, numSysId) == true)
        {
          cout << "entered: " << numSysId << endl;
          conv.setBase(numSysId);
        } else throw IdError(numSysId);
      }

      cout << "Enter the type of output: ";
      cin >> convType;
      cout << "entered: " << convType << endl;
      if( convType != "int" && convType != "double")
      {
        throw TypeError(convType);
      }
      else
      {
        if(convType == "int") cout << int(conv)    << endl;
        if(convType == "double") cout << double(conv) << endl;
      }
    }
    catch (Error &e)
    {
        e.printError();
    }
    catch (runtime_error &e) {
        cout << "Runtime error: " << e.what() << endl;
    }
    catch (bad_alloc &e) {
        cout << "Bad allocation\n";
    }
    catch (...) {
        cout << "Undefined exception" << endl;
    }
    ~conv;
    cout << "wish to continue?" << endl;
    cin >> answer;
    if(answer != 'y') f = true;
  }
  cout << "Гуменчук Артур, IП-71, Варіант 7, рівень Б" << "\n";

}
