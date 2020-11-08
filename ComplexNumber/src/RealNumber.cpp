#include "RealNumber.h"

int64_t RealNumber::getNum() const noexcept {
    return num_;
}

void RealNumber::setNum(int num) noexcept {
    num_ = num;
}

int64_t RealNumber::getDenom() const noexcept {
    return denom_;
}

void RealNumber::setDenom(int denom) noexcept {
    denom_ = denom;
}

int RealNumber::sgn(int number) noexcept {
    return number < 0 ? -1 : 1;
}

RealNumber &RealNumber::operator=(const RealNumber &other) noexcept = default ;

bool RealNumber::operator==(const RealNumber &other) const noexcept {
    return this->num_ == other.num_ && this->denom_ == other.denom_;
}

bool RealNumber::operator!=(const RealNumber &other) const noexcept {
    return !(other == *this);
}

int64_t RealNumber::gcd(int64_t a, int64_t b) noexcept {
    a = std::abs(a);
    b = std::abs(b);

    if (a < b) {
        std::swap(a, b);
    }

    if (b == 0) {
        return 1;
    }

    while (a % b != 0) {
        a = a % b;
        std::swap(a, b);
    }

    return b;
}

int64_t RealNumber::commonDenom(int a, int b) noexcept {
    return (a * b) / gcd(a, b);
}

RealNumber RealNumber::operator+(const RealNumber &other) const noexcept {
    int64_t lcm = commonDenom(this->denom_, other.denom_);
    return RealNumber(this->num_ * lcm / this->denom_ + other.num_ * lcm / other.denom_, lcm);
}

RealNumber RealNumber::operator-(const RealNumber &other) const noexcept {
    int64_t lcm = commonDenom(this->denom_, other.denom_);
    return RealNumber(this->num_ * lcm / this->denom_ - other.num_ * lcm / other.denom_, lcm);
}

RealNumber RealNumber::operator*(const RealNumber &other) const noexcept {
    return RealNumber(this->num_ * other.num_, this->denom_ * other.denom_);
}

RealNumber RealNumber::operator/(const RealNumber &other) const noexcept {
    return RealNumber(this->num_ * other.denom_, this->denom_ * other.num_);
}

RealNumber &RealNumber::operator+=(const RealNumber &other) noexcept {
    *this = operator+(other);
    return *this;
}

RealNumber &RealNumber::operator-=(const RealNumber &other) noexcept {
    *this = operator-(other);
    return *this;
}

RealNumber &RealNumber::operator*=(const RealNumber &other) noexcept {
    *this = operator*(other);
    return *this;
}

RealNumber &RealNumber::operator/=(const RealNumber &other) noexcept {
    *this = operator/(other);
    return *this;
}

RealNumber RealNumber::operator-() const noexcept {
    return RealNumber(-this->num_, this->denom_);
}

std::ostream& operator<<(std::ostream& out, const RealNumber& num) noexcept {
    return out << num.num_ << "/" << num.denom_;
}

RealNumber::operator double() const noexcept {
    return static_cast<double>(num_) / denom_;
}

RealNumber RealNumber::pow(int n) const noexcept {
    return RealNumber(std::pow(num_, n) / std::pow(denom_, n));
}

RealNumber RealNumber::abs() const noexcept {
    return RealNumber(std::abs(num_), std::abs(denom_));
}

RealNumber RealNumber::sqrt() const noexcept {
    return RealNumber(std::sqrt(num_) / std::sqrt(denom_));
}

int RealNumber::sign() const noexcept {
    return sgn(num_);
}

int RealNumber::getDigits() noexcept {
    return 10000;
}

double RealNumber::getEps() noexcept {
    return 0.0001;
}
