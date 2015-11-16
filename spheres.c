#include<stdio.h>

typedef struct{
	float x;
	float y;
	float z;
}tipo_centro;

typedef struct{
	int codigo;
	float radio;
	tipo_centro centro;
}tipo_esfera;

typedef struct{
	int codigo;
	float volumen;
}esfera_aux;

typedef esfera_aux vector_esfera_aux[500];
typedef tipo_esfera vector_esferas[500];


void Altaesfera(vector_esferas esferas, int *codigo);
void Versuperficievolumen(vector_esferas esferas, int codigo);
void Esferasconcentricas(vector_esferas esferas, int codigo);
void Listarporvolumen(vector_esferas esferas, int codigo);
void Listarpositivas(vector_esferas esferas, int codigo);
void Esferasinterceptadas(vector_esferas esferas, int codigo);

int main()
{
	int codigo=0, i, opcion=0;
	vector_esferas esferas;
	for(i=0;i<=500;i++)
	{
		esferas[i].centro.x=0;
		esferas[i].centro.y=0;
		esferas[i].centro.z=0;
		esferas[i].radio=0;
		esferas[i].codigo=0;
	}
	do{
			printf("1)Dar de alta una nueva esfera\n"
					"2)Ver la superficie y el volumen de una esfera\n"
					"3)Ver si una esfera esta dentros de otra\n"
					"4)Mostrar las esferas ordenadas por volumen\n"
					"5)Listar las esferas que estan en el octante positivo\n"
					"6)Ver si dos esferas se interceptan en el espacio\n"
					"7)Salir\n");
			scanf("%i",&opcion);
			while(getchar()!='\n');
			while((opcion<1)||(opcion>7))
			{
				printf("Opcion equivocada, repita\n");
				scanf("%i",&opcion);
				while(getchar()!='\n');
			}
			if(((opcion==2)||(opcion==3)||(opcion==4)||(opcion==5)||(opcion==6))&&(codigo==0))
			{
				printf("No hay esferas dadas de alta\n");
			}
			else
			{
				switch(opcion)
				{
					case 1:Altaesfera(esferas, &codigo);
					break;
					case 2:Versuperficievolumen(esferas, codigo);
					break;
					case 3:Esferasconcentricas(esferas, codigo);
					break;
					case 4:Listarporvolumen(esferas, codigo);
					break;
					case 5:Listarpositivas(esferas, codigo);
					break;
					case 6:Esferasinterceptadas(esferas, codigo);
					break;
				}
			}
		}while(opcion!=7);
}




void Altaesfera(vector_esferas esferas, int *codigo)
{
	printf("Escriba el radio\n");
	scanf("%f",&esferas[*codigo].radio);
	while(getchar()!='\n');
	printf("Escriba la coordenada x del centro\n");
	scanf("%f",&esferas[*codigo].centro.x);
	while(getchar()!='\n');
	printf("Escriba la coordenada y del centro\n");
	scanf("%f",&esferas[*codigo].centro.y);
	while(getchar()!='\n');
	printf("Escriba la coordenada z del centro\n");
	scanf("%f",&esferas[*codigo].centro.z);
	while(getchar()!='\n');
	esferas[*codigo].codigo=*codigo+1;
	*codigo=*codigo+1;
}



void Versuperficievolumen(vector_esferas esferas, int codigo)
{
	int cod=0;
	float superficie, volumen;
	printf("Escriba el codigo de la esfera\n");
	scanf("%i",&cod);
	while(getchar()!='\n');
	if(esferas[cod].codigo!=0)
	{
		volumen=(4*(3.1415)*(esferas[cod].radio*(esferas[cod].radio)*(esferas[cod].radio)))/3;
		superficie=4*3.1415*(esferas[cod].radio)*(esferas[cod].radio);
		printf("El volumen de la esfera %i es: %.2f"
				"y la superficie es: %.2f",esferas[cod].codigo, volumen, superficie);
	}
	else
	{
		printf("Esfera no encontrada\n");
	}
}


void Esferasconcentricas(vector_esferas esferas, int codigo)
{
	float num, num1, num2, num3, resultado;
	int i;
	for(i=0;i<codigo-1;i++)
	{
		resultado=0;
		num1=(esferas[i+1].centro.x-esferas[i].centro.x)*(esferas[i+1].centro.x-esferas[i].centro.x);
		num2=(esferas[i+1].centro.y-esferas[i].centro.y)*(esferas[i+1].centro.y-esferas[i].centro.y);
		num3=(esferas[i+1].centro.z-esferas[i].centro.z)*(esferas[i+1].centro.z-esferas[i].centro.z);
		num=num1+num2+num3;
		while((resultado*resultado)<=num)
		{
			resultado++;
		}
		resultado--;
		while((resultado*resultado)<=num)
		{
			resultado=resultado+0.1;
		}
		resultado=resultado-0.1;
		while((resultado*resultado)<=num)
		{
			resultado=resultado+0.01;
		}
		resultado=resultado-0.01;
		if((resultado+esferas[i+1].radio)<=esferas[i].radio)
		{
			printf("La esfera %i esta dentro de la esfera %i\n",i+2,i+1);
		}
	}
}



void Listarporvolumen(vector_esferas esferas, int codigo)
{
	int i, j, a;
	vector_esfera_aux vectoraux;
	for(i=0;i<codigo;i++)
	{
		a=0;
		while((a<i)&&(((4*(3.1415)*(esferas[i].radio*(esferas[i].radio)*(esferas[i].radio)))/3)<((4*(3.1415)*(esferas[i+1].radio*(esferas[i+1].radio)*(esferas[i+1].radio)))/3)))
		{
			a=a+1;
		}
		for(j=a;j>a;j--)
		{
			vectoraux[j]=vectoraux[j-1];
		}
		vectoraux[i].codigo=esferas[i].codigo;
		vectoraux[i].volumen=((4*(3.1415)*(esferas[i].radio*(esferas[i].radio)*(esferas[i].radio)))/3);
	}
	for(i=0;i<codigo;i++)
	{
		printf("Radio de la esfera %i: %f\n"
				"Coordenadas: %.2f,%.2f,%.2f\n\n", vectoraux[i].codigo, esferas[vectoraux[i].codigo-1].radio,
				esferas[vectoraux[i].codigo-1].centro.x,
				esferas[vectoraux[i].codigo-1].centro.y,esferas[vectoraux[i].codigo-1].centro.z);
	}
}



void Listarpositivas(vector_esferas esferas, int codigo)
{
	int i;
	for(i=0;i<codigo;i++)
	{
		if((esferas[i].centro.x>0)&&(esferas[i].centro.y>0)
				&&(esferas[i].centro.z>0))
		{
			printf("La esfera %i esta en el octante positivo\n",esferas[i].codigo);
		}
	}
}


void Esferasinterceptadas(vector_esferas esferas, int codigo)
{
	int i, j=1;
	for(i=0;i<499;i++)
	{
		do{
			if((esferas[i].radio+esferas[i].radio)<=(esferas[i].radio+esferas[j].radio))
			{
				printf("La esfera %i se cruza con la esfera %i\n",i+1,j+1);
			}
			j++;
		}while(j<=499);
		j=i+2;
	}
}








