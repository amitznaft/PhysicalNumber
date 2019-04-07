#include "PhysicalNumber.h"
#include <regex>
#include <math.h>

using namespace ariel;
//using ariel::Remainder, ariel::PhysicalNumber;

bool ariel::equals(const Remainder& r1 , const Remainder& r2){
    if(r1==r2) return true;
    else{return false;}
}
/*
ariel::PhysicalNumber(const float num , Unit unit) {
    switch(unit){
        case Unit::KM: Remainder::Length;
        case Unit::TON: Remainder::Weight;
        case Unit::HOUR: Remainder::Time;
        case Unit::M: Remainder::Length;
        case Unit::KG: Remainder::Weight;
        case Unit::MIN: Remainder::Time;
        case Unit::CM: Remainder::Length;
        case Unit::G: Remainder::Weight;
        case Unit::SEC: Remainder::Time;
    }
    this->_unit = unit;
    this->_value = num;
  }
*/

ariel::PhysicalNumber::PhysicalNumber(double num , Unit unit){
  this->_value = num;
  this->_unit = unit;
}


const PhysicalNumber PhysicalNumber::operator-() const{
  return PhysicalNumber(_value*(-1),_unit);}

const PhysicalNumber PhysicalNumber::operator+() const{
  return *this;
}
const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& other) const{
  /*
  if ((_unit - other._unit)%3!=0) {
    throw string("Invalid unit type");
  }
  int a = fmax( this->_unit,other._unit);
  int b = fmin( this->_unit,other._unit);
  int ratio = a-b;
  if (a%3==2) {
    switch (ratio/3) {
      case 0: return PhysicalNumber(_value+other._value, a); //fix urgently
      case 1: return PhysicalNumber( a ,b );
      case 2: return PhysicalNumber()
    }
  }
  return ans;
  */
  return *this;
}
PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& other) {
   PhysicalNumber ans = *this + other;
   this->_value = ans._value;
   return *this;
 }
PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& other) {
   PhysicalNumber ans = *this - other;
   this->_value = ans._value;
   return *this;
}
PhysicalNumber& PhysicalNumber::operator-(const PhysicalNumber& other) {
   PhysicalNumber ans = *this - other;
   this->_value = ans._value;
   return *this;
}
bool PhysicalNumber::operator==(const PhysicalNumber& other) {
  if (
    (this->_value == other._value) &&  (this->_unit == other._unit)) {
    return true;
}
else {
  return false;
}
}

bool ariel::operator!=(const PhysicalNumber& p1, const PhysicalNumber& p2) { if (!(p2._value
   == p1._value)) return true; else return false; }
bool ariel::operator>=(const PhysicalNumber& p1, const PhysicalNumber& p2) { if (!(p2 <= p1)) return true; else return false; }
bool ariel::operator>(const PhysicalNumber& p1, const PhysicalNumber& p2) {  if ((p1 < p2)) return true; else return false; }
bool ariel::operator<=(const PhysicalNumber& p1, const PhysicalNumber& p2) { if (!(p2 >= p1)) return true; else return false; }
bool ariel::operator<(const PhysicalNumber& p1, const PhysicalNumber& p2) { if (!(p2 > p1)) return true; else return false; }
//bool ariel::operator<(const PhysicalNumber& p1, const PhysicalNumber& p2) { if (!(p2 > p1)) return true; else return false; }


ostream& ariel::operator<< (ostream& os, const PhysicalNumber& num) {
    string printUnit = "";
    switch(num._unit){
        case Unit::KM: printUnit = "[km]"; break;
        case Unit::M: printUnit = "[m]"; break;
        case Unit::CM: printUnit = "[cm]"; break;
        case Unit::SEC: printUnit = "[sec]"; break;
        case Unit::HOUR: printUnit = "[hour]"; break;
        case Unit::G: printUnit = "[g]"; break;
        case Unit::KG: printUnit = "[kg]"; break;
        case Unit::TON: printUnit = "[ton]"; break;
        default: printUnit = "[deafult]"; break; //need to correct, case of cout << a+b << endl;
    }
    return os << num._value << '[' << printUnit << ']';
}

//Input operator, example: istringstream input("700[kg]"); input >> a;
istream& ariel::operator>> (istream& is, PhysicalNumber& num){
    is>> num._value; //need to correct
    return is;
}
