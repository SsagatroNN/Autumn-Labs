// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vformulafsm.h for the primary calling header

#include "verilated.h"

#include "Vformulafsm___024root.h"

VL_ATTR_COLD void Vformulafsm___024root___initial__TOP__0(Vformulafsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vformulafsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vformulafsm___024root___initial__TOP__0\n"); );
    // Body
    vlSelf->formulafsm__DOT__num = 0U;
}

VL_ATTR_COLD void Vformulafsm___024root___settle__TOP__0(Vformulafsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vformulafsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vformulafsm___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->dout = vlSelf->formulafsm__DOT__num;
}

VL_ATTR_COLD void Vformulafsm___024root___eval_initial(Vformulafsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vformulafsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vformulafsm___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    Vformulafsm___024root___initial__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vformulafsm___024root___eval_settle(Vformulafsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vformulafsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vformulafsm___024root___eval_settle\n"); );
    // Body
    Vformulafsm___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vformulafsm___024root___final(Vformulafsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vformulafsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vformulafsm___024root___final\n"); );
}

VL_ATTR_COLD void Vformulafsm___024root___ctor_var_reset(Vformulafsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vformulafsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vformulafsm___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->en = VL_RAND_RESET_I(1);
    vlSelf->dout = VL_RAND_RESET_I(8);
    vlSelf->formulafsm__DOT__num = VL_RAND_RESET_I(8);
}
