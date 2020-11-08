#include <ostream>
#include <cmath>
#include <iomanip>

class RealNumber {
public:
    template<typename T = int64_t>
    RealNumber(T num = static_cast<T>(0), T denom = static_cast<T>(1)) noexcept {
        num_ = sgn(num) * sgn(denom) * static_cast<int64_t>(std::abs(num * getDigits()));
        denom_ = static_cast<int64_t>(std::abs(denom * getDigits()));
        int gcd = RealNumber::gcd(num_, denom_);
        num_ = num_ / gcd;
        denom_ = denom_ / gcd;

        if (num_ == 0) {
            denom_ = 1;
        }
    }

    explicit operator double() const noexcept;

    int64_t getNum() const noexcept;

    void setNum(int) noexcept;

    int64_t getDenom() const noexcept;

    void setDenom(int) noexcept;

    int sign() const noexcept;

    static double getEps() noexcept;

    RealNumber pow(int) const noexcept;

    RealNumber sqrt() const noexcept;

    RealNumber abs() const noexcept;

    RealNumber &operator=(const RealNumber &) noexcept;

    bool operator==(const RealNumber &) const noexcept;

    bool operator!=(const RealNumber &) const noexcept;

    RealNumber operator+(const RealNumber &) const noexcept;

    RealNumber operator-(const RealNumber &) const noexcept;

    RealNumber operator*(const RealNumber &) const noexcept;

    RealNumber operator/(const RealNumber &) const noexcept;

    RealNumber &operator+=(const RealNumber &) noexcept;

    RealNumber &operator-=(const RealNumber &) noexcept;

    RealNumber &operator*=(const RealNumber &) noexcept;

    RealNumber &operator/=(const RealNumber &) noexcept;

    RealNumber operator-() const noexcept;

    friend std::ostream &operator<<(std::ostream &, const RealNumber &) noexcept;

    static int64_t gcd(int64_t , int64_t) noexcept;

private:

    int64_t num_, denom_;

    static int64_t commonDenom(int, int) noexcept;

    static int sgn(int) noexcept;

    static int getDigits() noexcept;
};
