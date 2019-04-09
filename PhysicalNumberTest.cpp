/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);
    // MY BASIC TESTS 
    PhysicalNumber e(3, Unit::KM);
    PhysicalNumber f(400, Unit::M);
    PhysicalNumber j(450, Unit::CM);
    PhysicalNumber g(3, Unit::HOUR);
    PhysicalNumber h(40, Unit::MIN);
    PhysicalNumber i(300, Unit::SEC);
    PhysicalNumber k(10, Unit::G);
    PhysicalNumber l(4, Unit::KG);
    PhysicalNumber m(1, Unit::TON);
  
    
    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT

      .setname("My Basic output")
      .CHECK_OUTPUT(e, "3[km]")
      .CHECK_OUTPUT(f, "400[m]")
      .CHECK_OUTPUT(g, "3[hour]")
      .CHECK_OUTPUT(h, "40[min]")
      .CHECK_OUTPUT(i, "300[sec]")
      .CHECK_OUTPUT(j, "450[cm]")
      .CHECK_OUTPUT(k, "10[g]")
      .CHECK_OUTPUT(l, "4[kg]")
      .CHECK_OUTPUT(m, "1[ton]")
      
      .setname("Compatible dimensions")
      .CHECK_OUTPUT(f+e, "3400[m]")
      .CHECK_OUTPUT((e+=f), "3.4[km]")
      .CHECK_OUTPUT(e, "3.4[km]")
      .CHECK_OUTPUT(e+e, "6.8[km]")
      .CHECK_OUTPUT(j+f, "40450[cm]")
      .CHECK_OUTPUT((f+=j), "404.5[m]")
      .CHECK_OUTPUT(f, "400.450[m]")
      .CHECK_OUTPUT(f-f, "0[m]")
      .CHECK_OUTPUT(e-e, "0[km]")
      .CHECK_OUTPUT(j-j, "0[km]")
      .CHECK_OUTPUT(g+g, "6[hour]")
      .CHECK_OUTPUT(h+h, "80[min]")
      .CHECK_OUTPUT(i+i, "600[sec]") 
      .CHECK_OUTPUT(, "600[sec]") 
      .CHECK_OUTPUT(h+g, "220[min]")
      .CHECK_OUTPUT(h+i, "45[min]")
      .CHECK_OUTPUT(h-i, "35[min]")
      .CHECK_OUTPUT(g-g, "0[hour]")
      .CHECK_OUTPUT(h-h, "0[min]")
      .CHECK_OUTPUT(i-i, "0[sec]")
      
      
      .setname("Incompatible dimensions")
      .CHECK_THROWS(e+g)
      .CHECK_THROWS(e+h)
      .CHECK_THROWS(e+i)
      .CHECK_THROWS(f+g)
      .CHECK_THROWS(f+h)
      .CHECK_THROWS(f+i)
      .CHECK_THROWS(j+g)
      .CHECK_THROWS(j+h)
      .CHECK_THROWS(j+i)
      .CHECK_THROWS(k+g)
      .CHECK_THROWS(k+h)
      .CHECK_THROWS(k+i)
      .CHECK_THROWS(l+g)
      .CHECK_THROWS(l+h)
      .CHECK_THROWS(l+i)
      .CHECK_THROWS(m+g)
      .CHECK_THROWS(m+h)
      .CHECK_THROWS(m+i)

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
