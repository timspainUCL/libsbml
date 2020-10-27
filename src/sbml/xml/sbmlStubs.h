/*
 * sbmlStubs.h
 *
 * Utilities and stub implementations to build libxsbml.
 *
 *  Created on: 23 October 2020
 *      Author: Timothy Spain
 */

#ifndef SBMLSTUBS_H
#define SBMLSTUBS_H

#include <list>
#include <sbml/xml/sbmlMemoryStubs.h>

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



class SBMLNamespaces {
public:
	static std::list<SBMLNamespaces> getSupportedNamespaces();
	static void freeSBMLNamespaces(std::list<SBMLNamespaces> nmsp);
	std::string getURI();
};

extern "C"
const char*
getLibSBMLDottedVersion ();


#endif /*ndef SBMLSTUBS_H */
