
/*

Kutay Tire
22001787
Sec03
04.01.2022

*/
#include <iostream>

#include "AlgebraicExpression.h"

using namespace std;

int main() {


cout << infix2postfix("( 102 + 3 ) - 9 * 13") << endl;

cout << infix2postfix("100") << endl;
cout << infix2prefix("( 45 - 6 ) * 7 - ( 55 + 3 ) / 1 * 2") << endl;

cout << infix2prefix("100") << endl;


cout << evaluatePostfix("200 7 35 - 6 * + 5 /") << endl;

cout << evaluatePostfix("100") << endl;
cout << evaluateInfix("15") << endl;
cout << evaluatePrefix("30") << endl;

cout<< "imp"<< endl;

cout << prefix2postfix("- + / 200 7 35 - 6 5") << endl;
cout << evaluatePrefix("* + * 200 7 35 - 6 5") << endl;
cout << prefix2infix("- + / 200 7 35 - 6 5") << endl;

cout << evaluateInfix("( 15 + 40 ) - 30 * 12") << endl;
cout << postfix2infix("200 7 9 - 21 * + 3 /") << endl;

cout << postfix2infix("100") << endl;


cout << postfix2prefix("200 7 35 - 6 * + 5 /") << endl;

cout << postfix2prefix("100") << endl;


cout << prefix2postfix("- + / 200 7 35 - 6 5") << endl;


return 0;
}

