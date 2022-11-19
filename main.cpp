#include <iostream>
#include <string>
#include "trigfunc.h"
using namespace std;
double exp(double a, double b);
double nthroot(double, double);
string calculate(string str);
double num1, num2, num3, test, a_double, b_double, f_double, n_double, num_double, np_double, limit_double, index_double, x_double, sum, i;
float f_float;
const float pi(3.141592653589793238);
const float e(2.71828);
int userInput, trigUserInput;
string equation, answer;

// Check if string can be converted to double.
bool String2Double(string inputString, double& result) {
    char* end;
    result = strtod(inputString.c_str(), &end);
    if (end == inputString.c_str() || *end != '\0') return false;
    return true;
}

bool isNumber(string s) // if number or variable
{
    for (size_t i = 0; i < s.length(); i++) {
        char a = s[i];
        if (!std::isdigit(a) || a == '.' || isalpha(a)) {
            return false;
        }
    }
    return true;
}

// credits to fastapprox for this implementation its extremely fast.
float mylog2(float x)
{
    union { float f; uint32_t i; } vx = { x };
    union { uint32_t i; float f; } mx = { (vx.i & 0x007FFFFF) | 0x3f000000 };
    float y = vx.i;
    y *= 1.1920928955078125e-7f;

    return y - 124.22551499f
        - 1.498030302f * mx.f
        - 1.72587999f / (0.3520887068f + mx.f);
}

string ln(string x)
{
    if (String2Double(x, test) == true) {
        double x_double = stod(x);
        string test("");
    }
    else {
        x_double = stod(calculate(x));
    }
    return to_string(0.69314718f * mylog2(x_double));
}

double multdec(double x, int i) {
    double r = 1.0;
    for (i; i > 0; i--) r *= x;
    return r;
}

// log_b(x) = log_e(x) / log_e(b)
string mylog(string b, string n) {

    if (String2Double(b, test) == true) {
        double b_double = stod(b);
        string test("");
    }
    else {
        b_double = stod(calculate(b));
    }
    if (String2Double(n, test) == true) {
        double n_double = stod(n);
        string test("");
    }
    else {
        n_double = stod(calculate(n));
    }
    double val = 0;
    int i, a = 10, r = 0;
    while (n_double != 1 && a >= 0) {
        for (i = 0; n_double >= b_double; i++) n_double /= b_double;
        n = multdec(n_double, 10);
        val = 10 * (val + i);
        a--; r++;
    }
    return to_string(val / (double)multdec(10, r));
}

// log_b(x) = log_e(x) / log_e(b)
string mytestlog(string n) {
    double n_double;
    if (String2Double(n, test) == true) {
        n_double = stod(n);
        string test("");
    }
    else {
        n_double = stod(calculate(n));
    }
    double val = 0;
    int i, a = 10, r = 0;
    while (n_double != 1 && a >= 0) {
        for (i = 0; n_double >= 2; i++) n_double /= 2;
        n_double = multdec(n_double, 10);
        val = 10 * (val + i);
        a--; r++;
    }
    return to_string((double)val / (double)multdec(10, r));
}

double exp(string a, string b) {
    if (String2Double(a, test) == true) {
        double a_double = stod(a);
        string test("");
    }
    else {
        a_double = stod(calculate(a));
    }
    if (String2Double(b, test) == true) {
        double b_double = stod(b);
        string test("");
    }
    else {
        b_double = stod(calculate(b));
    }
    double t(1);
    for (int i = 0; i < b_double; ++i)
        t *= a_double;
    return t;
}

string add(string x, string y) {
    if (!isNumber(x)) {
        x = calculate(x);
    }
    double xd = stod(x);

    if (!isNumber(y)) {
        y = calculate(y);;
    }
    double yd = stod(y);
    return to_string(xd + yd);
}

string subtract(string x, string y) {
    if (!isNumber(x)) {
        x = calculate(x);
    }
    double xd = stod(x);

    if (!isNumber(y)) {
        y = calculate(y);
    }
    double yd = stod(y);
    return to_string(xd - yd);
}

string multiply(string x, string y) {
    if (!isNumber(x)) {
        x = calculate(x);
    }
    double xd = stod(x);

    if (!isNumber(y)) {
        y = calculate(y);
    }
    double yd = stod(y);
    return to_string(xd * yd);
}

