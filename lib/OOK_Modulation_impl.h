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

#ifndef INCLUDED_MODULATION_OOK_MODULATION_IMPL_H
#define INCLUDED_MODULATION_OOK_MODULATION_IMPL_H

#include <Modulation/OOK_Modulation.h>

namespace gr {
  namespace Modulation {

    class OOK_Modulation_impl : public OOK_Modulation
    {
     private:
      float my_max;
      float my_min;
      float my_interpolation;

     public:
      OOK_Modulation_impl(float max,float min,float interpolation);
      ~OOK_Modulation_impl();

	void d_max(float max) {my_max = max;}
	float max() {return my_max;}
	void d_min(float min) {my_min = min;}
	float min() {return my_min;}
	void d_interpolation(float interpolation) {my_interpolation = interpolation;}
	float interpolation() {return my_interpolation;}

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace Modulation
} // namespace gr

#endif /* INCLUDED_MODULATION_OOK_MODULATION_IMPL_H */

