/////////////////////////////
/* Bitwise value operators */
/////////////////////////////

void readBits() { // read bit values for bitwise-stored variables
  int bParam = 0;
  switch (bitNum) {
    case 0:
      bParam = 5;
      break;
    case 1:
      bParam = 6;
      break;
    case 2:
      bParam = 145;
      break;
    case 3:
      bParam = 146;
      break;
    case 4:
      bParam = 147;
      break;
  }
  int bit0 = getParam(bParam);
  for (int i = 7; i >= 0; i--) {
    bitValues[bitNum][i] = bitRead(bit0, i);
  }
}

void storeBits() { // store bit values for bitwise-stored variables
  int bit0 = 0;
  int bParam = 0;
  switch (bitNum) {
    case 0:
      bParam = 5;
      break;
    case 1:
      bParam = 6;
      break;
    case 2:
      bParam = 145;
      break;
    case 3:
      bParam = 146;
      break;
    case 4:
      bParam = 147;
      break;
  }
  for (int i = 7; i >= 0; i--) {
    bitWrite(bit0, i, bitValues[bitNum][i]);
  }
  setParam(bParam, bit0);
}
