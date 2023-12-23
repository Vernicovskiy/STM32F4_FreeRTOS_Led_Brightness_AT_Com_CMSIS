#include "CMD_Parse_Brightness.h"
#include "string.h"



int CMD_Parse_Brightness (char *cmd) {
  if (strncmp (cmd, CMD_PREFIX, strlen (CMD_PREFIX)) == 0) { // Если команда начинается с префикса
    return (atoi (cmd + strlen (CMD_PREFIX))); // Возвращаем числовое значение после префикса
  } else { // Если команда не начинается с префикса
    return -1; // Возвращаем -1, как признак ошибки
  }
}
