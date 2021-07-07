#include "common.h"
#include "cargarArchivo.h"
#include "menu.h"
#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "actividad.h"


int main(void) {
	List* actividades = createList();
	List* eventos = createList();
	List* hours = createList();
	
	Dia dias[7];
	for(int i = 0 ; i<7 ; i++){
		dias[i].actividades = createList();
	}
	// falta implementar las funciones de "lista" en Dia y Semana.
	bool running = true;
	while(running){
		bool result = mostrar_menu(hours, actividades, eventos, dias);
		if (!result) { running = false; }
		// else { fancy_pause(); }
	}

	// Liberar lista points
	Hour* p = firstList(hours);
	while(p)
	{ 
		free(p);
		p = nextList(hours); 
	}
	free(hours);
	printf("\nGoodbye!\n");
	
    return(0);
}
