#ifndef FIXED_H
#define FIXED_H

#define F_N 5
#define F_ONE (1 << F_N)
#define F_K (1 << (F_N - 1))
#define F_MASK (~(F_ONE | (F_ONE - 1)))

#ifdef CONFIG_TEST
#define F_LIT(f) (fixed) f
#ifndef CONFIG_RISCV
#define F_TO_FLOAT(f) (float)f
#endif
#else
#define F_LIT(f) (fixed)(f * F_ONE)
#ifndef CONFIG_RISCV
#define F_TO_FLOAT(f) (float)(f) / F_ONE
#endif
#endif
#define F_ADD(a, b) a + b
#define F_SUB(a, b) a - b
#define F_MUL(a, b) f_mul(a, b)
#define F_DIV(a, b) f_div(a, b)
#define F_ROUND(a) f_round(a)
#define F_SQRT(a) f_sqrt(a)
#define F_SIN(a) f_sin(a)
#define F_COS(a) f_cos(a)
#define F_LT(a, b) a < b
#define F_LTE(a, b) a <= b
#define F_GT(a, b) a > b
#define F_GTE(a, b) a >= b
#define F_EQ(a, b) a == b
#define F_NEQ(a, b) a != b

#define F_PI F_LIT(3.1415926)
#define F_TWO_PI F_LIT(6.2831853)
#define F_HALF_PI F_LIT(1.5707963)
#define CONFIG_BITWIDTH 16
#if CONFIG_BITWIDTH == 8
typedef signed char fixed;
#else
typedef signed int fixed;
#endif

// Comment out middle two lines for int arithmetic to work
static inline fixed f_mul(fixed a, fixed b) {
#ifdef CONFIG_TEST
  return a * b;
#else
  signed int tmp = a * b;
  tmp += F_K;
  tmp >>= F_N;
  return (fixed)tmp;
#endif
};

static inline fixed f_div(fixed a, fixed b) {
#ifdef CONFIG_TEST
  return a / b;
#else
  signed long tmp = a << F_N;
  if ((tmp >= 0 && b >= 0) || (tmp < 0 && b < 0)) {
    tmp += b / 2;
  } else {
    tmp -= b / 2;
  }
  return (fixed)(tmp / b);
#endif
}

static inline fixed f_round(fixed a) { return a & (F_MASK); }

fixed f_sqrt(fixed);
fixed f_sin(fixed);
fixed f_cos(fixed);

#endif
