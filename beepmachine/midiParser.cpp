#include "midiParser.h"
#include "iostream"
#include <midifile/MidiFile.h>
#include <midifile/MidiMessage.h>
#include <math.h>
using namespace std;
using namespace smf;

MidiParser::MidiParser()
{
}
MidiParser::MidiParser(QString fileName)
{
    _fileName = fileName;
}

Sheet MidiParser::getSheet()
{

   MidiFile midifile;
   midifile.read(_fileName.toStdString());
   cout << "TPQ: " << midifile.getTicksPerQuarterNote() << endl;
   cout << "TRACKS: " << midifile.getTrackCount() << endl;
   midifile.joinTracks();
   midifile.doTimeAnalysis();
   midifile.linkNotePairs();
   // midifile.getTrackCount() will now return "1", but original
   // track assignments can be seen in .track field of MidiEvent.
   cout << "TICK    DELTA   TRACK   MIDI MESSAGE\n";
   cout << "____________________________________\n";
   QVector<PlayableNote> vec;
   MidiEvent* mev;
   double deltatick;
   int size = midifile[0].size();
    int lastTick = 0;
    midifile.deltaTicks();

    for (int event=0; event < size; event++) {
      mev = &midifile[0][event];
      if (!mev->isNote()) continue;
      if (!mev->isNoteOn()) continue;
      if (event == 0) deltatick = mev->getTickDuration() * mev->tick;
      else deltatick = (mev->tick ) * mev->getTickDuration();
      float aa = (float)(int) mev->getP1();
      aa -= 12*5;
      float freq = 440 * pow(2, (aa / 12));
      cout << aa << endl;
      if (deltatick > 1) {
          vec.push_back(PlayableNote(-1, mev->tick));
      }
      vec.push_back(PlayableNote(freq, 1000.0 * mev->getDurationInSeconds()));

      lastTick = mev->tick;

   }
   return Sheet(vec, 0);
}

