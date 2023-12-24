#include "CMD_Parse_Brightness.h"
#include "string.h"



int CMD_Parse_Brightness (char *cmd) {
  if ((strncmp (cmd, CMD_PREFIX_HIGH_REG, strlen (CMD_PREFIX_HIGH_REG)) && strncmp (cmd, CMD_PREFIX_LOW_REG, strlen (CMD_PREFIX_LOW_REG))) == 0) { // Если команда начинается с префикса
    return (atoi (cmd + strlen (CMD_PREFIX_HIGH_REG))); // Возвращаем числовое значение после префикса
  } else { // Если команда не начинается с префикса
    return -1; // Возвращаем -1, как признак ошибки
  }
}
