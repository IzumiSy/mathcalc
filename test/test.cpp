#include "minunit.h"

MU_TEST(test1) {
  mu_check(1 == 1);
}

MU_TEST(test2) {
  mu_check(2 == 2);
}

MU_TEST(test3) {
  mu_check(3 == 3);
}

MU_TEST(test4) {
  mu_check(2 == 1);
}

int main(int argc, char *argv[]) {
  MU_RUN_TEST(test1);
  MU_RUN_TEST(test2);
  MU_RUN_TEST(test3);
  MU_RUN_TEST(test4);
  MU_REPORT();
  return minunit_status;
}