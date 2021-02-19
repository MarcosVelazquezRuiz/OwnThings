#include <stdio.h>

void imprimeRomanos(int numero);
void Roman(int tipo, char Anterior, char Actual, char Siguiente);

void main() {
	
	int romano; // 0-3999

	printf_s("Introduce un n%cmero [0-3999]\n",163);
	scanf_s("%d", &romano);
	printf_s("El n%cmero %d en n%cmeros romanos es: ",163, romano,163);
	imprimeRomanos(romano);
}
void imprimeRomanos(int numero) {
	int i;
	int mil = numero / 1000;
	int cen = (numero - mil * 1000) / 100;
	int dec = (numero - mil * 1000 - cen * 100) / 10;
	int unid = (numero - mil * 1000 - cen * 100 - dec * 10);

	for (i = 0; i < mil; i++)
		printf_s("M");

	Roman(cen, 'M', 'D','C');
	Roman(dec, 'C', 'L','X');
	Roman(unid, 'X', 'V','I');
}
void Roman(int tipo, char Anterior, char Actual,char Siguiente) {

	int i;

	if (tipo >= 5 && tipo < 9) {
		printf("%c", Actual);
		if (tipo > 5) {
			for (i = 0; i < tipo - 5; i++) {
				printf("%c", Siguiente);
			}
		}
	}
	if ((tipo < 5 || tipo == 9) && (tipo != 0)) {
		printf("%c", Siguiente);
		if (tipo == 9) printf("%c", Anterior);
		if (tipo == 4) printf("%c", Actual);
		if (tipo < 4) {
			for (i = 0; i <tipo-1; i++) {
				printf("%c", Siguiente);
			}
		}
	}
}