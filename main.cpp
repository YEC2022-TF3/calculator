#include <iostream>
#include <trigfunc.h>
using namespace std;
double exponent(double, double);
double nthroot(double, double);
double test;

// Check if string can be converted to double.
bool String2Double(string inputString, double &result) {
    char* end;
    result = strtod(inputString.c_str(), &end);
    if (end == inputString.c_str() || *end != '\0') return false;
    return true;
}

// credits to fastapprox for this implementation its extremely fast.
static inline float
log2 (float x)
{
    union { float f; uint32_t i; } vx = { x };
    union { uint32_t i; float f; } mx = { (vx.i & 0x007FFFFF) | 0x3f000000 };
    float y = vx.i;
    y *= 1.1920928955078125e-7f;

    return y - 124.22551499f
             - 1.498030302f * mx.f
             - 1.72587999f / (0.3520887068f + mx.f);
}

string ln (string x)
{
    if (String2Double(x, test) = true) {
         double x = std::stod(x);
         string test("");
    }
    else {
         calculate
    }
    return 0.69314718f * log2 (x);
}

double multdec(double x, int i) {
    double r = 1.0;
    for(i; i > 0; i--) r *= x;
    return r;
}

// log_b(x) = log_e(x) / log_e(b)
string log(string b, string n) {
    if (String2Double(b, test) = true) {
         double b = std::stod(b);
         string test("");
    }
    else {
         calculate
    }
    if (String2Double(n, test) = true) {
         double n = std::stod(n);
         string test("");
    }
    else {
         calculate
    }
    double val = 0;
    int i, a = 10, r = 0;
    while(n != 1 && a >= 0) {
        for(i = 0; n >= b; i++) n /= b;
            n = multdec(n, 10);
            val = 10 * (val + i);
            a--; r++;
    }
    return (double)val / multdec(10, r);
}

string exponent(string a, string b){
    if (String2Double(a, test) = true) {
         double a = std::stod(a);
         string test("");
    }
    else {
         calculate
    }
    if (String2Double(b, test) = true) {
         double b = std::stod(b);
         string test("");
    }
    else {
         calculate
    }
    double t(1);
    for(int i = 0; i < b; ++i)
        t *= a;
    return t;
}

// https://en.wikipedia.org/wiki/Nth_root#Computing_principal_roots
string nthroot(string num, string np){
    if (String2Double(num, test) = true) {
         double num = std::stod(num);
         string test("");
    }
    else {
         calculate
    }
    if (String2Double(np, test) = true) {
         double np = std::stod(np);
         string test("");
    }
    else {
         calculate
    }
    double x;
    double A(num);
    double dx;
    double eps(10e-6);
    double n(np);
    x = A * 0.5;
    dx = (A/exponent(x, n-1)-x)/n;
    while(dx >= eps || dx <= -eps){
        x = x + dx;
        dx = (A/exponent(x, n - 1)-x)/n;
    }
   return x;
}

string summation(string limit, string index, string x){
    if (String2Double(limit, test) = true) {
         double limit = std::stod(limit);
         string test("");
    }
    else {
         calculate
    }
    if (String2Double(index, test) = true) {
         double index = std::stod(index);
         string test("");
    }
    else {
         calculate
    }
    if (String2Double(x, test) = true) {
         double x = std::stod(x);
         string test("");
    }
    else {
         calculate
    }
    double sum = 0;
    for(size_t = index; i <= limit; i++){
        sum += x;
    }
}

string product(string limit, string index, string x){
    if (String2Double(limit, test) = true) {
         double limit = std::stod(limit);
         string test("");
    }
    else {
         calculate
    }
    if (String2Double(index, test) = true) {
         double index = std::stod(index);
         string test("");
    }
    else {
         calculate
    }
    if (String2Double(x, test) = true) {
         double x = std::stod(x);
         string test("");
    }
    else {
         calculate
    }
    double product = 1;
    for(size_t = index;i <= limit; i++){
        sum *= x;
    }
}

// These are just trig functions wrapped around David's code.
string cos(string f){
    if (String2Double(f, test) = true) {
         float f = std::stof(f);
         string test("");
    }
    else {
         calculate
    }
    return cosFunction(f)
}

string sin(string f){
    if (String2Double(f, test) = true) {
         float f = std::stof(f);
         string test("");
    }
    else {
         calculate
    }
    return sinFunction(f)
}

