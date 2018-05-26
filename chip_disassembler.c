/**
  Algorithm for disassembling 8080 code:
    1. Read the code into a buffer
    2. Get a pointer to the beginning of the buffer
    3. Use the byte at the pointer to determine the opcode
    4. Print out the name of the opcode using the bytes after the opcode as data, if applicable
    5. Advance the point the number of bytes used by that instruction (1, 2, or 3 bytes)
    6. If not at the end of the buffer, go to step 3
**/

int Disassemble8080Op(unsigned char *codebuffer, int pc){
  unsigned char *code = &codebuffer[pc];
  int opbytes = 1;
  printf("%04x ", pc); //value is formatted as a hexadecimal with 4 digits and leading zeros
  switch (*code)
  {
    case 0x00: printf("NOP"); break;
    case 0x01: printf("LXI    B,#$%02x%02x", code[2], code[1]); opbytes = 3; break;
    case 0x02: printf("STAX   B"); break;
    case 0x03: printf("INX    B"); break;
    case 0x04: printf("INR    B"); break;
    case 0x05: printf("DCR    B"); break;
    case 0x06: printf("MVI    B,#$%02x", code[1]); opbytes = 2; break;
    case 0x07: printf("RLC"); break;
    case 0x08: printf("NOP"); break;
    case 0x09: printf("DAD    B"); break;
    case 0x0a: printf("LDAX   B"); break;
    case 0x0b: printf("DCX    B"); break;
    case 0x0c: printf("INR    C"); break;
    case 0x0d: printf("DCR    C"); break;
    case 0x0e: printf("MVI    C,#$%02x", code[1]); opbytes = 2; break;
    case 0x0f: printf("RRC"); break;
    case 0x10: printf("NOP"); break;
    case 0x11: printf("LXI    D,#$%02x%02x", code[2], code[1]); opbytes = 3; break;
    case 0x12: printf("STAX   D"); break;
    case 0x13: printf("INX    D"); break;
    case 0x14: printf("INR    D"); break;
    case 0x15: printf("DCR    D"); break;
    case 0x16: printf("MVI    D,#$%02x", code[1]); opbytes = 2; break;
    case 0x17: printf("RAL"); break;
    case 0x18: printf("NOP"); break;
    case 0x19: printf("DAD    D"); break;
    case 0x1a: printf("LDAX   D"); break;
    case 0x1b: printf("DCX    D"); break;
    case 0x1c: printf("INR    E"); break;
    case 0x1d: printf("DCR    E"); break;
    case 0x1e: printf("MVI    E,#$%02x", code[1]); opbytes = 2; break;
    case 0x1f: printf("RAR"); break;
    case 0x20: printf("RIM"); break;
    case 0x21: printf("LXI    D,#$%02x%02x", code[2], code[1]); opbytes = 3; break;
    case 0x22: printf("SHLD   adr"); break;
    case 0x23: printf("INX    H"); break;
    case 0x24: printf("INR    H"); break;
    case 0x25: printf("DCR    H"); break;
    case 0x26: printf("MVI    H,#$%02x", code[1]); opbytes = 2; break;
    case 0x27: printf("DAA"); opbytes = 1; break;
    case 0x28: printf("NOP"); break;
    case 0x29: printf("DAD    H"); break;
    case 0x2a: printf("LHLD   adr"); opbytes = 3; break;
    case 0x2b: printf("DCX    H"); break;
    case 0x2c: printf("INR    L"); break;
    case 0x2d: printf("DCR    L"); break;
    case 0x2e: printf("MVI    L,#$%02x", code[1]); opbytes = 2; break;
    case 0x2f: printf("CMA"); break;
    case 0x30: printf("SIM"); break;
    case 0x31: printf("LXI    SP,#$%02x%02x", code[2], code[1]); opbytes = 3; break;
    case 0x32: printf("STA    adr"); opbytes= 3; break;
    case 0x33: printf("INX    SP"); break;
    case 0x34: printf("INR    M"); break;
    case 0x35: printf("DCR    M"); break;
    case 0x36: printf("MVI    M,#$%02x", code[1]); break;
    case 0x37: printf("STC"); break;
    case 0x38: printf("NOP"); break;
    case 0x39: printf("DAD    SP"); break;
    case 0x3a: printf("LDA    adr"); opbytes = 3; break;
    case 0x3b: printf("DCX    SP"); break;
    case 0x3c: printf("INR    A"); break;
    case 0x3d: printf("DCR    A"); break;
    case 0x3e: printf("MVI    A,#0x%02x", code[1]); opbytes = 2; break; //why this inconsistency?
    case 0x3f: printf("CMC"); break;
    case 0x40: printf("MOV    B,B"), break;
    case 0x41:

  }
  printf("\n");
  return opbytes;
}
