// Sean Moylan
// Padding for SHA256


// What does this program do?
// 1: It takes a file as input
// 2: Appends a 1 bit to the end of the message
// 3: Then pads with 0's and leaves room to 
//    add 64bits at the end which is the length of the orginal file in bits
// 4: The output is either 512 bit or a multiple of 512

#include <stdio.h>
#include <inttypes.h>


uint64_t nozerobytes(uint64_t nobits) {
  uint64_t result = 512ULL - (nobits % 512ULL);

  if(result < 65)
    result += 512;
  
  result -= 72;

  return (result / 8ULL); 
}


int main(int argc, char *argv[ ]) {

  if(argc != 2) {
    printf("Error: expected single file name as argument. \n");
    return 1;
  }

  FILE *infile = fopen(argv[1], "rb");
  if(!infile){
    printf("Error: couldn't open file %s.\n",argv[1]);
    return 1;
  }

  // creates an unsigned 8bit integer for b 
  // 64bit integer for number of bits in the file
  uint8_t b;
  uint64_t nobits;

  // Reads from the file 1 byte at a time and prints to the screen as a hex digit
  for(nobits = 0; fread(&b, 1, 1, infile) == 1; nobits += 8) {
    printf("%02" PRIx8, b);
  }
  
  // Print the 1bit that is added to the end and add the 7 0's to make it a byte
  printf("%02" PRIx8, 0x80); // Bits: 1000 0000

  for(uint64_t i = nozerobytes(nobits); i > 0; i--){
    printf("%02" PRIx8, 0x00);
  }

  printf("%016" PRIx64, nobits);

  printf("\n");

  fclose(infile);
  
  return 0;
}
