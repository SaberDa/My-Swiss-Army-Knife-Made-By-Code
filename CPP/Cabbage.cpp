#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

namespace sead {
    class Random {
    public:
        void init();
        void init(uint32_t seed);
        void init(uint32_t seed1, uint32_t seed2, uint32_t seed3, uint32_t seed4);
        uint32_t getU32();
        uint64_t getU64();
        void getContext(uint32_t *seed1, uint32_t *seed2, uint32_t *seed3, uint32_t *seed4);
    private:
        uint32_t mContext[4];
    };

    void Random::init() {
        init(42069);
    }

    void Random::init(uint32_t seed) {
        // Mersenne twister
        // 梅森旋转算法
        // 为了解决过去 PRNG 质量低下的问题
        mContext[0] = 0x6c078965 * (seed ^ (seed >> 30)) + 1;
        mContext[1] = 0x6C078965 * (mContext[0] ^ (mContext[0] >> 30)) + 2;
        mContext[2] = 0x6C078965 * (mContext[1] ^ (mContext[1] >> 30)) + 3;
        mContext[3] = 0x6C078965 * (mContext[2] ^ (mContext[2] >> 30)) + 4;
    }

    void Random::init(uint32_t seed1, uint32_t seed2, uint32_t seed3, uint32_t seed4) {
        if ((seed1 || seed2 || seed3 || seed4) == 0) {
            // seeds must not be all zero
            // use TM generate init values
            seed1 = 1;
            seed2 = 0x6C078967;
            seed3 = 0x714ACB41;
            seed4 = 0x48077044;
        }
        mContext[0] = seed1;
        mContext[1] = seed2;
        mContext[2] = seed3;
        mContext[3] = seed4;
    }

    uint32_t Random::getU32() {
        uint32_t n = mContext[0] ^ (mContext[0] << 11);

        mContext[0] = mContext[1];
        mContext[1] = mContext[2];
        mContext[2] = mContext[3];
        mContext[3] = n ^ (n >> 8) ^ mContext[3] ^ (mContext[3] >> 19);

        return mContext[3];
    }

    uint64_t Random::getU64() {
        uint32_t n1 = mContext[0] ^ (mContext[0] << 11);
        uint32_t n2 = mContext[1];
        uint32_t n3 = n1 ^ (n1 >> 8) ^ mContext[3];

        mContext[0] = mContext[2];
        mContext[1] = mContext[3];
        mContext[2] = n3 ^ (mContext[3] >> 19);
        mContext[3] = n2 ^ (n2 << 11) ^ ((n2 ^ (n2 << 11)) >> 8) ^ mContext[2] ^ (n3 >> 19);

        return ((uint64_t)mContext[2] << 32 | mContext[3]);
    }
    
    void Random::getContext(uint32_t *seed1, uint32_t *seed2, uint32_t *seed3, uint32_t *seed4) {
        *seed1 = mContext[0];
        *seed2 = mContext[1];
        *seed3 = mContext[2];
        *seed4 = mContext[3];
    }

} // namespace sead

uint32_t pf(float f) {
    return *((uint32_t *)&f);
}

struct Cabbage {
    int32_t basePrice;
    int32_t sellPrices[14];
    uint32_t whatPattern;
    int32_t tmp40;

    void calculate();

    // utility stuff for testing
    sead::Random rng;
    bool randbool() {
        return rng.getU32() & 0x80000000;
    }
    int randint(int min, int max) {
        return (((uint64_t)rng.getU32() * (uint64_t)(max - min + 1)) >> 32) + min;
    }
    float randfloat(float a, float b) {
        uint32_t val = 0x3F800000 | (rng.getU32() >> 9);
        float fval = *(float *)(&val);
        return a + ((fval - 1.0f) * (b - a));
    }
    int intceil(float val) {
        return (int)(val + 0.99999f);
    }
};

