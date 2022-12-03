#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 10

typedef struct
{
    char interprete[30];
    int num_pistas;
    float duracion;
}TDisco;

typedef struct
{
    TDisco conjunto[N];
    int tam,pos;
}TConjunto;


void InicializarConjunto(TConjunto *C, int tam);
int InsertarConjunto(TConjunto *C, TDisco D);
int EliminarConjunto(TConjunto *C, TDisco D);
int UnirConjunto(TConjunto C1, TConjunto B, TConjunto *C);
TConjunto Interseccion(TConjunto C1, TConjunto C2);
TConjunto DiferenciaDeConjuntos(TConjunto C1, TConjunto C2);
void Imprimir(TConjunto C);

int Menu();
char Captura_conjunto();
char Captura_conjunto_imp();
int Captura_dif();
int Captura_tam();
TDisco Captura_disco();
int ComparandoAndo(TDisco D, TDisco D1);


int main()
{
    TConjunto C1;
    TConjunto C2;
    TConjunto C3;
    TDisco D;
    int op=0;
    int tammm=0,inserta=0,Delete=0, unionn=0, dif=0, bandc1=0, bandc2=0, bandc3=0;
    int cont,cont1=0;
    do
    {

        op=Menu();
        switch(op)
        {
            case 1: op=1;
                    cont1=cont1+1;
                    cont = Captura_conjunto();
                    tammm= Captura_tam();
                    if(cont==1&&cont1<3)
                    {
                        InicializarConjunto(&C1, tammm);
                        printf("Conjunto C1 inicializado.\n\n");
                        bandc1=1;
                    }if(cont1>2){
                    printf("\nConjuntos YA inicializados");}
                    if(cont==2&&cont1<4)
                    {
                        InicializarConjunto(&C2, tammm);
                        printf("Conjunto C2 inicializado.\n\n");
                        bandc2=1;
                    }if(cont1>4){
                    printf("\nConjuntos YA inicializados");;}

                    break;

            case 2: op=2;
                    cont = Captura_conjunto();
                    if(cont==1)
                    {
                        if(bandc1==1)
                        {
                            D = Captura_disco();
                            inserta = InsertarConjunto(&C1, D);
                            if(inserta==1)
                            {
                                printf("Disco insertado correctamente en C1\n\n");
                            }else if(inserta==0)
                                {
                                    printf("El conjunto C1 lleno\n\n");
                                }else
                                    {
                                        printf("Este disco ya esta en el conjunto C1\n\n");
                                    }

                        }else
                            {
                                printf("Error Conjunto no inicializado, inicialice C1 para continuar\n\n");
                            }
                    }else
                        {
                            if(bandc2==1)
                            {
                                D = Captura_disco();
                                inserta = InsertarConjunto(&C2, D);
                                if(inserta==1)
                                {
                                    printf("Disco insertado correctamente en C2.\n\n");
                                }else if(inserta==0)
                                    {
                                        printf("El conjunto C2 esta lleno\n");
                                    }else
                                        {
                                            printf("Este disco ya esta en el conjunto C2.\n\n");
                                        }
                            }else
                                {
                                    printf("Error Conjunto no inicializado, inicialice C2 para continuar\n\n");
                                }
                        }
                    break;

            case 3: op=3;
                    cont = Captura_conjunto();
                    if(cont==1)
                    {
                        if(bandc1==1)
                        {
                            D = Captura_disco();
                            Delete = EliminarConjunto(&C1, D);
                            if(Delete==1)
                            {
                                printf("Disco eliminado correctamente de C1 \n\n");
                            }else
                                {
                                    printf("El disco no existe en C1 \n\n");
                                }
                        }else
                            {
                                printf("Error Conjunto no inicializado, inicialice C1 para continuar\n\n");
                            }
                    }else
                        {
                            if(bandc2==1)
                            {
                                D=Captura_disco();
                                Delete=EliminarConjunto(&C2, D);
                                if(Delete==1)
                                {
                                    printf("Disco eliminado correctamente de C2\n\n");
                                }else
                                    {
                                        printf("El disco no existe en C2\n\n");
                                    }

                            }else
                                {
                                    printf("Error Conjunto no inicializado, inicialice C2 para continuar\n\n");
                                }
                        }
                    break;

            case 4: op=4;
                    cont = Captura_conjunto_imp();
                    if(cont==1)
                    {
                        if(bandc1==1)
                        {
                            Imprimir(C1);
                        }else
                        {
                            printf("Error Conjunto no inicializado, inicialice C1 para continuar\n\n");
                        }
                    }else if(cont==2)
                        {
                        if(bandc1==1)
                        {
                            Imprimir(C2);
                        }else
                        {
                            printf("Error Conjunto no inicializado, inicialice C2 para continuar \n\n");
                        }
                        }else
                        {
                        if(bandc3==1)
                        {
                            Imprimir(C3);
                        }else
                        {
                            printf("Error Conjunto no inicializado, inicialice C3 para continuar\n\n");
                        }
                        }
                    break;

            case 5: op=5;
                    if(bandc1==1 && bandc2==1)
                    {
                        unionn = UnirConjunto(C1, C2, &C3);
                        if(unionn==1)
                        {
                            printf("Union exitosa, datos almacendos en c3 \n\n");
                        }
                        bandc3=1;

                        }if(bandc1==1 && bandc2==0)

                        {
                            printf("Error al unir c1 con c1\n\n");
                        }
                        if(bandc1==0 && bandc2==1)
                        {
                            printf("Error al unir c2 con c2\n\n");
                        }
                        else
                        {
                            printf("No hay conjuntos para Unir\n\n");
                        }
                    break;

            case 6: op=6;
                    if(bandc1==1 && bandc2==1)
                    {
                        C3 = Interseccion(C1, C2);
                        printf("Inteerseccion exitosa Datos de la interseccion en c3\n\n");
                        bandc3=1;

                    }else if(bandc1==1 && bandc2==0)
                        {
                            printf("Error al unir c1 con c1\n\n");
                    }else if(bandc1==0 && bandc2==1)
                        {
                            printf("Error al unir c2 con c2\n\n");
                        }else
                        {
                            printf("No hay conjuntos para intersectar\n\n");
                        }
                    break;

            case 7: op=7;
                    if(bandc1==1&&bandc2==1)
                    {
                        dif=Captura_dif();
                        if(dif==1)
                        {
                            C3=DiferenciaDeConjuntos(C1, C2);
                            printf("Diferencia de C1-C2 exitosa y almacenada en c3 \n\n");
                            bandc3=1;
                        }else
                        {
                            C3=DiferenciaDeConjuntos(C2, C1);
                            printf("Diferencia C2-C1 exitosa y almacenada en c3\n\n");
                            bandc3=1;
                        }
                    }else if(bandc1==1&&bandc2==0)
                    {
                        printf("Error en la diferncia de  c1 con c1\n\n");
                    }else if(bandc1==0&&bandc2==1)
                        {
                            printf("Error en la diferncia de  c2 con c2\n\n");
                        }else
                        {
                            printf("No hay conjuntos para restar\n\n");
                        }
                    break;

            case 8: op=8;
                    break;
        }
    }while(op<8);
}

