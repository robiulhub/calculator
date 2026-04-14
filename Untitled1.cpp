#include <iostream>
#include <stack>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <string>

using namespace std;

// ---------- clean number format ----------
string format(double x) {
    stringstream ss;
    ss << fixed << setprecision(10) << x;
    string s = ss.str();

    s.erase(s.find_last_not_of('0') + 1, string::npos);
    if (!s.empty() && s.back() == '.') s.pop_back();

    return s;
}

// ---------- precedence ----------
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' ) return 2;
    if (op == '^') return 3;
    return 0;
}

// ---------- apply normal operations ----------
double applyOp(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b != 0) ? a / b : 0;
        case '^': return pow(a, b);
    }
    return 0;
}

// ---------- evaluate expression ----------
double evaluate(string expr) {
    stack<double> values;
    stack<char> ops;

    for (int i = 0; i < expr.length(); i++) {

        if (expr[i] == ' ') continue;

        // number (supports decimal)
        if (isdigit(expr[i]) || expr[i] == '.') {
            string num = "";

            while (i < expr.length() &&
                  (isdigit(expr[i]) || expr[i] == '.')) {
                num += expr[i];
                i++;
            }

            values.push(stod(num));
            i--;
        }

        else if (expr[i] == '(') ops.push('(');

        else if (expr[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(a, b, op));
            }
            ops.pop();
        }

        else {
            while (!ops.empty() &&
                   precedence(ops.top()) >= precedence(expr[i])) {

                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();

                values.push(applyOp(a, b, op));
            }
            ops.push(expr[i]);
        }
    }

    while (!ops.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(a, b, op));
    }

    return values.top();
}

// ---------- replace all occurrences ----------
void replaceAll(string &expr, const string &from, const string &to) {
    size_t pos;
    while ((pos = expr.find(from)) != string::npos) {
        expr.replace(pos, from.length(), to);
    }
}

// ---------- main ----------
int main() {

    string expr;
    double ans = 0;
    bool hasAns = false;

    cout << "====== SMART CALCULATOR V1.5 ======\n";
    cout << "Operators: + , - , * , / , % , ^\n";
    cout << "% calculation available. Example: 30% of 20000 | 1000 * 30% | 50% + 20 | 30 % 1000\n";
    cout << "Power (^) calculation available. Example: 2^2 = 4\n";
    cout << "( ) supported system\n";
    cout << "Discount calculation intigrated.\nExample: 20000 - 10% of 20000\n";
    cout << "Decimals supported (1.222 system)\n";
    cout << "y = previous answer\n";
    cout << "r = reset | q = quit\n";
    cout << "==============================================\n";

    while (true) {

        cout << "\nEnter expression: ";
        getline(cin, expr);

        // QUIT
        if (expr == "q" || expr == "Q") {
            cout << "?? Goodbye!\n";
            break;
        }

        // RESET
        if (expr == "r" || expr == "R") {
            cout << "?? Reset Done!\n";
            ans = 0;
            hasAns = false;
            continue;
        }

        // replace y with ans
        if (hasAns) {
            replaceAll(expr, "y", format(ans));
        }

        // =========================
        // ?? PERCENTAGE SYSTEM
        // =========================
        // Example: 30%  ?  0.3
        size_t pos;

        // convert "30% of 200" style ? (30/100)*200
        while ((pos = expr.find("% of")) != string::npos) {
            expr.replace(pos, 4, "/100*");
        }

        // convert single percent values
        while ((pos = expr.find('%')) != string::npos) {
            expr.replace(pos, 1, "/100");
        }

        try {
            double result = evaluate(expr);

            cout << "====================\n";
            cout << "Result: " << format(result) << endl;
            cout << "====================\n";

            ans = result;
            hasAns = true;

        } catch (...) {
            cout << "? Invalid Expression!\n";
        }
    }

    return 0;
}
