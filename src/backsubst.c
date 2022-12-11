#include "backsubst.h"
#include <stdio.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
				
	for(int wiersze = (mat->r)-1; wiersze >=0; wiersze--){
		
			double s = 0;
		for (int kolumny = wiersze+1; kolumny < mat->c; kolumny++) s+= mat->data[wiersze][kolumny] * x->data[kolumny][0];
		if(mat->data[wiersze][wiersze] == 0) return 1; // 0 na diagonali
		x->data[wiersze][0] = (b->data[wiersze][0] - s) / mat->data[wiersze][wiersze];

	}
	
	/* To ponizej jest przepisaniem b do x. Nalezy to poprawic! */


				int i;

					printf("Wypisuje wyniki:\n");
				for (i =0; i < x->r; i++) {
				printf("x%d:%g\n",i, x->data[i][0]);	
					//x->data[i][0] = b->data[i][0];
				}

				return 0;
}


