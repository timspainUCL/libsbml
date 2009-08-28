/**
 * @file    StoichiometryMathVars.h
 * @brief   Ensures FunctionDefinitions contain no undefined variables.
 * @author  Ben Bornstein
 *
 * $Id$
 * $HeadURL$
 */
/* Copyright 2005 California Institute of Technology and Japan Science and
 * Technology Corporation.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is
 * provided in the file named "LICENSE.txt" included with this software
 * distribution.  It is also available online at
 * http://sbml.org/software/libsbml/license.html
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 */


#ifndef StoichiometryMathVars_h
#define StoichiometryMathVars_h


#ifdef __cplusplus


#include <string>
#include <sbml/validator/VConstraint.h>
#include "IdList.h"

LIBSBML_CPP_NAMESPACE_BEGIN

class FunctionDefinition;


class StoichiometryMathVars: public TConstraint<Reaction>
{
public:

  /**
   * Creates a new Constraint with the given id.
   */
  StoichiometryMathVars (unsigned int id, Validator& v);

  /**
   * Destroys this Constraint.
   */
  virtual ~StoichiometryMathVars ();


protected:

  /**
   * Checks that all variables referenced in FunctionDefinition bodies are
   * bound variables (function arguments).
   */
  virtual void check_ (const Model& m, const Reaction& object);

  /**
   * Logs a message about an undefined variable in the given
   * FunctionDefinition.
   */
  void logUndefined (const Reaction& r, const std::string& varname);

  IdList mSpecies;
};

LIBSBML_CPP_NAMESPACE_END

#endif  /* __cplusplus */
#endif  /* StoichiometryMathVars_h */
