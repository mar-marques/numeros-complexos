#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct tComplex{
  int x;
  int y;
};

struct tComplex complexo(int, int);

struct tComplex soma(struct tComplex, struct tComplex);

struct tComplex sub(struct tComplex, struct tComplex);

struct tComplex mult(struct tComplex, struct tComplex);

struct tComplex divi(struct tComplex, struct tComplex);


int main(){

  struct tComplex resultado;
  char entrada[30],auxent[30];
  char *A, *B, *C, *D, *op;
  int i= 0;


   while(fgets(entrada,30,stdin) != 0)
  {
    strcpy(auxent,entrada);
    A = strtok(auxent," ");
    B = strtok(NULL, "i");
    op = strtok(NULL, " ");
    C = strtok(NULL, " ");
    D = strtok(NULL,"i");

    if(strcmp(op,"+") == 0 )
    {
      resultado = soma(complexo(atoi(A), atoi(B)),complexo(atoi(C), atoi(D)));
    }
    else if(strcmp(op,"-") == 0 )
    {
      resultado = sub(complexo(atoi(A), atoi(B)),complexo(atoi(C), atoi(D)));
    }
    else if(strcmp(op,"*") == 0 )
    {
      resultado = mult(complexo(atoi(A), atoi(B)),complexo(atoi(C), atoi(D)));
    }
    else
    {
      resultado = divi(complexo(atoi(A), atoi(B)),complexo(atoi(C), atoi(D)));
    }

    printf("%d %s%di\n",resultado.x,resultado.y >= 0?"+":"",resultado.y);
   }

  return 0;
}

struct tComplex complexo(int a, int b)
{
    struct tComplex complexo;
    complexo.x = a;
    complexo.y = b;
    return complexo;
}

struct tComplex soma(struct tComplex m1, struct tComplex m2)
{
  m1.x = m1.x + m2.x;

  m1.y = m1.y + m2.y;

  return m1;
}

struct tComplex sub(struct tComplex m1, struct tComplex m2)
{
  m1.x = m1.x - m2.x;

  m1.y = m1.y - m2.y;

  return m1;
}

struct tComplex mult(struct tComplex m1, struct tComplex m2)
{
 struct tComplex r;
 r.x = m1.x * m2.x - m1.y * m2.y;

 r.y = m1.x * m2.y + m1.y * m2.x;

  return r;
}

struct tComplex divi(struct tComplex m1, struct tComplex m2)
{

 struct tComplex r;

int aux;
  r.x = (m1.x*m2.x + m1.y*m2.y)/(m2.x*m2.x + m2.y*m2.y);
  r.y = (m1.y*m2.x - m1.x*m2.y)/(m2.x*m2.x + m2.y*m2.y);

  return r;

}