int Menu()
{
    int c;
    printf("\n--Elige una opcion--\n");
    printf("\nPresiona(1)para un Nuevo Conjunto");
    printf("\nPresiona(2)para agregar un disco");
    printf("\nPresiona(3)para eliminar un disco");
    printf("\nPresiona(4)para Imprimir el conjunto");
    printf("\nPresiona(5)para unir 2 conjuntos");
    printf("\nPresiona(6)para intersectar 2 conjuntos");
    printf("\nPresiona(7)para obtener la diferencia de 2 conjuntos");
    printf("\nPresiona(8)para finalizar el programa\n");
    scanf("%d",&c);
    return(c);
}

void InicializarConjunto(TConjunto *c, int tam)
{
    c -> tam=tam<=N?tam:N;
    c -> pos=0;
}

int InsertarConjunto(TConjunto *c, TDisco D)
{
    int i;
    if(c->pos==c->tam)
    {
        return(0);
    }
    for(i=0; i<c->pos && ComparandoAndo(c->conjunto[i], D)==0; i++);
    if(i==c->pos)
    {
        c->conjunto[i]=D;
        c->pos++;
        return(1);
    }
    return(-1);
}

int EliminarConjunto(TConjunto *c, TDisco D)
{
    int i;
    for(i=0; i<c->pos && ComparandoAndo(c->conjunto[i], D)==0; i++);
    if(i==c->pos)
    {
        return(0);
    }
    for( ; i<c->pos; i++)
    {
        c->conjunto[i]=c->conjunto[i+1];
    }
    c->pos--;
    return(1);
}

