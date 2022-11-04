// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vformulafsm.h for the primary calling header

#include "verilated.h"

#include "Vformulafsm___024root.h"

VL_INLINE_OPT void Vformulafsm___024root___sequent__TOP__0(Vformulafsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vformulafsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vformulafsm___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->formulafsm__DOT__num = ((IData)(vlSelf->en)
                                     ? ((0xffU == (IData)(vlSelf->formulafsm__DOT__num))
                                         ? 0U : ((0xfeU 
                                                  & ((IData)(vlSelf->formulafsm__DOT__num) 
                                                     << 1U)) 
                                                 | (IData)(vlSelf->en)))
                                     : (IData)(vlSelf->formulafsm__DOT__num));
    vlSelf->dout = vlSelf->formulafsm__DOT__num;
}

void Vformulafsm___024root___eval(Vformulafsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vformulafsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vformulafsm___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vformulafsm___024root___sequent__TOP__0(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vformulafsm___024root___eval_debug_assertions(Vformulafsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vformulafsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vformulafsm___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
