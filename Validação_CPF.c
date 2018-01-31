#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define TAM 11

void Preencher(char *cpf) {
	int i;
	printf("Informe o CPF:");
	//Preencher CPF
	for (i = 0; i < TAM; i++) {
		cpf[i] = getche();
		fflush(stdin);
		if (cpf[i] == 13) {//Ira parar se apertar enter
			break;
		}
		//Colocando '.' e '-'
		if (i == 2 || i == 5) {
			printf(".");

		}
		if (i == 8) {
			printf("-");
		}
	}
	cpf[i] = '\0';

}

int Validar_Digitacao(char *cpf) {
	int i, validacao = 1;
	char letra;
	//Verificar se só tem numeros
	for (i = 0; i < TAM; i++) {
		letra = cpf[i];
		if (isdigit(letra) == 0) {
			validacao = 0;
			break;
		}
	}
	//Se o CPF tem menos digitos que 11
	if (i < TAM) {
		validacao = 0;
	}
	return validacao;
}

int Primeiro_Dig_Verificador(char *cpf) {
	int i, x = 0, colunas[10], somatorio = 0, resto, quociente, primeiro_Digito;
	char dig;

	//Multiplicando colunas
	for (i = 0; i < 9; i++) {
		somatorio += (cpf[i] - '0') * (10 - i);
	}

	//Somando colunas
	resto = somatorio % 11;

	//Descobrindo primeiro dijito
	if (resto < 2) {
		primeiro_Digito = 0;
	}
	else {
		primeiro_Digito = 11 - resto;
	} 
	//Comparado dijito
	if (primeiro_Digito == (cpf[9] - '0')) {
		return 1;
	}
	else {
		return 0;
	}
}

int Segundo_Dig_Verificador(char *cpf) {
	int i, x = 0, colunas[11], somatorio = 0, resto, quociente, segundo_Digito;
	char dig;
	//Multiplicando colunas
	for (i = 0; i < 10; i++) {
		somatorio += (cpf[i] - '0') * (11 - i);
	}
	//Somando colunas
	resto = somatorio % 11;
	//Descobrindo segundo dijito
	if (resto < 2) {
		segundo_Digito = 0;
	}
	else {
		segundo_Digito = 11 - resto;
	}
	//Comparado dijito
	if (segundo_Digito == (cpf[10] - '0')) {
		return 1;
	}
	else {
		return 0;
	}

}

int Verificar_Dig_Verificador(char *cpf) {
	if (Primeiro_Dig_Verificador(cpf) == 0) {
		return 0;
	}
	else if (Segundo_Dig_Verificador(cpf) == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	char cpf[(TAM + 1)], letra, resposta;
	printf("\tVerificar CPFs\n\n");
	//Preenchendo CPFs
	Preencher(cpf);
	//Validando digitacao
	if (Validar_Digitacao(cpf) == 0) {
		printf("O CPF: %s eh invalido\n", cpf);
	}


	//Validado digito verificador
	if (Verificar_Dig_Verificador(cpf)) {
		printf("O CPF: %s eh valido\n", cpf);
	}
	else {
		printf("O CPF: %s eh invalido\n", cpf);
	}
	do {
		//Preenchendo outros CPFs
		do {
			printf("Deseja testar outro CPF? (s/n)\n");
			resposta = toupper(getchar());
		} while (resposta != 'S' && resposta != 'N');
		Preencher(cpf);
		//Validando digitacao
		if (Validar_Digitacao(cpf) == 0) {
			printf("O CPF: %s eh invalido\n", cpf);
		}
		//Validado digito verificador
		if (Verificar_Dig_Verificador(cpf)) {
			printf("O CPF: %s eh valido\n", cpf);
		}
		else {
			printf("O CPF: %s eh invalido\n", cpf);
		}
	} while (resposta == 'S');
	return 0;
}
