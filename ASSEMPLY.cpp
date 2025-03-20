// ASSEMPLY.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
#include<stack>
#include <stack>

void Dec_TO_Bin(int n) {

	int binary[32];

	int i = 0;
	while (n > 0) {
		binary[i] = n % 2;
		n = n / 2;
		printf("%d", binary[i]);
		i++;
	}
}


int main()
{

	int multiplicand;
	int  multiplier;
	int result = 0;

	printf("ENTER THE MULTIPLICAND: ");

	scanf("%d", &multiplicand);

	printf("\nENTER THE MULTIPLIER: ");

	scanf("%d", &multiplier);

	while ((multiplicand < 0) || (multiplier < 0)) {

		printf("\nPLEAS INTER THE UNSIGNED NUMBER ONLY!\n");

		printf("ENTER THE MULTIPLICAND: ");

		scanf("%d", &multiplicand);

		printf("\nENTER THE MULTIPLIER: ");

		scanf("%d", &multiplier);


	}





	__asm
	{
		PUSHAD


		MOV EAX, multiplicand; STORDED THE MULIPLICAND IN AX


		MOV EBX, multiplier; STORDED THE MULTIPLIER IN BX

		MOV ECX, 0

		MMULTIPLIER_LOOP :

		TEST EBX, 1
			;
		JZ SKIPE_ADDITION
			;

		MOV ESI, EAX

			SUM :

		MOV EDX, 0

			XOR EAX, ECX; SUMTION WITHOUT A CARRY

			AND ESI, ECX; SUMTION WITH A CARRY

			SHL ESI, 1

			MOV ECX, EAX

			MOV EAX, ESI

			TEST ESI, ESI; TEST THE LAST CARRY

			JNZ SUM

			MOV EAX, ECX

			SKIPE_ADDITION :

		SHL EAX, 1
			SHR EBX, 1
			JNZ MMULTIPLIER_LOOP;

		MOV result, ECX


			POPAD




	}

	printf("\nTHE DECIMAL RESULT IS:%d\n", result);
	printf("************************************\n");

	printf("\nTHE RESULT IN BINERY IS:");
	int binaryR[32], binaryA[32], binaryB[32];

	Dec_TO_Bin(result);
	printf("\n************************************\n");

	printf("\nTHE MULIPLICAND IN BINERY IS:");

	Dec_TO_Bin(multiplicand);

	printf("\n************************************\n");

	printf("\nTHE MULIPLICAND IN BINERY IS:");

	Dec_TO_Bin(multiplier);
	printf("\n************************************\n");
	return 0;


}


