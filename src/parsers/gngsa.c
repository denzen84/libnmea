#include <ctype.h>

#include "../nmea/parser_types.h"
#include "gngsa.h"
#include "parse.h"

int
init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_GNGSA);
	NMEA_PARSER_PREFIX(parser, "GNGSA");
	return 0;
}

int
allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof (nmea_gngsa_s));
	if (NULL == parser->data) {
		return -1;
	}

	return 0;
}

int
set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof (nmea_gngsa_s));
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
	nmea_gngsa_s *data = (nmea_gngsa_s *) parser->data;

	switch (val_index) {
	case NMEA_GNGSA_MODE:
		data->mode = *value;
		if (('M' != toupper(data->mode)) && ('A' != toupper(data->mode))) {
			return -1;
		}
		break;
	case NMEA_GNGSA_FIXTYPE:
		data->fixtype = strtol(value, NULL, 10);
		if ((1 != data->fixtype) && (2 != data->fixtype) && (3 != data->fixtype)) {
			return -1;
		}
		break;
	case NMEA_GNGSA_SATID_00:
		data->satID_00 = strtol(value, NULL, 10);
		break;
	case NMEA_GNGSA_SATID_01:
		data->satID_01 = strtol(value, NULL, 10);
		break;
	case NMEA_GNGSA_SATID_02:
		data->satID_02 = strtol(value, NULL, 10);
		break;
	case NMEA_GNGSA_SATID_03:
		data->satID_03 = strtol(value, NULL, 10);
		break;
	case NMEA_GNGSA_SATID_04:
		data->satID_04 = strtol(value, NULL, 10);
		break;
	case NMEA_GNGSA_SATID_05:
		data->satID_05 = strtol(value, NULL, 10);
		break;
	case NMEA_GNGSA_SATID_06:
		data->satID_06 = strtol(value, NULL, 10);
		break;
	case NMEA_GNGSA_SATID_07:
		data->satID_07 = strtol(value, NULL, 10);
		break;
	case NMEA_GNGSA_SATID_08:
		data->satID_08 = strtol(value, NULL, 10);
		break;
	case NMEA_GNGSA_SATID_09:
		data->satID_09 = strtol(value, NULL, 10);
		break;
	case NMEA_GNGSA_SATID_10:
		data->satID_10 = strtol(value, NULL, 10);
		break;
	case NMEA_GNGSA_SATID_11:
		data->satID_11 = strtol(value, NULL, 10);
		break;
	case NMEA_GNGSA_PDOP:
		data->pdop = strtod(value, NULL);
		break;
	case NMEA_GNGSA_HDOP:
		data->hdop = strtod(value, NULL);
		break;
	case NMEA_GNGSA_VDOP:
		data->vdop = strtod(value, NULL);
		break;
	default:
		break;
	}

	return 0;
}
