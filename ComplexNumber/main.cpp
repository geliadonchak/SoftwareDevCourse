#define CATCH_CONFIG_MAIN

#include "libs/catch.hpp"
#include "src/ComplexNumber.h"
#include <complex>

TEST_CASE("Construction of complex number, getters and setters") {
    std::vector<ComplexNumber> nums = {
            ComplexNumber(),
            ComplexNumber(1, 1),
            ComplexNumber(RealNumber(1.0f)),
            ComplexNumber(4.356, 1.0),
            ComplexNumber(RealNumber(5, -6)),
            ComplexNumber(RealNumber(-34, -80), RealNumber(11, 23)),
            ComplexNumber(56.3f)
    };

    std::vector<std::complex<double>> c_nums = {
            std::complex<double>(),
            std::complex<double>(1, 1),
            std::complex<double>(1),
            std::complex<double>(4.356, 1),
            std::complex<double>(-5.0 / 6.0),
            std::complex<double>(34.0 / 80.0, 11.0 / 23.0),
            std::complex<double>(56.3)
    };

    for (int i = 0; i < nums.size(); i++) {
        REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(nums[i]).getRe()) - c_nums[i].real()) <
                 RealNumber::getEps()));
        REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(nums[i]).getIm()) - c_nums[i].imag()) <
                 RealNumber::getEps()));
    }

    nums[0].setRe(RealNumber(-103, 4));
    nums[0].setIm(RealNumber(20, 2));
    c_nums[0].real(-103.0 / 4.0);
    c_nums[0].imag(20.0 / 2.0);

    REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(nums[0]).getRe()) - c_nums[0].real()) <
             RealNumber::getEps()));
    REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(nums[0]).getIm()) - c_nums[0].imag()) <
             RealNumber::getEps()));
}

TEST_CASE("Sum of complex number") {
    std::vector<ComplexNumber> nums = {
            ComplexNumber(1),
            ComplexNumber(RealNumber(-5.2)),
            ComplexNumber(RealNumber(-6, 2), RealNumber(7, 11))
    };

    std::vector<std::complex<double>> c_nums = {
            std::complex<double>(1),
            std::complex<double>(-5.2),
            std::complex<double>(-3.0, 7.0 / 11.0),
    };

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            ComplexNumber sum = nums[i] + nums[j];
            std::complex<double> c_sum = c_nums[i] + c_nums[j];

            REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(sum).getRe()) - c_sum.real()) <
                     RealNumber::getEps()));
            REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(sum).getIm()) - c_sum.imag()) <
                     RealNumber::getEps()));
        }
    }

    nums[0] += nums[1];
    c_nums[0] += c_nums[1];
    REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(nums[0]).getRe()) - c_nums[0].real()) <
             RealNumber::getEps()));
    REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(nums[0]).getIm()) - c_nums[0].imag()) <
             RealNumber::getEps()));
}

TEST_CASE("Difference of complex number") {
    std::vector<ComplexNumber> nums = {
            ComplexNumber(1),
            ComplexNumber(RealNumber(-5.2)),
            ComplexNumber(RealNumber(-6, 2), RealNumber(7, 11))
    };

    std::vector<std::complex<double>> c_nums = {
            std::complex<double>(1),
            std::complex<double>(-5.2),
            std::complex<double>(-3.0, 7.0 / 11.0),
    };

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            ComplexNumber dif = nums[i] - nums[j];
            std::complex<double> c_dif = c_nums[i] - c_nums[j];

            REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(dif).getRe()) - c_dif.real()) <
                     RealNumber::getEps()));
            REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(dif).getIm()) - c_dif.imag()) <
                     RealNumber::getEps()));
        }
    }

    nums[0] -= nums[1];
    c_nums[0] -= c_nums[1];
    REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(nums[0]).getRe()) - c_nums[0].real()) <
             RealNumber::getEps()));
    REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(nums[0]).getIm()) - c_nums[0].imag()) <
             RealNumber::getEps()));
}

