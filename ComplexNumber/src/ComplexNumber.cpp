#include "ComplexNumber.h"
#include <iostream>
//тесты на опирации с другими типами
// константы в тестах (где методы константные)
// сделать тесты лучше (через форы, без странных значений)
// проверка в тестах через стл комплекс намбер
// сделать операторы с вещ числами (мб через шаблон)
// быстрое возведение в степень - не сделать, т.к. комплексное число не просто возвести в степень (формула Муавра или просто умножение)
// в вещ числах сокращать дроби
// сделать ноу эксепт (где методы не выкидывают ошибку)
// убрать дефайны (заменить на методы)
// дефолтная инициализация в конструкторах

ComplexNumber::ComplexNumber(RealNumber re, RealNumber im) noexcept : re_(re), im_(im) {}

RealNumber ComplexNumber::getRe() const noexcept {
    return re_;
}

void ComplexNumber::setRe(RealNumber re) noexcept {
    re_ = re;
}

RealNumber ComplexNumber::getIm() const noexcept {
    return im_;
}

void ComplexNumber::setIm(RealNumber im) noexcept {
    im_ = im;
}

ComplexNumber &ComplexNumber::operator=(const ComplexNumber &other) noexcept = default;

bool ComplexNumber::operator==(const ComplexNumber &other) const noexcept {
    return re_ == other.re_ && im_ == other.im_;
}

template <typename T>
bool ComplexNumber::operator==(const T &other) const noexcept {
    return operator==(ComplexNumber(other));
}

template <typename T>
bool ComplexNumber::operator!=(const T &other) const noexcept {
    return !operator==(other);
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &other) const noexcept {
    return ComplexNumber(this->re_ + other.re_, this->im_ + other.im_);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &other) const noexcept {
    return ComplexNumber(this->re_ - other.re_, this->im_ - other.im_);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &other) const noexcept {
    return ComplexNumber(this->re_ * other.re_ - this->im_ * other.im_,
                         this->re_ * other.im_ + other.re_ * this->im_);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &other) const noexcept {
    RealNumber denominator = other.re_ * other.re_ + other.im_ * other.im_;
    return ComplexNumber((this->re_ * other.re_ + this->im_ * other.im_) / denominator,
                         (this->im_ * other.re_ - this->re_ * other.im_) / denominator);
}

ComplexNumber ComplexNumber::operator-() const noexcept {
    return ComplexNumber(-this->re_, -this->im_);
}

std::ostream &operator<<(std::ostream &out, const ComplexNumber &num) noexcept {
    out << std::setprecision(10);
    return out << num.re_ << (num.im_.getNum() < 0 ? " - " : " + ") << num.im_.abs() << "i";
}

double ComplexNumber::abs() const noexcept {
    return double(RealNumber(this->re_.pow(2) + this->im_.pow(2)).sqrt());
}

double ComplexNumber::arg() const noexcept {
    double arctg = std::atan(double((this->im_ / this->re_).abs()));

    if (this->re_ == RealNumber(0)) {
        return this->im_.sign() * M_PI / 2;
    }

    if (this->re_.getNum() < 0) {
        return (-this->im_.sign() * (arctg - M_PI));
    }

    return this->im_.sign() * arctg;
}

ComplexNumber ComplexNumber::pow(int n) const noexcept {
    if (n == 0) return ComplexNumber(RealNumber(1), RealNumber(0));
    ComplexNumber result = *this;
    for (int i = 0; i < n - 1; i++) {
        result *= *this;
    }
    return result;
}

