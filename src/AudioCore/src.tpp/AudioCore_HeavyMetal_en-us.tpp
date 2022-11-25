topic "class HeavyMetal : public FM";
[ $$0,0#00000000000000000000000000000000:Default]
[i448;a25;kKO9; $$1,0#37138531426314131252341829483380:structitem]
[l288;2 $$2,0#27521748481378242620020725143825:desc]
[0 $$3,0#96390100711032703541132217272105:end]
[{_}%EN-US 
[s1;:AudioCore`:`:HeavyMetal`:`:class:%- [@(0.0.255) class]_[* HeavyMetal]_:_[@(0.0.255) pub
lic]_[*@3 FM]&]
[s2; heavy metal FM synthesis instrument.&]
[s2; &]
[s2;     This class implements 3 cascade operators with&]
[s2;     feedback modulation, also referred to as&]
[s2;     algorithm 3 of the TX81Z.&]
[s2; &]
[s2;     `\code&]
[s2;     Algorithm 3 is :    4`-`-`\&]
[s2;                     3`-`->2`-`- `+ `-`->1`-`->Out&]
[s2;     `\endcode&]
[s2; &]
[s2;     Control Change Numbers: &]
[s2;        `- Total Modulator Index `= 2&]
[s2;        `- Modulator Crossfade `= 4&]
[s2;        `- LFO Speed `= 11&]
[s2;        `- LFO Depth `= 1&]
[s2;        `- ADSR 2 `& 4 Target `= 128&]
[s2; &]
[s2;     The basic Chowning/Stanford FM patent expired&]
[s2;     in 1995, but there exist follow`-on patents,&]
[s2;     mostly assigned to Yamaha.  If you are of the&]
[s2;     type who should worry about this (making&]
[s2;     money) worry away.&]
[s3;%- &]
[s0; ]]