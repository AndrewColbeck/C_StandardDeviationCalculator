#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



int main(){
	srand(time(NULL));
	int i;
	int data_set_size;
	float m[30]={0};
	float deviation_of_m[30]={0};
	float difference_of_m[30]={0};
	float difference_mean=0;
	float standard_deviation=0;
	float sum=0;
	float mean=0;
	printf("\n\n");
	printf("-------------------------------------\n");
	printf("*** STANDARD DEVIATION CALCULATOR ***\n");
 	printf("-------------------------------------\n"); 
	do{
		printf("\nHow many numbers are in the set? (Enter between 1 - 30 only):\n");
		scanf("%d", &data_set_size);
		if ( data_set_size > 0 && data_set_size < 30 )
			break;
		else
			printf("Invalid response.  Please choose a number between 1 - 30.\n");
	}while(1);

	printf("Please enter values:\n");
	printf("(to enter the next value, start a new line with Enter key):\n");

	for ( i = 0; i<data_set_size; i++)
		scanf("%f", &m[i]);

	// CALCULATE THE SUM:
	for (i = 0; i < data_set_size; i++)
		sum += m[i];
	printf("---------------------------\n");
	printf("** SUM OF ALL VALUES IS: **\n");
	printf("---------------------------\n");	
	printf("%.2f\n\n", sum);

	// CALCULATE THE MEAN:
	mean = sum / (data_set_size);
	printf("---------------------------\n");
	printf("**      THE MEAN IS:     **\n");
	printf("---------------------------\n");	
	printf("%.2f\n\n", mean);

	// CALCULATE THE DEVIATION:
	// NOTE: To calculate the deviation about the mean,
	// Take the element, and subtract the mean (average).
	printf("---------------------------\n");
	printf("** DEVIATION PER VALUE:  **\n");
	printf("---------------------------\n");
	printf("| VALUE:| DEVIATION:\t |\n");

	for (i=0; i<data_set_size; i++){
		// Store each element's Deviation in an Array:
		deviation_of_m[i] = m[i]-mean;

		// Accounts for minus symbol (aligns figures correctly):
		if (deviation_of_m[i] < 0)
			printf("| %.2f\t|   %.2f\t |\n", m[i], deviation_of_m[i]);
		else
			printf("| %.2f\t|    %.2f\t |\n", m[i], deviation_of_m[i]);
	}

	// CALCULATE TE STANDARD DEVIATION:
	sum=0;

	for (i = 0; i < data_set_size; i++){
		// 1. Subtract the mean from each element, and square the result.
		difference_of_m[i] = (m[i]-mean) * (m[i]-mean);
		sum += difference_of_m[i];
	}

	// 2. Work out the mean of the result
	difference_mean = sum / data_set_size;

	// 3. The Square Root of this mean is the Standard Deviation.
	standard_deviation = sqrt(difference_mean);
	printf("\n---------------------------\n");
	printf("**  STANDARD DEVIATION:  **\n");
	printf("---------------------------\n");
	printf("%0.2f\n\n", standard_deviation);

	return 0;
	
}
