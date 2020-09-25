
#ifndef   COUNTING_INT_H_INCLUDED
#define   COUNTING_INT_H_INCLUDED

#include <iostream>

class CountingInt
{
private:
    int storge;

    mutable int n_compares;
    mutable int n_assignments;
public:
    /* Not explicit */
    CountingInt(int def = 0) noexcept
        : storge        (def)
        , n_compares    (0)
        , n_assignments (0)
    {}
    CountingInt(const CountingInt &rhs) noexcept
        : storge        (rhs.storge)
        , n_compares    (0)
        , n_assignments (0)
    {}
    /* Delegating */
    CountingInt(CountingInt &&rhs) noexcept
        : CountingInt   (rhs)
    {}

    CountingInt& operator=(const CountingInt &rhs) noexcept {
        storge = rhs.storge;
        n_assignments++;
        return *this;
    }
    bool operator==(const CountingInt &rhs) const noexcept {
        n_compares++;
        return storge == rhs.storge;
    }
    
    bool operator<(const CountingInt &rhs) const noexcept {
        n_compares++;
        return storge < rhs.storge;
    }

    int operator++() noexcept {
        return storge++;
    }
    int operator++(int) noexcept {
        return ++storge;
    }

    int times_compared_against() const noexcept {
        return n_compares;
    }
    int times_assigned() const noexcept {
        return n_assignments;
    }

    friend std::ostream& operator<<(std::ostream& os,
                                    const CountingInt &rhs) {
        os << "(" << rhs.storge << " " << rhs.n_compares
           << " " << rhs.n_assignments << ")";
        return os;
    }

};

#endif // COUNTING_INT_H_INCLUDED

