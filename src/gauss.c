#include "gauss.h"
#include <stdio.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    
	// zeruje kolejne kolumny pod przekatna
	// nie uwzgledniam na razie przypadku gdy w przekatnej bedzie 0
	// to bedzie uwzglednione w innej wersji programu
	for(int kolumny = 0; kolumny < mat->c; kolumny++){
		
		for(int wiersze = kolumny+1; wiersze < mat->r; wiersze++){
			if(mat->data[kolumny][kolumny] == 0) return 1; // macierz osobliwa
			double mnoznik = mat->data[wiersze][kolumny]/mat->data[kolumny][kolumny];
			// zerujemy kolumne ponizej przekatnej
			for(int i = kolumny; i < mat->c; i++)
			{
				mat->data[wiersze][i] -= mnoznik * mat->data[kolumny][i];
			}
			b->data[wiersze][0] -= mnoznik * b->data[kolumny][0];
		}
	}
		printf("Stan po schodkowaniu: \n");
		printToScreen(mat);
		return 0;
}