void Cabbage::calculate() {
    // 初始价格，在90和110之间
    basePrice = randint(90, 110);
    int chance  = randint(0, 99);

    // select the next pattern
    int nextPattern;
    if (whatPattern >= 4) {
        nextPattern = 2;
    } else {
        switch (whatPattern) {
            case 0:
                if (chance < 20) {
                    nextPattern = 0;
                } else if (chance < 50) {
                    nextPattern = 1;
                } else if (chance < 65) {
                    nextPattern = 2;
                } else {
                    nextPattern = 3;
                }
                break;
            case 1:
                if (chance < 50) {
                    nextPattern = 0;
                } else if (chance < 55) {
                    nextPattern = 1;
                } else if (chance < 75) {
                    nextPattern = 2;
                } else {
                    nextPattern = 3;
                }
                break;
            case 2:
                if (chance < 25) {
                    nextPattern = 0;
                } else if (chance < 70) {
                    nextPattern = 1;
                } else if (chance < 75) {
                    nextPattern = 2;
                } else {
                    nextPattern = 3;
                }
                break;
            case 3:
                if (chance < 45) {
                    nextPattern = 0;
                } else if (chance < 70) {
                    nextPattern = 1;
                } else if (chance < 85) {
                    nextPattern = 2;
                } else {
                    nextPattern = 3;
                }
                break;
        }
    }

    whatPattern = nextPattern;

    for (int i = 2; i < 14; i++) {
        sellPrices[i] = 0;
    }
    sellPrices[0] = basePrice;
    sellPrices[1] = basePrice;

    int work;
    int decPhaseLen1, decPhaseLen2, peakStart;
    int hiPhaseLen1, hiPhaseLen2and3, hiPhaseLen3;
    float rate;

    switch (whatPattern) {
        case 0:
            // Pattern 0: 
            // 随机波形
            // high, decreasing, high, decreasing, high
            // 价格频繁的上下浮动，即使是价格突然下跌也有可能会立马回升
            work = 2;
            decPhaseLen1 = randbool() ? 3 : 2;
            decPhaseLen2 = 5 - decPhaseLen1;

            hiPhaseLen1 = randint(0, 6);
            hiPhaseLen2and3 = 7 - hiPhaseLen1;
            hiPhaseLen3 = randint(0, hiPhaseLen2and3 - 1);

            // high phase 1
            for (int i = 0; i < hiPhaseLen1; i++) {
                sellPrices[work++] = intceil(randfloat(0.9, 1.4) * basePrice);
            }

            // decreasing phase 1
            rate = randfloat(0.8, 0.6);
            for (int i = 0; i < decPhaseLen1; i++) {
                sellPrices[work++] = intceil(rate * basePrice);
                rate -= 0.04;
                rate -= randfloat(0, 0.06);
            }

            // high phase 2
            for (int i = 0; i < (hiPhaseLen2and3 - hiPhaseLen3); i++) {
                sellPrices[work++] = intceil(randfloat(0.9, 1.4) * basePrice);
            }

            // decreasing phase 2
            rate = randfloat(0.8, 0.6);
            for (int i = 0; i < decPhaseLen2; i++) {
                sellPrices[work++] = intceil(rate * basePrice);
                rate -= 0.04;
                rate -= randfloat(0, 0.06);
            }

            // high phase 3
            for (int i = 0; i < hiPhaseLen3; i++) {
                sellPrices[work++] = intceil(randfloat(0.9, 1.4) * basePrice);
            }

            break;

        case 1:
            // Pattern 1:
            // 四期型
            // 前几日会价格持续下跌，接着在某一天突然价格上涨, 但峰值要比三期型低上许多
            // decreasing middle, high spike, random low
            peakStart = randint(3, 9);
            rate = randfloat(0.9, 0.85);
            for (work = 2; work < peakStart; work++) {
                sellPrices[work] = intceil(rate * basePrice);
                rate -= 0.03;
                rate -= randfloat(0, 0.02);
            }
            sellPrices[work++] = intceil(randfloat(0.9, 1.4) * basePrice);
            sellPrices[work++] = intceil(randfloat(1.4, 2.0) * basePrice);
            sellPrices[work++] = intceil(randfloat(2.0, 6.0) * basePrice);
            sellPrices[work++] = intceil(randfloat(1.4, 2.0) * basePrice);
            sellPrices[work++] = intceil(randfloat(0.9, 1.4) * basePrice);

            while (work < 14) {
                sellPrices[work++] = intceil(randfloat(0.4, 0.9) * basePrice);
            }

            break;
        case 2:
            // Pattern 2:
            // 递减
            // 价格持续下跌，不过这种类型很可能演变成三期型与四期型。如果在周四下午还未发现价格回升，那就可以确定本周为递减型
            // consistently decreasing
            rate = 0.9;
            rate -= randfloat(0, 0.05);
            for (work = 2; work < 14; work++) {
                sellPrices[work] = intceil(rate * basePrice);
                rate -= 0.03;
                rate -= randfloat(0, 0.02);
            }

            break;
        case 3:
            // Pattern 3:
            // 三期型
            // 前几日会价格持续下跌，接着在某一天突然价格上涨
            // decreasing, spike, decreasing
            peakStart = randint(2, 9);

            // decreasing phase before the peak
            rate = randfloat(0.9, 0.4);
            for (work = 2; work < peakStart; work++) {
                sellPrices[work] = intceil(rate * basePrice);
                rate -= 0.03;
                rate -= randfloat(0, 0.02);
            }

            sellPrices[work++] = intceil(randfloat(0.9, 1.4) * (float)basePrice);
            sellPrices[work++] = intceil(randfloat(0.9, 1.4) * basePrice);
            rate = randfloat(1.4, 2.0);
            sellPrices[work++] = intceil(randfloat(1.4, rate) * basePrice) - 1;
            sellPrices[work++] = intceil(rate * basePrice);
            sellPrices[work++] = intceil(randfloat(1.4, rate) * basePrice) - 1;

            // decreasing phase after the peak
            if (work < 14) {
                rate = randfloat(0.9, 0.4);
                while (work < 14) {
                    sellPrices[work++] = intceil(rate * basePrice);
                    rate -= 0.03;
                    rate -= randfloat(0, 0.02);
                }
            }
            break;
    }

    sellPrices[0] = 0;
    sellPrices[1] = 0;

}

int main(int argc, char **argv) {
    Cabbage cabbages;

    if (argc == 3) {
        cabbages.whatPattern = atoi(argv[1]);
        cabbages.rng.init(atoi(argv[2]));
    } else {
        printf("Usage: %s <pattern> <seed> \n", argv[0]);
        return 0;
    }
    
    // output
    cabbages.calculate();
    printf("Pattern %d : \n", cabbages.whatPattern);
    printf("Sun Mon Tue Wed Thu Fri Sat \n");
    printf("%3d %3d %3d %3d %3d %3d %3d \n", 
            cabbages.basePrice,
            cabbages.sellPrices[2], cabbages.sellPrices[4], cabbages.sellPrices[6],
            cabbages.sellPrices[8], cabbages.sellPrices[10], cabbages.sellPrices[12]);
    printf("    %3d  %3d  %3d  %3d  %3d  %3d \n",
            cabbages.sellPrices[3], cabbages.sellPrices[5], cabbages.sellPrices[7],
            cabbages.sellPrices[9], cabbages.sellPrices[11], cabbages.sellPrices[13]);

    return 0;
}


