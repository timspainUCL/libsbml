/**
 * @file    CompFlatteningConverter.h
 * @brief   Definition of a first flattening converter.
 * @author  Frank T. Bergmann
 * 
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2014 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *     3. University of Heidelberg, Heidelberg, Germany
 * 
 * Copyright 2011-2012 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 * ---------------------------------------------------------------------- -->
 *
 * @class CompFlatteningConverter
 * @sbmlbrief{comp} "Flattens" a model, removing composition.
 *
 * @htmlinclude libsbml-facility-only-warning.html
 *
 * This converter translates a hierarchical model defined with the SBML
 * Level&nbsp;3 Hierarchical %Model Composition package to a so-called
 * "flattened" version of the same model.  A "flattened" model is one that
 * results from interpreting the hierarchical structure and creating an
 * equivalent model that does not use any Hierarchical %Model Composition
 * package constructs; all of the mathematics of the model remain as
 * intended, but the hierarchical structure is removed.
 * CompFlatteningConverter achieves this by performing the following actions
 * on a model:
 * <ol>
 * <li> Each submodel is instantiated; that is, a copy of every Model object
 * referenced by every Submodel object is created.  This is a recursive
 * process: if the instantiated Model itself has Submodel children, they are
 * also instantiated.
 *
 * <li> The identifier of every component object in every Model that is
 * instantiated is modified by prepending a prefix to it, to make the
 * identifier unique in the overall flattened SBML model.  The prefix
 * consists of the Submodel object identifier, plus a small integer if
 * necessary to ensure uniqueness, plus two underscore characters
 * (<code>"__"</code>).  Typically, this results in a final identifier of the
 * form <span
 * class="code-placeholder">%SubmodelIdentifier__</span><span
 * class="code-placeholder2-nospace">ObjectIdentifier</span>, where <span
 * class="code-placeholder2">ObjectIdentifier</span> is the object's original
 * identifier and <span
 * class="code-placeholder">%SubmodelIdentifier__</span> is
 * the prefix.  The same process is applied to @em metaid (meta-identifier)
 * values of every component object as well.
 *
 * <li> All deleted elements are removed from the model and all instantiated
 * submodels.
 *
 * <li> All replaced elements are removed from the model and all instantiated
 * submodels.
 *
 * <li> All references to replaced elements are changed to point to the
 * replacement element instead.
 *
 * <li> All remaining elements are placed in a single Model object; this Model
 * object is made the new child of the SBMLDocument container.  The original
 * Model, ModelDefinition, and ExternalModelDefinition objects are all
 * deleted.
 *
 * </ol>
 *
 * Note an implication of this process is that if conversion is successful,
 * all old pointers to the SBMLDocument object's Model object as well as all
 * of its children, will be rendered obsolete, and will no longer work.
 *
 * @section CompFlatteningConverter-usage Configuration and use of CompFlatteningConverter
 *
 * CompFlatteningConverter is enabled by creating a ConversionProperties
 * object with the option @em "flatten comp", and passing this
 * ConversionProperties object to SBMLDocument::convert(@if java
 * ConversionProperties@endif).  The converter accepts numerous options.  The
 * following list summarizes the options; they are described in more detail
 * in the subsections below.
 *
 * @li @em abortIfUnflattenable: Possible values are @c "all", @c
 * "requiredOnly" (the default), or @c "none".
 *
 * @li @em stripUnflattenablePackages: Possible values are @c "true" or @c
 * "false" (the default).
 *
 * @li @em basePath: The value must be a string representing the path where
 * the converter should search for any ExternalModelDefinition objects.
 * (Default value: ".", meaning, the current directory.)
 *
 * @li @em leavePorts: Possible values are @c "true" or @c "false" (the
 * default).
 *
 * @li @em listModelDefinitions: Possible values are @c "true" or @c "false"
 * (the default).
 *
 * @li @em performValidation: Possible values are @c "true" (the default) or
 * @c "false".
 *
 * The following sections delve into more detail about the meanings of these
 * options and their effects on the flattening process.
 *
 * @subsection behavior-if-unflattenable Options for handling Level&nbsp;3 packages that lack flattening algorithms
 *
 * If other SBML Level&nbsp;3 packages are used in the SBMLDocument, the same
 * rules apply to each package's constructs if an implementation of the
 * flattener exists for that Level&nbsp;3 package.  If no implementation
 * exists, the behavior of this CompFlatteningConverter depends on the values
 * of the options @em abortIfUnflattenable and @em
 * stripUnflattenablePackages.  Specifically:
 * <ul>
 *
 * <li> The option @em abortIfUnflattenable controls whether the flattening
 * process is abandoned.  The following are the possible values for this
 * option and their meanings:
 * <ul style="list-style-type: circle">
 *
 * <li> If the @em abortIfUnflattenable option is set to @c "all", then if any
 *     construct is found for a package that has no flattening algorithm
 *     available, the converter will abort, return failure, and avoid
 *     changing the original SBMLDocument object.
 *
 * <li> If @em abortIfUnflattenable is set to @c "requiredOnly" (the default),
 *     then if any SBML Level&nbsp;3 package construct is found for a package
 *     that is labeled @c "required=true" and for which no flattening
 *     algorithm is available, the converter will abort, return failure, and
 *     avoid changing the original SBMLDocument object.  SBML Level&nbsp;3
 *     package constructs from packages set @c "required=false" for which no
 *     flattening algorithm is implemented will be ignored and the constructs
 *     will be kept or removed depending on the value of the @em
 *     stripUnflattenablePackages option described below.
 * 
 * <li> If @em abortIfUnflattenable is set to @c 'none', constructs from all
 *     unflattenable SBML Level&nbsp;3 packages will be ignored, and their
 *     constructs will be kept or removed depending on the value of the @em
 *     stripUnflattenablePackages option.
 *
 * </ul>
 *
 * <li> The option @em stripUnflattenablePackages controls whether SBML
 * Level&nbsp;3 package constructs are removed from the final flattened
 * model.  The following are the possible values for this option and their
 * meanings:
 * <ul style="list-style-type: circle">
 *
 * <li> If the option @em stripUnflattenablePackages is set to @c "true", and
 *      the option @em abortIfUnflattenable has the value @c "requireOnly"
 *      or @c "none", then CompFlatteningConverter will remove all constructs
 *      belonging to packages that lack a flattening converter.  The XML
 *      namespace declaration for unflattenable SBML Level&nbsp;3 packages
 *      will also be removed.
 *
 * <li> If the option @em stripUnflattenablePackages is set to @c "false"
 *     (the default), CompFlatteningConverter will leave any package
 *     constructs that cannot be flattened due to the lack of a flattening
 *     implementation.  These Level&nbsp;3 package constructs will remain in
 *     the final model.  Note that any package constructs from an
 *     instantiated Submodel object that was @em not a child of a retained
 *     component will be lost (because the SBML component where it was
 *     located was removed from the final, flattened model).
 *
 * </ul>
 *
 * </ul>
 *
 * @subsection general-flattener-options Additional general conversion options for CompFlatteningConverter
 *
 * The following are other, general options offered by CompFlatteningConverter:
 *
 * @li @em basePath: if there are ExternalModelDefinition objects that are to
 *     be instantiated in a flattened Submodel, the @em basePath option may
 *     be set to a location where those external models may be found.  The
 *     default is the working directory (@c ".").
 *
 * @li @em leavePorts: if this option is set to @c "false" (the default), the
 *     flattened model will have no Port objects in it.  Conversely, if @em
 *     leavePorts is set to @c "true", any Port objects not referenced by any
 *     Replacement or Deletion will be left in the resulting flattened Model.
 *
 * @li @em listModelDefinitions: If this option is set to @c "false" (the
 *     default), no ModelDefinition or ExternalModelDefinition objects will
 *     be present in the flattened SBMLDocument.  If @em listModelDefinitions
 *     is set to @c "true", they will remain, although they will no longer be
 *     referenced by any Submodel in the flattened Model child of the
 *     SBMLDocument.
 *
 * @li @em performValidation: if this option is set to @c "true" (the
 *     default), the SBMLDocument will first be validated before flattening
 *     is attempted.  If there are any validation errors, those errors will
 *     be logged with the SBMLDocument, which will remain otherwise
 *     unchanged, and the conversion process will return a failure code.
 *     Similarly, if the flattened Model is not valid, those validation
 *     errors will be added to the SBMLDocument, which will remain otherwise
 *     unchanged, and the conversion attempt will return failure.
 *     Conversely, if the option @em performValidation is set to @c
 *     "false", the SBMLDocument will be flattened regardless of any
 *     validation errors.  The conversion may yet fail if insurmountable
 *     errors are encountered in the course of trying to flatten the model
 *     (for instance, if an element is replaced by something that does not
 *     exist), but no separate validation steps are performed.
 *
 * Note that if both the option @em leavePorts and @em listModelDefinitions
 * are set to @c "false" (which they are by default), the Hierarchical %Model
 * Composition namespace will be removed from the resulting SBMLDocument.
 *
 * @section comp-flattening-example Complete example of invoking CompFlatteningConverter
 *
 * In this section, we present a complete example of a program that can take
 * an SBML model containing Level&nbsp;3 Hierarchical %Model Composition
 * constructs and flatten it to a plain SBML Level&nbsp;3 model.
 * A version of this program is available in the libSBML distribution's
 * @if cpp <code>examples/c++/comp</code>@endif
 * @if python <code>examples/python/comp</code>@endif
 * @if java <code>examples/java/comp</code>@endif
 * @if javascript <code>examples/javascript/comp</code>@endif
 * @if csharp <code>examples/csharp/comp</code>@endif
 * @if ruby  <code>examples/ruby/comp</code>@endif
 * @if perl  <code>examples/perl/comp</code>@endif@~ directory as the
 * program named
 * @if cpp @ref flattenModel.cpp "flattenModel.cpp"@endif
 * @if python  @ref flattenModel.py "flattenModel.py"@endif
 * @if java  @ref flattenModel.java "flattenModel.java"@endif
 * @if javascript  @ref flattenModel.js "flattenModel.js"@endif
 * @if csharp  @ref FlattenModel.cs "FlattenModel.cs"@endif
 * @if ruby @ref flattenModel.rb "flattenModel.rb"@endif
 * @if perl @ref flattenModel.pl "flattenModel.pl"@endif.  The example
 * XML models shown below are the same models as given in sections
 * 4.1&ndash;4.2 in the specification document for SBML Level&nbsp;3
 * Hierarchical %Model Composition.
 *
 * @subsection comp-flattening-example-program Example program
 *
 * For brevity, we do not give the general scaffolding that a real program
 * would have (such as inclusion of header files, command-line argument
 * checks and so on), and focus instead on the parts relevant to an
 * application of "comp".
 *
 * First, our program checks that this copy of libSBML has the "comp"
 * extension available.  The process for doing that simply involves a call to
 * the extension registry in libSBML:
 * @if cpp
@code{.cpp}
if (SBMLExtensionRegistry::isPackageEnabled("comp") == false)
{
    cerr << "The version of libsbml being used does not have the comp"
         << " package code enabled" << endl;
    return 1;
}
@endcode
@endif
 *
 * Next, we read the SBML input file.  For this example, we simply
 * assume that the path to the file is given as the first argument
 * to the program.
 * @if cpp
@code{.cpp}
const char* inputFile  = argv[1];
SBMLDocument* document = readSBML(inputFile);

if (document->getNumErrors() > 0)
{
    cerr << "Encountered the following SBML errors:" << endl;
    document->printErrors(cerr);
    return 1;
}
@endcode
@endif
 * Continuing, we set up options for the call to the converter.
 * The use of ConversionProperties and the general scheme behind
 * conversion options is explained further below; for the purposes
 * of this example, it is enough to know that the following are the
 * basic lines of code needed to obtain a copy of a libSBML
 * converter object that will invoke CompFlatteningConverter:
 * @if cpp
@code{.cpp}
ConversionProperties* props = new ConversionProperties();
props->addOption("flatten comp");
SBMLConverter* converter =
    SBMLConverterRegistry::getInstance().getConverterFor(*props);
@endcode
@endif
 * Now comes the actual invocation of CompFlatteningConverter.
 * As always, it is critical to check for possible errors by
 * checking the status code returned by the call; we do this
 * in the code below too.
 * @if cpp
@code{.cpp}
converter->setDocument(document);
int result = converter->convert();

if (result != LIBSBML_OPERATION_SUCCESS)
{
    cerr << "Conversion failed\n";
    document->printErrors();
}
@endcode
@endif
 * If successful, we simply write out the resulting flattened model
 * to an output file which, for the purposes of this simple example,
 * we assume is indicated by the second argument handed to the program
 * on the command line by the user.  We also clean up the objects
 * we allocated, to avoid leaking memory.
 * @if cpp
@code{.cpp}
const char* outputFile  = argv[2];
writeSBML(document, outputFile);

delete converter;
delete document;
@endcode
@endif
 *
 * @section comp-flattening-example-use Example use of the program
 *
 * What is the result of the above on an actual model?  Suppose we
 * have the following SBML Level&nbsp;3 model stored in a file named
 * @c "enzyme_model.xml":
@code{.xml}
<?xml version="1.0" encoding="UTF-8"?>
<sbml xmlns="http://www.sbml.org/sbml/level3/version1/core" level="3" version="1"
      xmlns:comp="http://www.sbml.org/sbml/level3/version1/comp/version1" comp:required="true">

  <model id="aggregate">
    <comp:listOfSubmodels>
      <comp:submodel comp:id="submod1" comp:modelRef="enzyme"/>
      <comp:submodel comp:id="submod2" comp:modelRef="enzyme"/>
    </comp:listOfSubmodels>
  </model>
  <comp:listOfModelDefinitions>
    <comp:modelDefinition id="enzyme" name="enzyme">
      <listOfCompartments>
        <compartment id="compartment" spatialDimensions="3" size="1" constant="true"/>
      </listOfCompartments>
      <listOfSpecies>
        <species id="S"  compartment="compartment" hasOnlySubstanceUnits="false"
                         boundaryCondition="false" constant="false"/>
        <species id="E"  compartment="compartment" hasOnlySubstanceUnits="false" 
                         boundaryCondition="false" constant="false"/>
        <species id="D"  compartment="compartment" hasOnlySubstanceUnits="false" 
                         boundaryCondition="false" constant="false"/>
        <species id="ES" compartment="compartment" hasOnlySubstanceUnits="false"
                         boundaryCondition="false" constant="false"/>
      </listOfSpecies>
      <listOfReactions>
        <reaction id="J0" reversible="true" fast="false">
          <listOfReactants>
            <speciesReference species="S" stoichiometry="1" constant="true"/>
            <speciesReference species="E" stoichiometry="1" constant="true"/>
          </listOfReactants>
          <listOfProducts>
            <speciesReference species="ES" stoichiometry="1" constant="true"/>
          </listOfProducts>
        </reaction>
        <reaction id="J1" reversible="true" fast="false">
          <listOfReactants>
            <speciesReference species="ES" stoichiometry="1" constant="true"/>
          </listOfReactants>
          <listOfProducts>
            <speciesReference species="E" stoichiometry="1" constant="true"/>
            <speciesReference species="D" stoichiometry="1" constant="true"/>
          </listOfProducts>
        </reaction>
      </listOfReactions>
    </comp:modelDefinition>
  </comp:listOfModelDefinitions>
</sbml>
@endcode
 * Also suppose we have the following SBML Level&nbsp;3 model stored
 * in a file called @c "main.xml" in the same directory as the
 * file above.  The model below imports the model @c "enzyme" from
 * the model file above twice; this is used to create two submodels
 * whose identifiers are @c "A" and @c "B".
@code{.xml}
<?xml version="1.0" encoding="UTF-8"?>
<sbml xmlns="http://www.sbml.org/sbml/level3/version1/core" level="3" version="1"
      xmlns:comp="http://www.sbml.org/sbml/level3/version1/comp/version1" comp:required="true">
  <model>
    <listOfCompartments>
      <compartment id="compartment" spatialDimensions="3" size="1" constant="true">
        <comp:listOfReplacedElements>
          <comp:replacedElement comp:idRef="compartment" comp:submodelRef="A"/>
          <comp:replacedElement comp:idRef="compartment" comp:submodelRef="B"/>
        </comp:listOfReplacedElements>
      </compartment>
    </listOfCompartments>
    <listOfSpecies>
      <species id="S" compartment="compartment" hasOnlySubstanceUnits="false"
                      boundaryCondition="false" constant="false">
        <comp:listOfReplacedElements>
          <comp:replacedElement comp:idRef="S" comp:submodelRef="A"/>
          <comp:replacedElement comp:idRef="S" comp:submodelRef="B"/>
        </comp:listOfReplacedElements>
      </species>
    </listOfSpecies>
    <comp:listOfSubmodels>
      <comp:submodel comp:id="A" comp:modelRef="ExtMod1"/>
      <comp:submodel comp:id="B" comp:modelRef="ExtMod1"/>
    </comp:listOfSubmodels>
  </model>
  <comp:listOfExternalModelDefinitions>
    <comp:externalModelDefinition comp:id="ExtMod1" comp:source="enzyme_model.xml"
                                  comp:modelRef="enzyme"/>
  </comp:listOfExternalModelDefinitions>
</sbml>
@endcode
 * Finally, invoking the example program developed the previous section on the
 * file @c "main.xml", we would obtain the following XML output as result a
 * result
@code{.xml}
<?xml version="1.0" encoding="UTF-8"?>
<sbml xmlns="http://www.sbml.org/sbml/level3/version1/core" level="3" version="1">
  <model>
    <listOfCompartments>
      <compartment id="compartment" spatialDimensions="3" size="1" constant="true"/>
    </listOfCompartments>
    <listOfSpecies>
      <species id="S"     compartment="compartment" hasOnlySubstanceUnits="false"
                          boundaryCondition="false" constant="false"/>
      <species id="A__E"  compartment="compartment" hasOnlySubstanceUnits="false"
                          boundaryCondition="false" constant="false"/>
      <species id="A__D"  compartment="compartment" hasOnlySubstanceUnits="false"
                          boundaryCondition="false" constant="false"/>
      <species id="A__ES" compartment="compartment" hasOnlySubstanceUnits="false"
                          boundaryCondition="false" constant="false"/>
      <species id="B__E"  compartment="compartment" hasOnlySubstanceUnits="false"
                          boundaryCondition="false" constant="false"/>
      <species id="B__D"  compartment="compartment" hasOnlySubstanceUnits="false"
                          boundaryCondition="false" constant="false"/>
      <species id="B__ES" compartment="compartment" hasOnlySubstanceUnits="false"
                          boundaryCondition="false" constant="false"/>
    </listOfSpecies>
    <listOfReactions>
      <reaction id="A__J0" reversible="true" fast="false">
        <listOfReactants>
          <speciesReference species="S" stoichiometry="1" constant="true"/>
          <speciesReference species="A__E" stoichiometry="1" constant="true"/>
        </listOfReactants>
        <listOfProducts>
          <speciesReference species="A__ES" stoichiometry="1" constant="true"/>
        </listOfProducts>
      </reaction>
      <reaction id="A__J1" reversible="true" fast="false">
        <listOfReactants>
          <speciesReference species="A__ES" stoichiometry="1" constant="true"/>
        </listOfReactants>
        <listOfProducts>
          <speciesReference species="A__E" stoichiometry="1" constant="true"/>
          <speciesReference species="A__D" stoichiometry="1" constant="true"/>
        </listOfProducts>
      </reaction>
      <reaction id="B__J0" reversible="true" fast="false">
        <listOfReactants>
          <speciesReference species="S" stoichiometry="1" constant="true"/>
          <speciesReference species="B__E" stoichiometry="1" constant="true"/>
        </listOfReactants>
        <listOfProducts>
          <speciesReference species="B__ES" stoichiometry="1" constant="true"/>
        </listOfProducts>
      </reaction>
      <reaction id="B__J1" reversible="true" fast="false">
        <listOfReactants>
          <speciesReference species="B__ES" stoichiometry="1" constant="true"/>
        </listOfReactants>
        <listOfProducts>
          <speciesReference species="B__E" stoichiometry="1" constant="true"/>
          <speciesReference species="B__D" stoichiometry="1" constant="true"/>
        </listOfProducts>
      </reaction>
    </listOfReactions>
  </model>
</sbml>
@endcode
 * The final model is a concrete realization of the effective
 * model defined by @c "main.xml", with a single compartment and two
 * reactions; the species @c "S" can either bind with enzyme @c "E" (from
 * submodel @c "A") to form @c "D" (from submodel @c "A"), or with enzyme
 * @c "E" (from submodel @c "B") to form @c "D" (from submodel @c "B").
 * In the flattened model above, note how the identifiers of components
 * inside the ModelDefinition objects @c "A" and @c "B" of our file @c
 * "enzyme_model.xml" have been rewritten as (for example) @c "A__E" @c
 * "B__E", etc.
 *
 * @copydetails doc_section_using_sbml_converters
 */

