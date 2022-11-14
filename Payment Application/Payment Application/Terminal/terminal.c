#include "terminal.h"

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	//dd/mm/yy
	termData->transactionDate[2] = '/';
	termData->transactionDate[5] = '/';
	time_t date = time(NULL);
	struct tm* gm_date = localtime(&date);
	if (gm_date->tm_mday > 9)
	{
		//tm_mday=23
		termData->transactionDate[0] = gm_date->tm_mday / 10 + '0';
		termData->transactionDate[1] = gm_date->tm_mday % 10 + '0';
	}
	else
	{
		//tm_mday=9->09
		termData->transactionDate[0] = '0';
		termData->transactionDate[1] = gm_date->tm_mday + '0';
	}
	if (gm_date->tm_mon + 1 > 9)
	{
		termData->transactionDate[3] = (gm_date->tm_mon + 1) / 10 + '0';
		termData->transactionDate[4] = (gm_date->tm_mon + 1) % 10 + '0';
	}
	else
	{
		termData->transactionDate[3] = 0 + '0';
		termData->transactionDate[4] = (gm_date->tm_mon + 1) + '0';
	}
	termData->transactionDate[6] = ((gm_date->tm_year + 1900) / 1000) + '0';
	termData->transactionDate[7] = (((gm_date->tm_year + 1900) - 2000) / 100) + '0';
	termData->transactionDate[8] = (((gm_date->tm_year + 1900) - 2000) / 10) + '0';
	termData->transactionDate[9] = ((gm_date->tm_year + 1900) % 10) + '0';
	return OK_TERMINAL;
}

EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{	//Exp. date = MM/YY - Today's date DD/MM/YY 
	if (cardData.cardExpirationDate[3] > termData.transactionDate[8])
		return OK_TERMINAL;
	else if ((cardData.cardExpirationDate[3] == termData.transactionDate[8]) && (cardData.cardExpirationDate[4] > termData.transactionDate[9]))
		return OK_TERMINAL;
	else if ((cardData.cardExpirationDate[4] == termData.transactionDate[9]) && (cardData.cardExpirationDate[0] > termData.transactionDate[3]))
		return OK_TERMINAL;
	else if ((cardData.cardExpirationDate[0] == termData.transactionDate[3]) && (cardData.cardExpirationDate[1] > termData.transactionDate[4]))
		return OK_TERMINAL;
	else
		return EXPIRED_CARD;
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	printf("Enter Transaction Amount:");
	scanf_s("%f", &termData->transAmount);
	if (termData->transAmount <= 0)
	{
		printf("Invalid Amount \n");
		return INVALID_AMOUNT;
	}
	else
		return OK_TERMINAL;
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	if (termData->transAmount > termData->maxTransAmount)
	{
		printf("Entered Amount Exceed Max Amount \n");
		return EXCEED_MAX_AMOUNT;
	}
	else
		return OK_TERMINAL;
}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)
{
	printf("Enter Max Amount: ");
	scanf_s("%f", &termData->maxTransAmount);
	if (termData->maxTransAmount <= 0)
	{
		printf("Invalid Max Amount \n");
		return INVALID_MAX_AMOUNT;
	}
	else
		return OK_TERMINAL;
}