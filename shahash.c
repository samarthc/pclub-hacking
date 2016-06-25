#include <stdio.h>

#define BUFSIZE 500

char out[2*BUFSIZE];

int main(int argc, char **argv)
{
	char buf[BUFSIZE];
        char out2[BUFSIZE];
        FILE *f;

        if(argc < 2)
        {
            gets(buf);
            f = fopen ("./random.txt", "w");
            fputs(buf, f);
            fclose(f);

            sprintf(out, "openssl dgst -sha256 random.txt");
        }

        else
        {
            sprintf(out, "openssl dgst -sha256 %s", argv[1]);
        }

        FILE *fp = popen(out, "r");
        if (fp == NULL) {
            printf("Error");
            return 1;
        }

        f = fopen("./hash.txt", "w");
        if(argc >= 2)
        {
            sprintf(out, "Hash for %s:\n", argv[1]); 
            fputs(out, f);
        }
        
        while (fgets(out, sizeof(out), fp) > 0)
            fputs(out, f);

        pclose(fp);
        fclose(f);

	return 0;
}
