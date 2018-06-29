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
#include "PAM_Demodulation_impl.h"

namespace gr {
  namespace Modulation {

    PAM_Demodulation::sptr
    PAM_Demodulation::make(float val00, float val01, float val10, float val11, float interpolation)
    {
      return gnuradio::get_initial_sptr
        (new PAM_Demodulation_impl(val00,val01,val10,val11,interpolation));
    }

    /*
     * The private constructor
     */
    PAM_Demodulation_impl::PAM_Demodulation_impl(float val00, float val01, float val10, float val11, float interpolation)
      : gr::sync_interpolator("PAM_Demodulation",
              gr::io_signature::make(1, 1, sizeof(float)),
              gr::io_signature::make(1, 1, sizeof(char)), interpolation)
    {
	d_val00(val00);	
	d_val01(val01);
	d_val10(val10);
	d_val11(val11);
	d_interpolation(interpolation);
	}

    /*
     * Our virtual destructor.
     */
    PAM_Demodulation_impl::~PAM_Demodulation_impl()
    {
    }

    int
    PAM_Demodulation_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const float *in = (const float *) input_items[0];
      char *out = (char *) output_items[0];

      int i = 0;
      int j = 0;
      

	while(i < noutput_items) { 	//Interpolation need to be set as 2 for this function
		if (in[j] <= (val00()+0.01))
			{ out[i=2*j] = 0;
			  out[i=2*j+1] = 0;
			  j=j+1;}
		if (in[j] >= (val01()-0.01) and in[j] <= (val01()+0.01))
			{ out[i=2*j] = 0;
			  out[i=2*j+1] = 1;
			  j=j+1;}
		if (in[j] >= (val10()-0.01) and in[j] <= (val10()+0.01))
			{ out[i=2*j] = 1;
			  out[i=2*j+1] = 0;
			  j=j+1;}
		if (in[j] >= (val11()-0.01))
			{ out[i=2*j] = 1;
			  out[i=2*j+1] = 1;
			  j=j+1;}
				 }

      // Do <+signal processing+>

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace Modulation */
} /* namespace gr */

