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

#ifndef INCLUDED_MODULATION_OOK_DEMODULATION_IMPL_H
#define INCLUDED_MODULATION_OOK_DEMODULATION_IMPL_H

#include <Modulation/OOK_Demodulation.h>

namespace gr {
  namespace Modulation {

    class OOK_Demodulation_impl : public OOK_Demodulation
    {
     private:
      float my_thresthold;
      float my_decimation;

     public:
      OOK_Demodulation_impl(float thresthold, float decimation);
      ~OOK_Demodulation_impl();

	void d_thresthold(float thresthold) {my_thresthold = thresthold;}
	float thresthold() {return my_thresthold;}
	void d_decimation(float decimation) {my_decimation = decimation;}
	float decimation() {return my_decimation;}

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace Modulation
} // namespace gr

#endif /* INCLUDED_MODULATION_OOK_DEMODULATION_IMPL_H */

