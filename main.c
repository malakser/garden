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
  char dg[] = "0123456789ABCDEF";
  char hi4 = n >> 4;
  char lo4 = n - (hi4 << 4);
  pc(dg[hi4]);
  pc(dg[lo4]);
}

void pnB(char* buf, int n) {
  for (int i=0; i<n; i++) {
    pB(buf[i]);
  }
}

void pX(int x) {
  char* dg = "0123456789ABCDEF";
  int d = x / 16;
  int r = x % 16;
  if (d) pX(d);
  pc(dg[r]);
}

void pd(int x) {
  char* dg = "0123456789";
  int d = x / 10;
  int r = x % 10;
  if (d) pd(d);
  pc(dg[r]);
}


int max(int a, int b) {
  return a > b ? a : b;
}

int min(int a, int b) {
  return a < b ? a : b;
}

void xxd(char* buf, int len) {
  int sz = 16;
  int line_n = len / sz + !!(len % sz);
  for (int i=0; i<line_n; i++) {
    int off = sz * i;
    int byte_n = min(len - off, sz);
    for (int j=0; j<byte_n; j++) {
      pB(buf[off + j]);
      if (j % 2 == 1) pc(' ');
    }
    int pad_n = sz/2*5 - (byte_n * 2) - (byte_n / 2) + 1;
    for (int j=0; j<pad_n; j++) pc(' ');
    for (int j=0; j<byte_n; j++) {
      char c = buf[off + j];
      if (c >= ' ' && c <= '~') pc(c);
      else pc('.');
    }
    pc('\n');
  }
}

int slen(char* s) {
  int i = 0;
  for (; s[i]; i++);
  return i;
}

void megadump() {
  //maximum range to not segfault
  pnB("aaaa"-8*1024-4, 84*1024);
}

int main() {
  //megadump();
  //pX(128);
  //pX(84*1024 - (8*1024+4));
  //char* foo = "sdfghjklasa;dsfghjdkksjkfsdlfkdsdjfdskfklsdfsdjlf";
  char foo[] = "1234567890abcdefghi";
  foo[10] = 10;
  xxd(foo, slen(foo));
  pd(1337);
  pn();
}


