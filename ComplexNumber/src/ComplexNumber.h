#include <ostream>
#include <cmath>
#include <iomanip>
#include "RealNumber.h"

class ComplexNumber {
 public:
    explicit ComplexNumber(RealNumber = RealNumber(0), RealNumber = RealNumber(0)) noexcept;

    template <typename T = int>
    explicit ComplexNumber(T re, T im = static_cast<T>(0)) noexcept {
        this->re_ = RealNumber(re);
        this->im_ = RealNumber(im);
    }

    RealNumber getRe() const noexcept;

    void setRe(RealNumber) noexcept;

    RealNumber getIm() const noexcept;

    void setIm(RealNumber) noexcept;

    double abs() const noexcept;

    double arg() const noexcept;

    ComplexNumber pow(int) const noexcept;

    ComplexNumber &operator=(const ComplexNumber &) noexcept;

    bool operator==(const ComplexNumber &) const noexcept;

    template <typename T>
    bool operator==(const T &) const noexcept;

    template <typename T>
    bool operator!=(const T &) const noexcept;

    ComplexNumber operator+(const ComplexNumber &) const noexcept;

    template <typename T>
    ComplexNumber operator+(const T &other) const noexcept {
        return *this + ComplexNumber(other);
    }

    ComplexNumber operator-(const ComplexNumber &) const noexcept;

    template <typename T>
    ComplexNumber operator-(const T &other) const noexcept {
        return *this - ComplexNumber(other);
    }

    ComplexNumber operator*(const ComplexNumber &) const noexcept;

    template <typename T>
    ComplexNumber operator*(const T &other) const noexcept {
        return *this * ComplexNumber(other);
    }

    ComplexNumber operator/(const ComplexNumber &) const noexcept;

    template <typename T>
    ComplexNumber operator/(const T &other) const noexcept {
        return *this / ComplexNumber(other);
    }

    template <typename T>
    ComplexNumber &operator+=(const T &other) noexcept {
        *this = operator+(other);
        return *this;
    }

    template <typename T>
    ComplexNumber &operator-=(const T &other) noexcept {
        *this = operator-(other);
        return *this;
    }

    template <typename T>
    ComplexNumber &operator*=(const T &other) noexcept {
        *this = operator*(other);
        return *this;
    }

    template <typename T>
    ComplexNumber &operator/=(const T &other) noexcept {
        *this = operator/(other);
        return *this;
    }

    ComplexNumber operator-() const noexcept;

    friend std::ostream &operator<<(std::ostream &, const ComplexNumber &) noexcept;

 private:
    RealNumber re_, im_;
};
