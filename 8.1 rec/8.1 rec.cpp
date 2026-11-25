// ЛР 8.1, варіант 6 (рекурсивний спосіб, C++).
// 1. Вияснити, чи є серед символів пара сусідніх букв "SQ" або "QS".
// 2. Замінити кожну пару сусідніх букв "SQ" або "QS" трійкою зірочок "***".

#include <iostream>
#include <string>

using namespace std;

// Повертає true, якщо пара символів (a, b) є "SQ" або "QS".
bool IsSQPair(char a, char b)
{
    return (a == 'S' && b == 'Q') || (a == 'Q' && b == 'S');
}

// Рекурсивно шукає пару "SQ" або "QS" в рядку s, починаючи з позиції pos.
bool HasSQPairRec(const string& s, size_t pos = 0)
{
    if (pos + 1 >= s.size())
    {
        return false;
    }
    if (IsSQPair(s[pos], s[pos + 1]))
    {
        return true;
    }
    return HasSQPairRec(s, pos + 1);
}

// Рекурсивно будує рядок, замінюючи кожну пару "SQ" або "QS" на "***",
// починаючи з позиції pos рядка s.
string ReplaceSQPairsRec(const string& s, size_t pos = 0)
{
    if (pos >= s.size())
    {
        return "";
    }
    if (pos + 1 < s.size() && IsSQPair(s[pos], s[pos + 1]))
    {
        return "***" + ReplaceSQPairsRec(s, pos + 2);
    }
    return string(1, s[pos]) + ReplaceSQPairsRec(s, pos + 1);
}

#ifndef UNIT_TEST
int main()
{
    string input;

    cout << "Enter string: ";
    getline(cin, input);

    if (HasSQPairRec(input))
    {
        cout << "String contains pair \"SQ\" or \"QS\"." << endl;
    }
    else
    {
        cout << "String does not contain pair \"SQ\" or \"QS\"." << endl;
    }

    string modified = ReplaceSQPairsRec(input);
    cout << "Modified string: " << modified << endl;

    return 0;
}
#endif

