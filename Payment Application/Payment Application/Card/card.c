#include "card.h"

EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	printf("Enter Cardholder's Name: ");
	gets(cardData->cardHolderName);
	size_t x= 0;
	x= strlen(cardData->cardHolderName);
	if (x == 0 || x < 20 || x>24)
	{
		return WRONG_NAME;
	}
	else
	{
		printf("Accepted Format\n");
		return OK_CARD;
	}
}
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	printf("Enter Card Expiry Date 'MM/YY': ");
	gets(cardData->cardExpirationDate);
	size_t y = 0;
	y = strlen(cardData->cardExpirationDate);
	if (y==5 && cardData->cardExpirationDate[2]=='/')
	{
		if (isdigit(cardData->cardExpirationDate[0]) &&
			isdigit(cardData->cardExpirationDate[1]) &&
			isdigit(cardData->cardExpirationDate[3]) &&
			isdigit(cardData->cardExpirationDate[4]))
		{
			if (cardData->cardExpirationDate[0] > '1' )
			{
				return WRONG_EXP_DATE;
			}
			else if (cardData->cardExpirationDate[0] == '1' && cardData->cardExpirationDate[1] > '2')
			{
				return WRONG_EXP_DATE;
			}
			return OK_CARD;
		}
		return WRONG_EXP_DATE;
	}
	else 
		return WRONG_EXP_DATE;
}
EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	int count = 0;
	printf("Enter Card Primary Account Number: ");
	gets(cardData->primaryAccountNumber);
	size_t z = 0;
	z = strlen(cardData->primaryAccountNumber);
	if (z != 20)
	{
		printf("Wrong Pan\n");
		return WRONG_PAN;
	}
	for (int i = 0; i < 20; i++)
	{
		if (isdigit(cardData->primaryAccountNumber[i]))
			count++;
	}
	if (count < 1 || count > 4)
	{
		printf("Wrong Pan\n");
		return WRONG_PAN;
	}
	return OK_CARD;
}

