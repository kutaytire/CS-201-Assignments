
/*

Kutay Tire
22001787
Sec03
04.01.2022

*/

#include "Stack.h"
#include "AlgebraicExpression.h"
#include <iostream>
using namespace std;
#include <string>
#include <sstream>




void reverseString(string& str) {
    int n = str.length();

    for (int i=0, j=n-1; i<j; i++,j--)
        swap(str[i], str[j]);
}



int priority( char ch) {

    if (ch == '+' || ch == '-') {

        return 0;
    }

    else if (ch == '*' || ch == '/') {

        return 1;
    }

}

string infix2prefix( const string exp ) {

    string postfix;
    postfix = infix2postfix( exp );
    return postfix2prefix(postfix);
}




string infix2postfix( const string exp ){

    string postFixExp;
    Stack aStack;
    char top;
    string tops;
    string value;
    int a = 0;

    while ( a < exp.length()) {

            while (exp[a] != ' ' && a < exp.length()) {

                value = value + exp[a];
                a++;


            }



            if (value == "(") {


                aStack.push(value);
            }

            else if ( value == ")") {


                aStack.getTop(tops);
                top = tops[0];

                while (top != '(') {

                    postFixExp = postFixExp + top + " ";
                    aStack.pop();
                    aStack.getTop(tops);
                    top = tops[0];

                }

                aStack.pop();
            }

            else if ( value == "+" || value == "-" || value == "*" || value == "/") {

                    aStack.getTop(tops);
                    top = tops[0];


                while( !aStack.isEmpty() && top != '(' && priority(value[0]) <= priority(top)) {

                        postFixExp = postFixExp + top + " ";
                        aStack.pop();
                        aStack.getTop(tops);
                        top = tops[0];

                    }

                    aStack.push(value);

            }

            else if (value != " ") {

                postFixExp = postFixExp + value + " ";

            }
            a++;
            value = "";

    }

    while (!aStack.isEmpty()) {

            aStack.getTop(tops);
            top = tops[0];
            postFixExp = postFixExp + top + " ";
            aStack.pop();

    }


    postFixExp.erase(postFixExp.length()-1,1);


    return postFixExp;

}


double evaluatePostfix( const string exp ) {

    double result;
    string results;
    Stack aStack;
    char top;
    string tops;
    string value = "";
    int a = 0;

    while( a < exp.length())  {

            while ( exp[a] != ' ' && a < exp.length()) {


                value = value + exp[a];

                a++;
            }



            if ( !(value == "+" || value == "-" || value == "*" || value == "/" )) {

                aStack.push(value);

            }

            else {

                double operand1;
                double operand2;
                aStack.getTop(tops);

                string operands1 = tops;
                aStack.pop();
                aStack.getTop(tops);

                string operands2 = tops;
                aStack.pop();


                stringstream ss1;
                ss1 << operands1;
                ss1 >> operand1;

                stringstream ss2;
                ss2 << operands2;
                ss2 >> operand2;

                if ( value == "+") {

                    result = operand1 + operand2;

                }

                else if ( value == "-") {

                    result = operand2 - operand1;

                }

                else if ( value == "*") {

                    result = operand1 * operand2;

                }

                else if ( value == "/") {

                    result = operand2 / operand1;

                }

                ostringstream streamObj;
                streamObj << result;
                results = streamObj.str();


                aStack.push(results);



            }
            a++;
            value = "";
        }

         if (!aStack.isEmpty()) {


            double operand;
            string result3;
            aStack.getTop(result3);
            stringstream ss1;
                ss1 << result3;
                ss1 >> operand;

            return operand;
         }

         return result;

}



string prefix2postfixSubMethod(string& exp, string& postfix) {

    int a = 0;
    string value = "";
    while ( exp[a] != ' ' && a != exp.length() ) {

            value = value + exp[a];
            a++;

    }

    exp.erase(0, value.length() + 1);


    if ( value != "+" && value != "-" && value != "*" && value != "/"  ) {

        postfix.append(value);
        postfix.append(" ");


    }

    else {

        prefix2postfixSubMethod(exp, postfix);

        prefix2postfixSubMethod(exp, postfix);

        postfix.append(value);
        postfix.append(" ");

    }
    return postfix;

}

string prefix2postfix( const string exp) {

    string out;
    string in = exp;
    prefix2postfixSubMethod(in, out);
    out.erase(out.length() - 1, 1);

    return out;

}

double evaluatePrefix( const string exp ){

    string post;

    post = prefix2postfix(exp);
    return evaluatePostfix(post);


}

string prefix2infix( const string exp ){

    string postfix;
    postfix = prefix2postfix(exp);
    return postfix2infix(postfix);


    // Alternative Implementation


    /*
        Stack aStack;
        int a = exp.length() - 1;
        string value = "";
        string top = "";

        while ( a >= 0) {


            while ( exp[a] != ' ' && a >= 0 ) {

                value = value + exp[a];
                a--;
            }

            reverseString( value);


            if ( value != "+" && value != "-" && value != "*" && value != "/") {


                aStack.push(value);
            }

            else {


                aStack.getTop(top);
                string op1 = top;
                aStack.pop();

                aStack.getTop(top);
                string op2 = top;
                aStack.pop();

                string temp = "( " + op1 + " "  + value + " " + op2 + " )";

                aStack.push(temp);
            }
            a--;
            value = "";


        }

        aStack.getTop(top);
        return top;
    */

}

double evaluateInfix( const string exp ){

    string infix;

    infix = infix2postfix(exp);
    return evaluatePostfix(infix);


}

string postfix2infix( const string exp ){

    Stack aStack;
    int a = 0;
    string value = "";
    string top = "";

    while ( a < exp.length()) {


        while ( exp[a] != ' ' && a < exp.length() ) {

            value = value + exp[a];
            a++;
        }



        if ( value != "+" && value != "-" && value != "*" && value != "/") {


            aStack.push(value);
        }

        else {


            aStack.getTop(top);
            string op1 = top;
            aStack.pop();

            aStack.getTop(top);
            string op2 = top;
            aStack.pop();

            string temp = "( " + op2 + " "  + value + " " + op1 + " )";

            aStack.push(temp);
        }
        a++;
        value = "";


    }

    aStack.getTop(top);

    cout << top.length()<< endl;
    //top.erase(top.length()-1,1);
    return top;

}

string postfix2prefix( const string exp ){



    Stack aStack;
    int a = 0;
    string value = "";
    string top = "";

    while ( a < exp.length()) {


        while ( exp[a] != ' ' && a < exp.length() ) {

            value = value + exp[a];
            a++;
        }


        if ( value != "+" && value != "-" && value != "*" && value != "/") {


            aStack.push(value);
        }

        else {


            aStack.getTop(top);
            string op1 = top;
            aStack.pop();

            aStack.getTop(top);
            string op2 = top;
            aStack.pop();


            string temp =  value + " "  + op2 + " " + op1 ;

            aStack.push(temp);
        }
        a++;
        value = "";


    }

    aStack.getTop(top);
    return top;


/*

    string infix = postfix2infix(exp);
    return infix2prefix(infix);

*/


}


