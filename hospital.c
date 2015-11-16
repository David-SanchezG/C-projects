#include<stdio.h>

typedef struct{
	int dia;
	int mes;
	int ano;
}tipo_fecha;

typedef struct{
	int hora;
	int minutos;
}tipo_hora;

typedef char cadena[31];
typedef char cadena2[61];

typedef struct{
	int codigo;
	cadena nombre;
	cadena2 apellidos;
	tipo_fecha fecha_recepcion;
	tipo_hora hora;
	char sintomas[361];
	int consulta;
	cadena nombre_doctor;
	cadena2 apellidos_doctor;
	char diagnostico[101];
	tipo_fecha fecha_alta;
	tipo_hora hora_alta;
}tipo_paciente;

typedef tipo_paciente vector_paciente[800];

void Nuevopaciente(vector_paciente pacientes, int *posicionvacia);
void Descripcionpreliminar(vector_paciente pacientes, int posicionvacia);
void Asignarconsultaydoctor(vector_paciente pacientes, int posicionvacia);
void Escribirdiagnostico(vector_paciente pacientes, int posicionvacia);
void Daralta(vector_paciente pacientes, int posicionvacia);
void Listarpacientesingresados(vector_paciente pacientes, int posicionvacia);
void Listarpacientessinconsultaydoctor(vector_paciente pacientes, int posicionvacia);
void Mostrarpacientes(vector_paciente pacientes, int posicionvacia);
void Mostrardatos(vector_paciente pacientes, int posicionvacia);
void Borrarpacientesantesfecha(vector_paciente pacientes, int *posicionvacia);

int main()
{
	int opcion, i, posicionvacia=0;
	vector_paciente pacientes;
	for(i=0;i<=800;i++)
	{
		pacientes[i].codigo=0;
		pacientes[i].consulta=0;
		pacientes[i].hora_alta.hora=0;
	}
	do{
		printf("Elija una opcion del menu\n\n");
		printf("Menu:\n\n"
				"1-Nuevo paciente\n"
				"2-Descripción preliminar de los síntomas\n"
				"3-Asignar a un paciente una consulta y doctor\n"
				"4-Escribir el diagnóstico normalizado.\n"
				"5-Dar el alta al paciente\n"
				"6-Listar todos los pacientes que han ingresado entre dos horas de un mismo día\n"
				"7-Listar todos los pacientes ingresados a los que no se les ha asignado consulta y doctor\n"
				"8-Mostrar todos los pacientes asignados en un día concreto a un doctor concreto\n"
				"9-Mostrar todos los datos de un paciente dado su código o su nombre y apellidos\n"
				"10-Dada una fecha eliminar todos los pacientes anteriores a ella que han sido dados de alta antes\n"
				"11-Salir\n\n");
		scanf("%i",&opcion);
		while(getchar()!='\n');
		while((opcion<1)||(opcion>11))
		{
			printf("Opcion equivocada, repita\n");
			scanf("%i",&opcion);
			while(getchar()!='\n');
		}
		switch(opcion)
		{
			case 1:Nuevopaciente(pacientes, &posicionvacia);
			break;
			case 2:Descripcionpreliminar(pacientes, posicionvacia);
			break;
			case 3:Asignarconsultaydoctor(pacientes, posicionvacia);
			break;
			case 4:Escribirdiagnostico(pacientes, posicionvacia);
			break;
			case 5:Daralta(pacientes, posicionvacia);
			break;
			case 6:Listarpacientesingresados(pacientes, posicionvacia);
			break;
			case 7:Listarpacientessinconsultaydoctor(pacientes, posicionvacia);
			break;
			case 8:Mostrarpacientes(pacientes, posicionvacia);
			break;
			case 9:Mostrardatos(pacientes, posicionvacia);
			break;
			case 10:Borrarpacientesantesfecha(pacientes, &posicionvacia);
			break;
		}
	}while(opcion!=11);
}





void Nuevopaciente(vector_paciente pacientes, int *posicionvacia)
{
	printf("Escriba su nombre\n");
	scanf("%30[^\n]s",pacientes[*posicionvacia].nombre);
	pacientes[*posicionvacia].nombre[30]='\0';
	while(getchar()!='\n');
	printf("Escriba sus apellidos\n");
	scanf("%60[^\n]s",pacientes[*posicionvacia].apellidos);
	pacientes[*posicionvacia].nombre[60]='\0';
	while(getchar()!='\n');
	printf("Escriba el dia de entrada\n");
	scanf("%i",&pacientes[*posicionvacia].fecha_recepcion.dia);
	while(getchar()!='\n');
	printf("Escriba el mes de entrada\n");
	scanf("%i",&pacientes[*posicionvacia].fecha_recepcion.mes);
	while(getchar()!='\n');
	printf("Escriba el año de entrada\n");
	scanf("%i",&pacientes[*posicionvacia].fecha_recepcion.ano);
	while(getchar()!='\n');
	printf("Escriba la hora de entrada\n");
	scanf("%i",&pacientes[*posicionvacia].hora.hora);
	while(getchar()!='\n');
	printf("Escriba los minutos de entrada\n");
	scanf("%i",&pacientes[*posicionvacia].hora.minutos);
	while(getchar()!='\n');
	pacientes[*posicionvacia].codigo=*posicionvacia+1;
	*posicionvacia=*posicionvacia+1;
}




