// Copyright 2002 - 2008, 2010, 2011 National Technology Engineering
// Solutions of Sandia, LLC (NTESS). Under the terms of Contract
// DE-NA0003525 with NTESS, the U.S. Government retains certain rights
// in this software.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef StructuredCellIndex_hpp_
#define StructuredCellIndex_hpp_

#include <array>
#include <iostream>

namespace percept {

  using StructuredCellIndex = std::array<unsigned,4>;  // i,j,k, block

}

#endif