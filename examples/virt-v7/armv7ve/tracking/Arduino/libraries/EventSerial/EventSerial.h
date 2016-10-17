/*
 *
 */

#include "Arduino.h"
#include "HardwareSerial.h"

static const byte COMMAND_BUFFER_SIZE = 50;

class EventSerial;
class EventSerialManager;

class Buffer
{
  private:
    char m_WorkingBuffer[COMMAND_BUFFER_SIZE];
    char m_WorkingBufferSave[COMMAND_BUFFER_SIZE];
    byte m_WorkingBufferIndex;

  public:
    Buffer() :
      m_WorkingBufferIndex(0)
    {
      m_WorkingBuffer[0] = '\0';
    }
    bool addChar(char c) {
      if (m_WorkingBufferIndex == COMMAND_BUFFER_SIZE - 1) return false;
      else {
        m_WorkingBuffer[m_WorkingBufferIndex++] = c;
        m_WorkingBuffer[m_WorkingBufferIndex] = '\0';
        return true;
      }
    }
    bool deleteLastChar() {
      bool result = m_WorkingBufferIndex > 0;
      if (result) m_WorkingBuffer[--m_WorkingBufferIndex] = '\0';
      return result;
    }
    void trim(int from, int len);
    byte space()   { return COMMAND_BUFFER_SIZE - 1 - m_WorkingBufferIndex; }
    bool isEmpty() { return m_WorkingBufferIndex == 0; }
    char *get();
    bool search(char *fromSrc, int &pos);
    char *getCommandAndArgCount(byte &argCount);
    char *searchArgs(byte &argCount);
    char *getArg() {
      return strtok(NULL, " ");
    }
    void print(HardwareSerial &serial) { serial.println(m_WorkingBuffer); }
    void printHex(HardwareSerial &serial);
    void reset();
};

/*
 *
 */
typedef void (*eventFunction)(EventSerialManager&, byte);

class EventSerial
{
  private:
    String m_EventString;
    eventFunction m_Function;
    bool m_useArgs;
    EventSerial *m_NextEvent;
    EventSerialManager *m_Manager;
    int m_EventLength;
    int m_State;

  public:
    EventSerial(const String eventString, eventFunction function);
    void setManager(EventSerialManager*);
    void attachEventToEventList(EventSerial*);
    String printEvent();
    EventSerial *getNextEvent();
    void execute(Buffer);
};

class EventSerialManager
{
  private:
    HardwareSerial &m_SerialLink;         // the serial it uses
    EventSerial *m_EventList; // the list of events
    byte m_Terminator;
    Buffer m_Buffer;

  public:
    EventSerialManager(HardwareSerial &m_SerialLink);
    HardwareSerial &getSerial() { return m_SerialLink; }
    void addEvent(EventSerial &event);
    void execute();
    void printEvents();
    void getEventList();
    bool readString(String &result);
};
/*
struct Transition {
  State* from;
  State* to;
}

class Fsm
{
  private:
    Transition *mTransitionList;
  public:

}
*/