void Descripcionpreliminar(vector_paciente pacientes, int posicionvacia)
{
	int codigo;
	printf("Escriba el codigo del paciente\n");
	scanf("%i",&codigo);
	while(getchar()!='\n');
	while((codigo<1)||(codigo>posicionvacia))
	{
		printf("Codigo erroneo, repita\n");
		scanf("%i",&codigo);
		while(getchar()!='\n');
	}
	printf("Escriba la descripcion preliminar de los sintomas\n");
	scanf("%360[^\n]s",pacientes[codigo-1].sintomas);
	pacientes[codigo-1].sintomas[360]='\0';
	while(getchar()!='\n');
}


void Asignarconsultaydoctor(vector_paciente pacientes, int posicionvacia)
{
	int codigo;
	printf("Escriba el codigo del paciente\n");
	scanf("%i",&codigo);
	while(getchar()!='\n');
	scanf("%i",&codigo);
	while(getchar()!='\n');
	while((codigo<1)||(codigo>posicionvacia))
	{
		printf("Codigo erroneo, repita\n");
		scanf("%i",&codigo);
		while(getchar()!='\n');
	}
	printf("Escriba la consulta que le asigna\n");
	scanf("%i",&pacientes[codigo-1].consulta);
	while(getchar()!='\n');
	while(pacientes[codigo-1].consulta<1)
	{
		printf("Numero de consulta equivocado, repita\n");
		scanf("%i",&pacientes[codigo-1].consulta);
		while(getchar()!='\n');
	}
	printf("Escriba el nombre del doctor\n");
	scanf("%30[^\n]s",pacientes[codigo-1].nombre_doctor);
	pacientes[codigo-1].nombre_doctor[30]='\0';
	while(getchar()!='\n');
	printf("Escriba los apellidos del doctor\n");
	scanf("%60[^\n]s",pacientes[codigo-1].apellidos_doctor);
	pacientes[codigo-1].apellidos_doctor[60]='\0';
	while(getchar()!='\n');
}



void Escribirdiagnostico(vector_paciente pacientes, int posicionvacia)
{
	int codigo;
	printf("Escriba el codigo del paciente\n");
	scanf("%i",&codigo);
	while(getchar()!='\n');
	while((codigo<1)||(codigo>posicionvacia))
	{
		printf("Codigo erroneo, repita\n");
		scanf("%i",&codigo);
		while(getchar()!='\n');
	}
	printf("Escriba el diagnostico\n");
	scanf("%100[^\n]s",pacientes[codigo-1].diagnostico);
	pacientes[codigo-1].sintomas[100]='\0';
	while(getchar()!='\n');
}



void Daralta(vector_paciente pacientes, int posicionvacia)
{
	int codigo, i;
	printf("Escriba el codigo del paciente que desea dar de alta\n");
	scanf("%i",&codigo);
	while(getchar()!='\n');
	while((codigo<1)||(codigo>posicionvacia))
	{
		printf("Codigo erroneo, repita\n");
		scanf("%i",&codigo);
		while(getchar()!='\n');
	}
	printf("Escriba la hora de alta\n");
	scanf("%i",&pacientes[codigo-1].hora_alta.hora);
	while(getchar()!='\n');
	while((pacientes[i].hora_alta.hora<1)||(pacientes[i].hora_alta.hora>24))
	{
		printf("Hora equivocada, repita\n");
		scanf("%i",&pacientes[codigo-1].hora_alta.hora);
		while(getchar()!='\n');
	}
	printf("Escriba los minutos del alta\n");
	scanf("%i",&pacientes[codigo-1].hora_alta.minutos);
	while(getchar()!='\n');
	while((pacientes[i].hora_alta.minutos<1)||(pacientes[i].hora_alta.minutos>59))
	{
		printf("Minutos equivocados, repita\n");
		scanf("%i",&pacientes[codigo-1].hora_alta.minutos);
		while(getchar()!='\n');
	}
	printf("Escriba el dia de alta\n");
	scanf("%i",&pacientes[codigo-1].fecha_alta.dia);
	while(getchar()!='\n');
	while((pacientes[i].fecha_alta.dia<1)||(pacientes[i].fecha_alta.dia>31))
	{
		printf("Dia equivocado, repita\n");
		scanf("%i",&pacientes[codigo-1].fecha_alta.dia);
		while(getchar()!='\n');
	}
	printf("Escriba el mes de alta\n");
	scanf("%i",&pacientes[codigo-1].fecha_alta.mes);
	while(getchar()!='\n');
	while((pacientes[i].fecha_alta.mes<1)||(pacientes[i].fecha_alta.mes>12))
	{
		printf("Mes equivocado, repita\n");
		scanf("%i",&pacientes[codigo-1].fecha_alta.mes);
		while(getchar()!='\n');
	}
	printf("Escriba el año de alta\n");
	scanf("%i",&pacientes[codigo-1].fecha_alta.ano);
	while(getchar()!='\n');
	while(pacientes[i].fecha_alta.ano<1)
	{
		printf("Año equivocado, repita\n");
		scanf("%i",&pacientes[codigo-1].fecha_alta.ano);
		while(getchar()!='\n');
	}
}