string divide(string x, string y) {
    if (!isNumber(x)) {
        x = calculate(x);
    }
    double xd = stod(x);

    if (!isNumber(y)) {
        y = calculate(y);
    }
    double yd = stod(y);
    return to_string(xd / yd);
}

/*
// https://en.wikipedia.org/wiki/Nth_root#Computing_principal_roots
string nthroot(string num, string np) {
    if (String2Double(num, test) == true) {
        double num_double = stod(num);
        string test("");
    }
    else {
        num_double = stod(calculate(num));
    }
    if (String2Double(np, test) == true) {
        double np_double = stod(np);
        string test("");
    }
    else {
        np_double = stod(calculate(np));
    }
    double x;
    double A(num_double);
    double dx;
    double eps(10e-6);
    double n(np_double);
    x = A * 0.5;
    dx = (A / exp(x, n - 1) - x) / n;
    while (dx >= eps || dx <= -eps) {
        x = x + dx;
        dx = (A / exp(x, n - 1) - x) / n;
    }
    return to_string(x);
}
*/
string summation(string limit, string index, string x) {
    if (String2Double(limit, test) == true) {
        double limit_double = stod(limit);
        string test("");
    }
    else {
        limit_double = stod(calculate(limit));
    }
    if (String2Double(index, test) == true) {
        double index_double = stod(index);
        string test("");
    }
    else {
        index_double = stod(calculate(index));
    }
    if (String2Double(x, test) == true) {
        double x_double = stod(x);
        string test("");
    }
    else {
        x_double = stod(calculate(x));
    }
    double sum = 0;
    for (size_t i = index_double; i <= limit_double; i++) {
        sum += x_double;
    }
    return to_string(sum);
}

string product(string limit, string index, string x) {
    if (String2Double(limit, test) == true) {
        double limit_double = stod(limit);
        string test("");
    }
    else {
        limit_double = stod(calculate(limit));
    }
    if (String2Double(index, test) == true) {
        double index_double = stod(index);
        string test("");
    }
    else {
        index_double = stod(calculate(index));
    }
    if (String2Double(x, test) == true) {
        double x_double = stod(x);
        string test("");
    }
    else {
        x_double = stod(calculate(x));
    }
    double product = 1;
    for (size_t i = index_double; i <= limit_double; i++) {
        sum *= x_double;
    }
    return to_string(sum);
}
// These are just trig functions wrapped around David's code.
string cos(string f) {
    float f_float;
    if (String2Double(f, test) == true) {
        f_float = stof(f);
        string test("");
    }
    else {
        f_float = stod(calculate(f));
    }
    return to_string(cosFunction(f_float));
}

string sin(string f) {
    float f_float;
    if (String2Double(f, test) == true) {
        f_float = stof(f);
        string test("");
    }
    else {
        f_float = stod(calculate(f));
    }
    return to_string(sinFunction(f_float));
}

string tan(string f) {
    float f_float;
    if (String2Double(f, test) == true) {
        f_float = stof(f);
        string test("");
    }
    else {
        f_float = stod(calculate(f));
    }
    return to_string(tanFunction(f_float));
}

string cot(string f) {
    float f_float;
    if (String2Double(f, test) == true) {
        f_float = stof(f);
        string test("");
    }
    else {
        f_float = stod(calculate(f));
    }
    return to_string(cotFunction(f_float));
}

string csc(string f) {
    float f_float;
    if (String2Double(f, test) == true) {
        f_float = stof(f);
        string test("");
    }
    else {
        f_float = stod(calculate(f));
    }
    return to_string(cscFunction(f_float));
}

string sec(string f) {
    float f_float;
    if (String2Double(f, test) == true) {
        f_float = stof(f);
        string test("");
    }
    else {
        f_float = stod(calculate(f));
    }
    return to_string(secFunction(f_float));
}

string asin(string f) {
    float f_float;
    if (String2Double(f, test) == true) {
        f_float = stof(f);
        string test("");
    }
    else {
        f_float = stod(calculate(f));
    }
    return to_string(asinFunction(f_float));
}

string acos(string f) {
    float f_float;
    if (String2Double(f, test) == true) {
        f_float = stof(f);
        string test("");
    }
    else {
        f_float = stod(calculate(f));
    }
    return to_string(acosFunction(f_float));
}

string atan(string f) {
    float f_float;
    if (String2Double(f, test) == true) {
        f_float = stof(f);
        string test("");
    }
    else {
        f_float = stod(calculate(f));
    }
    return to_string(atanFunction(f_float));
}

