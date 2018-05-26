/**
  Algorithm for disassembling 8080 code:
    1. Read the code into a buffer
    2. Get a pointer to the beginning of the buffer
    3. Use the byte at the pointer to determine the opcode
    4. Print out the name of the opcode using the bytes after the opcode as data, if applicable
    5. Advance the point the number of bytes used by that instruction (1, 2, or 3 bytes)
    6. If not at the end of the buffer, go to step 3
**/
// post to github later

int Disassemble8080Op(unsigned char *codebuffer, int pc){
  unsigned char *code = &codebuffer[pc];
  int opbytes = 1;
  printf("%04x ", pc); //value is formatted as a hexadecimal with 4 digits and leading zeros
  switch (*code)
  {
    case 0x00: printf("NOP"); break;
    case 0x01: printf("LXI")

  }
}
