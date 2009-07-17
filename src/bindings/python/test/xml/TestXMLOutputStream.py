#
# @file    TestXMLOutputStream.py
# @brief   XMLOutputStream unit tests
#
# @author  Akiya Jouraku (Python conversion)
# @author  Sarah Keating 
#
# $Id$
# $HeadURL$
#
# This test file was converted from src/sbml/test/TestXMLOutputStream.c
# with the help of conversion sciprt (ctest_converter.pl).
#
#<!---------------------------------------------------------------------------
# This file is part of libSBML.  Please visit http://sbml.org for more
# information about SBML, and the latest version of libSBML.
#
# Copyright 2005-2009 California Institute of Technology.
# Copyright 2002-2005 California Institute of Technology and
#                     Japan Science and Technology Corporation.
# 
# This library is free software; you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation.  A copy of the license agreement is provided
# in the file named "LICENSE.txt" included with this software distribution
# and also available online as http://sbml.org/software/libsbml/license.html
#--------------------------------------------------------------------------->*/
import sys
import unittest
import libsbml

def wrapString(s):
  return s
  pass

class TestXMLOutputStream(unittest.TestCase):


  def test_XMLOutputStream_CharacterReference(self):
    oss = libsbml.ostringstream()
    stream = libsbml.XMLOutputStream(oss,"",False)
    stream.startElement( "testcr")
    stream.writeAttribute( "chars",    "one"     )
    stream.writeAttribute( "amp",      "&"       )
    stream.writeAttribute( "deccr",    "&#0168;"  )
    stream.writeAttribute( "hexcr",    "&#x00a8;")
    stream.writeAttribute( "lhexcr",   "&#x00A8;")
    stream.writeAttribute( "nodeccr1", "&#01688"  )
    stream.writeAttribute( "nodeccr2", "&#;"     )
    stream.writeAttribute( "nodeccr3", "&#00a8;" )
    stream.writeAttribute( "nodeccr4", "&#00A8;" )
    stream.writeAttribute( "nohexcr1", "&#x;"    )
    stream.writeAttribute( "nohexcr2", "&#xABCD" )
    stream.endElement( "testcr")
    expected = wrapString("<testcr chars=\"one\" amp=\"&amp;\" deccr=\"&#0168;\" hexcr=\"&#x00a8;\" ""lhexcr=\"&#x00A8;\" nodeccr1=\"&amp;#01688\" nodeccr2=\"&amp;#;\" " + 
    "nodeccr3=\"&amp;#00a8;\" nodeccr4=\"&amp;#00A8;\" " + 
    "nohexcr1=\"&amp;#x;\" nohexcr2=\"&amp;#xABCD\"/>")
    s = oss.str()
    self.assert_(( expected == s ))
    stream = None
    pass  

  def test_XMLOutputStream_Elements(self):
    d = 2.4
    l = 123456789
    ui = 5
    i = -3
    oss = libsbml.ostringstream()
    stream = libsbml.XMLOutputStream(oss,"",False)
    stream.startElement( "fred")
    stream.writeAttribute( "chars", "two")
    stream.writeAttribute( "bool",True)
    stream.writeAttribute( "double",d)
    stream.writeAttribute( "long",l)
    stream.writeAttribute( "uint",ui)
    stream.writeAttribute( "int",i)
    stream.endElement( "fred")
    expected =  "<fred chars=\"two\" bool=\"true\" double=\"2.4\" long=\"123456789\" uint=\"5\" int=\"-3\"/>";
    s = oss.str()
    self.assert_(( expected == s ))
    stream = None
    pass  

  def test_XMLOutputStream_PredefinedEntity(self):
    oss = libsbml.ostringstream()
    stream = libsbml.XMLOutputStream(oss,"",False)
    stream.startElement( "testpde")
    stream.writeAttribute( "amp",     "&"     )
    stream.writeAttribute( "apos",    "'"     )
    stream.writeAttribute( "gt",      ">"     )
    stream.writeAttribute( "lt",      "<"     )
    stream.writeAttribute( "quot",    "\""    )
    stream.writeAttribute( "pdeamp",  "&amp;" )
    stream.writeAttribute( "pdeapos", "&apos;")
    stream.writeAttribute( "pdegt",   "&gt;"  )
    stream.writeAttribute( "pdelt",   "&lt;"  )
    stream.writeAttribute( "pdequot", "&quot;")
    stream.endElement( "testpde")
    expected = wrapString("<testpde amp=\"&amp;\" apos=\"&apos;\" gt=\"&gt;\" lt=\"&lt;\" ""quot=\"&quot;\" pdeamp=\"&amp;\" pdeapos=\"&apos;\" pdegt=\"&gt;\" " + "pdelt=\"&lt;\" pdequot=\"&quot;\"/>")
    s = oss.str()
    self.assert_(( expected == s ))
    stream = None
    pass  

  def test_XMLOutputStream_createStdout(self):
    stream = libsbml.XMLOutputStream(libsbml.cout,"UTF-8",False)
    self.assert_( stream != None )
    stream = None
    pass  

  def test_XMLOutputStream_createStdoutWithProgramInfo(self):
    stream = libsbml.XMLOutputStream(libsbml.cout,"UTF-8",False, "foo", "bar")
    self.assert_( stream != None )
    stream = None
    pass  

  def test_XMLOutputStream_createString(self):
    expected =  "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    oss = libsbml.ostringstream()
    stream = libsbml.XMLOutputStream(oss,"UTF-8",True)
    self.assert_( stream != None )
    string = oss.str()
    self.assert_(( expected == string ))
    stream = None
    pass  

  def test_XMLOutputStream_createStringWithProgramInfo(self):
    expected =  "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    oss = libsbml.ostringstream()
    stream = libsbml.XMLOutputStream(oss,"UTF-8",True, "", "")
    self.assert_( stream != None )
    string = oss.str()
    self.assert_(( expected == string ))
    stream = None
    pass  

  def test_XMLOutputStream_startEnd(self):
    oss = libsbml.ostringstream()
    stream = libsbml.XMLOutputStream(oss,"",False)
    self.assert_( stream != None )
    stream.startEndElement( "id")
    string = oss.str()
    self.assert_((  "<id/>" == string ))
    stream = None
    pass  

def suite():
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TestXMLOutputStream))

  return suite

if __name__ == "__main__":
  if unittest.TextTestRunner(verbosity=1).run(suite()).wasSuccessful() :
    sys.exit(0)
  else:
    sys.exit(1)
