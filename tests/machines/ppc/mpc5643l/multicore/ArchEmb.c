/**
 * @file ArchEmb.c
 *
 * @section desc File description
 *
 * Trampoline Test Suite : Machine dependant embUnit functions
 *
 * @section copyright Copyright
 *
 * Trampoline Test Suite
 *
 * Trampoline Test Suite is copyright (c) IRCCyN 2005-2007
 * Trampoline Test Suite is protected by the French intellectual property law.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

static int stdimpl_strcpy(char* out, const char* in)
{
  int length = 0;
  while(*out++=*in++) length++;
  return length;
}

static void stdimpl_sprintf(char* out, const char* string, char** va_args)
{
  char current;

  while(current = *string++)
  {
    if(current != '%')
    {
      *out++ = current;
    }
    else
    {
      current = *string++;
      switch(current)
      {
        case 's':
          out += stdimpl_strcpy(out, *va_args);
          va_args = (char **)((int*)va_args + 1);
          break;
        default :
          out += stdimpl_strcpy(out, "<undef>");
          break;
      }
    }
  }
  *out = '\0';
}

/*
 *  The outString is rode by the lauterbach.cmm script at the end of the
 *  function.
 */
void stdimpl_print(const char* string, ...)
{
  char outString[50];
  char **va_args = &string + 1;
  stdimpl_sprintf(outString, string, va_args);
  return;
}

