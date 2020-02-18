// Sean Moylan
// Unions in c

#include <stdio.h>
#include <inttypes.h>

union endian {
  uint8_t ei[2];
  uint16_t si;
};

int main(int argc, char *argv) {

  // Create an instance of a union
  union endian myunion;

  // Assign a variable by using myunion.si =
  myunion.si = 0xff;
  myunion.ei[0] = 0x2;
  myunion.ei[1] = 0xab;

  printf("16bit: %04" PRIX16 "\n", myunion.si);
  printf(" 8bit: %02" PRIX8 "%02" PRIX8 "\n", myunion.ei[0], myunion.ei[1]);
  

  return 0;
}
