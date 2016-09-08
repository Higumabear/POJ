#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int k,n,a,b,c,l=1000,r=1;
  scanf("%d\n",&k);
  while (k--) {
    scanf("%d\n",&n);
    char *t=(char*)calloc(1001, 1);
    for (int i=0;i<n;i++) {
      scanf("%c%d%d\n", &c, &a, &b);
      if (b>r) r=b;
      if (a<l) l=a;
      for (int j=a;j<b;j++) t[j]++;
    }
    for (int i=l;i<r;i++) if (t[i]) putchar(64+t[i]);
    putchar('\n');
    free(t);
  }
}
