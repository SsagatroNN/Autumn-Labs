// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vformulafsm.h for the primary calling header

#ifndef VERILATED_VFORMULAFSM___024ROOT_H_
#define VERILATED_VFORMULAFSM___024ROOT_H_  // guard

#include "verilated.h"

class Vformulafsm__Syms;

class Vformulafsm___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(en,0,0);
    VL_OUT8(dout,7,0);
    CData/*7:0*/ formulafsm__DOT__num;
    CData/*0:0*/ __Vclklast__TOP__clk;

    // INTERNAL VARIABLES
    Vformulafsm__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vformulafsm___024root(Vformulafsm__Syms* symsp, const char* name);
    ~Vformulafsm___024root();
    VL_UNCOPYABLE(Vformulafsm___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
