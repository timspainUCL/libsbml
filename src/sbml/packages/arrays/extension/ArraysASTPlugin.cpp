/**
 * @file    ArraysASTPlugin.cpp
 * @brief   Implementation of ArraysASTPlugin, the plugin class of
 *          arrays package for the AST element.
 * @author  Sarah Keating
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2009-2011 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
 *  
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 *     Pasadena, CA, USA 
 *  
 * Copyright (C) 2002-2005 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. Japan Science and Technology Agency, Japan
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 */

#include <sbml/packages/arrays/extension/ArraysASTPlugin.h>
#include <sbml/packages/arrays/extension/ArraysExtension.h>

#include <iostream>
using namespace std;


#ifdef __cplusplus

LIBSBML_CPP_NAMESPACE_BEGIN

static unsigned int
determineNumChildren(XMLInputStream & stream, const std::string element = "")
{
  unsigned int n = 0;

  n = stream.determineNumberChildren(element);

  return n;
}


static const char* ARRAYS_MATHML_ELEMENTS[] =
{
    "determinant"
  , "outerproduct"
  , "scalarproduct"
  , "selector"
  , "transpose"
  , "vector"
  , "vectorproduct"
};

static const int ARRAYS_MATHML_TYPES[] =
{
    AST_LINEAR_ALGEBRA_DETERMINANT
  , AST_LINEAR_ALGEBRA_OUTER_PRODUCT
  , AST_LINEAR_ALGEBRA_SCALAR_PRODUCT
  , AST_LINEAR_ALGEBRA_SELECTOR
  , AST_LINEAR_ALGEBRA_TRANSPOSE
  , AST_LINEAR_ALGEBRA_VECTOR_CONSTRUCTOR
  , AST_LINEAR_ALGEBRA_VECTOR_PRODUCT
  , AST_ARRAYS_UNKNOWN
};

/*
 * Constructor
 */
ArraysASTPlugin::ArraysASTPlugin (const std::string &uri)
  : ASTBasePlugin(uri)
  , mVector (NULL)
{
}



/*
 * Copy constructor. Creates a copy of this SBase object.
 */
ArraysASTPlugin::ArraysASTPlugin(const ArraysASTPlugin& orig)
  : ASTBasePlugin(orig)
  , mVector (NULL)
{
  if ( orig.mVector  != NULL)
  {
    mVector = static_cast<ASTArraysVectorFunctionNode*>
                                 ( orig.mVector->deepCopy() );
  }
}


/*
 * Destroy this object.
 */
ArraysASTPlugin::~ArraysASTPlugin () 
{
}

/*
 * Assignment operator for ArraysASTPlugin.
 */
ArraysASTPlugin& 
ArraysASTPlugin::operator=(const ArraysASTPlugin& orig)
{
  if(&orig!=this)
  {
    this->ASTBasePlugin::operator =(orig);

    delete mVector;
    if ( orig.mVector  != NULL)
    {
      mVector = static_cast<ASTArraysVectorFunctionNode*>
                                  ( orig.mVector->deepCopy() );
    }
    else
    {
      mVector = NULL;
    }

  }    
  return *this;
}


/*
 * Creates and returns a deep copy of this ArraysASTPlugin object.
 * 
 * @return a (deep) copy of this SBase object
 */
ArraysASTPlugin* 
ArraysASTPlugin::clone () const
{
  return new ArraysASTPlugin(*this);  
}


const std::string& 
ArraysASTPlugin::getPackageName() const
{
  static string arrays("arrays"); 
  return (mSBMLExt != NULL) ? mSBMLExt->getName() : arrays;
}


bool
ArraysASTPlugin::read(XMLInputStream& stream, const std::string& reqd_prefix, 
                                             const XMLToken currentElement)
{
  bool read = false;
  
  stream.skipText();
  
  const string&  currentName = currentElement.getName();

  //ASTBase::checkPrefix(stream, reqd_prefix, currentElement);
  
  // create appropriate sub class
  if (currentName == "vector")
  {
    read = readVector(stream, reqd_prefix, currentElement);
  }
 
  return read;
}


