#include <stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;

typedef struct {
        float real; /*Parte real del número complejo*/
        float imaginario; /*Parte imaginaria del número complejo*/ 
} complejo;


/* Operación Suma Dos numeros complejos */
complejo sumar(complejo c1, complejo c2)
{ complejo res;
  res.real = c1.real + c2.real;
  res.imaginario = c1.imaginario + c2.imaginario;
  return res;
}
/* Operación resta  Dos numeros complejos */
complejo restar(complejo c1, complejo c2)
{ complejo res;
  res.real = c1.real - c2.real;
  res.imaginario = c1.imaginario - c2.imaginario;
  return res;
}

/* Operación multiplica  Dos numeros complejos */
complejo multiplicar(complejo c1, complejo c2)
{ complejo res;
  res.real = c1.real*c2.real -c1.imaginario*c2.imaginario ;
  res.imaginario =c1.real*c2.imaginario + c2.real*c1.imaginario;
  return res;
}
/* Operación divide  Dos numeros complejos */
complejo dividir(complejo c1, complejo c2)
{ complejo res;
  float denominador;
  denominador=(c2.real*c2.real+c2.imaginario*c2.imaginario);
  cout<<denominador;
  res.real = (c1.real*c2.real +c1.imaginario*c2.imaginario) /denominador;
  res.imaginario =(c2.real*c1.imaginario - c1.real*c2.imaginario )/ denominador;
  return res;
}


void imprimirComplejo( complejo c1, string mens)
{
     char posi ='+';
     if (c1.imaginario <0)
         posi =' ';
     cout<<mens<<c1.real<<posi<<c1.imaginario<<"i\n";
}
