#pragma once

//This will also define the max number of entities per container.
//ID's start with 1 because returning false or zero is used when possible id's are run out of.
#define ENTITY_ID_DATA_TYPE uint16_t
#define ENTITY_ID_MAX 65535
#define COMPONENT_ID_DATA_TYPE uint8_t
#define COMPONENT_ID_MAX 255