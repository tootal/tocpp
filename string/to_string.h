#ifndef TO_STRING_H
#define TO_STRING_H

namespace std {

string to_string(const char *s) {
    return "\"" + string(s) + "\"";
}

string to_string(const string &s) {
    return "\"" + s + "\"";
}

template <typename T1, typename T2>
string to_string(const pair<T1, T2> &x) {
    return "(" + to_string(x.first) + ", " + to_string(x.second) + ")";
}

template <typename T>
string to_string(vector<T> x) {
    string res = "{";
    bool first = true;
    for (auto &&i : x) {
        if (first) {
            first = false;
        } else {
            res += ", ";
        }
        res += to_string(i);
    }
    return res + "}";
}

template <typename T>
ostream& operator<<(ostream &out, const vector<T> &x) {
    out << to_string(x);
    return out;
}

template <typename T1, typename T2>
ostream& operator<<(ostream &out, const pair<T1, T2> &x) {
    out << to_string(x);
    return out;
}

}

#endif // TO_STRING_H