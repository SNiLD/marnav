#ifndef __NMEA__XTR__HPP__
#define __NMEA__XTR__HPP__

#include "sentence.hpp"
#include <marnav/utils/optional.hpp>

namespace marnav
{
namespace nmea
{

/// @brief XTR - Cross Track Error - Dead Reckoning
///
/// @code
///        1   2 3
///        |   | |
/// $--XTR,x.x,a,N*hh<CR><LF>
/// @endcode
///
/// Field Number:
/// 1. Magnitude of cross track error
/// 2. Direction to steer
///    - L = left
///    - R = right
/// 3. Unit
///    - N = Nautical Miles
///
class xtr : public sentence
{
public:
	constexpr static const sentence_id ID = sentence_id::XTR;
	constexpr static const char * TAG = "XTR";

	xtr();
	xtr(const xtr &) = default;
	xtr & operator=(const xtr &) = default;

	static std::unique_ptr<sentence> parse(const std::string & talker,
		const std::vector<std::string> & fields) throw(std::invalid_argument);

protected:
	virtual std::vector<std::string> get_data() const override;

private:
	utils::optional<double> cross_track_error_magnitude;
	utils::optional<side> direction_to_steer;
	utils::optional<char> cross_track_units;

public:
	NMEA_GETTER(cross_track_error_magnitude)
	NMEA_GETTER(direction_to_steer)
	NMEA_GETTER(cross_track_units)

	void set_cross_track_error_magnitude(double t) { cross_track_error_magnitude = t; }
	void set_direction_to_steer(side t) { direction_to_steer = t; }
	void set_cross_track_units(char t) { cross_track_units = t; }
};
}
}

#endif