string acsc(string f) {
    float f_float;
    if (String2Double(f, test) == true) {
        f_float = stof(f);
        string test("");
    }
    else {
        f_float = stod(calculate(f));
    }
    return to_string(acscFunction(f_float));
}

string asec(string f) {
    float f_float;
    if (String2Double(f, test) == true) {
        f_float = stof(f);
        string test("");
    }
    else {
        f_float = stod(calculate(f));
    }
    return to_string(asecFunction(f_float));
}

string acot(string f) {
    float f_float;
    if (String2Double(f, test) == true) {
        f_float = stof(f);
        string test("");
    }
    else {
        f_float = stod(calculate(f));
    }
    return to_string(acotFunction(f_float));
}

// takes string returns a number as a string
string factorial(string x)
{
    if (!isNumber(x)) {
        x = calculate(x);
    }
    double xd = stod(x);
    long long sum = 1;
    for (long long i = 2; i <= xd; i++) {
        sum *= i;
    }
    return to_string(sum);
}

// removes spaces
string removeSpaces(string str) {
    string newString = "";
    for (size_t i = 0; i < str.length(); i++) {
        if (str.at(i) != ' ') {
            newString += str.at(i);
        }
    }
    return newString;
}
// finds the character after the provided index
int findFront(string s, int index) {
    int brackets = 0;
    int front = 0;
    while (index >= 1) {
        index--;
        char a = s.at(index);
        if (isdigit(a) || a == '.') {
            front++;
        }
        else if (a == ')') {
            brackets++;
        }
        else if (brackets == 0) {
            return front;
        }
        if (a == '(') {
            brackets--;
        }
    }
    return front;
}
// finds the characters before the provided index
int findBack(string s, int index) {
    int brackets = 0;
    int front = 0;
    while (index < s.length() - 1) {
        index++;
        char a = s.at(index);
        if (isdigit(a) || a == '.') {
            front++;
        }
        else if (a == '(') {
            brackets++;
        }
        else if (brackets == 0) {
            return front;
        }
        if (a == ')') {
            brackets--;
        }
    }
    return front;
}

int findItem(string str, int index) {
    int num = 0;
    int brackets = 0;
    for (int i = (index + 1); i < str.length(); i++) {
        num++;
        if (str.at(i) == '(') {
            brackets++;
        }
        if (str.at(i) == ')') {
            brackets--;
        }

        if (brackets == 0) {
            return num;
        }

    }
    return num;
}

string frontString(string str, int index) {
    if (index == 0) return "";
    return str.substr(0, index);
}
string backString(string str, int index) {
    if (index == str.length() - 1) return "";
    return str.substr(index + 1, (str.length() - index - 1));
}
// 012(3)456

