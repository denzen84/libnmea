#include "../nmea/parser_types.h"
#include "gngll.h"
#include "parse.h"

int
init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_GNGLL);
	NMEA_PARSER_PREFIX(parser, "GNGLL");
	return 0;
}

int
allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof (nmea_gngll_s));
	if (NULL == parser->data) {
		return -1;
	}

	return 0;
}

int
set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof (nmea_gngll_s));
	return 0;
}

int
free_data(nmea_s *data)
{
	free(data);
	return 0;
}

int
parse(nmea_parser_s *parser, char *value, int val_index)
{
	nmea_gngll_s *data = (nmea_gngll_s *) parser->data;

	switch (val_index) {
	case NMEA_GNGLL_TIME:
		/* Parse time */
		if (-1 == nmea_time_parse(value, &data->time)) {
			return -1;
		}
		break;

	case NMEA_GNGLL_LATITUDE:
		/* Parse latitude */
		if (-1 == nmea_position_parse(value, &data->latitude)) {
			return -1;
		}
		break;

	case NMEA_GNGLL_LATITUDE_CARDINAL:
		/* Parse cardinal direction */
		data->latitude.cardinal = nmea_cardinal_direction_parse(value);
		if (NMEA_CARDINAL_DIR_UNKNOWN == data->latitude.cardinal) {
			return -1;
		}
		break;

	case NMEA_GNGLL_LONGITUDE:
		/* Parse longitude */
		if (-1 == nmea_position_parse(value, &data->longitude)) {
			return -1;
		}
		break;

	case NMEA_GNGLL_LONGITUDE_CARDINAL:
		/* Parse cardinal direction */
		data->longitude.cardinal = nmea_cardinal_direction_parse(value);
		if (NMEA_CARDINAL_DIR_UNKNOWN == data->longitude.cardinal) {
			return -1;
		}
		break;

	default:
		break;
	}

	return 0;
}
