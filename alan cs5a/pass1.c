
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void display()
{

	char str;
	FILE *fp1, *fp2, *fp3;

	printf("\nThe contents of Input Table :\n\n");
	fp1 = fopen("Input.txt", "r");
	str = fgetc(fp1);
	while (str != EOF)
	{
		printf("%c", str);
		str = fgetc(fp1);
	}
	fclose(fp1);

	printf("\n\nThe contents of Intermediate Table :\n\n");
	fp2 = fopen("Intermediate.txt", "r");
	str = fgetc(fp2);
	while (str != EOF)
	{
		printf("%c", str);
		str = fgetc(fp2);
	}
	fclose(fp2);

	printf("\n\nThe contents of Symbol Table :\n\n");
	fp3 = fopen("Symtab.txt", "r");
	str = fgetc(fp3);
	while (str != EOF)
	{
		printf("%c", str);
		str = fgetc(fp3);
	}
	fclose(fp3);
}

void main()
{
	FILE *f1, *f2, *f3, *f4;
	int locctr, start, length;
	char label[10], opcode[10], operand[10], mneumonic[10], code[10];
	f1 = fopen("Input.txt", "r");
	f3 = fopen("Symtab.txt", "w");
	f4 = fopen("Intermediate.txt", "w");

	fscanf(f1, "%s\t%s\t%s", label, opcode, operand);
	if (strcmp(opcode, "START") == 0)
	{
		start = atoi(operand);
		locctr = start;
		fprintf(f4, "----\t%s\t%s\t%s\n", label, opcode, operand);
		fscanf(f1, "%s\t%s\t%s", label, opcode, operand);
	}
	else
		locctr = 0;

	while (strcmp(opcode, "END") != 0)
	{
		fprintf(f4, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
		if (strcmp(label, "----") != 0)
		{
			fprintf(f3, "%s\t%d\n", label, locctr);
		}

		f2 = fopen("Optab.txt", "r");
		fscanf(f2, "%s\t%s", code, mneumonic);

		while (strcmp(code, "END") != 0)
		{
			if (strcmp(code, opcode) == 0)
			{
				locctr += 3;
				break;
			}
			fscanf(f2, "%s\t%s", code, mneumonic);
		}

		if (strcmp(opcode, "WORD") == 0)
			locctr += 3;

		else if (strcmp(opcode, "RESW") == 0)
			locctr = locctr + 3 * atoi(operand);

		else if (strcmp(opcode, "RESB") == 0)
			locctr += atoi(operand);

		else if (strcmp(opcode, "BYTE") == 0)
		{
			locctr = locctr + strlen(operand) - 2;
		}

		fscanf(f1, "%s\t%s\t%s", label, opcode, operand);
	}

	fprintf(f4, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
	length = locctr - start;
	printf("Size of program = %d\n", length);

	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);

	display();
}

// Size of program = 25
// The contents of Input Table:
// copy START 1000
// ---- LDA ALPHA
// ---- ADD ONE
// ---- SUB TWO
// ---- STA BETA
// ALPHA BYTE C'KLNCE
// ONE RESB 2
// TWO WORD 5
// BETA RESW 1
// ---- END ----
// The contents of Intermediate Table:
// ---- copy START 1000
// 1000 ---- LDA ALPHA
// 1003 ---- ADD ONE
// 1006 ---- SUB TWO
// 1009 ---- STA BETA
// 1012 ALPHA BYTE C'KLNCE
// 1017 ONE RESB 2
// 1019 TWO WORD 5
// 1022 BETA RESW 1
// 1025 ---- END ----
// The contents of Symbol Table:
// ALPHA 1012
// ONE 1017
// TWO 1019
// BETA 1022
