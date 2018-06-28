/* -*- c++ -*- */
/* 
 * Copyright 2018 Jason Nguyen.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "OOK_Demodulation_impl.h"

namespace gr {
  namespace Modulation {

    OOK_Demodulation::sptr
    OOK_Demodulation::make(float thresthold, float decimation)
    {
      return gnuradio::get_initial_sptr
        (new OOK_Demodulation_impl(thresthold, decimation));
    }

    /*
     * The private constructor
     */
    OOK_Demodulation_impl::OOK_Demodulation_impl(float thresthold, float decimation)
      : gr::sync_decimator("OOK_Demodulation",
              gr::io_signature::make(1, 1, sizeof(float)),
              gr::io_signature::make(1, 1, sizeof(char)), decimation) // For now, decimation doesn't play any role in the block. Change it as needed.
    {
	d_decimation(decimation);
	d_thresthold(thresthold);
	}

    /*
     * Our virtual destructor.
     */
    OOK_Demodulation_impl::~OOK_Demodulation_impl()
    {
    }

    int
    OOK_Demodulation_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const float *in = (const float *) input_items[0];
      char *out = (char *) output_items[0];

      for(int i =0; i < noutput_items; i++) { //use while loop with 2 variables i & j to use decimation
	 if (in[i] < thresthold()) 
		{out[i] = 0;}
	 if (in[i] >= thresthold())
		{out[i] = 1;}
	}

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace Modulation */
} /* namespace gr */

