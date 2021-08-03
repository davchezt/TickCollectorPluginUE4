// Made by Intax

#include "TickCollectionSubsystem.h"
#include "TickCollectionInterface.h"

void UTickCollectionWorldSubsystem::Tick(float DeltaTime)
{
	SCOPE_CYCLE_COUNTER(STAT_TickCollectorTotal);
	if(bInitialized == false) return;
		
	const int32 Count = GetCollectionCount();
	for(int16 i = 0; i <= Count; ++i)
	{
		if(ObjectCollection.IsValidIndex(i))
		{
			UObject* Object = ObjectCollection[i];
			if(IsValid(Object))
			{
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
}