TEST_CASE("Multiply of complex number") {
    std::vector<ComplexNumber> nums = {
            ComplexNumber(1),
            ComplexNumber(RealNumber(-5.2)),
            ComplexNumber(RealNumber(-6, 2), RealNumber(7, 11))
    };

    std::vector<std::complex<double>> c_nums = {
            std::complex<double>(1),
            std::complex<double>(-5.2),
            std::complex<double>(-3.0, 7.0 / 11.0),
    };

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            ComplexNumber mul = nums[i] * nums[j];
            std::complex<double> c_mul = c_nums[i] * c_nums[j];

            REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(mul).getRe()) - c_mul.real()) <
                     RealNumber::getEps()));
            REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(mul).getIm()) - c_mul.imag()) <
                     RealNumber::getEps()));
        }
    }

    nums[0] *= nums[1];
    c_nums[0] *= c_nums[1];
    REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(nums[0]).getRe()) - c_nums[0].real()) <
             RealNumber::getEps()));
    REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(nums[0]).getIm()) - c_nums[0].imag()) <
             RealNumber::getEps()));
}

TEST_CASE("Division of complex number") {
    std::vector<ComplexNumber> nums = {
            ComplexNumber(1),
            ComplexNumber(RealNumber(-5.2)),
            ComplexNumber(RealNumber(-6, 2), RealNumber(7, 11))
    };

    std::vector<std::complex<double>> c_nums = {
            std::complex<double>(1),
            std::complex<double>(-5.2),
            std::complex<double>(-3.0, 7.0 / 11.0),
    };

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            ComplexNumber div = nums[i] / nums[j];
            std::complex<double> c_div = c_nums[i] / c_nums[j];

            REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(div).getRe()) - c_div.real()) <
                     RealNumber::getEps()));
            REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(div).getIm()) - c_div.imag()) <
                     RealNumber::getEps()));
        }
    }

    nums[0] /= nums[1];
    c_nums[0] /= c_nums[1];
    REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(nums[0]).getRe()) - c_nums[0].real()) <
             RealNumber::getEps()));
    REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(nums[0]).getIm()) - c_nums[0].imag()) <
             RealNumber::getEps()));
}

TEST_CASE("Operations between complex number and other types") {
    std::vector<ComplexNumber> nums = {
            ComplexNumber(),
            ComplexNumber(1, 1),
            ComplexNumber(RealNumber(1.0f)),
            ComplexNumber(4.356, 1.0),
            ComplexNumber(RealNumber(5, -6)),
            ComplexNumber(RealNumber(-34, -80), RealNumber(11, 23)),
            ComplexNumber(56.3f)
    };

    std::vector<std::complex<double>> c_nums = {
            std::complex<double>(),
            std::complex<double>(1, 1),
            std::complex<double>(1),
            std::complex<double>(4.356, 1), // блять
            std::complex<double>(-5.0 / 6.0),
            std::complex<double>(34.0 / 80.0, 11.0 / 23.0),
            std::complex<double>(56.3)
    };

    std::vector<int> int_nums = {1, 2, 3, 4, 5, 6};
    std::vector<double> double_nums = {0.1, 1.2, 2.3, 3.4, 4.5, 5.6};
    std::vector<float> float_nums = {0.2f, 1.3f, 2.4f, 3.5f, 4.6f, 5.7f};

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < int_nums.size(); j++) {
            std::vector<ComplexNumber> res;
            std::vector<std::complex<double>> c_res;

            res.push_back(nums[i] + int_nums[j]);
            res.push_back(nums[i] + double_nums[j]);
            res.push_back(nums[i] + float_nums[j]);
            c_res.push_back(c_nums[i] + static_cast<std::complex<double>>(int_nums[j]));
            c_res.push_back(c_nums[i] + static_cast<std::complex<double>>(double_nums[j]));
            c_res.push_back(c_nums[i] + static_cast<std::complex<double>>(float_nums[j]));

            res.push_back(nums[i] - int_nums[j]);
            res.push_back(nums[i] - double_nums[j]);
            res.push_back(nums[i] - float_nums[j]);
            c_res.push_back(c_nums[i] - static_cast<std::complex<double>>(int_nums[j]));
            c_res.push_back(c_nums[i] - static_cast<std::complex<double>>(double_nums[j]));
            c_res.push_back(c_nums[i] - static_cast<std::complex<double>>(float_nums[j]));

            res.push_back(nums[i] * int_nums[j]);
            res.push_back(nums[i] * double_nums[j]);
            res.push_back(nums[i] * float_nums[j]);
            c_res.push_back(c_nums[i] * static_cast<std::complex<double>>(int_nums[j]));
            c_res.push_back(c_nums[i] * static_cast<std::complex<double>>(double_nums[j]));
            c_res.push_back(c_nums[i] * static_cast<std::complex<double>>(float_nums[j]));

            res.push_back(nums[i] / int_nums[j]);
            res.push_back(nums[i] / double_nums[j]);
            res.push_back(nums[i] / float_nums[j]);
            c_res.push_back(c_nums[i] / static_cast<std::complex<double>>(int_nums[j]));
            c_res.push_back(c_nums[i] / static_cast<std::complex<double>>(double_nums[j]));
            c_res.push_back(c_nums[i] / static_cast<std::complex<double>>(float_nums[j]));

            for (int k = 0; k < 12; k++) {
                REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(res[k]).getRe()) - c_res[k].real()) <
                         RealNumber::getEps()));
                REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(res[k]).getIm()) - c_res[k].imag()) <
                         RealNumber::getEps()));
            }
        }
    }
}

