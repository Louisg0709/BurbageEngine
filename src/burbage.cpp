#include "include/burbage.h"
#include <type_traits>

/*
* App Class Definitions
*/

template<class EType>
void App::CreateEntity()
{
	if (std::is_base_of<Entity, EType>::value) {
		COMPONENT_ID_DATA_TYPE MinID = FindMinAvailabeID();
		if (MinID) {
			EntityArr.push_back(EType(MinID));
		}
		else {
			//Send warning to the apps log
		}
	}
	else {
		//Send warning to apps log
	}
}

template<class EType>
std::vector<EType*> App::GetEntitiesFromType()
{
	std::vector<EType*> List;
	if (std::is_base_of<Entity, EType>::value) {
		for (ENTITY_ID_DATA_TYPE i = 0; i <= EntityArr.size(); i++) {
			EType* CurrentObj = static_cast<EType*>(&EntityArr[i]);
			if (CurrentObj) {
				List.push_back(CurrentObj);
			}
		}
		return List;
	}
	else {
		//Send warning to the apps log
	}
	return false;
}

void App::Tick(float DeltaTime)
{
	for (ENTITY_ID_DATA_TYPE i = 0; i <= EntityArr.size(); i++) {
		EntityArr[i].Tick(DeltaTime);
	}
}

void App::Reset()
{
	for (ENTITY_ID_DATA_TYPE i = 0; i <= EntityArr.size(); i++) {
		EntityArr[i].Reset();
	}
}

void App::RemoveEntity(ENTITY_ID_DATA_TYPE ID)
{
	ENTITY_ID_DATA_TYPE index = GetIndexFromId(ID);
	EntityArr.erase(EntityArr.begin() + index);
}

Entity* App::GetEntityFromID(ENTITY_ID_DATA_TYPE ID)
{
	for (ENTITY_ID_DATA_TYPE i = 0; i < EntityArr.size(); i++) {
		if (EntityArr[i].GetID() == ID) {
			return &EntityArr[i];
		}
	}
	return nullptr;
}

ENTITY_ID_DATA_TYPE App::GetIndexFromId(ENTITY_ID_DATA_TYPE ID)
{
	for (ENTITY_ID_DATA_TYPE i = 0; i < EntityArr.size(); i++) {
		if (EntityArr[i].GetID() == ID) {
			return i;
		}
	}
	return EntityArr.size() + 1;//returns out of bounds so that caller can tell id doesnt exist.
}

ENTITY_ID_DATA_TYPE App::FindMinAvailabeID()
{
	for (ENTITY_ID_DATA_TYPE i = 1; i < ENTITY_ID_MAX; i++) {
		if (GetEntityFromID(i) == nullptr) {
			return i;
		}
	}
	return false;
}

/*
* Entity Class Definitions
*/
Entity::Entity(ENTITY_ID_DATA_TYPE id, App* owner)
{
	EntityID = id;
	Owner = owner;
}

void Entity::Tick(float DeltaTime)
{
	for (COMPONENT_ID_DATA_TYPE i = 0; i <= ComponentArr.size(); i++) {
		ComponentArr[i].Tick(DeltaTime);
	}
}

void Entity::Reset()
{
	for (COMPONENT_ID_DATA_TYPE i = 0; i <= ComponentArr.size(); i++) {
		ComponentArr[i].Reset();
	}
}

ENTITY_ID_DATA_TYPE Entity::GetID()
{
	return EntityID;
}

template<typename CType>
void Entity::CreateComponent()
{
	if (std::is_base_of<Component, CType>::value) {
		COMPONENT_ID_DATA_TYPE MinID = FindMinAvailabeID();
		if (MinID) {
			ComponentArr.push_back(CType(MinID));
		}
		else {
			//Send warning to the apps log
		}
	}
	else {
		//Send warning to apps log
	}
}

template<class CType>
std::vector<CType*> Entity::GetComponentsFromType()
{
	std::vector<CType*> List;
	if (std::is_base_of<Component, CType>::value) {
		for (COMPONENT_ID_DATA_TYPE i = 0; i <= ComponentArr.size(); i++) {
			CType* CurrentObj = static_cast<CType*>(&ComponentArr[i]);
			if (CurrentObj) {
				List.push_back(CurrentObj);
			}
		}
		return List;
	}
	else {
		//Send warning to the apps log
	}
	return false;
}

void Entity::RemoveComponent(COMPONENT_ID_DATA_TYPE ID)
{
	COMPONENT_ID_DATA_TYPE index = GetIndexFromId(ID);
	ComponentArr.erase(ComponentArr.begin() + index);
}

Component* Entity::GetComponentFromID(COMPONENT_ID_DATA_TYPE ID)
{
	for (COMPONENT_ID_DATA_TYPE i = 0; i < ComponentArr.size(); i++) {
		if (ComponentArr[i].GetID() == ID) {

			return &ComponentArr[i];
		}
	}
	return nullptr;
}

COMPONENT_ID_DATA_TYPE Entity::GetIndexFromId(COMPONENT_ID_DATA_TYPE ID)
{
	for (COMPONENT_ID_DATA_TYPE i = 0; i < ComponentArr.size(); i++) {
		if (ComponentArr[i].GetID() == ID) {
			return i;
		}
	}
	return ComponentArr.size() + 1;//returns out of bounds so that caller can tell id doesnt exist.
}

COMPONENT_ID_DATA_TYPE Entity::FindMinAvailabeID() {
	for (COMPONENT_ID_DATA_TYPE i = 1; i < COMPONENT_ID_MAX; i++) {
		if (GetComponentFromID(i) == nullptr) {
			return i;
		}
	}
	return false;
}

/*
* Component Definitions
*/

Component::Component(COMPONENT_ID_DATA_TYPE id, Entity* owner)
{
	ComponentID = id;
	Owner = owner;
}

//These 2 are here to prevent unresolved externals error
void Component::Tick(float DeltaTime){}
void Component::Reset(){}

COMPONENT_ID_DATA_TYPE Component::GetID()
{
	return ComponentID;
}