// main function that breaks everything into smaller equations
string calculate(string str) {
    string newString = removeSpaces(str);

    long long brackets = 0;

    long long index = 0; // if we call the indexs when they are -1 it means an error occoured

    long long strLen = 0;

    long long digitcount = 0;
    bool inObject = false; // we are inside* an object

    size_t length = newString.length();

    if (newString.at(0) == '(' && newString.at(length - 1) == ')') {
        newString = newString.substr(1, length - 2);
        length -= 2;
    }

    for (size_t i = 0; i < length; i++) {

        char a = newString.at(i);

        if (inObject == false) {
            index = i;
            inObject = true;
        }
        strLen++;
        if (isdigit(a) || a == '.') {
            digitcount++;
        }

        if (a == '^') {
            double front = findFront(newString, i);
            double back = findBack(newString, i);
            double k = exp(newString.substr((i - 1) - front, front), newString.substr((i + 1), back));
            return(calculate(newString.substr(0, i - front) + "(" + to_string(k) + ")" + newString.substr(i + 1 + back, (length - 1) - i - back)));
        }

        if (a == 'l' || a == '!' || a == '*' || a == '/' || a == '+' || a == '-') {
            if (inObject && brackets == 0) {
                inObject = false;
                if (a == 'l') {
                    string func = "";
                    int k = 0;
                    for (int j = i; j < length; j++) {
                        if (k >= 3) {
                            break;
                        }
                        func += newString.at(j);
                        if (func == "ln") {
                            // find next bracket object
                            return (frontString(newString, i) + ln(newString.substr(j + 1, findItem(newString, j))) + backString(newString, j + findItem(newString, j))); // findItem() find the length of the item to the right of the function
                        }
                        if (func == "log") {
                            return (frontString(newString, i) + mytestlog(newString.substr(j + 1, findItem(newString, j))) + backString(newString, j + findItem(newString, j)));
                        }
                        k++;
                    }
                    // 7 + sin(9 -4 + 3) - 3
                }
                if (a == '!') {
                    return factorial(newString.substr(index, strLen - 1));
                }
                if (a == '*') {
                    return multiply(newString.substr(index, strLen - 1), newString.substr(i + 1, length - strLen));
                }
                if (a == '/') {
                    return divide(newString.substr(index, strLen - 1), newString.substr(i + 1, length - strLen));
                }
                if (a == '+') {
                    return add(newString.substr(index, strLen - 1), newString.substr(i + 1, length - strLen));
                }
                if (a == '-') {
                    return subtract(newString.substr(index, strLen - 1), newString.substr(i + 1, length - strLen));
                }
            }
        }

        if (a == 's' || a == 'c' || a == 't' || a == 'a') {
            if (a == 's') {
                string func = "";
                int k = 0;
                for (int j = i; j < length; j++) {
                    if (k >= 3) {
                        break;
                    }
                    func += newString.at(j);

                    if (func == "sin") {
                        cout << "go fuck yourself" << endl;
                        // find next bracket object
                        return (frontString(newString, i) + sin(newString.substr(j + 1, findItem(newString, j))) + backString(newString, j + findItem(newString, j))); // findItem() find the length of the item to the right of the function
                    }
                    if (func == "sec") {
                        return (frontString(newString, i) + sec(newString.substr(j + 1, findItem(newString, j))) + backString(newString, j + findItem(newString, j)));
                    }
                    k++;
                }
            }
            if (a == 'c') {
                string func = "";
                int k = 0;
                for (int j = i; j < length; j++) {
                    if (k >= 3) {
                        break;
                    }
                    func += newString.at(j);
                    if (func == "cos") {
                        // find next bracket object
                        return (frontString(newString, i) + cos(newString.substr(j + 1, findItem(newString, j))) + backString(newString, j + findItem(newString, j))); // findItem() find the length of the item to the right of the function
                    }
                    if (func == "cot") {
                        return (frontString(newString, i) + cot(newString.substr(j + 1, findItem(newString, j))) + backString(newString, j + findItem(newString, j)));
                    }
                    if (func == "csc") {
                        return (frontString(newString, i) + csc(newString.substr(j + 1, findItem(newString, j))) + backString(newString, j + findItem(newString, j)));
                    }
                    k++;
                }
            }
            if (a == 't') {
                string func = "";
                int k = 0;
                for (int j = i; j < length; j++) {
                    if (k >= 3) {
                        break;
                    }
                    func += newString.at(j);
                    if (func == "tan") {
                        // find next bracket object
                        return (frontString(newString, i) + tan(newString.substr(j + 1, findItem(newString, j))) + backString(newString, j + findItem(newString, j))); // findItem() find the length of the item to the right of the function
                    }
                    k++;
                }
            }
            if (a == 'a') {
                string func = "";
                int k = 0;
                for (int j = i; j < length; j++) {
                    if (k >= 4) {
                        break;
                    }
                    func += newString.at(j);
                    if (func == "acos") {
                        // find next bracket object
                        return (frontString(newString, i) + acos(newString.substr(j + 1, findItem(newString, j))) + backString(newString, j + findItem(newString, j))); // findItem() find the length of the item to the right of the function
                    }
                    if (func == "atan") {
                        // find next bracket object
                        return (frontString(newString, i) + atan(newString.substr(j + 1, findItem(newString, j))) + backString(newString, j + findItem(newString, j))); // findItem() find the length of the item to the right of the function
                    }
                    if (func == "acsc") {
                        // find next bracket object
                        return (frontString(newString, i) + acsc(newString.substr(j + 1, findItem(newString, j))) + backString(newString, j + findItem(newString, j))); // findItem() find the length of the item to the right of the function
                    }
                    if (func == "asec") {
                        // find next bracket object
                        return (frontString(newString, i) + asec(newString.substr(j + 1, findItem(newString, j))) + backString(newString, j + findItem(newString, j))); // findItem() find the length of the item to the right of the function
                    }
                    if (func == "acot") {
                        // find next bracket object
                        return (frontString(newString, i) + acot(newString.substr(j + 1, findItem(newString, j))) + backString(newString, j + findItem(newString, j))); // findItem() find the length of the item to the right of the function
                    }
                    k++;
                }
            }
        }

        if (a == '(') {
            brackets++;
        }
        if (a == ')') {
            brackets--;
        }

    }
    return newString;
}