TEST_CASE("ABS and ARG of complex number") {
    std::vector<ComplexNumber> nums = {
            ComplexNumber(1),
            ComplexNumber(RealNumber(-5.2)),
            ComplexNumber(RealNumber(-6, 2), RealNumber(7, 11)),
            ComplexNumber(13, 17),
            ComplexNumber(42.1),
            ComplexNumber(23.1f, 133.0f)
    };

    std::vector<std::complex<double>> c_nums = {
            std::complex<double>(1),
            std::complex<double>(-5.2),
            std::complex<double>(-3.0, 7.0 / 11.0),
            std::complex<double>(13, 17),
            std::complex<double>(42.1),
            std::complex<double>(23.1f, 133.0f)
    };

    for (int i = 0; i < nums.size(); i++) {
        REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(nums[i]).abs()) - abs(c_nums[i])) <
                 RealNumber::getEps()));
        REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(nums[i]).arg()) - arg(c_nums[i])) <
                 RealNumber::getEps()));
    }
}

TEST_CASE("Pow of complex number") {
    std::vector<ComplexNumber> nums = {
            ComplexNumber(1),
            ComplexNumber(RealNumber(-5.2)),
            ComplexNumber(RealNumber(-6, 2), RealNumber(7, 11))
    };

    std::vector<std::complex<double>> c_nums = {
            std::complex<double>(1),
            std::complex<double>(-5.2),
            std::complex<double>(-3.0, 7.0 / 11.0),
    };

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 1; j < 4; j++) {
            ComplexNumber pow = nums[i].pow(j);
            std::complex<double> c_pow = std::pow(c_nums[i], j);

            REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(pow).getRe()) - c_pow.real()) <
                     RealNumber::getEps()));
            REQUIRE((std::abs(static_cast<double>(static_cast<const ComplexNumber &>(pow).getIm()) - c_pow.imag()) <
                     RealNumber::getEps()));
        }
    }
}

TEST_CASE("Equality of complex number") {
    std::vector<ComplexNumber> nums = {
            ComplexNumber(1),
            ComplexNumber(RealNumber(-5.2)),
            ComplexNumber(RealNumber(-6, 2), RealNumber(7, 11)),
            ComplexNumber(13, 17),
            ComplexNumber(42.1),
            ComplexNumber(23.1f, 133.0f)
    };

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (i == j) {
                REQUIRE(nums[i] == nums[j]);
                continue;
            }

            REQUIRE_FALSE(nums[i] == nums[j]);
        }
    }
}

TEST_CASE("Copy of complex number") {
    std::vector<ComplexNumber> nums = {
            ComplexNumber(1),
            ComplexNumber(RealNumber(-5.2)),
            ComplexNumber(RealNumber(-6, 2), RealNumber(7, 11)),
            ComplexNumber(13, 17),
            ComplexNumber(42.1),
            ComplexNumber(23.1f, 133.0f)
    };

    for (auto num: nums) {
        ComplexNumber num_copy = num;
        REQUIRE(num_copy == num);
    }
}

TEST_CASE("Out of complex number") {
    ComplexNumber num(RealNumber(10.2101), RealNumber(-30.32));

    std::ostringstream oss;
    oss << num;

    REQUIRE(oss.str() == "102101/10000 - 758/25i");
}

