#pragma once

class Error
{
public:
    virtual void printError() = 0;
};

class IdError : public Error
{
  string arg;
public:
    IdError() = default;
    IdError(string arg)
    {
        this->arg = arg;
    }
    void printError()
    {
        std::cout << "Input number system base is incorrect: " << arg << endl;
    }
};

class NumError : public Error
{
  string arg;
public:
    NumError() = default;
    NumError(string arg)
    {
        this->arg = arg;
    }
    void printError()
    {
        std::cout << "Input number is incorrect: " << arg << endl;
    }
};

class TypeError : public Error
{
  string arg;
public:
    TypeError() = default;
    TypeError(string arg)
    {
        this->arg = arg;
    }
    void printError()
    {
        std::cout << "Output number type is incorrect: "<< arg << endl;
    }
};


bool correctNum(string num)
{
  bool answer = true;
  for (int i = 0; i < num.size(); i++)
  {
    if((!isdigit(num[i]))
   && (num[i] != 'A')
   && (num[i] != 'B')
   && (num[i] != 'C')
   && (num[i] != 'D')
   && (num[i] != 'E')
   && (num[i] != 'F')) {answer = false; break;}
  }
  return answer;
}

bool correctId(string num, string numSysId)
{
  bool answer = true;
  for (int i = 0; i < num.size(); i++)
  {
    // cout << (num[i] - '0') << endl;
    if((num[i]-'0') >= stoi(numSysId, nullptr)) { answer = false;  break; }
  }
  return answer;
}
