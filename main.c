int putchar(char c);
int getchar();

typedef signed char I1;
typedef unsigned char U1;
typedef signed short I2;
typedef unsigned short U2;
typedef signed int I4;
typedef unsigned int U4;
typedef signed long I8;
typedef unsigned long U8;


U1 heap[0xFFFF];


void pc(U1 c) {
  putchar(c);
}

U4 gc() {
  getchar();
}

void ps(U1* s) {
  for (;*s!=0;s++) {
    pc(*s);
  }
}

void pbl (U4 x) {
  pc(x ? '1' : '0');
}

void pb(U1 n) {
  for (U4 i=8; i>=0; i--) {
    U1 a = n >> i;
    pbl(a);
    n -= a << i;
  }
}

void pn() {
  pc('\n');
}

void pB(U1 n) {
  U1 dg[] = "0123456789ABCDEF";
  U1 hi4 = n >> 4;
  U1 lo4 = n - (hi4 << 4);
  pc(dg[hi4]);
  pc(dg[lo4]);
}

void pnB(U1* buf, U4 n) {
  for (U4 i=0; i<n; i++) {
    pB(buf[i]);
  }
}

void pX(U4 x) {
  U1* dg = "0123456789ABCDEF";
  U4 d = x / 16;
  U4 r = x % 16;
  if (d) pX(d);
  pc(dg[r]);
}

void pd(U4 x) {
  U1* dg = "0123456789";
  U4 d = x / 10;
  U4 r = x % 10;
  if (d) pd(d);
  pc(dg[r]);
}


U4 max(U4 a, U4 b) {
  return a > b ? a : b;
}

U4 min(U4 a, U4 b) {
  return a < b ? a : b;
}

void xxd(U1* buf, U4 len) {
  U4 sz = 16;
  U4 line_n = len / sz + !!(len % sz);
  for (U4 i=0; i<line_n; i++) {
    U4 off = sz * i;
    U4 byte_n = min(len - off, sz);
    for (U4 j=0; j<byte_n; j++) {
      pB(buf[off + j]);
      if (j % 2 == 1) pc(' ');
    }
    U4 pad_n = sz/2*5 - (byte_n * 2) - (byte_n / 2) + 1;
    for (U4 j=0; j<pad_n; j++) pc(' ');
    for (U4 j=0; j<byte_n; j++) {
      U1 c = buf[off + j];
      if (c >= ' ' && c <= '~') pc(c);
      else pc('.');
    }
    pc('\n');
  }
}

U4 slen(U1* s) {
  U4 i = 0;
  for (; s[i]; i++);
  return i;
}

void megadump() {
  //maximum range to not segfault
  xxd("aaaa"-8*1024-4, 82*1024);
}

U4 main() {
  megadump();
  /*
  U1 foo[] = "1234567890abcdefghi";
  foo[10] = 10;
  xxd(foo, slen(foo));
  */
  pd(1337);
  pn();
}


