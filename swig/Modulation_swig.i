/* -*- c++ -*- */

#define MODULATION_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "Modulation_swig_doc.i"

%{
#include "Modulation/OOK_Modulation.h"
%}


%include "Modulation/OOK_Modulation.h"
GR_SWIG_BLOCK_MAGIC2(Modulation, OOK_Modulation);
