/*
 *
 */

#include "EventSerial.h"
//#include <stdlib.h>

EventSerial::EventSerial(String eventString, eventFunction function)
  : m_EventString(eventString),
    m_Function(function),
    m_Manager(NULL),
    m_EventLength(eventString.length()),
    m_State(0)
{
}

void EventSerial::setManager(EventSerialManager *manager)
{
  m_Manager = manager;
}

void EventSerial::attachEventToEventList(EventSerial *headEventList)
{
  m_NextEvent = headEventList;
}

String EventSerial::printEvent() {
  String result;

  result = m_EventString + " - " + String(m_EventLength);

  return result;
}

EventSerial *EventSerial::getNextEvent() {
  return m_NextEvent;
}

void EventSerial::execute(Buffer theBuffer)
{
  byte argCount;
  char *args;
  bool commandFound = false;
  char command[COMMAND_BUFFER_SIZE];
  int positionOfCommand;
  String str;
  int i;
  // Serial.println("EventSerial::execute");
  // str = "Arg: " + String(argCount) + " : ";
  // str += commandString;
  // str += " - ";
  // for (i=0; i<argCount; i++) {
  //   str += theBuffer.getArg();
  //   str += " - ";
  // }
  // Serial.println(str);

  // Serial.println("-------------------");
  // Serial.println(m_EventString);
  // Serial.println(String(m_EventString.length()));
  // Serial.println("-------------------");

  m_EventString.toCharArray(command, m_EventString.length()+1);
  // Serial.println(command);
  if (theBuffer.search(command, positionOfCommand)) {
    // Serial.print("Buffer ");
    // theBuffer.print(Serial);
    commandFound = true;
    theBuffer.trim(0,m_EventString.length() + positionOfCommand);
    // Serial.print("Buffer trim ");
    // theBuffer.print(Serial);
    args = theBuffer.searchArgs(argCount);
    // Serial.println(String(argCount));
    // theBuffer.print(Serial);
    // str = "Arg: " + String(argCount) + " : ";
    // str += args;
    // str += " - ";
    // for (i=0; i < (argCount-1); i++) {
    //   str += theBuffer.getArg();
    //   str += " - ";
    // }
    // Serial.println(str);
    m_Function(*m_Manager, argCount);
  }
  // if (c == m_EventString.charAt(m_State)) {
  //   m_State++;
  // } else if (c == m_EventString.charAt(0)) {
  //   m_State = 1;
  // } else {
  //   m_State = 0;
  // }
  // if (m_State == m_EventLength) {
  //   // m_Function(*m_Manager, argCount);
  // }
  // m_Function(*m_Manager, argCount);
}

void Buffer::reset()
{
  m_WorkingBufferIndex = 0;
  m_WorkingBuffer[0] = '\0';
}

void Buffer::printHex(HardwareSerial &serial)
{
  int index = 0;

  while (m_WorkingBuffer[index] != '\0' && index < COMMAND_BUFFER_SIZE) {
    serial.print("_");
    serial.print((char)m_WorkingBuffer[index],HEX);
    index++;
  }
  serial.print("_");
}

bool Buffer::search(char *fromSrc, int &pos)
{
  bool patternFound = false;
  int index;
  char *ptrChar;

  // Serial.println("Buffer::search");
  // Serial.println(m_WorkingBuffer);
  // Serial.println(fromSrc);

  pos = -1;
  index = 0;
  strncpy(m_WorkingBufferSave, m_WorkingBuffer, COMMAND_BUFFER_SIZE);
  ptrChar = m_WorkingBuffer;
  // Serial.println(ptrChar);
  // Serial.println(fromSrc);
  while (((strlen(fromSrc) + index) < COMMAND_BUFFER_SIZE) && !patternFound) {
    if (strncmp(ptrChar, fromSrc, strlen(fromSrc)) == 0) {
      patternFound = true;
      pos = index;
      // Serial.print("Buffer::search OK : ");
      // Serial.println(String(pos));
    } else {
      index++;
      ptrChar++;
    }
  }
  // while (!patternFound && ((fromPatternIndex + len) < COMMAND_BUFFER_SIZE)) {
  //   if (strncmp(fromSrc, m_WorkingBuffer, len) == 0) {
  //     returnValue = true;
  //   };
  // }
  // if (strncmp(fromSrc, m_WorkingBuffer, len) == 0) {
  //   returnValue = true;
  // };

  return patternFound;
}

