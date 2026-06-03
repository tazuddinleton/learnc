

#include "../../munit/munit.h"
#include "text_buffer.h"
#include <stdio.h>
#include <stdlib.h>

static MunitResult when_null_buffer_given_returns_failed() {
  TextBuffer text_buffer;
  int result = smart_append(&text_buffer, "hello");
  munit_assert_int(result, ==, 1);
  return MUNIT_OK;
}

static MunitResult when_buffer_given_with_string_returns_success() {
  TextBuffer text_buffer;
  smart_append(&text_buffer, "hello");
  munit_assert_int(text_buffer.length, ==, 6);
  return MUNIT_OK;
}

static MunitTest tests[] = {
    {"/when_null_buffer_given_returns_failed",
     when_null_buffer_given_returns_failed, NULL, NULL, MUNIT_TEST_OPTION_NONE,
     NULL},
    {"/when_buffer_given_with_string_returns_success",
     when_buffer_given_with_string_returns_success, NULL, NULL,
     MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}};

static const MunitSuite suit = {"/text_buffer_tests", tests, NULL, 1,
                                MUNIT_SUITE_OPTION_NONE};

int main(int argc, char *argv[]) {

  // printf("text buffer length: %d, text: %s", text_buffer.length,
  //        text_buffer.text);

  return munit_suite_main(&suit, NULL, argc, argv);

  return EXIT_SUCCESS;
}
