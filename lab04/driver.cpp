#include <iostream>
#include <string>
using namespace std;

#include "LinkedList.hpp"

template <typename Func>
void expectThrow(const string& testName, Func f) {
    try {
        f();
        cout << "[FAIL] " << testName << " (no exception thrown)\n";
    } catch (string& e) {
        cout << "[PASS] " << testName << " -> threw: " << e << "\n";
    } catch (...) {
        cout << "[FAIL] " << testName << " -> threw non-string exception\n";
    }
}

int main() {
    cout << "===== LinkedList<int> Tests =====\n";
    LinkedList<int> L;

    cout << "\n-- Print empty --\n";
    cout << L;

    cout << "\n-- Exceptions on empty --\n";
    expectThrow("getElement(0) on empty", [&](){ L.getElement(0); });
    expectThrow("replace(0, x) on empty", [&](){ L.replace(0, 999); });

    cout << "\n-- Append 3 elements --\n";
    L.append(10);
    cout << "After append(10): " << L;
    L.append(20);
    cout << "After append(20): " << L;
    L.append(30);
    cout << "After append(30): " << L;

    cout << "\nLength should be 3: " << L.getLength() << "\n";

    cout << "\n-- getElement valid positions --\n";
    cout << "getElement(0) = " << L.getElement(0) << "\n";
    cout << "getElement(1) = " << L.getElement(1) << "\n";
    cout << "getElement(2) = " << L.getElement(2) << "\n";

    cout << "\n-- getElement invalid positions --\n";
    expectThrow("getElement(-1)", [&](){ L.getElement(-1); });
    expectThrow("getElement(3)",  [&](){ L.getElement(3); });

    cout << "\n-- replace valid positions --\n";
    L.replace(0, 111);
    cout << "After replace(0,111): " << L;
    L.replace(1, 222);
    cout << "After replace(1,222): " << L;
    L.replace(2, 333);
    cout << "After replace(2,333): " << L;

    cout << "\n-- replace invalid positions --\n";
    expectThrow("replace(-1, x)", [&](){ L.replace(-1, 5); });
    expectThrow("replace(3, x)",  [&](){ L.replace(3, 5); });

    cout << "\n-- clear non-empty --\n";
    L.clear();
    cout << "After clear(): " << L;
    cout << "Length should be 0: " << L.getLength() << "\n";

    cout << "\n-- clear already empty (should not crash) --\n";
    L.clear();
    cout << "After clear() again: " << L;

    cout << "\n===== LinkedList<string> Tests =====\n";
    LinkedList<string> S;
    cout << "Empty string list: " << S;

    S.append("CS");
    S.append("20");
    S.append("LinkedList");
    cout << "After appends: " << S;
    cout << "Length: " << S.getLength() << "\n";
    cout << "getElement(2) = " << S.getElement(2) << "\n";

    S.replace(1, "is");
    cout << "After replace(1,\"is\"): " << S;

    expectThrow("string getElement(99)", [&](){ S.getElement(99); });

    cout << "\nDONE\n";
    return 0;
}

