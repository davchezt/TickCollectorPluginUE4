// Made by Intax

#include "TickCollectionSubsystem.h"
#include "TickCollectionInterface.h"

void UTickCollectionWorldSubsystem::Tick(float DeltaTime)
{
	SCOPE_CYCLE_COUNTER(STAT_TickCollectorTotal);
	
	if(bInitialized == false || ObjectCollection.IsValidIndex(0) == false) 
	{
		return;
	}
	
	const int32 Count = GetCollectionCount();
	for(int16 i = 0; i <= Count; ++i)
	{
		UObject* Object = ObjectCollection[i];
		if(IsValid(Object))
		{
			// So as you can see, I'm using CastChecked<>() here, so its better if you ensure you have the interface implemented.
			// The reason we are using CastChecked<>() is, its being converted to static cast in packaged builds. Which is faster than dynamic casting.
			ITickCollectionInterface* Interface = CastChecked<ITickCollectionInterface>(Object);
			if(Interface->bCanCollectionTick == false)
			{
				continue;
			}
			Interface->CollectionTick(DeltaTime);
		}
		else
		{
			ObjectCollection.RemoveAt(i);
		}
	}
}