void Buffer::trim(int from, int len) {
  int index;
  int to;
  if (len < m_WorkingBufferIndex) {
    strncpy(m_WorkingBufferSave, m_WorkingBuffer, COMMAND_BUFFER_SIZE);
    for (index = 0; index < COMMAND_BUFFER_SIZE; index++) {
      m_WorkingBuffer[index] = '\0';
    }
    to = m_WorkingBufferIndex - len;
    for (index = 0; index < to; index++) {
      m_WorkingBuffer[index] = m_WorkingBufferSave[len + 1 + index];
    }
    m_WorkingBufferIndex = to;
  }
}

char *Buffer::getCommandAndArgCount(byte &argCount)
{
  byte count = 0;
  strncpy(m_WorkingBufferSave, m_WorkingBuffer, COMMAND_BUFFER_SIZE);
  char *tok = strtok(m_WorkingBufferSave, " ");
  while (tok = strtok(NULL, " ")) count++;
  argCount = count;
  strncpy(m_WorkingBufferSave, m_WorkingBuffer, COMMAND_BUFFER_SIZE);
  return strtok(m_WorkingBufferSave, " ");;
}
char *Buffer::searchArgs(byte &argCount)
{
  byte count = 0;
  char *ptrChar;

  ptrChar = m_WorkingBufferSave;
  strncpy(ptrChar, "_ ", 2);
  ptrChar = &m_WorkingBufferSave[2];
  strncpy(ptrChar, m_WorkingBuffer, COMMAND_BUFFER_SIZE - 2);
  // strncpy(m_WorkingBufferSave, m_WorkingBuffer, COMMAND_BUFFER_SIZE);
  char *tok = strtok(m_WorkingBufferSave, " ");
  while (tok = strtok(NULL, " ")) count++;
  argCount = count;

  ptrChar = m_WorkingBufferSave;
  strncpy(ptrChar, "_ ", 2);
  ptrChar = &m_WorkingBufferSave[2];
  strncpy(ptrChar, m_WorkingBuffer, COMMAND_BUFFER_SIZE - 2);
  // strncpy(m_WorkingBufferSave, m_WorkingBuffer, COMMAND_BUFFER_SIZE);

  return strtok(m_WorkingBufferSave, " ");
}

EventSerialManager::EventSerialManager(HardwareSerial &serialLink)
  : m_SerialLink(serialLink),
    m_EventList(NULL),
    m_Terminator('\n')
{

}

void EventSerialManager::addEvent(EventSerial &event)
{
  event.attachEventToEventList(m_EventList);
  m_EventList = &event;
  event.setManager(this);
}

/*EventSerialManager::runManager()
{

}*/
bool EventSerialManager::readString(String &result)
{
  result = m_Buffer.getArg();
  return result != NULL;
}

void EventSerialManager::execute()
{
  EventSerial *event = m_EventList;
  bool somethingToParse = false;
  String str;
  int nbchar = 0;
  char c;
  nbchar = m_SerialLink.available();
  while ((nbchar > 0) && !somethingToParse) {
    c = m_SerialLink.read();
    if (c == 0xD) {
      somethingToParse = true;
    } else if (c >= 0x20 && c <= 0x7D) {
        m_Buffer.addChar(c);
    }
    Serial.print(c);
    nbchar--;
  }
  if (somethingToParse) {
    event = m_EventList;
    while (event) {
      event->execute(m_Buffer);
      event = event->getNextEvent();
    }
    event = m_EventList;
    m_Buffer.reset();

  }
}
