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


#ifndef INCLUDED_MODULATION_OOK_MODULATION_H
#define INCLUDED_MODULATION_OOK_MODULATION_H

#include <Modulation/api.h>
#include <gnuradio/sync_interpolator.h>

namespace gr {
  namespace Modulation {

    /*!
     * \brief <+description of block+>
     * \ingroup Modulation
     *
     */
    class MODULATION_API OOK_Modulation : virtual public gr::sync_interpolator
    {
     public:
      typedef boost::shared_ptr<OOK_Modulation> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of Modulation::OOK_Modulation.
       *
       * To avoid accidental use of raw pointers, Modulation::OOK_Modulation's
       * constructor is in a private implementation
       * class. Modulation::OOK_Modulation::make is the public interface for
       * creating new instances.
       */
      static sptr make(float max,float min, float interpolation);

	virtual void d_max(float max) = 0;
	virtual float max() = 0;
	virtual void d_min(float min) = 0;
	virtual float min() = 0;
	virtual void d_interpolation(float interpolation) = 0;
	virtual float interpolation() = 0;

    };

  } // namespace Modulation
} // namespace gr

#endif /* INCLUDED_MODULATION_OOK_MODULATION_H */

