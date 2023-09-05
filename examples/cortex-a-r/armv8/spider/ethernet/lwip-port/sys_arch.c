#include "lwip/sys.h"

u32_t sys_now(void)
{
  return 0;
}

static int hexval(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    else if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    return 0;
}

/* This is needed because "netif.c" uses it and without this implementation
 * this would cause LIBC to be included and that's something we don't want. */
unsigned int atoi(const unsigned char *num) {
  long value = 0;
  int neg = 0;

  if (num[0] == '0' && num[1] == 'x') {
      // hex
      num += 2;
      while (*num && isxdigit(*num))
          value = value * 16 + hexval(*num++);
  } else {
      // decimal
      if (num[0] == '-') {
          neg = 1;
          num++;
      }
      while (*num && isdigit(*num))
          value = value * 10 + *num++  - '0';
  }
  if (neg)
      value = -value;
  return value;
}