#include "kson.h"
#include <stdio.h>
#include <string.h>

static JSONNode createNode(void);
{
	JSONNode node = (JSONNode)malloc(sizeof(struct JsonNode));
	memset(node,0,sizeof(struct JsonNode));
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

JSONNode createStringNode(const char* string)
{

}

JSONNode createObjectNode(void)
{

}

JSONNode createArrayNode(void)
{

}

void releaseNode(JSONNode node)
{
	if(node == NULL) return;
	JSONNode next;
	while(node) {
		next = node->next;
		if(node->_type == kStringType) {
			free(_value);
		} else if(node->_type == kObjectType) {
			releaseNode(_value.valueObject);
		} else if(node->_type == kArrayType) {
			releaseNode(_value.valueArray);
		}

		if(node->_child)    releaseNode(_child);
		if(node->_name)     free(_name);

		free(node);
		node = next;
	}
}


void node_addInt(JSONNode node,const char* name,int value)
{

}

void node_adddounble(JSONNode node,const char* name,double value)
{

}

void node_addString(JSONNode node,const char* name,const char* string)
{

}

void node_addObject(JSONNode node,const char* name,JSONNode object)
{

}

void node_addArray(JSONNode node,const char* name,NodeArray array)
{

}

char* node_toString(JSONNode node,int encode);
{
	char* start = "{";
	char* end = "}";
}
