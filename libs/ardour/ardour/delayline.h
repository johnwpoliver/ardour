/*
    Copyright (C) 2006, 2013 Paul Davis
    Author: Robin Gareus

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the Free
    Software Foundation; either version 2 of the License, or (at your option)
    any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    675 Mass Ave, Cambridge, MA 02139, USA.
*/

#ifndef __ardour_delayline_h__
#define __ardour_delayline_h__

#include "ardour/types.h"
#include "ardour/processor.h"

namespace ARDOUR {

class BufferSet;
class ChanCount;
class Session;

/** Meters peaks on the input and stores them for access.
 */
class DelayLine : public Processor {
public:

  DelayLine (Session& s, const std::string& name);
	~DelayLine ();

	bool display_to_user() const { return false; }

	void run (BufferSet&, framepos_t, framepos_t, pframes_t, bool);
	void set_delay(framecnt_t signal_delay);

	bool configure_io (ChanCount in, ChanCount out);
	bool can_support_io_configuration (const ChanCount& in, ChanCount& out) const;
	void monitoring_changed();

	XMLNode& state (bool full);

private:
	friend class IO;
	framecnt_t _delay, _pending_delay;
	framecnt_t _bsiz,  _pending_bsiz;
	frameoffset_t _roff, _woff;
	boost::shared_ptr<Sample> _buf;
	boost::shared_ptr<Sample> _pending_buf;
};

} // namespace ARDOUR

#endif // __ardour_meter_h__