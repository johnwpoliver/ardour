#ifndef mackie_surface_bcf_h
#define mackie_surface_bcf_h
/*
	Initially generated by scripts/generate-surface.rb
*/

#include "surface.h"

namespace Mackie
{

class MackieButtonHandler;

class BcfSurface : public Surface
{
public:
	BcfSurface( uint32_t max_strips ) : Surface( max_strips )
	{
	}
	
	virtual void handle_button( MackieButtonHandler & mbh, ButtonState bs, Button & button );
	virtual void init_controls();
	
	virtual void display_bank_start( SurfacePort & port, MackieMidiBuilder & builder, uint32_t current_bank );
	virtual void zero_all( SurfacePort & port, MackieMidiBuilder & builder );
	virtual void blank_jog_ring( SurfacePort & port, MackieMidiBuilder & builder );
	virtual bool has_timecode_display() const { return false; }
	
	virtual float scrub_scaling_factor() { return 50.0; }
	virtual float scaled_delta( const ControlState & state, float current_speed );

};

}

#endif