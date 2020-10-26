/*
 * sbmlStubs.h
 *
 * Utilities and stub implementations to build libxsbml.
 *
 *  Created on: 23 October 2020
 *      Author: Timothy Spain
 */

#ifndef SRC_SBML_XML_SBMLSTUBS_H_
#define SRC_SBML_XML_SBMLSTUBS_H_

#include <ctype.h>
#include <list>

/**
 * LIBSBML_DOTTED_VERSION:
 *
 * A version string of the form "1.2.3".
 */
#define LIBSBML_DOTTED_VERSION	"5.18.3"


/**
 * LIBSBML_VERSION:
 *
 * The version as an integer: version 1.2.3 becomes 10203.  Since the major
 * number comes first, the overall number will always increase when a new
 * libSBML is released, making it easy to use less-than and greater-than
 * comparisons when testing versions numbers.
 */
#define LIBSBML_VERSION		51803


/**
 * LIBSBML_VERSION_STRING:
 *
 * The numeric version as a string: version 1.2.3 becomes "10203".
 */
#define LIBSBML_VERSION_STRING	"51803"


extern "C"
char* safe_strdup(const char* s);
void* safe_malloc (size_t size);

class SBMLNamespaces {
public:
	static std::list<SBMLNamespaces> getSupportedNamespaces();
	static void freeSBMLNamespaces(std::list<SBMLNamespaces> nmsp);
	std::string getURI();
};

extern "C"
const char*
getLibSBMLDottedVersion ();


#endif /* SRC_SBML_XML_SBMLSTUBS_H_ */
