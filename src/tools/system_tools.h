#include <sys/time.h>
#include <atomic>

namespace tools{
  double clock(void);
  void sleep(double segundos);
  void sleep_us(unsigned int usec);
};
