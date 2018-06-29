/* -*- c++ -*- */

#define MODULATION_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "Modulation_swig_doc.i"

%{
#include "Modulation/OOK_Modulation.h"
#include "Modulation/OOK_Demodulation.h"
#include "Modulation/PAM_Modulation.h"
%}


%include "Modulation/OOK_Modulation.h"
GR_SWIG_BLOCK_MAGIC2(Modulation, OOK_Modulation);
%include "Modulation/OOK_Demodulation.h"
GR_SWIG_BLOCK_MAGIC2(Modulation, OOK_Demodulation);
%include "Modulation/PAM_Modulation.h"
GR_SWIG_BLOCK_MAGIC2(Modulation, PAM_Modulation);