void Listarpacientesingresados(vector_paciente pacientes, int posicionvacia)
{
	int hora, hora2, dia, mes, ano, i;
	printf("Escriba el dia\n");
	scanf("%i",&dia);
	while(getchar()!='\n');
	while((dia<1)||(dia>31))
	{
		printf("Dia erroneo, repita\n");
		scanf("%i",&dia);
		while(getchar()!='\n');
	}
	printf("Escriba el mes\n");
	scanf("%i",&mes);
	while(getchar()!='\n');
	while((mes<1)||(dia>12))
	{
		printf("Dia erroneo, repita\n");
		scanf("%i",&mes);
		while(getchar()!='\n');
	}
	printf("Escriba el ano\n");
	scanf("%i",&ano);
	while(getchar()!='\n');
	printf("Escriba la primera hora\n");
	scanf("%i",&hora);
	while(getchar()!='\n');
	printf("Escriba la segunda hora\n");
	scanf("%i",&hora2);
	while(getchar()!='\n');
	for(i=0;i<posicionvacia;i++)
	{
		if((pacientes[i].hora.hora>=hora)&&(pacientes[i].hora.hora<=hora2)
				&&(dia==pacientes[i].fecha_recepcion.dia)&&(mes==pacientes[i].fecha_recepcion.mes)
				&&(ano==pacientes[i].fecha_recepcion.ano))
		{
			printf("El paciente con los siguientes datos:\n"
					"Nombre: %s\n"
					"Apellidos: %s\n"
					"Fecha de entrada: %i-%i-%i a las %i:%i\n"
					"Y con codigo de referencia %i fue ingresado entre esas dos horas\n",
					pacientes[i].nombre,
					pacientes[i].apellidos, pacientes[i].fecha_recepcion.dia,
					pacientes[i].fecha_recepcion.mes,
					pacientes[i].fecha_recepcion.ano, pacientes[i].hora.hora,
					pacientes[i].hora.minutos, pacientes[i].codigo);
		}
	}
}


void Listarpacientessinconsultaydoctor(vector_paciente pacientes, int posicionvacia)
{
	int i;
	for(i=0;i<posicionvacia;i++)
	{
		if(pacientes[i].consulta==0)
		{
			printf("El paciente %s %s no tiene asignado consulta ni doctor\n",pacientes[i].nombre,
					pacientes[i].apellidos);
		}
	}
}



void Mostrarpacientes(vector_paciente pacientes, int posicionvacia)
{
	cadena nombre;
	cadena2 apellidos;
	int i, dia, mes, ano;
	printf("Escriba el nombre del doctor\n");
	scanf("%30[^\n]s",nombre);
	nombre[30]='\0';
	while(getchar()!='\n');
	printf("Escriba los apellidos del doctor\n");
	scanf("%60[^\n]s",apellidos);
	apellidos[60]='\0';
	while(getchar()!='\n');
	printf("Escriba el dia\n");
	scanf("%i",&dia);
	while(getchar()!='\n');
	while((dia<1)||(dia>31))
	{
		printf("Dia erroneo, repita\n");
		scanf("%i",&dia);
		while(getchar()!='\n');
	}
	printf("Escriba el mes\n");
	scanf("%i",&mes);
	while(getchar()!='\n');
	while((mes<1)||(dia>12))
	{
		printf("Dia erroneo, repita\n");
		scanf("%i",&mes);
		while(getchar()!='\n');
	}
	printf("Escriba el ano\n");
	scanf("%i",&ano);
	while(getchar()!='\n');

	for(i=0;i<posicionvacia;i++)
	{
		if((pacientes[i].consulta!=0)&&(strcmp(pacientes[i].nombre_doctor,nombre)==0)
				&&(strcmp(pacientes[i].apellidos_doctor,apellidos)==0)
				&&(dia==pacientes[i].fecha_recepcion.dia)&&(mes==pacientes[i].fecha_recepcion.mes)
				&&(ano==pacientes[i].fecha_recepcion.ano))
		{
			printf("El paciente %s %s tiene asignado el doctor %s %s el dia %i del mes %i del año %i\n",pacientes[i].nombre,
					pacientes[i].apellidos, pacientes[i].nombre_doctor, pacientes[i].apellidos_doctor);
		}
	}
}



