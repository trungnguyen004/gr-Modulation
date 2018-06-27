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


#ifndef INCLUDED_MODULATION_OOK_DEMODULATION_H
#define INCLUDED_MODULATION_OOK_DEMODULATION_H

#include <Modulation/api.h>
#include <gnuradio/sync_decimator.h>

namespace gr {
  namespace Modulation {

    /*!
     * \brief <+description of block+>
     * \ingroup Modulation
     *
     */
    class MODULATION_API OOK_Demodulation : virtual public gr::sync_decimator
    {
     public:
      typedef boost::shared_ptr<OOK_Demodulation> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of Modulation::OOK_Demodulation.
       *
       * To avoid accidental use of raw pointers, Modulation::OOK_Demodulation's
       * constructor is in a private implementation
       * class. Modulation::OOK_Demodulation::make is the public interface for
       * creating new instances.
       */
      static sptr make(float thresthold, float decimation);
	virtual void d_thresthold(float thresthold) = 0;
	virtual float thresthold() = 0;
	virtual void d_decimation(float decimation) = 0;
	virtual float decimation() = 0;
    };

  } // namespace Modulation
} // namespace gr

#endif /* INCLUDED_MODULATION_OOK_DEMODULATION_H */

