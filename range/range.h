#ifndef RANGE_H
#define RANGE_H

#include <iostream>

// 模拟Python中的range
class range {
private:
    class iterator;
public:
    range(int end) : m_start(0), m_end(end), m_step(1) {}
    range(int start, int end, int step = 1)
    : m_start(start), m_end(end), m_step(step) {}
    iterator begin() const {
        return iterator(this, m_start);
    }
    iterator end() const {
        return iterator(this, m_end);
    }
private:
    class iterator {
    public:
        iterator(const range *rg, int now) : m_range(rg), m_now(now) {}
        int operator*() {
            return m_now;
        }
        void operator++() {
            m_now += m_range->m_step;
        }
        bool operator!=(iterator other) {
            if (m_range->m_step >= 0 && m_now >= m_range->m_end
                && other.m_now >= other.m_range->m_end) return false;
            if (m_range->m_step < 0 && m_now <= m_range->m_end
                && other.m_now <= other.m_range->m_end) return false;
            return m_now != other.m_now;
        }
    private:
        const range *m_range;
        int m_now;
    };
    int m_start;
    int m_end;
    int m_step;
};

// 输出单链表
std::ostream& operator<<(std::ostream &out, const range &rg) {
    bool first = true;
    for (int i : rg) {
        if (first) {
            out << "[";
            first = false;
        } else {
            out << ", ";
        }
        out << i;
    }
    out << "]";
    return out;
}

#endif // RANGE_H