TEST_CASE("Unary minus of complex number") {
    std::vector<ComplexNumber> nums = {
            ComplexNumber(1),
            ComplexNumber(RealNumber(-5.2)),
            ComplexNumber(RealNumber(-6, 2), RealNumber(7, 11))
    };

    std::vector<std::complex<double>> c_nums = {
            std::complex<double>(1),
            std::complex<double>(-5.2),
            std::complex<double>(-3.0, 7.0 / 11.0),
    };

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 1; j < 4; j++) {
            ComplexNumber minus_num = -nums[i];
            std::complex<double> minus_c_num = -c_nums[i];

            REQUIRE((std::abs(
                    static_cast<double>(static_cast<const ComplexNumber &>(minus_num).getRe()) - minus_c_num.real()) <
                     RealNumber::getEps()));
            REQUIRE((std::abs(
                    static_cast<double>(static_cast<const ComplexNumber &>(minus_num).getIm()) - minus_c_num.imag()) <
                     RealNumber::getEps()));
        }
    }
}

TEST_CASE("Sign of real number") {
    std::vector<RealNumber> pos_nums = {
            RealNumber(),
            RealNumber(13, 17),
            RealNumber(42),
            RealNumber(23.1f)
    };

    std::vector<RealNumber> neg_nums = {
            RealNumber(-5.2),
            RealNumber(13, -17),
            RealNumber(-114),
            RealNumber(-3.1f)
    };

    for (auto num : pos_nums) {
        REQUIRE(num.sign() > 0);
    }

    for (auto num : neg_nums) {
        REQUIRE(num.sign() < 0);
    }
}

TEST_CASE("Sum of real number") {
    std::vector<RealNumber> nums = {
            RealNumber(),
            RealNumber(-5.2),
            RealNumber(13, 17),
            RealNumber(42),
            RealNumber(23.1f)
    };

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            RealNumber sum = nums[i] + nums[j];
            double double_sum = static_cast<double>(static_cast<double>(nums[i].getNum()) / nums[i].getDenom()) +
                                static_cast<double>(static_cast<double>(nums[j].getNum()) / nums[j].getDenom());
            REQUIRE(std::abs(static_cast<double>(static_cast<const RealNumber &>(sum)) - double_sum) <
                     RealNumber::getEps());
        }
    }

    RealNumber tmp = nums[0];
    nums[0] += nums[1];
    double sum_nums = (double) tmp + (double) nums[1];
    REQUIRE(std::abs(static_cast<double>(static_cast<const RealNumber&>(nums[0])) - sum_nums) < RealNumber::getEps());
}

TEST_CASE("Difference of real number") {
    std::vector<RealNumber> nums = {
            RealNumber(),
            RealNumber(-5.2),
            RealNumber(13, 17),
            RealNumber(42),
            RealNumber(23.1f)
    };

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            RealNumber dif = nums[i] - nums[j];
            double double_dif = static_cast<double>(static_cast<double>(nums[i].getNum()) / nums[i].getDenom()) -
                                static_cast<double>(static_cast<double>(nums[j].getNum()) / nums[j].getDenom());
            REQUIRE((std::abs(static_cast<double>(static_cast<const RealNumber &>(dif)) - double_dif) <
                     RealNumber::getEps()));
        }
    }

    RealNumber tmp = nums[0];
    nums[0] -= nums[1];
    double dif_nums = (double) tmp - (double) nums[1];
    REQUIRE(std::abs(static_cast<double>(static_cast<const RealNumber&>(nums[0])) - dif_nums) < RealNumber::getEps());
}

TEST_CASE("Multiply of real number") {
    std::vector<RealNumber> nums = {
            RealNumber(),
            RealNumber(-5.2),
            RealNumber(13, 17),
            RealNumber(42),
            RealNumber(23.1f)
    };

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            RealNumber mul = nums[i] * nums[j];
            double double_mul = static_cast<double>(static_cast<double>(nums[i].getNum()) / nums[i].getDenom()) *
                                static_cast<double>(static_cast<double>(nums[j].getNum()) / nums[j].getDenom());
            REQUIRE((std::abs(static_cast<double>(static_cast<const RealNumber &>(mul)) - double_mul) <
                     RealNumber::getEps()));
        }
    }

    RealNumber tmp = nums[0];
    nums[0] *= nums[1];
    double mul_nums = (double) tmp * (double) nums[1];
    REQUIRE(std::abs(static_cast<double>(static_cast<const RealNumber&>(nums[0])) - mul_nums) < RealNumber::getEps());
}

