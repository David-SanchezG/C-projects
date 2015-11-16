#include<stdio.h>

typedef char cadena[41];
typedef char psalida[16];
typedef char tipo_telefono[10];
typedef struct{
	int dia;
	int mes;
}tipo_fecha;

typedef psalida tipo_puertos[25];
typedef float tipo_millas[25];

typedef struct{
	int codigo_crucero;
	cadena nombre_cliente;
	tipo_telefono telefono;
	psalida puerto_salida;
	tipo_fecha dia_salida;
	int numero_etapas;
	tipo_puertos puertos;
	tipo_millas millas_etapas;
	int pasajeros;
}tipo_viaje;

typedef tipo_viaje tipo_cruceros[500];

void Altacrucero(tipo_cruceros crucero, int *codigo);
void Anotarmillas(tipo_cruceros crucero, int codigo);
void Rectificarruta(tipo_cruceros crucero, int codigo);
void Mostrardatoscrucero(tipo_cruceros crucero, int codigo);
void Crucerosmes(tipo_cruceros crucero, int codigo);
void Crucerospuerto(tipo_cruceros crucero, int codigo);


int main()
{
	int i, codigo=0, opcion=0;
	tipo_cruceros crucero;
	do{
		printf("1)Dar de alta una nueva petición de crucero\n"
				"2)Anotar las millas naúticas de los distintos tramos\n"
				"3)Rectificar una cierta ruta\n"
				"4)Mostrar en pantalla todos los datos de un cierto crucero\n"
				"5)Listar todos los cruceros que parten un cierto mes\n"
				"6)Listar todos los cruceros que pasan por un cierto puerto\n"
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
			printf("No hay cruceros dados de alta\n");
		}
		else
		{
			switch(opcion)
			{
				case 1:Altacrucero(crucero, &codigo);
				break;
				case 2:Anotarmillas(crucero, codigo);
				break;
				case 3:Rectificarruta(crucero, codigo);
				break;
				case 4:Mostrardatoscrucero(crucero, codigo);
				break;
				case 5:Crucerosmes(crucero, codigo);
				break;
				case 6:Crucerospuerto(crucero, codigo);
				break;
			}
		}
	}while(opcion!=7);
}



void Altacrucero(tipo_cruceros crucero, int *codigo)
{
	int i;
	printf("Escriba su nombre\n");
	scanf("%40[^\n]s",crucero[*codigo].nombre_cliente);
	crucero[*codigo].nombre_cliente[40]='\0';
	while(getchar()!='\n');
	printf("Escriba su telefono\n");
	scanf("%9[^\n]s",crucero[*codigo].telefono);
	crucero[*codigo].telefono[9]='\0';
	while(getchar()!='\n');
	printf("Escriba el nombre del puerto de salida\n");
	scanf("%15[^\n]s",crucero[*codigo].puerto_salida);
	crucero[*codigo].puerto_salida[15]='\0';
	while(getchar()!='\n');
	printf("Escriba el dia de salida\n");
	scanf("%i",&crucero[*codigo].dia_salida.dia);
	while(getchar()!='\n');
	while((crucero[*codigo].dia_salida.dia<1)||(crucero[*codigo].dia_salida.dia>31))
	{
		printf("Dia equivocado, repita\n");
		scanf("%i",&crucero[*codigo].dia_salida.dia);
		while(getchar()!='\n');
	}
	printf("Escriba el mes de salida\n");
	scanf("%i",&crucero[*codigo].dia_salida.mes);
	while(getchar()!='\n');
	while((crucero[*codigo].dia_salida.mes<1)||(crucero[*codigo].dia_salida.mes>12))
	{
		printf("Dia equivocado, repita\n");
		scanf("%i",&crucero[*codigo].dia_salida.mes);
		while(getchar()!='\n');
	}
	printf("Escriba el numero de etapas\n");
	scanf("%i",&crucero[*codigo].numero_etapas);
	while(getchar()!='\n');
	while((crucero[*codigo].numero_etapas<1)||(crucero[*codigo].numero_etapas>25))
	{
		printf("Numero equivocado, repita\n");
		scanf("%i",&crucero[*codigo].numero_etapas);
		while(getchar()!='\n');
	}
	for(i=0;i<crucero[*codigo].numero_etapas;i++)
	{
		printf("Escriba el nombre del puerto %i\n",i+1);
		scanf("%15[^\n]s",crucero[*codigo].puertos[i]);
		crucero[*codigo].puertos[i][15]='\0';
		while(getchar()!='\n');
	}
	printf("Escriba el numero de pasajeros del crucero\n");
	scanf("%i",&crucero[*codigo].pasajeros);
	while(getchar()!='\n');
	while((crucero[*codigo].pasajeros<1)||(crucero[*codigo].pasajeros>12))
	{
		printf("Numero equivocado, repita\n");
		scanf("%i",&crucero[*codigo].pasajeros);
		while(getchar()!='\n');
	}

	crucero[*codigo].codigo_crucero=*codigo+1;
	*codigo=*codigo+1;
}



