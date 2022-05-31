#include "../nmea/parser_types.h"
#include "gnvtg.h"
#include "parse.h"

int
init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_GNVTG);
	NMEA_PARSER_PREFIX(parser, "GNVTG");
	return 0;
}

int
allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof (nmea_gnvtg_s));
	if (NULL == parser->data) {
		return -1;
	}

	return 0;
}

int
set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof (nmea_gnvtg_s));
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
	nmea_gnvtg_s *data = (nmea_gnvtg_s *) parser->data;

	switch (val_index) {
	case NMEA_GNVTG_TRACKGOOD:
		data->track_deg = strtod(value, NULL);
		break;
	case NMEA_GNVTG_GNDSPD_KNOTS:
		data->gndspd_knots = strtod(value, NULL);
		break;
	case NMEA_GNVTG_GNDSPD_KMPH:
		data->gndspd_kmph = strtod(value, NULL);
		break;
	default:
		break;
	}

	return 0;
}
