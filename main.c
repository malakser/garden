int putchar(char c);
int getchar();


char heap[0xFFFF];


void pc(char c) {
  putchar(c);
}

int gc() {
  getchar();
}

void ps(char* s) {
  for (;*s!=0;s++) {
    pc(*s);
  }
}

void pbl (int x) {
  pc(x ? '1' : '0');
}

void pb(char n) {
  for (int i=8; i>=0; i--) {
    char a = n >> i;
    pbl(a);
    n -= a << i;
  }
}

void pn() {
  pc('\n');
}

void pB(char n) {
  char d[] = "0123456789ABCDEF";
  char hi4 = n >> 4;
  char lo4 = n - (hi4 << 4);
  pc(d[hi4]);
  pc(d[lo4]);
}

void pnB(char* buf, int n) {
  for (int i=0; i<n; i++) {
    pB(buf[i]);
  }
}

void pX(int x) {
  char dg[] = "0123456789ABCDEF";
  int d = x / 16;
  int r = x % 16;
  if (d) pX(d);
  pc(dg[r]);
}

/*
void xxd(char* buf, int len) {
  int line_n = len / 32;
  for (int byte_i= 0;)
}
*/

void megadump() {
  //maximum range to not segfault
  pnB("aaaa"-8*1024-4, 84*1024);
}

int main() {
  //megadump();
  pX(128);
  pc('\n');
}


