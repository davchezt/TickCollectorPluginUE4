// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TickCollectionInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UTickCollectionInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TICKCOLLECTIONPLUGIN_API ITickCollectionInterface
{
	GENERATED_BODY()

public:

	bool bCanCollectionTick = true;

	virtual void CollectionTick(float DeltaTime) {}
	
};
