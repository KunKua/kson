/**
 * A Tiny JSON library 
 */
#ifndef HEADER_KSON_H
#define HEADER_KSON_H

#ifdef __cplusplus
extern "C"
{
#endif


///////////////////////////////////////////////////////////////////////////////
// Type

//! Type of JSON value
enum Type {
    kNullType = 0,      //!< null
    kFalseType = 1,     //!< false
    kTrueType = 2,      //!< true
    kObjectType = 3,    //!< object
    kArrayType = 4,     //!< array
    kStringType = 5,    //!< string
    kNumberType = 6     //!< number
};

//current support encode
enum Encode {
	utf8 = 1
};

struct JsonNode;
typedef struct JsonNode* JSONNode;
typedef struct JsonNode* NodeArray;

union JsonValue {
	int valueInt;
	double valueDouble;
	char* valueString;
	JSONNode valueNode;
	NodeArray valueArray;
};

typedef union JsonValue JSONValue;

struct JsonNode {
	JSONNode _pre,_next;
	JsonNode* _child; /* An array or object item will have a child pointer pointing to a chain of the items in the array/object. */

	enum Type _type; 	/* The type of the item, as above. */
	char* _nodeName;    /* The item's name string, if this item is the child of, or is in the list of subitems of an object. */
	JSONValue _value; 	/* The item's value*/

};

JSONNode createNode();

JSONNode createNullNode(void);
JSONNode createTrueNode(void);
JSONNode createFalseNode(void);
JSONNode createIntNode(int value);
JSONNode createDoubleNode(double value);

JSONNode createStringNode(const char* string);
JSONNode createObjectNode(void);
JSONNode createArrayNode(void);
    
/* These utilities create an Array of count items. */
extern NodeArray createIntArray(const int *numbers,int count);
extern NodeArray createFloatArray(const float *numbers,int count);
extern NodeArray createDoubleArray(const double *numbers,int count);
extern NodeArray createStringArray(const char **strings,int count);

void deleteNode(JsonNode* node);

void node_addInt(JSONNode node,const char* name,int value);
void node_addDounble(JSONNode node,const char* name,double value);
void node_addString(JSONNode node,const char* name,const char* string);
void node_addObject(JSONNode node,const char* name,JSONNode object);
void node_addArray(JSONNode node,const char* name,NodeArray array);

JsonNode* kson_parse(const char* content,enum Encode encode);
char* node_toString(int encode);
JSONNode node_parseString(const char* str);

#ifdef __cplusplus
}
#endif

#endif