string tan(string f){
    if (String2Double(f, test) = true) {
         float f = std::stof(f);
         string test("");
    }
    else {
         calculate
    }
    return tanFunction(f)
}

string cot(string f){
    if (String2Double(f, test) = true) {
         float f = std::stof(f);
         string test("");
    }
    else {
         calculate
    }
    return cotFunction(f)
}

string csc(string f){
    if (String2Double(f, test) = true) {
         float f = std::stof(f);
         string test("");
    }
    else {
         calculate
    }
    return cscFunction(f)
}

string sec(string f){
    if (String2Double(f, test) = true) {
         float f = std::stof(f);
         string test("");
    }
    else {
         calculate
    }
    return secFunction(f)
}

string asin(string f){
    if (String2Double(f, test) = true) {
         float f = std::stof(f);
         string test("");
    }
    else {
         calculate
    }
    return asinFunction(f)
}

string acos(string f){
    if (String2Double(f, test) = true) {
         float f = std::stof(f);
         string test("");
    }
    else {
         calculate
    }
    return acosFunction(f)
}

string atan(string f){
    if (String2Double(f, test) = true) {
         float f = std::stof(f);
         string test("");
    }
    else {
         calculate
    }
    return atanFunction(f)
}

string acsc(string f){
    if (String2Double(f, test) = true) {
         float f = std::stof(f);
         string test("");
    }
    else {
         calculate
    }
    return acscFunction(f)
}

string asec(string f){
    if (String2Double(f, test) = true) {
         float f = std::stof(f);
         string test("");
    }
    else {
         calculate
    }
    return asecFunction(f)
}

string acot(string f){
    if (String2Double(f, test) = true) {
         float f = std::stof(f);
         string test("");
    }
    else {
         calculate
    }
    return acotFunction(f)
}

bool isNumber(string s) // if number or variable
{
    for (size_t i = 0; i < s.length(); i++) {
        char a = s[i];
        if(!std::isdigit(a) || a=='.'|| isalpha(a) ){
            return false;
        }
    }
    return true;
}

// takes long long numbers returns
long long factorial(long long x)
{
    long long sum = 1;
    for(long long i = 2; i <= x; i++){
        sum *= i;
    }
    return sum;
}

// removes spaces
string removeSpaces(string str){
    string newString="";
    for(size_t i = 0; i < str.length() ; i++){
        if(str.at(i) != ' '){
            newString +=str.at(i);
        }
    }
    return newString;
}



string calculate(string str){

    if(isNumber(str)){ // if it's a number itself
        return str;
    }

    size_t length = str.length();
    if(str.at(0) == '(' && str.at(length-1) == ')'){ // removes front and last brackets if there are any
        return calculate(str.substr(1,length-2));
    }

    long long brackets =0;
    long long index = 0; // if we call the indexs when they are -1 it means an error occoured
    long long strLen =0;
    bool inObject = false; // we are inside* an object

    string answer="";

    // loops through string
    for(size_t i =0; i<length ;i++){
        strLen++;
        char a = str.at(i);
        if(inObject == false){
            index = i;
            inObject = true;
        }

        if(a=='+' ||a=='-' ||a=='*' ||a=='/' ||a=='^'){
            if(inObject && brackets == 0){
                inObject = false;
                answer+= calculate(str.substr(index, strLen-1)) + "\n"+ a + "\n";

                strLen =0;
                // cout << str.substr(index, strLen-1) << endl;
                // cout << '+' << endl;
            }
        }

        if(a == '('){
            brackets++;
        }
        if(a == ')'){
            brackets--;
        }
        if(i == length - 1){ // end of the string
         answer+= calculate(str.substr(index, strLen-1));
            // cout << str.substr(index, strLen) << endl;
        }
    }
    return answer;
}
string parseEquation(string s){
    string str = removeSpaces(s);
    string k = calculate(str);
    // return std::stod(k);
    return k;
}
int main()
{

    string s;
    s = "(((5 - 3) + 7)^3 + (9)) + (4 - 3) - 9";
    // s = "(((5 - 3) + 7)^3 + (9))";
    // s = "((5 - 3) + 7)+3";

    cout<<s<<endl;
    cout <<parseEquation(s) << endl;


    return 0;
}
