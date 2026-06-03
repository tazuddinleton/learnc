

#include <stdio.h>

typedef enum HttpErrors {
  HTTP_BAD_REQUEST = 400,
  HTTP_NOT_FOUND = 404,
  HTTP_SERVER_ERROR = 500
} http_error_t;

char *httpErrorToString(http_error_t err) {

  switch (err) {
  case HTTP_NOT_FOUND:
    return "Not found";
  case HTTP_BAD_REQUEST:
    return "Bad request";
  case HTTP_SERVER_ERROR:
    return "Something wen wrong";
  default:
    return "UNKNOWN";
  }
}

int main(int arc, char *argv[]) {

  http_error_t err = HTTP_SERVER_ERROR;
  http_error_t err2 = HTTP_BAD_REQUEST;
  http_error_t err3 = HTTP_NOT_FOUND;

  printf("http err code: %d, and message: %s\n", err, httpErrorToString(err));
  printf("http err code: %d, and message: %s\n", err2, httpErrorToString(err2));
  printf("http err code: %d, and message: %s\n", err3, httpErrorToString(err3));
  return 0;
}
