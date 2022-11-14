#include "app.h"

void appStart(void)
{
    ST_cardData_t myCardData = {"Name","PAN","05/28"};
    ST_terminalData_t myTermData = {0,0,"19/05/2005"};
    EN_transState_t myTransState = 0;
    uint32_t mytransactionSequenceNumber=0;
    ST_transaction_t myTransData = {myCardData,myTermData,myTransState,mytransactionSequenceNumber};

    while (1)
    {
        myTransData.transState = 0;
        //getting Card Holder Name
        if (getCardHolderName(&myCardData) != OK_CARD)
        {
            printf("ERROR: Wrong Name Format\n");
            myTransData.transState = DECLINED_STOLEN_CARD;
            continue;
        }
        //getting Card Expiration Date
        if (getCardExpiryDate(&myCardData) != OK_CARD)
        {
            printf("ERROR: Wrong Expiration Date Format\n");
            myTransData.transState = DECLINED_STOLEN_CARD;
            continue;
        }
        //getting Card PAN & checking Card Validity
        if (getCardPAN(&myCardData) != OK_TERMINAL)
        {
            myTransData.transState = DECLINED_STOLEN_CARD;
            continue;
        }
        strcpy_s(myTransData.cardHolderData.cardHolderName, 25,myCardData.cardHolderName);
        strcpy_s(myTransData.cardHolderData.cardExpirationDate, 6, myCardData.cardExpirationDate);
        strcpy_s(myTransData.cardHolderData.primaryAccountNumber, 21,myCardData.primaryAccountNumber);
                
        //getting and printing Transaction Date
        getTransactionDate(&myTermData);
        printf("Today is %s\n", myTermData.transactionDate);
        strcpy_s(myTransData.terminalData.transactionDate,11,myTermData.transactionDate);
        if (isCardExpired(myCardData, myTermData) != OK_TERMINAL)
        {
            printf("Your Card Is Expired\n");
            continue;
        }
        //getting Transaction Amount
        if (getTransactionAmount(&myTermData) != OK_TERMINAL)
        {
            char y = 'a';
            getchar(y);
            continue;
        }
        myTransData.terminalData.transAmount = myTermData.transAmount;
        
        if (setMaxAmount(&myTermData) != OK_TERMINAL)
        {
            char y = 'a';
            getchar(y);
            continue;
        }

        myTransData.terminalData.maxTransAmount = myTermData.maxTransAmount;
       
        if (isBelowMaxAmount(&myTermData) != OK_TERMINAL)
        {
            char y = 'a';
            getchar(y);
            myTransData.transState = DECLINED_STOLEN_CARD;
            continue;
        }
        //receiving data and checking Account Validity
      
        if (recieveTransactionData(&myTransData) != APPROVED)
        {
            char y = 'a';
            getchar(y);
            continue;
        }
        myTransData.transactionSequenceNumber++;
        char y = 'a';
        getchar(y);
        
    }
}
int main()
{
    appStart();
    return 0;
}
