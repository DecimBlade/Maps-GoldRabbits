/**
Name: Ellesia Truong
Class (CECS 282-04)
Project Name (Program 5 - BigInt goldRabbits)
Due Date (11/30/21)
I certify that this program is my own original work. I did not copy any part of this program from any other source. I further certify that I typed each and every line of code in this program
*/

#ifndef BigInt_H
#define BigInt_H

#include <climits>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iterator>

using namespace std;

class BigInt{
  private:
    vector<char> numbers;

  public:
  // Default Constructors
    BigInt();
    BigInt(string n);
    BigInt(int n);

  // Copy constructor
    BigInt(const BigInt &other);

  // Destructor
    ~BigInt();

  // Print
    void print();
    friend ostream & operator << (ostream &str, BigInt bigNum);
  
  // return vector func
    vector<char> getVector();

  // Operators
  // COMPARISON
  // =
  BigInt operator = (BigInt n);
  BigInt operator = (int n);

  // ==
  bool operator == (int n);
  bool operator == (const BigInt&) const;

  // <
  bool operator < (int n);
  bool operator < (const BigInt&) const;

  // <=
  bool operator <= (int n);
  bool operator <= (const BigInt &n) const;
  
  // Increment
  // +
  BigInt operator + (int n);
  BigInt operator + (BigInt n) const;

  // -
  BigInt operator - (int n);
  BigInt operator - (BigInt n) const;

  // ++
  BigInt operator ++ (int n);
};

#endif