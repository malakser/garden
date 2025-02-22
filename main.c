int putchar(char c);


char a[0xFFFF];



/*
enum DynType {
  INT,
  DINT, //???
}
//^don't you need dynamic allocation for that?


typedef struct {
  int v;
  int t;
} Dint;

union {
}
*/

void pc(char c) {
  putchar(c);
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
    pB(buf[n]);
  }
}

/*
void xxd(char* buf, int len) {
  int line_n = len / 32;
  for (int byte_i= 0;)
}
*/

int main() {
  pB(17);
  pc('\n');
}

/*
pbl(0x23 >> 0);
pbl(0x23 >> 1);
pbl(0x23 >> 2);
pbl(0x23 >> 3);
pbl(0x23 >> 4);
this might generate mask
*/

