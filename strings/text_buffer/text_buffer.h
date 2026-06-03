#ifndef TEXT_BUFFER_H
#define TEXT_BUFFER_H

#define MAX_BUFFER_SIZE 64

typedef struct TextBuffer {
  char text[MAX_BUFFER_SIZE];
  int length;
} TextBuffer;

int smart_append(TextBuffer *buffer, char *src);
#endif // !TEXT_BUFFER_H
