#include "xml2json-c.h"

/*
 ============================================================================
 Name        : xml2json-c.c
 Author      : Katie Snow
 Version     :
 Copyright   : Copyright 2015 Katie Snow
 Description : XML 2 JSON-C main configuration library
 ============================================================================
*/

#include <libxml/tree.h>
#include <json.h>

void xml2jsonc_convert_elements(xmlNode *anode, json_object *jobj)
{
  xmlNode *cur_node = NULL;
  json_object *cur_jobj = NULL;
  json_object *cur_jstr = NULL;

  for (cur_node = anode; cur_node; cur_node = cur_node->next)
  {
    if (cur_node->type == XML_ELEMENT_NODE)
    {
      if (xmlChildElementCount(cur_node) == 0)
      {
        /* JSON string object */
        cur_jstr = json_object_new_string(xmlNodeGetContent(cur_node));
        cur_jobj = json_object_new_object();
        json_object_object_add(jobj, cur_node->name, cur_jstr);
      }
      else
      {
        /* JSON object */
        cur_jobj = json_object_new_object();
        json_object_object_add(jobj, cur_node->name, json_object_get(cur_jobj));
      }
    }

    xml2jsonc_convert_elements(cur_node->children, cur_jobj);
  }
}