int UnirConjunto(TConjunto C1, TConjunto B, TConjunto *c)
{
    int i, x;
    InicializarConjunto(&*c, C1.pos + B.pos);
    for(i=0; i<C1.pos; i++)
    {
        c -> conjunto[i]=C1.conjunto[i];
    }
    c -> pos=C1.pos;
    for(i=0; i<B.pos; i++)
    {
        x=InsertarConjunto(&*c, B.conjunto[i]);
        if(x==0)
        {
            return(0);
        }
    }
    return(1);
}

TConjunto Interseccion(TConjunto C1, TConjunto B)
{
    int i, j;
    TConjunto I;
    InicializarConjunto(&I, C1.pos);
    for(i=0; i<C1.pos; i++)
    {
        for(j=0; j<B.pos; j++)
        {
            if(ComparandoAndo(C1.conjunto[i], B.conjunto[j])==1)
            {
                InsertarConjunto(&I, C1.conjunto[i]);
            }
        }
    }
    return(I);
}

TConjunto DiferenciaDeConjuntos(TConjunto C1, TConjunto C2)
{
    int i, j;
    TConjunto D;
    InicializarConjunto(&D, C1.pos);
    for(i=0; i<C1.pos; i++)
    {
        for(j=0; j<C2.pos+1 && ComparandoAndo(C1.conjunto[i], C2.conjunto[j])==0 ; j++)
        {
            if(j==C2.pos)
            {
                InsertarConjunto(&D, C1.conjunto[i]);
            }
        }
    }
    return(D);
}

char Captura_conjunto()
{
    int conj;
    printf("Seleccione un conjunto(C1[1] o C2[2]):");
    scanf("%d", &conj);
    return(conj);
}

char Captura_conjunto_imp()
{
    int conj;
    printf("Seleccione un conjunto(C1[1] ,C2[2] o C3[3]):");
    scanf("%d", &conj);
    return(conj);
}

int Captura_dif()
{
    int opd;
    printf("\n Diferencias");
    printf("\n Presione(1)para la diferencia entre C1-C2");
    printf("\n Presione(1)para la diferencia entre C2-C1");
    scanf("%d", &opd);
    return(opd);
}

int Captura_tam()
{
    int t;
    printf("Ingrese la dimension del conjunto:");
    scanf("%d", &t);
    return(t);
}

TDisco Captura_disco()
{
    TDisco D;
    printf("Interprete:");
    fflush(stdin);
    gets(D.interprete);
    printf("Numero de pistas:");
    scanf("%d",&D.num_pistas);
    printf("Duracion:");
    scanf("%f",&D.duracion);
    return(D);
}

void Imprimir(TConjunto c)
{
    int i;
    for(i=0; i<c.pos; i++)
    {
        printf("Interprete: %s", c.conjunto[i].interprete);
        printf("Numero de pistas: %d", c.conjunto[i].num_pistas);
        printf("Duracion: %f", c.conjunto[i].duracion);
        printf("\n");
    }
}

int ComparandoAndo(TDisco D, TDisco d1)
{
    if(D.duracion == d1.duracion && D.num_pistas == d1.num_pistas && strcmp(D.interprete, d1.interprete)==0)
    {
        return(1);
    }
    return(0);
}