void Mostrardatos(vector_paciente pacientes, int posicionvacia)
{
	cadena nombre;
	cadena2 apellidos;
	int i, codigo, opcion;
	printf("¿Que va a escribir?\n"
			"1-Nombre y apellidos\n"
			"2-Codigo\n");
	scanf("%i",&opcion);
	while(getchar()!='\n');
	while((opcion<1)||(opcion>2))
	{
		printf("Opcion equivocada, repita\n");
		scanf("%i",&opcion);
		while(getchar()!='\n');
	}
	if(opcion==1)
	{
		printf("Escriba el nombre del paciente\n");
		scanf("%30[^\n]s",nombre);
		nombre[30]='\0';
		while(getchar()!='\n');
		printf("Escriba los apellidos del paciente\n");
		scanf("%60[^\n]s",apellidos);
		apellidos[60]='\0';
		while(getchar()!='\n');
		for(i=0;((pacientes[i].consulta!=0)&&(i<799));i++)
		{
			if((strcmp(pacientes[i].nombre,nombre)==0)&&(strcmp(pacientes[i].apellidos,apellidos)==0))
			{
				printf("El paciente con los siguientes datos:\n"
						"Nombre: %s\n"
						"Apellidos: %s\n"
						"Fecha de entrada: %i-%i-%i a las %i:%i\n"
						"Codigo de referencia: %i\n"
						"Sintomas: %s\n"
						"Diagnostico: %s\n"
						"Consulta: %i\n"
						"Nombre doctor: %s\n"
						"Apellidos doctor: %s\n",
						pacientes[i].nombre,
						pacientes[i].apellidos,
						pacientes[i].fecha_recepcion.dia,
						pacientes[i].fecha_recepcion.mes,
						pacientes[i].fecha_recepcion.ano,
						pacientes[i].hora.hora,
						pacientes[i].hora.minutos,
						pacientes[i].codigo,
						pacientes[i].sintomas, pacientes[i].diagnostico,
						pacientes[i].consulta,
						pacientes[i].nombre_doctor, pacientes[i].apellidos_doctor);
				i=800;
			}
		}
	}
	if(opcion==2)
	{
		printf("Escriba el codigo\n");
		scanf("%i",&codigo);
		while(getchar()!='\n');
		for(i=0;((pacientes[i].consulta!=0)&&(i<799));i++)
		{
			if(pacientes[i].codigo==codigo)
			{
				printf("El paciente con los siguientes datos:\n"
						"Nombre: %s\n"
						"Apellidos: %s\n"
						"Fecha de entrada: %i-%i-%i a las %i:%i\n"
						"Codigo de referencia: %i\n"
						"Sintomas: %s\n"
						"Diagnostico: %s\n"
						"Consulta: %i\n"
						"Nombre doctor: %s\n"
						"Apellidos doctor: %s\n",
						pacientes[i].nombre,
						pacientes[i].apellidos,
						pacientes[i].fecha_recepcion.dia,
						pacientes[i].fecha_recepcion.mes,
						pacientes[i].fecha_recepcion.ano,
						pacientes[i].hora.hora,
						pacientes[i].hora.minutos,
						pacientes[i].codigo,
						pacientes[i].sintomas, pacientes[i].diagnostico,
						pacientes[i].consulta,
						pacientes[i].nombre_doctor, pacientes[i].apellidos_doctor);
				i=800;
			}
		}
	}
}



void Borrarpacientesantesfecha(vector_paciente pacientes, int *posicionvacia)
{
	int dia, mes, ano, i, j;
	printf("Escriba el dia\n");
	scanf("%i",&dia);
	while(getchar()!='\n');
	while((dia<1)||(dia>31))
	{
		printf("Dia erroneo, repita\n");
		scanf("%i",&dia);
		while(getchar()!='\n');
	}
	printf("Escriba el mes\n");
	scanf("%i",&mes);
	while(getchar()!='\n');
	while((mes<1)||(dia>12))
	{
		printf("Dia erroneo, repita\n");
		scanf("%i",&mes);
		while(getchar()!='\n');
	}
	printf("Escriba el ano\n");
	scanf("%i",&ano);
	while(getchar()!='\n');
	for(i=0;i<*posicionvacia;i++)
	{
		if(pacientes[i].hora_alta.hora!=0)
		{
			for(j=0;j<*posicionvacia;j++)
			{
				pacientes[j]=pacientes[j+1];
			}
			*posicionvacia=*posicionvacia-1;
		}
	}
}

