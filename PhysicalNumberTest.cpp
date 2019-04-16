/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */
#include <string>
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

	PhysicalNumber km(5, Unit::KM);
	PhysicalNumber m(600, Unit::M);
	PhysicalNumber cm(10, Unit::CM);
		
	PhysicalNumber hour(4, Unit::HOUR);
	PhysicalNumber min(60, Unit::MIN);
	PhysicalNumber sec(120, Unit::SEC);

	PhysicalNumber g(6, Unit::G);
	PhysicalNumber kg(3, Unit::KG);
	PhysicalNumber ton(7, Unit::TON);

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

	.setname("My Basic output")
	.CHECK_OUTPUT(km, "5[km]")
	.CHECK_OUTPUT(g, "6[g]")
	.CHECK_OUTPUT(ton, "7[ton]")
	.CHECK_OUTPUT(min, "60[min]")

	.setname("My Compatible dimensions")
	.CHECK_OUTPUT(km + m, "5.6[km]")
	.CHECK_OUTPUT(cm + km, "500010[cm]")
	.CHECK_OUTPUT(m + cm, "600.1[m]")
	.CHECK_OUTPUT(hour + min, "5[hour]")
	.CHECK_OUTPUT(min + sec, "62[min]")
	.CHECK_OUTPUT(sec + hour, "14520[sec]")
	
	.setname("My Incompatible dimensions")
	.CHECK_THROWS(m + min)
	.CHECK_THROWS(cm + g)
	.CHECK_THROWS(hour + ton)
	.CHECK_THROWS(sec + kg)
	.CHECK_THROWS(km + min)

	.setname("My boolean test")
	.CHECK_EQUAL((kg == kg), true)
	.CHECK_EQUAL((hour >= PhysicalNumber(7, Unit::HOUR)), false)
	.CHECK_EQUAL((kg <= PhysicalNumber(3, Unit::KG)), true)
	.CHECK_EQUAL((cm > PhysicalNumber(3, Unit::CM)), true)
	.CHECK_EQUAL((ton < PhysicalNumber(4, Unit::TON)), false)
	.CHECK_EQUAL((g == PhysicalNumber(3, Unit::G)), true)

	.setname("My Basic input")
	.CHECK_OK(istringstream("70[kg]") >> km)
	.CHECK_OUTPUT((hour -= PhysicalNumber(2, Unit::HOUR)), "2[hour]")

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}