#include <stdio.h>
#include <string.h>
int main()
{
    char buf[1000] = {0};
    memset(buf, 0, sizeof(buf));
    FILE *fp = fopen("test2.dat","wb");
    fwrite(buf,1,1000,fp);
    return 0;
}
