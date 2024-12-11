#include <stdio.h>
#include <string.h>
int F(int sk, char tk, char p[])
{
    if(sk<strlen(p) && p[sk] == tk)
    {
        return sk+1;
    }
    else{
        return 0;
    }
}
int patternMatching(char p[], char t[])
{
    int N =strlen(t);
    int sk = 0;
    int k = 1;
 while (sk!=strlen(p) && k<=N)
  {
      char tk = t[k-1];
      sk = F(sk,tk,p);
      k++;}
  if(sk == strlen(p))
  {
      return k-strlen(p);
  }
  else{
    return 0;
  }}
int main()
{
    char t[] = "MynameisPUJA";
    char p[] = "name";
    int index = patternMatching(p,t);
    if(index>0)
    {
        printf("Pattern found at index: %d\n",index);
    }
    else{
        printf("Pattern not found!\n");
    }
    return 0;
}
