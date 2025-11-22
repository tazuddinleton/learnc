

#include <stdint.h>
#include <stdio.h>

typedef union RGBA {
  struct {
    uint8_t R;
    uint8_t G;
    uint8_t B;
    uint8_t A;
  };
  uint32_t rgba;
} color_t;

typedef struct TCP {
  uint16_t src_port;
  uint16_t dest_port;

  uint32_t seq_num;

} tcp_header_t;

typedef union PacketHeader {
  tcp_header_t header;
  char raw[8];
} packet_header_t;

int main(int argc, char *argv[]) {

  printf("hello world!");
  color_t color = {.R = 29, .G = 100, .B = 10, .A = 1};

  printf("R: %d, G: %d, B: %d, A: %d\n", color.R, color.G, color.B, color.A);

  printf("Raw bytes of RGBA: %020X\n", color.rgba);
  return 0;
}
