// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vformulafsm.h for the primary calling header

#include "verilated.h"

#include "Vformulafsm__Syms.h"
#include "Vformulafsm___024root.h"

void Vformulafsm___024root___ctor_var_reset(Vformulafsm___024root* vlSelf);

Vformulafsm___024root::Vformulafsm___024root(Vformulafsm__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vformulafsm___024root___ctor_var_reset(this);
}

void Vformulafsm___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vformulafsm___024root::~Vformulafsm___024root() {
}
