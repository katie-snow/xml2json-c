/*
 ============================================================================
 Name        : main.c
 Author      : Katie Snow
 Version     :
 Copyright   : Copyright 2015 Katie Snow
 Description : XML 2 JSON-C command line utility
 ============================================================================
 */

#include <stdio.h>
#include "libs/xml2json-c.h"

#include <libxml/parser.h>
#include <json.h>

#ifdef LIBXML_TREE_ENABLED

int main(int argc, char **argv)
{
  int idx;
  int retVal = EXIT_SUCCESS;
  xmlDoc *doc = NULL;
  xmlNode *root_element = NULL;
  json_object* jobj = NULL;

  for (idx = 1; idx < argc; ++idx)
  {
    if (strcmp(argv[idx], "-h") == 0 || strcmp(argv[idx], "--help") == 0)
    {
      printf("xml2jsonc [-h] [--help] [xml file] [json file]\n");
      printf("-h | --help\t\t Prints this information\n");
      printf("xml file\t\t XML file to be processed\n");
      printf("json file\t\t JSON file where the output will be saved\n");
      retVal = EXIT_SUCCESS;
      goto exit;
    }
  }

  if (argc != 3)
  {
    retVal = EXIT_FAILURE;
    goto exit;
  }

  /*
   * this initialize the library and check potential ABI mismatches
   * between the version it was compiled for and the actual shared
   * library used.
   */
  LIBXML_TEST_VERSION

  /*parse the file and get the DOM */
  doc = xmlReadFile(argv[1], NULL, 0);

  if (doc == NULL)
  {
    printf("error: could not parse file %s\n", argv[1]);
    retVal = EXIT_FAILURE;
  }

  /*Create JSON object */
  jobj = json_object_new_object();

  /*Get the root element node */
  root_element = xmlDocGetRootElement(doc);

  xml2jsonc_convert_elements(root_element, jobj);

  /*free the document */
  xmlFreeDoc(doc);

  /*
   *Free the global variables that may
   *have been allocated by the parser.
   */
  xmlCleanupParser();

  json_object_to_file(argv[2], jobj);

  exit: return retVal;
}
#else
int main(void)
{
  fprintf(stderr, "Tree support not compiled in\n");
  exit(EXIT_SUCCESS;);
}
#endif
