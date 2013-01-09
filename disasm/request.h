#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>
#include "proto.h"

struct DisassemblerProperties{
  DisassemblerProperties() :
    m_comment_level(1),
    m_quiet(false),
    m_accum_16(false),
    m_index_16(false),
    m_stop_at_rts(false),
    m_use_extern_symbols(false),
    m_print_data_addr(false),
    m_start_bank(0x00),
    m_start_addr(0x8000), 
    m_end_bank(0xFF),
    m_end_addr(0xFFFF),
    m_passes(1)
  {}  

  int m_comment_level;

  bool m_quiet;
  bool m_accum_16;
  bool m_index_16;
  bool m_stop_at_rts;
  bool m_use_extern_symbols;
  bool m_print_data_addr;

  unsigned char m_start_bank; 
  unsigned int m_start_addr;
  
  unsigned char m_end_bank;
  unsigned int m_end_addr;

  int m_passes;
};

struct Request{
    Request(DisassemblerProperties properties = DisassemblerProperties()) : 
    m_type(Smart),
    m_properties(properties),
    m_quit(false)
  {}

  enum Type { Asm, Dcb, Ptr, PtrLong, Smart};

  bool get(std::istream & in, bool hirom);

  Type m_type;
  bool m_quit;
  DisassemblerProperties m_properties;
};

#endif