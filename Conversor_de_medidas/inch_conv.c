#include<stdio.h>
#include<stdlib.h>

#define Esc 27

float inch,mm,frac;
  int ap_frac, ap_fracinch;

float inchtomm(float);
float mmtoinch(float);
float mmtofracinch(int);
float inchtofracinch(int);
float fracinchtomm(float);

int main()
{
  char answ;

do{

  int op;

    system("clear");

   printf("\n\tConversor de medidas\n");

	printf("\n\tDigite opcao desejada\n\t1 - polegada para mm\n\t2 - mm para polegada\n\t3 - mm para polegada fracionaria\n\t4 - polegada para polegada fracionaria\n\t5 - polegada fracionaria para mm\n");
    scanf("%i",&op);

if(op==1) inchtomm(mm);

else if(op==2) mmtoinch(inch);

else if(op==3) mmtofracinch(ap_frac);

else if(op==4) inchtofracinch(ap_fracinch);
               
else if(op==5) fracinchtomm(mm);


else if(!(op==1&&op==2&&op==3&&op==4)) printf("\nValor invalido\n");

printf("\nTecle Esc para sair\n");
  scanf("%s",&answ);

}while(answ!=Esc);
  return 0;
}

float inchtomm(float mm)
{

  printf("\nDigite valor em polegada\n");
      scanf("%f",&inch);

      mm=inch*25.4;

  printf("\nmm = %.3f\n",mm);

  return mm;
}

float mmtoinch(float inch)
{

printf("\nDigite valor em milimetro\n");
  scanf("%f",&mm);

  inch=mm/25.4;

printf("\ninch = %.3f\n",inch);

  return inch;
}
float mmtofracinch(int ap_frac)
{
	int den=128;

printf("\nDigite valor em milimetro\n");
  scanf("%f",&mm);

  frac=(mm/25.4)*128;
  ap_frac=frac;

  //arredonda para cima se o decimal seguinte for maior que 5
if((frac-ap_frac)>=0.5) ap_frac=frac+1-(frac-ap_frac);
 while((ap_frac % 2)==0)
 {
  ap_frac=ap_frac/2.00;
  den=den/2;
 }

printf("\nfrac_inch = %i/%i\n",ap_frac,den);

 return ap_frac;
}

float inchtofracinch(int ap_fracinch)
{

printf("\nDigite valor em polegada\n");            
	scanf("%f",&inch);
 
  int deno=128;
  frac=inch*128;
  ap_fracinch=frac;

  //arredonda para cima se o decimal seguinte for maior que 5
if((frac-ap_fracinch)>=0.5) ap_fracinch=frac+1-(frac-ap_fracinch);
//simplifica enquanto tiver resto 0
 while(((ap_fracinch % 2)==0) && deno>1)
 {
  ap_fracinch=ap_fracinch/2.00;
  deno=deno/2;
 }
 printf("\nfrac_inch = %i/%i\n",ap_fracinch,deno);         
 return ap_fracinch;
}

float fracinchtomm(float mm)                         {                  
	float inch_nu,inch_de;

  printf("\nDigite valor em polegada do numerador e denominador separado por espaco\n");   
  scanf("%f%f",&inch_nu,&inch_de);

	mm=(inch_nu/inch_de)*25.4;
                                                       printf("\nmm = %.3f\n",mm);                        
  return mm;                                         }
