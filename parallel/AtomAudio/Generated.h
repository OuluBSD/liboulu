#ifndef _AtomAudio_Generated_h_
#define _AtomAudio_Generated_h_

// This file is generated. Do not modify this file.

namespace TS {

namespace Parallel {

class MidiFileReaderPipe : public MidiFileReaderAtom {

public:
	RTTI_DECL1(MidiFileReaderPipe, MidiFileReaderAtom)
	COPY_PANIC(MidiFileReaderPipe)
	ATOM_MAKE_ACTION_BEGIN
	ATOM_MAKE_ACTION_UNDEF_TO_TRUE("midi.file.reader.pipe")
	ATOM_MAKE_ACTION_END
	static AtomTypeCls GetAtomType();
	static LinkTypeCls GetLinkType();
	void Visit(RuntimeVisitor& vis) override;
	AtomTypeCls GetType() const override;

};

class MidiFileReader : public MidiFileReaderAtom {

public:
	RTTI_DECL1(MidiFileReader, MidiFileReaderAtom)
	COPY_PANIC(MidiFileReader)
	ATOM_MAKE_ACTION_BEGIN
	ATOM_MAKE_ACTION_UNDEF_TO_TRUE("midi.file.reader")
	ATOM_MAKE_ACTION_END
	static AtomTypeCls GetAtomType();
	static LinkTypeCls GetLinkType();
	void Visit(RuntimeVisitor& vis) override;
	AtomTypeCls GetType() const override;

};

class MidiNullSink : public MidiNullAtom {

public:
	RTTI_DECL1(MidiNullSink, MidiNullAtom)
	COPY_PANIC(MidiNullSink)
	ATOM_MAKE_ACTION_BEGIN
	ATOM_MAKE_ACTION_UNDEF_TO_TRUE("midi.null.sink")
	ATOM_MAKE_ACTION_END
	static AtomTypeCls GetAtomType();
	static LinkTypeCls GetLinkType();
	void Visit(RuntimeVisitor& vis) override;
	AtomTypeCls GetType() const override;

};

class FluidsynthPipe : public FluidsynthInstrument {

public:
	RTTI_DECL1(FluidsynthPipe, FluidsynthInstrument)
	COPY_PANIC(FluidsynthPipe)
	ATOM_MAKE_ACTION_BEGIN
	ATOM_MAKE_ACTION_UNDEF_TO_TRUE("fluidsynth.pipe")
	ATOM_MAKE_ACTION_END
	static AtomTypeCls GetAtomType();
	static LinkTypeCls GetLinkType();
	void Visit(RuntimeVisitor& vis) override;
	AtomTypeCls GetType() const override;

};

using MidiFileReaderPipeRef = Ref<MidiFileReaderPipe, AtomParent>;

using MidiFileReaderRef = Ref<MidiFileReader, AtomParent>;

using MidiNullSinkRef = Ref<MidiNullSink, AtomParent>;

using FluidsynthPipeRef = Ref<FluidsynthPipe, AtomParent>;

}

}



#endif
