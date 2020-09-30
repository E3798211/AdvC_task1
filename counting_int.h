
#ifndef   COUNTING_INT_H_INCLUDED
#define   COUNTING_INT_H_INCLUDED

#include <iostream>

class CountingInt
{
private:
    int storage;

    mutable int n_compares;
    mutable int n_assignments;
public:
    /* Not explicit */
    CountingInt(int def = 0) noexcept
        : storage       (def)
        , n_compares    (0)
        , n_assignments (0)
    {}
    CountingInt(const CountingInt &rhs) noexcept
        : storage       (rhs.storage)
        , n_compares    (0)
        , n_assignments (0)
    {}
    /* Delegating */
    CountingInt(CountingInt &&rhs) noexcept
        : CountingInt   (rhs)
    {}

    CountingInt& operator=(const CountingInt &rhs) noexcept {
        storage = rhs.storage;
        n_assignments++;
        return *this;
    }
    bool operator==(const CountingInt &rhs) const noexcept {
        n_compares++;
        return storage == rhs.storage;
    }
    
    bool operator<(const CountingInt &rhs) const noexcept {
        n_compares++;
        return storage < rhs.storage;
    }

    int operator++() noexcept {
        return storage++;
    }
    int operator++(int) noexcept {
        return ++storage;
    }

    int times_compared_against() const noexcept {
        return n_compares;
    }
    int times_assigned() const noexcept {
        return n_assignments;
    }

    /* Risking to leave it not explicit */
    operator int() const noexcept {
        return storage;
    }

    friend std::ostream& operator<<(std::ostream& os,
                                    const CountingInt &rhs) {
        os << "(" << rhs.storage << " " << rhs.n_compares
           << " " << rhs.n_assignments << ")";
        return os;
    }

};

#endif // COUNTING_INT_H_INCLUDED

