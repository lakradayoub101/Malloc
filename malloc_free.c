#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	double **Array2D = NULL;
	double x, y;
	int i, j;

	printf("Taille de la matrice (format : <rows> <columns>) ? ");
	scanf("%1lf %1lf", &x, &y);

	//Création
	Array2D = malloc(x * sizeof(double*));

	if(Array2D == NULL)
		exit(1);

	for(i = 0 ; i < x ; i++)
	{
		Array2D[i] = malloc(y * sizeof(double));

		if(Array2D[i] == NULL)
			exit(1);
	}

	//Remplissage
	for(i = 0 ; i < x ; i++)
		for(j = 0 ; j < y ; j++)
		{
			printf("Valeur pour [%d][%d] ? ", i, j);
			scanf("%2lf", &Array2D[i][j]);
		}

	//Affichage
	for(i = 0 ; i < x ; i++)
		for(j = 0 ; j < y ; j++)
			printf("[%d][%d] = %f\n", i, j, Array2D[i][j]);
				printf("Adresses des allocations : %p\n", Array2D);

	//Destruction
	for(i = 0 ; i < x ; i++)
	{
		free(Array2D[i]);
		Array2D[i] = NULL;
	}
	free(Array2D);
	Array2D = NULL;

	return 0;
}
