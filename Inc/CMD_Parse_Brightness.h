/*
 * CMD_Parse_Brightness.h
 *
 *  Created on: Dec 21, 2023
 *      Author: Виктор
 */

#ifndef CMD_PARSE_BRIGHTNESS_H_
#define CMD_PARSE_BRIGHTNESS_H_

#define CMD_PREFIX_HIGH_REG "AT+LED=" // Префикс для команды
#define CMD_PREFIX_LOW_REG "at+led=" // Префикс для команды



int CMD_Parse_Brightness (char *cmd);

#endif /* CMD_PARSE_BRIGHTNESS_H_ */