TEST_CASE("Division of real number") {
    std::vector<RealNumber> nums = {
            RealNumber(),
            RealNumber(-5.2),
            RealNumber(13, 17),
            RealNumber(42),
            RealNumber(23.1f)
    };

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 1; j < nums.size(); j++) {
            RealNumber div = nums[i] / nums[j];
            double double_div= static_cast<double>(static_cast<double>(nums[i].getNum()) / nums[i].getDenom()) /
                                static_cast<double>(static_cast<double>(nums[j].getNum()) / nums[j].getDenom());
            REQUIRE((std::abs(static_cast<double>(static_cast<const RealNumber &>(div)) - double_div) <
                     RealNumber::getEps()));
        }
    }

    RealNumber tmp = nums[0];
    nums[0] /= nums[1];
    double div_nums = (double) tmp / (double) nums[1];
    REQUIRE(std::abs(static_cast<double>(static_cast<const RealNumber&>(nums[0])) - div_nums) < RealNumber::getEps());
}

TEST_CASE("Copy of real number") {
    std::vector<RealNumber> nums = {
            RealNumber(),
            RealNumber(-5.2),
            RealNumber(13, 17),
            RealNumber(42),
            RealNumber(23.1f)
    };

    for (auto num: nums) {
        RealNumber num_copy = num;
        REQUIRE(num_copy == num);
    }
}

TEST_CASE("Unary minus of real number") {
    std::vector<RealNumber> nums = {
            RealNumber(),
            RealNumber(-5.2),
            RealNumber(13, 17),
            RealNumber(42),
            RealNumber(23.1f)
    };

    for (int i = 0; i < nums.size(); i++) {
        RealNumber minus_num = -nums[i];

        REQUIRE((std::abs(static_cast<double>(static_cast<const RealNumber &>(minus_num)) +
                          static_cast<double>(static_cast<const RealNumber &>(nums[i]))) < RealNumber::getEps()));
    }
}

TEST_CASE("Out of real number") {
    RealNumber num(-4, 13);

    std::ostringstream oss;
    oss << num;

    REQUIRE(oss.str() == "-4/13");
}

TEST_CASE("Equality of real number") {
    std::vector<RealNumber> nums = {
            RealNumber(),
            RealNumber(-5.2),
            RealNumber(13, 17),
            RealNumber(42),
            RealNumber(23.1f)
    };

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (i == j) {
                REQUIRE(nums[i] == nums[j]);
                continue;
            }

            REQUIRE_FALSE(nums[i] == nums[j]);
        }
    }
}

TEST_CASE("Pow of real number") {
    std::vector<RealNumber> nums = {
            RealNumber(),
            RealNumber(-5.2),
            RealNumber(13, 17),
            RealNumber(42),
            RealNumber(23.1f)
    };

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 1; j < 4; j++) {
            double pow_num = static_cast<double>(pow(nums[i].getNum(), j) / pow(nums[i].getDenom(), j));
            REQUIRE((std::abs(static_cast<double>(static_cast<const RealNumber &>((nums[i].pow(j))) - pow_num)) <
                     RealNumber::getEps()));
        }
    }
}

TEST_CASE("Abs of real number") {
    std::vector<RealNumber> nums = {
            RealNumber(),
            RealNumber(-5.2),
            RealNumber(13, 17),
            RealNumber(42),
            RealNumber(23.1f)
    };

    for (int i = 0; i < nums.size(); i++) {
        double abs_num = std::abs(static_cast<double>(nums[i].getNum()) / nums[i].getDenom());
        REQUIRE((std::abs(static_cast<double>(static_cast<const RealNumber &>(nums[i].abs()) - abs_num)) <
                 RealNumber::getEps()));
    }
}

TEST_CASE("Sqrt of real number") {
    std::vector<RealNumber> nums = {
            RealNumber(),
            RealNumber(-5.2),
            RealNumber(13, 17),
            RealNumber(42),
            RealNumber(23.1f)
    };

    for (int i = 0; i < nums.size(); i++) {
        double sqrt_num = static_cast<double>(sqrt(nums[i].getNum())) / sqrt(nums[i].getDenom());
        REQUIRE((std::abs(static_cast<double>(static_cast<const RealNumber &>((nums[i].sqrt())) - sqrt_num)) <
                 RealNumber::getEps()));
    }
}

TEST_CASE("Real number to double") {
    std::vector<RealNumber> nums = {
            RealNumber(),
            RealNumber(-5.2),
            RealNumber(13, 17),
            RealNumber(42),
            RealNumber(23.1f)
    };

    for (int i = 0; i < nums.size(); i++) {
        double double_num = static_cast<double>(nums[i].getNum()) / nums[i].getDenom();
        REQUIRE((std::abs(static_cast<double>(static_cast<const RealNumber &>((double) nums[i])) - double_num)) <
                RealNumber::getEps());
    }
}