string parseEquation(string s) {
    string str = removeSpaces(s);
    string k = calculate(str);
    // return std::stod(k);
    return k;
}

int main()
{
    equation = "(((5!) * 3) + 5)/2";
    cout << "Example of an equation: " << endl;
    cout << equation << endl;
    cout << "Enter an equation: " << endl;
    getline(cin, equation);
    cout << parseEquation(equation) << endl;
    cout << "\nAction: (1:10)\n";
    cout << "1. Addition\n";
    cout << "2. Subtract\n";
    cout << "3. Multiply\n";
    cout << "4. Divide\n";
    cout << "5. Exponent\n";
    cout << "6. Logarithm\n";
    cout << "7. Natural Logarithm\n";
    cout << "8. Summation\n";
    cout << "9. Product\n";
    cout << "10. Inverse / trig functions\n";
    cin >> userInput;
    switch (userInput) {
    case 1:
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        answer = add(to_string(num1), to_string(num2));
        cout << answer;
        break;
    case 2:
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        answer = subtract(to_string(num1), to_string(num2));
        cout << answer;
        break;
    case 3:
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        answer = multiply(to_string(num1), to_string(num2));
        cout << answer;
        break;
    case 4:
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        answer = divide(to_string(num1), to_string(num2));
        cout << answer;
        break;
    case 5:
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        answer = exp(to_string(num1), to_string(num2));
        cout << answer;
        break;
    case 6:
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        answer = mylog(to_string(num1), to_string(num2));
        cout << answer;
        break;
    case 7:
        cout << "Enter first number: ";
        cin >> num1;
        answer = ln(to_string(num1));
        cout << answer;
        break;
    case 8:
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        cout << "Enter third number: ";
        cin >> num3;
        answer = summation(to_string(num1), to_string(num2), to_string(num3));
        cout << answer;
        break;
    case 9:
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        cout << "Enter third number: ";
        cin >> num3;
        answer = product(to_string(num1), to_string(num2), to_string(num3));
        cout << answer;
        break;
    case 10:
        cout << "Action: (1:12)\n";
        cout << "1. sin\n";
        cout << "2. cos\n";
        cout << "3. tan\n";
        cout << "4. cot\n";
        cout << "5. csc\n";
        cout << "6. sec\n";
        cout << "7. acos\n";
        cout << "8. atan\n";
        cout << "9. acsc\n";
        cout << "10. asec\n";
        cout << "11. acot\n";
        cout << "12. asin\n";
        cin >> trigUserInput;
        switch (trigUserInput) {
        case 1:
            cout << "Enter your number: ";
            cin >> num1;
            answer = sin(to_string(num1));
            cout << answer;
            break;
        case 2:
            cout << "Enter your number: ";
            cin >> num1;
            answer = cos(to_string(num1));
            cout << answer;
            break;
        case 3:
            cout << "Enter your number: ";
            cin >> num1;
            answer = tan(to_string(num1));
            cout << answer;
            break;
        case 4:
            cout << "Enter your number: ";
            cin >> num1;
            answer = cot(to_string(num1));
            cout << answer;
            break;
        case 5:
            cout << "Enter your number: ";
            cin >> num1;
            answer = csc(to_string(num1));
            cout << answer;
            break;
        case 6:
            cout << "Enter your number: ";
            cin >> num1;
            answer = sec(to_string(num1));
            cout << answer;
            break;
        case 7:
            cout << "Enter your number: ";
            cin >> num1;
            answer = acos(to_string(num1));
            cout << answer; 
            break;
        case 8:
            cout << "Enter your number: ";
            cin >> num1;
            answer = atan(to_string(num1));
            cout << answer; 
            break;
        case 9:
            cout << "Enter your number: ";
            cin >> num1;
            answer = acsc(to_string(num1));
            cout << answer; 
            break;
        case 10:
            cout << "Enter your number: ";
            cin >> num1;
            answer = asec(to_string(num1));
            cout << answer; 
            break;
        case 11:
            cout << "Enter your number: ";
            cin >> num1;
            answer = acot(to_string(num1));
            cout << answer; 
            break;
        case 12:
            cout << "Enter your number: ";
            cin >> num1;
            answer = asin(to_string(num1));
            cout << answer;
            break;
        }
        break;
    }

    return 0;
}
