#include <cstdio>

class Print {
public:
    char sep = ' ';
    char end = '\n';
    Print(FILE *file) : _file(file) {}
    // 输出字符
    void operator()(char c) {
        putc(c, _file);
    }
    void operator()(const char *s) {
        while (*s++) putc(*s, _file);
    }
    void operator()(int x) {
        if (x == 0) {
            putc('0', _file);
            return ;
        } else if (x < 0) {
            putc('-', _file);
            x = -x;
        }
        char s[15];
        int n = 0;
        while (x) {

        }
    }
private:
    FILE *_file;
} print(stdout);

int main() {
    print('a');
    print("abcd");
    return 0;
}