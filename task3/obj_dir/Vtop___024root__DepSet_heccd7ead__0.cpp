// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__0\n"); );
    // Init
    SData/*15:0*/ __Vdly__top__DOT__clktickr__DOT__count;
    CData/*7:0*/ __Vdly__top__DOT__fsm__DOT__num;
    // Body
    __Vdly__top__DOT__clktickr__DOT__count = vlSelf->top__DOT__clktickr__DOT__count;
    __Vdly__top__DOT__fsm__DOT__num = vlSelf->top__DOT__fsm__DOT__num;
    if (vlSelf->rst) {
        __Vdly__top__DOT__fsm__DOT__num = 0U;
    }
    __Vdly__top__DOT__fsm__DOT__num = ((IData)(vlSelf->tick)
                                        ? ((0xffU == (IData)(vlSelf->top__DOT__fsm__DOT__num))
                                            ? 0U : 
                                           ((0xfeU 
                                             & ((IData)(vlSelf->top__DOT__fsm__DOT__num) 
                                                << 1U)) 
                                            | (IData)(vlSelf->tick)))
                                        : (IData)(vlSelf->top__DOT__fsm__DOT__num));
    if (vlSelf->rst) {
        vlSelf->tick = 0U;
        __Vdly__top__DOT__clktickr__DOT__count = vlSelf->N;
    } else if (vlSelf->en) {
        if ((0U == (IData)(vlSelf->top__DOT__clktickr__DOT__count))) {
            vlSelf->tick = 1U;
            __Vdly__top__DOT__clktickr__DOT__count 
                = vlSelf->N;
        } else {
            __Vdly__top__DOT__clktickr__DOT__count 
                = (0xffffU & ((IData)(vlSelf->top__DOT__clktickr__DOT__count) 
                              - (IData)(1U)));
            vlSelf->tick = 0U;
        }
    }
    vlSelf->top__DOT__fsm__DOT__num = __Vdly__top__DOT__fsm__DOT__num;
    vlSelf->dout = vlSelf->top__DOT__fsm__DOT__num;
    vlSelf->top__DOT__clktickr__DOT__count = __Vdly__top__DOT__clktickr__DOT__count;
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vtop___024root___sequent__TOP__0(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
