#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x) {
   return pow(x,5)-3*pow(x,4)-3*pow(x,2)+2;
}


int main() {

float esc,salva;
float a, b, e;


    printf("Digite o metodo: \n");
    printf("1 Metodo de Bissecao \n");
    printf("2 Metodo da Posicao Falsa \n");
    printf("3 Metodo de Pegaso \n");
    scanf("%f",&esc);
    printf("Digite o intervalo: \n");
    scanf("%f %f",&a,&b);
    printf("Digite a precisao : \n");
    scanf("%f",&e);

    if(esc == 1){
           float p, c;
           int teorema = 0;

            teorema = (f(a)*f(b) > 0);
            while(teorema == 0) {
            printf("\n nao satisfaz o teorema do intervalo: ",a,b);
            scanf("%f %f", &a, &b);
            teorema = (f(a)*f(b) > 0);
           }
            while(p > e) {
                p = b-a;
                c = (a+b)/2;
                if(f(c) == 0) {
                printf("resposta %.4f\n",c);
                return 0;
                  }

                  if(f(a)*f(c) < 0)  b = c;
                   else a = c;
               }

               printf("\n resultado aproximado %.4f \n",(a+b)/2);

                salva=(a+b)/2;
                FILE *fp;

                   fp = fopen("bissecao A.txt","w");
                   if(!fp)
                    {
                      printf( "Erro na abertura do arquivo");
                      exit(0);
                    }

                    fprintf(fp," Resultado em Bissecao %f \n", salva);

                   fclose(fp);



               return 0;
            }
    if(esc == 2){

                float c;
                c = (b*f(a)-f(b)*a)/(f(a)-f(b));
                while(f(c) > e){
                c = (b*f(a)-f(b)*a)/(f(a)-f(b));
                if(f(c)*f(a) < 0)  b = c;
                else a = c;
               }
                printf("\n resultado aproximado %.4f \n",c);


                FILE *fp;

                   fp = fopen("Posicao Falsa A.txt","w");
                   if(!fp)
                    {
                      printf( "Erro na abertura do arquivo");
                      exit(0);
                    }

                    fprintf(fp," Resultado em Posicao falsa %f \n", c);

                   fclose(fp);

             return 0;
    }
    if(esc == 3){

                float c;
                c = (a*f(b)-f(a)*b)/(f(b)-f(a));
                while(f(c) > e){
                c = (a*f(b)-f(a)*b)/(f(b)-f(a));
                if(f(a)*f(c) < 0)  b = c;
                else a = c;
               }
                printf("\n resultado aproximado %.4f \n",c);

                  FILE *fp;

                   fp = fopen("Pegaso A.txt","w");
                   if(!fp)
                    {
                      printf( "Erro na abertura do arquivo");
                      exit(0);
                    }

                    fprintf(fp," Resultado em Pegaso %f \n", c);

                   fclose(fp);

             return 0;
    }
    else{

    printf("ERROR");
    }
return 0;
}
