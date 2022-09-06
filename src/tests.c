/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "tests.check" instead.
 */

#include <check.h>
#include <stdio.h>

#include "back/calc.h"

#define EPS 1e-7

START_TEST(res_test1) {
  char *e = "1+1";
  double res, x = 0;
  int error_code;
  calculator(e, x, &res, &error_code);
  ck_assert_double_eq_tol(2, res, EPS);
}
END_TEST

START_TEST(res_test2) {
  char *e = "1-1 + 2*2";
  double res, x = 0;
  int error_code;
  calculator(e, x, &res, &error_code);
  ck_assert_double_eq_tol(4, res, EPS);
}
END_TEST

START_TEST(res_test3) {
  char *e = "1 + 2 * cos(-0) + cos(x)";
  double res, x = 0;
  int error_code;
  calculator(e, x, &res, &error_code);
  ck_assert_double_eq_tol(4, res, EPS);
}
END_TEST

START_TEST(res_test4) {
  char *e = "-2^2";
  double res, x = 0;
  int error_code;
  calculator(e, x, &res, &error_code);
  ck_assert_double_eq_tol(4, res, EPS);
}
END_TEST

START_TEST(res_test5) {
  char *e = "asin(0) * (5 + 1)";
  double res, x = 0;
  int error_code;
  calculator(e, x, &res, &error_code);
  ck_assert_double_eq_tol(0, res, EPS);
}
END_TEST

START_TEST(res_test61) {
  char *e = "1 + ";
  double res, x = 0;
  int error_code;
  calculator(e, x, &res, &error_code);
  ck_assert_int_eq(4, error_code);
}
END_TEST

START_TEST(res_test62) {
  char *e = "* / 1";
  double res, x = 0;
  int error_code;
  calculator(e, x, &res, &error_code);
  ck_assert_int_eq(4, error_code);
}
END_TEST

START_TEST(res_test7) {
  char *e = "1 2";
  double res, x = 0;
  int error_code;
  calculator(e, x, &res, &error_code);
  ck_assert_int_eq(5, error_code);
}
END_TEST

START_TEST(res_test8) {
  char *e = "sin";
  double res, x = 0;
  int error_code;
  calculator(e, x, &res, &error_code);
  ck_assert_int_eq(2, error_code);
}
END_TEST

START_TEST(res_test9) {
  char *e = "sin()";
  double res, x = 0;
  int error_code;
  calculator(e, x, &res, &error_code);
  ck_assert_int_eq(4, error_code);
}
END_TEST

START_TEST(res_test10) {
  char *e = "1+-sintancos1";
  double res, x = 0;
  int error_code;
  calculator(e, x, &res, &error_code);
  ck_assert_double_eq_tol(0.435489, res, EPS);
}
END_TEST

START_TEST(res_test11) {
  char *e = "ln1";
  double res, x = 0;
  int error_code;
  calculator(e, x, &res, &error_code);
  ck_assert_double_eq_tol(.0, res, EPS);
}
END_TEST

START_TEST(res_test12) {
  char *e = "[]";
  double res, x = 0;
  int error_code;
  calculator(e, x, &res, &error_code);
  ck_assert_int_eq(1, error_code);
}
END_TEST

START_TEST(res_test13) {
  char *e = "   ";
  double res, x = 0;
  int error_code;
  calculator(e, x, &res, &error_code);
  ck_assert_int_eq(1, error_code);
}
END_TEST

START_TEST(res_test14) {
  char *e = "sin 0";
  double res, x = 0;
  int error_code;
  calculator(e, x, &res, &error_code);
  ck_assert_double_eq_tol(.0, res, EPS);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, res_test1);
  tcase_add_test(tc1_1, res_test2);
  tcase_add_test(tc1_1, res_test3);
  tcase_add_test(tc1_1, res_test4);
  tcase_add_test(tc1_1, res_test5);
  tcase_add_test(tc1_1, res_test61);
  tcase_add_test(tc1_1, res_test62);
  tcase_add_test(tc1_1, res_test7);
  tcase_add_test(tc1_1, res_test8);
  tcase_add_test(tc1_1, res_test9);
  tcase_add_test(tc1_1, res_test10);
  tcase_add_test(tc1_1, res_test11);
  tcase_add_test(tc1_1, res_test12);
  tcase_add_test(tc1_1, res_test13);
  tcase_add_test(tc1_1, res_test14);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
