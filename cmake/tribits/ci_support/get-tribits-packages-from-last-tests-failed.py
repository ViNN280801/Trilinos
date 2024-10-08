#!/usr/bin/env python

# @HEADER
# *****************************************************************************
#            TriBITS: Tribal Build, Integrate, and Test System
#
# Copyright 2013-2016 NTESS and the TriBITS contributors.
# SPDX-License-Identifier: BSD-3-Clause
# *****************************************************************************
# @HEADER

from TribitsPackageTestNameUtils import *


#
# Read in the commandline arguments
#

usageHelp = \
r"""get-tribits-packages-from-last-tests-failed.py --deps-xml-file=<file> \
  --last-tests-failed-file=<file>

This returns a comma-separated list of TriBITS packages that correspond to the
list of failing tests provided in the passed-in file LastTestsFailed*.log
generated by ctest in the directory <build-dir>/Testing/Temporary/.
"""

from optparse import OptionParser

clp = OptionParser(usage=usageHelp)

clp.add_option(
  "--deps-xml-file", dest="depsXmlFile", type="string", default=None,
  help="File containing the listing of packages, dir names, dependencies, etc.")

clp.add_option(
  "--last-tests-failed-file", dest="lastTestsFailedFile", type="string", default=None,
  help="Path to file LastTestsFailed*.log file generated by CTest under <build-dir>/Testing/Temporary/.")

(options, args) = clp.parse_args()

if not options.lastTestsFailedFile:
  raise Exception("Error, the option --last-tests-failed-file=FILENAME must be set!")

trilinosDependencies = getProjectDependenciesFromXmlFile(options.depsXmlFile)

lastTestsFailedLines = readStrFromFile(options.lastTestsFailedFile).splitlines()

packageNames = getPackageNamesFromLastTestsFailedLines(trilinosDependencies,
  lastTestsFailedLines)

print(','.join(packageNames))