#ifndef CompFlatteningConverter_h
#define CompFlatteningConverter_h

#include <sbml/SBMLNamespaces.h>
#include <sbml/packages/comp/extension/CompModelPlugin.h>
#include <sbml/conversion/SBMLConverter.h>
#include <sbml/conversion/SBMLConverterRegister.h>


#ifdef __cplusplus


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN CompFlatteningConverter : public SBMLConverter
{
public:

  /** @cond doxygenLibsbmlInternal */

  /**
   * Register with the ConversionRegistry.
   */
  static void init();

  /** @endcond */


  /**
   * Constructor.
   */
  CompFlatteningConverter();


  /**
   * Copy constructor.
   */
  CompFlatteningConverter(const CompFlatteningConverter&);


  /**
   * Creates and returns a deep copy of this CompFlatteningConverter.
   * 
   * @return a (deep) copy of this CompFlatteningConverter.
   */
  virtual CompFlatteningConverter* clone() const;


  /**
   * Destroy this CompFlatteningConverter object.
   */
  virtual ~CompFlatteningConverter ();


  /**
   * This function determines whether a given converter matches the 
   * configuration properties given. 
   * 
   * @param props the properties to match
   * 
   * @return @c true if this converter is a match, @c false otherwise.
   */
  virtual bool matchesProperties(const ConversionProperties &props) const;


  /**
   * Calls the conversion and cleans up potentially changed state.
   * 
   * @return status code represeting success/failure/conversion impossible
   */
  virtual int convert();

  /**
   * Performs the actual conversion.
   * 
   * @return status code represeting success/failure/conversion impossible
   */
  virtual int performConversion();

  /**
   * Returns the default properties of this converter.
   * 
   * A given converter exposes one or more properties that can be adjusted
   * in order to influence the behavior of the converter.  This method
   * returns the @em default property settings for this converter.  It is
   * meant to be called in order to discover all the settings for the
   * converter object.
   *
   * The properties for the CompFlatteningConverter are:
   * @li "flatten comp": the name of this converter
   * @li "basePath": the base directory to find external references in
   * @li "leavePorts": boolean indicating whether unused ports 
   *   should be listed in the flattened model; default = false
   * @li "listModelDefinitions": boolean indicating whether the model 
   *   definitions should be listed in the flattened model; default = false
   * @li "stripUnflattenablePackages": boolean indicating whether packages 
   *   that cannot be flattened should be removed; default = true
   * @li "performValidation": boolean indicating whether validation should be 
   *   performed. When @c true either an invalid source document or 
   *   an invalid flattened document will cause flattening to fail; default = true
   * @li "abortIfUnflattenable": string indicating the required status of
   *   any unflattenable packages that should cause flattening to fail.
   *   Possible values are "none", "requiredOnly" and "all"; default = requiredOnly
   *
   * @note previously there was an "ignorePackages" option; whose name
   * proved to be very misleading. This option has been deprecated and 
   * replaced by the "stripUnflattenablePackages" but will still work.
   *
   * @return the ConversionProperties object describing the default properties
   * for this converter.
   */
  virtual ConversionProperties getDefaultProperties() const;

private:

  int validateOriginalDocument();

  int validateFlatDocument(Model* flatmodel, unsigned int pkgVersion, 
                           unsigned int level, unsigned int version);

  int stripPackages();

  int reconstructDocument(Model* flatmodel); 

  int reconstructDocument(Model* flatmodel, 
                          SBMLDocument &dummyDoc,  bool dummyRecon = false);

  void stripUnflattenablePackages();

  bool getLeavePorts() const;

  bool getLeaveDefinitions() const;

  bool getIgnorePackages() const;

  bool getStripUnflattenablePackages() const;

  bool getPerformValidation() const;

  bool getAbortForAll() const;

  bool getAbortForRequired() const;

  bool getAbortForNone() const;

  const std::string& getPackagesToStrip() const;

  bool canBeFlattened();

  void restoreNamespaces();

  std::set<std::pair<std::string, std::string> > mDisabledPackages;


#ifndef SWIG
  typedef std::vector<bool>                     ValueSet;
  typedef std::map<const std::string, ValueSet> PackageValueMap;
  typedef PackageValueMap::iterator             PackageValueIter;
#endif

  PackageValueMap mPackageValues;

  void analyseDocument();

  bool getRequiredStatus(const std::string & package);

  bool getKnownStatus(const std::string& package);

  bool getFlattenableStatus(const std::string& package);

  bool haveUnknownRequiredPackages();

  bool haveUnknownUnrequiredPackages();

  bool haveUnflattenableRequiredPackages();

  bool haveUnflattenableUnrequiredPackages();

};

LIBSBML_CPP_NAMESPACE_END

#endif  /* __cplusplus */

  
#ifndef SWIG

LIBSBML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS


END_C_DECLS
LIBSBML_CPP_NAMESPACE_END

#endif  /* !SWIG */
#endif  /* CompFlatteningConverter_h*/

