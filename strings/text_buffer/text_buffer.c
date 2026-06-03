

#include "text_buffer.h"
#include <string.h>

int smart_append(TextBuffer *buffer, char *src) {

  if (buffer == NULL || buffer->length == MAX_BUFFER_SIZE) {
    return 1;
  }

  int src_len = strlen(src);
  int available_space = MAX_BUFFER_SIZE - buffer->length;

  int idx = 0;
  for (; idx < available_space; idx++) {
    buffer->text[buffer->length + idx] = src[idx];
  }
  buffer->length += idx;

  if (available_space < src_len) {
    return 1;
  }
  return 0;
}
