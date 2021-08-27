# Tick Collector Plugin

A dead simple tick collector plugin for UE4. As it is just made for simple usage it doesnt have blueprint support yet. Nothing special about this repo. The main purpose here is to demonstrate the idea of tick collection.

<h2>Usage:</h2>

- Disable tick in your actor

```cpp
PrimaryActorTick.bCanEverTick = false; // go to hell with your bloated tick FTickableGameObject..
```

- Inherit ITickCollectorInterface to your actor

```cpp
class YOURPOJECT_API AMyAwesomeClass : public AActor, public ITickCollectorInterface
```

- Add this to your beginplay: (note: you can directly call AddObjectToCollection() too, which is declared in interface)

```cpp

if(UWorld* World = GetWorld())
    {
        if(UTickCollectionWorldSubsystem* TickCollectionWorldSubsystem = World->GetSubsystem<UTickCollectionWorldSubsystem>())
        {
            TickCollectionWorldSubsystem->AddToCollection(this);
        }
    }
 ```

- Override CollectionTick() and implement your tick logic there, if you want you can call Super::Tick()

```cpp
// .h
virtual void CollectionTick(float DeltaTime) override;

// .cpp
void AMyAwesomeClass::CollectionTick(float DeltaTime)
{
    Super::Tick(DeltaTime); // if you need it. you dont always need to call it.
    
    // your awesome logic here.
}
 ```
 
- When you need to stop ticking, set `bCanCollectionTick` to false. Its declared in `ITickCollectionInterface` so it is a global variable, you can use it on your ctor either.

- If your class destroyed or somehow went invalid in the world in the tick loop subsystem already checks if its `IsValid()` or not, so it will be automatically removed from collection array in similar cases. 

- Finally, have fun of instant micro optimisation because your call time of Tick() function is reduced slightly, with more actors it will be more visible on framerate, **with fewer actors it doesnt even worth the effort to implement**. What this plugin does is adds your class to an array and loops them on *single* tick. That way your *call time* of Tick() function reduces. 
