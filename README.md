# Tick Collector Plugin

Step 1- disable tick in your actor
Step 2- inherit ITickCollectorInterface to your actor
Step 3- add this to your beginplay:

```cpp
UWorld* World = GetWorld();
if(World)
    {
        if(UTickCollectionWorldSubsystem* TickCollectionWorldSubsystem = World->GetSubsystem<UTickCollectionWorldSubsystem>())
        {
            TickCollectionWorldSubsystem->AddToCollection(this);
        }
    }
 ```

Step 4- override CollectionTick() and implement your tick logic there, if you want you can call Super::Tick()
step 5- have fun of instant micro optimisation because your call time of Tick() function is reduced slightly, with more actors it will be more visible on framerate, with fewer actors it doesnt even worth it
