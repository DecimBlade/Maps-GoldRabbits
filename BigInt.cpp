/**
Name: Ellesia Truong
Class (CECS 282-04)
Project Name (Program 5 - BigInt)
Due Date (11/30/21)
I certify that this program is my own original work. I did not copy any part of this program from any other source. I further certify that I typed each and every line of code in this program
*/

#include <climits>
#include <iostream>
#include <string>
#include "BigInt.h" 
// #include "GoldRabbits.tools"

using namespace std;

// default constructors
BigInt::BigInt(){
  numbers.push_back(0);
}

// Constructor with string
BigInt::BigInt(string n){
  int size = n.size();

  for(int i = size - 1; i >= 0; i--){
    numbers.push_back(n[i] - '0');
  }
}

// Constructor with int
BigInt::BigInt(int n){
  string s = to_string(n);
  int size = s.size();

  for(int i = size - 1; i >= 0; i--){
    numbers.push_back(s[i] - '0');
  }
}

// Copy constructor
BigInt::BigInt(const BigInt &other){
  this->numbers = other.numbers;
}

// Use clear or erase
// Erase needs an parameter to work, clear doesn't need a parameter.

// Destructor
BigInt::~BigInt(){
  numbers.clear();
}

// Printing method
void BigInt::print(){
  for(int i = numbers.size() - 1; i >= 0; i--){
    cout << int(numbers.at(i));
  }
}

ostream & operator<<(ostream &str, BigInt bigNum){
  int size = bigNum.numbers.size();

  if(size > 11){
    for( int i = size - 1; i >= size - 11; i--){
      str << int(bigNum.getVector()[i]);
      if(i == size - 1){
        str << ".";
      }
    }
    str << "e" << size - 1 << endl;
  }
  else{
    bigNum.print();
  }
  return str;
}


// Return vector function
vector<char> BigInt::getVector(){
  return numbers;
}


// OPERATORS
// Comparison OPERATORS

// =
BigInt BigInt::operator = (int n){
  BigInt bigNum(n);

  this->numbers = bigNum.numbers;

  return(*this);
}

BigInt BigInt::operator = (BigInt n){
  numbers = n.numbers;
  return (*this);
}


// ==
bool BigInt::operator == (int n){
  BigInt bigNum = BigInt(n);

  return (*this) == bigNum;
}

bool BigInt::operator == (const BigInt &n) const{
  bool logic = true;

  if(numbers.size() == n.numbers.size()){
    // set the increment to 0
    int inc = 0;

    while( inc < numbers.size() && logic == true){
      if(numbers[inc] != n.numbers[inc]){
        logic = false;
      }
      inc++;
    }
  }
  else{
    logic = false;
  }
  return logic;
}

// <
bool BigInt::operator < (const BigInt &n) const{
  bool logic = false;

  if(numbers.size() < n.numbers.size()){
    logic = true;
  }

  else if(*this == n){
    return false;
  }

  else if(numbers.size() > n.numbers.size()){
    logic = false;
  }

  else{
    for(int i = (int)numbers.size() - 1; i > -1; i--){
      if(numbers[i] < n.numbers[i]){
        return true;
      }
      else if(numbers[i] > n.numbers[i]){
        return false;
      }
    }
  }
  return logic;
}

// <=
bool BigInt::operator <= (int n){
  BigInt bigNum = BigInt(n);
  return (*this) <= bigNum;
}

bool BigInt::operator <= (const BigInt &n) const{
  return (*this) < (n) || (*this) == (n);
}

// Increment OPERATORS

// +
BigInt BigInt::operator + (int n){
  BigInt bigNum = BigInt(n);
  return (*this) + bigNum;
}


BigInt BigInt::operator + (BigInt n) const{
  BigInt bigNum = (*this);
  char c = 0;
  while(this->numbers.size() != n.numbers.size()){
    if(n.numbers.size() > this->numbers.size()){
      bigNum.numbers.push_back(0);
    }
    else{
      n.numbers.push_back(0);
    }
  }

  for(int i = 0; i < bigNum.numbers.size(); i++){
    if(c == 1){
      c = 0;
      bigNum.numbers[i] = bigNum.numbers[i] + 1;
    }

    if(bigNum.numbers[i] + n.numbers[i] >= 10){
      c = 1;
    }
    bigNum.numbers[i] = bigNum.numbers[i] + n.numbers[i] - c * 10;
  }
  if(c == 1){
    bigNum.numbers.push_back(c);
  }
  return bigNum;
}

// -
BigInt BigInt::operator - (int n){
  BigInt bigNum = BigInt(n);

  return (*this) - bigNum;
}


BigInt BigInt::operator - (BigInt n) const{
  BigInt bigNum = (*this);

  // when both nums are uneven
  while(this->numbers.size() != n.numbers.size()){
    // if this is true than put 0's in bottom, if false put 0's in top
    if(bigNum.numbers.size() > n.numbers.size()){
      n.numbers.push_back(0);
    }
    else{
      bigNum.numbers.push_back(0);
    }
  }

  for(size_t i = 0; i < bigNum.numbers.size(); i++){
    if(bigNum.numbers[i] < n.numbers[i]){
      bigNum.numbers[i] = bigNum.numbers[i] + 10;
      bigNum.numbers[i + 1] = bigNum.numbers[i + 1] - 1;
    }

    // Actual subtraction
    bigNum.numbers[i] = bigNum.numbers[i] - n.numbers[i];

    if(i == bigNum.numbers.size() - 1 && bigNum.numbers[i] == 0 && n.numbers[i] == 0){
      bigNum.numbers.erase(bigNum.numbers.end() - 1);
    }
  }
  return bigNum;
}

// ++
BigInt BigInt::operator ++(int n){
  return (*this) = (*this) + 1;
}

