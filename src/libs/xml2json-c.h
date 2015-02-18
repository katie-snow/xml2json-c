/*
 ============================================================================
 Name        : xml2json-c.h
 Author      : Katie Snow
 Version     :
 Copyright   : Copyright 2015 Katie Snow
 Description : XML 2 JSON-C main configuration library
 ============================================================================
*/

#ifndef __XML2JSON_C_H_
#define __XML2JSON_C_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _xmlNode xmlNode;
typedef struct json_object json_object;

/**
 * converts from xml to a json-c object
 *
 * Parameters: pointers to xmlNode and json_object
 */
extern void xml2jsonc_convert_elements (xmlNode *anode, json_object* jobj);

#ifdef __cplusplus
}
#endif

#endif /* __XML2JSON_C_H_ */