bool 
ArraysASTPlugin::readVector(XMLInputStream& stream, const std::string& reqd_prefix,
                        const XMLToken currentElement)
{
  bool read = false;
  
  stream.skipText();
  const XMLToken nextElement = stream.peek();
  const string&  nextName = nextElement.getName();
  
  unsigned int numChildren = determineNumChildren(stream, "vector");
    
  mVector = new ASTArraysVectorFunctionNode();
  
  mVector->setExpectedNumChildren(numChildren);
  
  // read attributes on this element here since we have already consumed
  // the element
  ExpectedAttributes expectedAttributes;
  mVector->addExpectedAttributes(expectedAttributes, stream);
  read = mVector->ASTBase::readAttributes(currentElement.getAttributes(), 
                                expectedAttributes, stream, currentElement);
  if (read == false)
  {
    mVector = NULL;
  }
  else
  {  
    read = mVector->read(stream, reqd_prefix);
  }

  return read;
}


void
ArraysASTPlugin::reset()
{
  mVector = NULL;
}


const ASTBase* 
ArraysASTPlugin::getMath() const
{
  if (mVector != NULL)
  {
    return mVector;
  }
  else
  {
    return NULL;
  }
}



bool
ArraysASTPlugin::isSetMath() const
{
  if (mVector != NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}


void
ArraysASTPlugin::createMath(int type)
{
  reset();
  switch (type)
  {
  case AST_LINEAR_ALGEBRA_VECTOR_CONSTRUCTOR:
    mVector = new ASTArraysVectorFunctionNode();
    break;
  default:
    break;
  }
}


int 
ArraysASTPlugin::addChild(ASTBase * child)
{ 
  if (child == NULL)
  {
    return LIBSBML_INVALID_OBJECT;
  }

  if (mVector != NULL)
  {
    return mVector->addChild(child);
  }
  else
  {
    return LIBSBML_INVALID_OBJECT;
  }
}


ASTBase* 
ArraysASTPlugin::getChild (unsigned int n) const
{ 
  if (mVector != NULL)
  {
    return mVector->getChild(n);
  }
  else
  {
    return NULL;
  }
}


unsigned int 
ArraysASTPlugin::getNumChildren() const
{ 
  if (mVector != NULL)
  {
    return mVector->getNumChildren();
  }
  else
  {
    return 0;
  }
}


int 
ArraysASTPlugin::insertChild(unsigned int n, ASTBase* newChild)
{ 
  if (mVector != NULL)
  {
    return mVector->insertChild(n, newChild);
  }
  else
  {
    return LIBSBML_INVALID_OBJECT;
  }
}


int 
ArraysASTPlugin::prependChild(ASTBase* newChild)
{ 
  if (mVector != NULL)
  {
    return mVector->prependChild(newChild);
  }
  else
  {
    return LIBSBML_INVALID_OBJECT;
  }
}


int 
ArraysASTPlugin::removeChild(unsigned int n)
{ 
  if (mVector != NULL)
  {
    return mVector->removeChild(n);
  }
  else
  {
    return LIBSBML_INVALID_OBJECT;
  }
}


int 
ArraysASTPlugin::replaceChild(unsigned int n, ASTBase* newChild)
{ 
  if (mVector != NULL)
  {
    return mVector->replaceChild(n, newChild);
  }
  else
  {
    return LIBSBML_INVALID_OBJECT;
  }
}

/* default for components that have no required elements */
//bool
//ArraysASTPlugin::hasRequiredElements() const
//{
//  bool allPresent = true;
//
//  if (mArraysitativeSpecies.size() < 1)
//  {
//    allPresent = false;    
//  }
//  if (mTransitions.size() < 1)
//  {
//    allPresent = false;    
//  }
//  return allPresent;
//}
//
//


/*
 * Sets the parent SBML object of this plugin object to
 * this object and child elements (if any).
 * (Creates a child-parent relationship by this plugin object)
 */
void
ArraysASTPlugin::connectToParent (ASTBase* astbase)
{
  ASTBasePlugin::connectToParent(astbase);

}


/*
 * Enables/Disables the given package with child elements in this plugin
 * object (if any).
 */
void
ArraysASTPlugin::enablePackageInternal(const std::string& pkgURI,
                                        const std::string& pkgPrefix, bool flag)
{
}

  

bool 
ArraysASTPlugin::isFunction(int type) const
{
  bool valid = false;

  switch (type)
  {
    case AST_LINEAR_ALGEBRA_SELECTOR:
    case AST_LINEAR_ALGEBRA_DETERMINANT:
    case AST_LINEAR_ALGEBRA_TRANSPOSE:
    case AST_LINEAR_ALGEBRA_VECTOR_PRODUCT:
    case AST_LINEAR_ALGEBRA_SCALAR_PRODUCT:
    case AST_LINEAR_ALGEBRA_OUTER_PRODUCT:
      valid = true;
      break;
    default:
      break;

  }
  return valid;
}


bool 
ArraysASTPlugin::isFunctionNode(int type) const
{
  bool valid = false;

  switch (type)
  {
    case AST_LINEAR_ALGEBRA_VECTOR_CONSTRUCTOR:
      valid = true;
      break;
    default:
      break;

  }
  return valid;
}



bool 
ArraysASTPlugin::representsUnaryFunction(int type) const
{
  bool valid = false;

  switch (type)
  {
    case AST_LINEAR_ALGEBRA_DETERMINANT:
    case AST_LINEAR_ALGEBRA_TRANSPOSE:
      valid = true;
      break;
    default:
      break;

  }
  return valid;
}


bool 
ArraysASTPlugin::representsBinaryFunction(int type) const
{
  bool valid = false;

  switch (type)
  {
    case AST_LINEAR_ALGEBRA_VECTOR_PRODUCT:
    case AST_LINEAR_ALGEBRA_SCALAR_PRODUCT:
    case AST_LINEAR_ALGEBRA_OUTER_PRODUCT:
      valid = true;
      break;
    default:
      break;

  }
  return valid;
}


bool 
ArraysASTPlugin::representsNaryFunction(int type) const
{
  bool valid = false;

  switch (type)
  {
    case AST_LINEAR_ALGEBRA_SELECTOR:
      valid = true;
      break;
    default:
      break;

  }
  return valid;
}


bool 
ArraysASTPlugin::isTopLevelMathMLFunctionNodeTag(const std::string& name) const
{
  bool valid = false;

  if (name == "vector")
  {
    valid = true;
  }

  return valid;
}


int 
ArraysASTPlugin::getTypeFromName(const std::string& name) const
{
  int type = AST_UNKNOWN;

  static const int size = sizeof(ARRAYS_MATHML_ELEMENTS) / sizeof(ARRAYS_MATHML_ELEMENTS[0]);

  int  index = util_bsearchStringsI(ARRAYS_MATHML_ELEMENTS, name.c_str(), 0, size - 1);
  bool found = (index < size);

  if (found) 
  {
    type = ARRAYS_MATHML_TYPES[index];
  }

  return type;
}

const char * 
ArraysASTPlugin::getNameFromType(int type) const
{
  std::string name = "";

  static const int size = sizeof(ARRAYS_MATHML_ELEMENTS) / sizeof(ARRAYS_MATHML_ELEMENTS[0]);
  if (type >= AST_LINEAR_ALGEBRA_DETERMINANT && type < AST_ARRAYS_UNKNOWN)
  {
    bool found = false;
    unsigned int i;
    for (i = 0; i < size, found == false; i++)
    {
      if (type == ARRAYS_MATHML_TYPES[i])
        found = true;
    }
    if (found == true)
    {
      name = ARRAYS_MATHML_ELEMENTS[i-1];
    }
  }

  return safe_strdup(name.c_str());
}
LIBSBML_CPP_NAMESPACE_END

#endif  /* __cplusplus */
