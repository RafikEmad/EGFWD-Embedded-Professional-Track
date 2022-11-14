#include "server.h"
struct ST_accountsDB_t accounts[255] = { {1000,RUNNING,"aaaabbbbccccdddd0000"},
										 {1000,RUNNING,"aaaabbbbccccdddd0001"},
										 {1000,RUNNING,"aaaabbbbccccdddd0002"},
										 {1000,RUNNING,"aaaabbbbccccdddd0003"},
										 {1000,RUNNING,"aaaabbbbccccdddd0004"},
										 {1000,RUNNING,"aaaabbbbccccdddd0005"},
										 {1000,RUNNING,"aaaabbbbccccdddd0006"},
										 {1000,RUNNING,"aaaabbbbccccdddd0007"},
										 {1000,RUNNING,"aaaabbbbccccdddd0008"},
										 {1000,RUNNING,"aaaabbbbccccdddd0009"},
										 {1000,RUNNING,"aaaabbbbccccdddd0010"},
										 {1000,BLOCKED,"aaaabbbbccccdddd0011"},
										 {1000,BLOCKED,"aaaabbbbccccdddd0012"},
										 {1000,BLOCKED,"aaaabbbbccccdddd0013"},
										 {1000,BLOCKED,"aaaabbbbccccdddd0014"},
										 {1000,BLOCKED,"aaaabbbbccccdddd0015"},
										 {1000,BLOCKED,"aaaabbbbccccdddd0016"},
										 {1000,BLOCKED,"aaaabbbbccccdddd0017"},
										 {1000,BLOCKED,"aaaabbbbccccdddd0018"},
										 {1000,BLOCKED,"aaaabbbbccccdddd0019"},
										 
};
struct ST_transaction_t transactions[255] = { 0 };
//extern  ST_transaction_t myTransData;
int PANINDEX = -1;
uint32_t TransactionSequenceNumber = 0;

EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	if (isValidAccount(&transData->cardHolderData) == ACCOUNT_NOT_FOUND)
	{
		printf("Account Not Found - Fraud Card\n");
		return FRAUD_CARD;
	}
	if (isAmountAvailable(&transData->terminalData) == LOW_BALANCE)
	{
		printf("Amount Not Available - Declined Insuffecient Fund\n");
		return DECLINED_INSUFFECIENT_FUND;
	}
	if (isBlockedAccount(&accounts[PANINDEX]) == BLOCKED_ACCOUNT)
	{
		printf("Blocked Account - Declined Stolen Card\n");
		return DECLINED_STOLEN_CARD;
	}
	if (saveTransaction(transData) == SAVING_FAILED)
	{
		return INTERNAL_SERVER_ERROR;
	}
	return APPROVED;
	
}

EN_serverError_t isValidAccount(ST_cardData_t* cardData)
{
	PANINDEX = -1;
	for (int i = 0; i < 256; i++)
		{
			if (strcmp((cardData->primaryAccountNumber), (accounts[i].primaryAccountNumber)) == 0)
			{
				printf("PAN Found In Database number: %d\n", i);
				PANINDEX = i;
				return OK_SERVER;
			}
			else if ((strcmp((cardData->primaryAccountNumber), (accounts[i].primaryAccountNumber)) != 0) && i == 255)
			{
				printf("PAN NOT Found In Database\n");
				return ACCOUNT_NOT_FOUND;
			}
		}
		return ACCOUNT_NOT_FOUND;
	}

EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence)
{
	if (accountRefrence->state == RUNNING)
	{
		printf("Running Account\n");
		return OK_SERVER;
	}
	else
	{
		printf("Blocked Account\n");
		return BLOCKED_ACCOUNT;
	}
}

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData)
{
	termData->maxTransAmount = accounts[PANINDEX].balance;
	if (termData->transAmount <= termData->maxTransAmount)
	{
		printf("Enough Amount \n");
		return OK_SERVER;
	}
	else
		printf("Low Balance\n");
		return LOW_BALANCE;
}

EN_serverError_t saveTransaction(ST_transaction_t* transData)
{
	if (transData->transState == DECLINED_INSUFFECIENT_FUND)
	{
		printf("Saving Failed Due To Insuffecient Fund\n");
		return SAVING_FAILED;
	}
	else if (transData->transState == DECLINED_STOLEN_CARD)
	{
		printf("Saving Failed Due To Stolen Card\n");
		return SAVING_FAILED;
	}
	else if (transData->transState == INTERNAL_SERVER_ERROR)
	{
		printf("Saving Failed Due To Server Error\n");
		return SAVING_FAILED;
	}
	else if (transData->transState == FRAUD_CARD)
	{
		printf("Declined Due To Non Existed Account\n");
		return FRAUD_CARD;
	}
	else if (getTransaction(TransactionSequenceNumber,transData)==SAVING_FAILED)
	{
		printf("Saving Failed As Max Transaction Reached\n");
		return SAVING_FAILED;
	}
	else
	{
		printf("Transaction Saved\n");
		transactions[TransactionSequenceNumber] = *transData;
		printf("Your New Balance is: %f\n",accounts[PANINDEX].balance);
		listSavedTransactions();
		TransactionSequenceNumber++;
		return OK_SERVER;
	}
}

EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData)
{
	printf("transactionSequenceNumber=%d\n", transactionSequenceNumber);
	if ((transactionSequenceNumber >= 255) || (transactionSequenceNumber < 0))
	{
		return SAVING_FAILED;
	}
	if (transData->transactionSequenceNumber == transactionSequenceNumber)
	{
		transData->terminalData.maxTransAmount = accounts[PANINDEX].balance;
		transData->terminalData.maxTransAmount = transData->terminalData.maxTransAmount - transData->terminalData.transAmount;
		accounts[PANINDEX].balance = transData->terminalData.maxTransAmount;
		return OK_SERVER;
	}
	return SAVING_FAILED;
}

void listSavedTransactions(void)
{
	for (uint32_t i = 0; i <= TransactionSequenceNumber; i++)
	{
		printf("###########################\n");
		printf("Transaction Sequence Number: %d\n", transactions[i].transactionSequenceNumber);
		printf("Transaction Date: %s\n", transactions[i].terminalData.transactionDate);
		printf("Transaction Amount: %f\n", transactions[i].terminalData.transAmount);
		printf("Transaction State: %d\n", transactions[i].transState);
		printf("Terminal Max Amount: %f\n", transactions[i].terminalData.maxTransAmount);
		printf("Cardholder Name: %s\n", transactions[i].cardHolderData.cardHolderName);
		printf("PAN: %s\n", transactions[i].cardHolderData.primaryAccountNumber);
		printf("Card Expiration Date: %s\n", transactions[i].cardHolderData.cardExpirationDate);
		printf("###########################\n");
	}
}