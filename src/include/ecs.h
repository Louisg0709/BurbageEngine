#ifndef ECS_H
#define ECS_H

#include "BurbageConfig.h"
#include <vector>

namespace Burbage {

	class Component;
	class Entity;

	class Container {
		//general
	public:
		void Tick(float DeltaTime); //Ticks all ecs logic
		void Reset();

		//ecs
	public:
		//Related to components
		template <class EType>
		void CreateEntity();
		void RemoveEntity(ENTITY_ID_DATA_TYPE ID);
		Entity* GetEntityFromID(ENTITY_ID_DATA_TYPE ID);
		template <class EType>
		std::vector<EType*> GetEntitiesFromType();
		ENTITY_ID_DATA_TYPE GetIndexFromId(ENTITY_ID_DATA_TYPE ID);
	private:
		ENTITY_ID_DATA_TYPE FindMinAvailabeID();
		std::vector<Entity> EntityArr;
	};



	class Component {
	public:
		Component(COMPONENT_ID_DATA_TYPE id, Entity* Owner);

		void Tick(float DeltaTime);
		void Reset();

		COMPONENT_ID_DATA_TYPE GetID();

	protected:
		COMPONENT_ID_DATA_TYPE ComponentID;
		Entity* Owner;
	};

	class Entity {
	public:
		Entity(ENTITY_ID_DATA_TYPE id, Container* Owner);

		//Entity Logic
		void Tick(float DeltaTime);
		void Reset();

		//related to app
		ENTITY_ID_DATA_TYPE GetID();

	protected:
		ENTITY_ID_DATA_TYPE EntityID;
		Container* Owner;

		//Related to components
		template <class CType>
		void CreateComponent();
		void RemoveComponent(COMPONENT_ID_DATA_TYPE ID);
		Component* GetComponentFromID(COMPONENT_ID_DATA_TYPE ID);
		template <class CType>
		std::vector<CType*> GetComponentsFromType();
		COMPONENT_ID_DATA_TYPE GetIndexFromId(COMPONENT_ID_DATA_TYPE ID);
	private:
		COMPONENT_ID_DATA_TYPE FindMinAvailabeID();
		std::vector<Component> ComponentArr;
	};
}

#endif // !ECS_H

