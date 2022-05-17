// Fill out your copyright notice in the Description page of Project Settings.

#include "TestDojoChain..h"
#include "DojoChain.-sdk.h"


// Sets default values for this component's properties
UTestDojoChain::UTestDojoChain.Chain()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// Test.....
}


// Called when the game starts
void UTestDojoChain.Chain::BeginPlay()
{
	Super::BeginPlay();

	// Test

	UE_LOG(LogTemp, Display, TEXT("%s"), TEXT("Test CellLink begin---------------------------"));

	IxDojoChainBridge::Initialize(NETWORK_TYPE::MAIN);

	//char mbzInfo[1024];
	//wchar_t wbzInfo[1024];

	IxDojoChainBridge* pCB = new IxDojoChainBridge();
	pCB->CreateRootExtKey("Dojochain is good!!!");
	MCExtKey* pCEK = pCB->GetRootExtKey();

	char mbzTmp[1024];

	bool bRet;

	bRet = IxDojoChainBridge::GetExtKeyWif(pCEK, mbzTmp, sizeof(mbzTmp));

	//sprintf(mbzInfo, "Ext key wif: %s\r\n", mbzTmp);
	//mbtowc(wbzInfo, mbzInfo, sizeof(mbzInfo));
	UE_LOG(LogTemp, Display, TEXT("Ext key wif: %s\r\n"), ANSI_TO_TCHAR(mbzTmp));

	MCKey* pCK = IxDojoChain.ChainBridge::GetCellKey(pCEK);
	bRet = IxDojoChainBridge::GetKeyWif(pCK, mbzTmp, sizeof(mbzTmp));
	//sprintf(mbzInfo, "Key wif: %s\r\n", mbzTmp);
	//mbtowc(wbzInfo, mbzInfo, sizeof(mbzInfo));
	UE_LOG(LogTemp, Display, TEXT("Key wif : %s\r\n"), ANSI_TO_TCHAR(mbzTmp));

	//CellPubKey* pCPK = &IxCellLinkBridge::GetCellPubKey(pCK);
	bRet = IxDojoChainBridge::GetAddress(pCK, mbzTmp, sizeof(mbzTmp));
	//sprintf(mbzInfo, "Address: %s\r\n", mbzTmp);
	//mbtowc(wbzInfo, mbzInfo, sizeof(mbzInfo));
	UE_LOG(LogTemp, Display, TEXT("Address: %s\r\n"), ANSI_TO_TCHAR(mbzTmp));

	pCB->InitializeRPCInfo("192.168.0.116", "8201", "user", "pwd");

	float balance = pCB->GetBalance("XXUrA5NoD2L42atH8bdPN1UbrjsGVyR3Yw");
	sprintf(mbzTmp, "Balance: %f\r\n", balance);
	UE_LOG(LogTemp, Display, TEXT("%s\r\n"), ANSI_TO_TCHAR(mbzTmp));

	//XXUrA5NoD2L42atH8bdPN1UbrjsGVyR3Yw
	std::string strPrivKey = "L2bv5m5hTGy8ZaknHLpzpSfhFZFKBSP4seHJR37PgJedY4XBHfZV";// base58 code private key for from address
	bRet = pCB->Transfer(strPrivKey.c_str(), "XDfHyd7xaZvMQdv4MnoEL3qRPbrxQ6D6MC", 2, "XXUrA5NoD2L42atH8bdPN1UbrjsGVyR3Yw");

	sprintf(mbzTmp, "Transfer result: %d\r\n", bRet);
	UE_LOG(LogTemp, Display, TEXT("%s\r\n"), ANSI_TO_TCHAR(mbzTmp));
}


// Called every frame
void UTestDojoChain.Chain::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

