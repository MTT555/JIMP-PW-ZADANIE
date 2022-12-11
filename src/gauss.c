#include "gauss.h"
#include <stdio.h>
#include <math.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    
	// zeruje kolejne kolumny pod przekatna
	// w tej wersji programu uwzgledniam przypadek kiedy na przekatnej moze byc 0
	// wtedy program dokonuje zamiany kolejnosci wierszy
	int kolumny = 0;
	for(kolumny = 0; kolumny < mat->c; kolumny++){
		int kolumnyMAX = kolumny;
		for (int wiersze = kolumny+1; wiersze < mat->r; wiersze++) 
			if(fabs(mat->data[wiersze][kolumny]) > fabs(mat->data[kolumnyMAX][kolumny])) kolumnyMAX = wiersze;
	if (kolumnyMAX != kolumny){
	// zamieniamy kolejnosc wierszy
	double *tymczasowy = mat->data[kolumny];
	mat->data[kolumny] = mat->data[kolumnyMAX];
	mat->data[kolumnyMAX] = tymczasowy;
	double *bTymczasowy = b->data[kolumny];
	b->data[kolumny] = b->data[kolumnyMAX];
	b->data[kolumnyMAX] = bTymczasowy;

	}
	}
	printf("Stan po zamianie kolejnosci wierszy: \n");
		printToScreen(mat);
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