void Anotarmillas(tipo_cruceros crucero, int codigo)
{
	int i;
	for(i=0;i<crucero[codigo].numero_etapas;i++)
	{
		printf("Escriba las millas del puerto %i\n",i+1);
		scanf("%f",crucero[codigo].millas_etapas[i]);
		while(getchar()!='\n');
	}
}

void Rectificarruta(tipo_cruceros crucero, int codigo)
{
	int i, cod_crucero, opcion;
	printf("Escriba el codigo del crucero\n");
	scanf("%i",&cod_crucero);
	while(getchar()!='\n');
	while((cod_crucero<1)||(cod_crucero>codigo))
	{
		printf("Codigo inexistente, repita\n");
		scanf("%i",&cod_crucero);
		while(getchar()!='\n');
	}
	printf("Desea modificar el numero de puertos\n"
			"1)Si\n"
			"2)No\n");
	scanf("%i",&opcion);
	while(getchar()!='\n');
	if(opcion==1)
	{
		printf("Escriba el numero de etapas\n");
		scanf("%i",&crucero[cod_crucero].numero_etapas);
		while(getchar()!='\n');
		while((crucero[cod_crucero].numero_etapas<1)||(crucero[cod_crucero].numero_etapas>25))
		{
			printf("Numero equivocado, repita\n");
			scanf("%i",&crucero[cod_crucero].numero_etapas);
			while(getchar()!='\n');
		}
	}
	printf("Desea modificar el nombre de los puertos\n"
			"1)Si\n"
			"2)No\n");
	scanf("%i",&opcion);
	while(getchar()!='\n');
	if(opcion==1)
	{
		for(i=1;i<=crucero[cod_crucero].numero_etapas;i++)
		{
			printf("Escriba el nombre del puerto %i\n",i);
			scanf("%15[^\n]s",crucero[cod_crucero].puertos[i]);
			crucero[cod_crucero].puertos[i][15]='\0';
			while(getchar()!='\n');
		}
	}
	else
	{
		printf("De acuerdo\n");
	}
}


void Mostrardatoscrucero(tipo_cruceros crucero, int codigo)
{
	int i, cod_crucero;
	printf("Escriba el codigo del crucero\n");
	scanf("%i",&cod_crucero);
	while(getchar()!='\n');
	while((cod_crucero<1)||(cod_crucero>codigo))
	{
		printf("Codigo inexistente, repita\n");
		scanf("%i",&cod_crucero);
		while(getchar()!='\n');
	}
	printf("Codigo de crucero: %i\n",crucero[cod_crucero-1].codigo_crucero);
	printf("Nombre del cliente: %s\n",crucero[cod_crucero-1].nombre_cliente);
	printf("Telefono: %s\n",crucero[cod_crucero-1].telefono);
	printf("Puerto de salida: %s\n",crucero[cod_crucero-1].puerto_salida);
	printf("Dia de salida: %i\n",crucero[cod_crucero-1].dia_salida);
	printf("Numero de etapas: %i\n",crucero[cod_crucero-1].numero_etapas);
	for(i=0;i<=crucero[cod_crucero-1].numero_etapas;i++)
	{
		printf("El nombre del puerto %i es: %s\n",i+1, crucero[cod_crucero-1].puertos[i]);
	}
	printf("Numero de pasajeros del crucero: %i\n\n",crucero[cod_crucero-1].pasajeros);
}



void Crucerosmes(tipo_cruceros crucero, int codigo)
{
	int i, mes;
	printf("Escriba el mes que quiera\n");
	scanf("%i",&mes);
	while(getchar()!='\n');
	while((mes<1)||(mes>12))
	{
		printf("Mes equivocado, repita\n");
		scanf("%i",&mes);
		while(getchar()!='\n');
	}
	for(i=0;i<codigo;i++)
	{
		if(crucero[i].dia_salida.mes==mes)
		{
			printf("Codigo de crucero\n");
			printf("Nombre del cliente\n");
			printf("Numero de telefono\n");
			printf("Dia de salida\n");
			printf("Puerto de salida\n");
		}
	}
}


void Crucerospuerto(tipo_cruceros crucero, int codigo)
{
	int i, j;
	char puerto[16];
	printf("Escriba el puerto\n");
	scanf("%15[^\n]s",puerto);
	puerto[15]='\0';
	while(getchar()!='\n');
	for(i=0;i<=codigo;i++)
	{
		for(j=0;j<=24;j++)
		{
			if(strcmp(puerto,crucero[i].puertos[j])==0)
			{
				printf("El crucero con codigo %i que salio del puerto %s el dia %i pasa por ese puerto\n",crucero[i].codigo_crucero, crucero[i].puerto_salida, crucero[i].dia_salida);
			}
		}
	}
}
