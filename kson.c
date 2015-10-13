#include "kson.h"
#include <stdio.h>
#include <string.h>

static JSONNode createNode(void);
{
	JSONNode node = (JSONNode)malloc(sizeof(struct JsonNode));
	memset(node ,0 ,sizeof(struct JsonNode));
	return node;
}

JSONNode createNullNode(void) {
	JSONNode node = createNode();
	node->_type = kNullType;
	return node;
}

JSONNode createTrueNode(void)
{
	JSONNode node = createNode();
	node->_type = kTrueType;
	return node;
}

JSONNode createFalseNode(void)
{
	JSONNode node = createNode();
	node->_type = kFalseType;
	return node;
}

JSONNode createIntNode(int value)
{
	JSONNode node = createNode();
	node->_type = kNumberType;
	node->_value.valueInt = value;
	return node;
}

JSONNode createDoubleNode(double value)
{
	JSONNode node = createNode();
	node->_type = kNumberType;
	node->_value.valueDouble = value;
	return node;
}

JSONNode createStringNode(const char* string)
{
	JSONNode node = createNode();
	node->_type = kStringType;
	node->_value.valueString = strdup(string);
	return node;
}

JSONNode createObjectNode(void)
{
	JSONNode node = createNode();
	node->_type = kObjectType;
	node->_value.valueNode = NULL;
	return node;
}

JSONNode createArrayNode(void)
{
	JSONNode node = createNode();
	node->_type = kArrayType;
	node->_value.valueArray = NULL;
	return node;
}

void releaseNode(JSONNode node)
{
	if(node == NULL) return;
	JSONNode next;
	while(node)
   	{
		next = node->next;
		if(node->_type == kStringType) {
			free(_value);
		} else if(node->_type == kObjectType) {
			releaseNode(_value.valueObject);
		} else if(node->_type == kArrayType) {
			releaseNode(_value.valueArray);
		}

		if(node->_child)    releaseNode(_child);
		if(node->_nodeName)     free(_nodeName);

		free(node);
		node = next;
	}
}


void node_addInt(JSONNode node,const char* name,int value)
{
	if(node == NULL || name == NULL) {
			return NULL;
	}
	
	JSONNode one = createIntNode(value);
	one->_nodeName = strdup(name);

	JSONNode tmp = node->_child;
	while(tmp->_next) {
		tmp = tmp->_next;
	}

	tmp->_next = one;
	one->_pre = tmp;
}

void node_addDounble(JSONNode node,const char* name,double value)
{
	if(node == NULL || name == NULL) {
			return NULL;
	}
}

void node_addString(JSONNode node,const char* name,const char* string)
{
	if(node == NULL || name == NULL || string == NULL) {
			return NULL;
	}
}

void node_addObject(JSONNode node,const char* name,JSONNode object)
{
	if(node == NULL || name == NULL || object == NULL) {
			return NULL;
	}
}

void node_addArray(JSONNode node,const char* name,NodeArray array)
{
	if(node == NULL || name == NULL) {
			return NULL;
	}
}

char* node_toString(JSONNode node,int encode);
{
	char* start = "{";
	char* end = "}";
}

JSONNode parseString(const char* str)
{
	if(str == NULL) {
		return NULL;
	}
}

