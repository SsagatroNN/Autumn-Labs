// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vformulafsm__Syms.h"


void Vformulafsm___024root__trace_chg_sub_0(Vformulafsm___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vformulafsm___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vformulafsm___024root__trace_chg_top_0\n"); );
    // Init
    Vformulafsm___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vformulafsm___024root*>(voidSelf);
    Vformulafsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vformulafsm___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vformulafsm___024root__trace_chg_sub_0(Vformulafsm___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vformulafsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vformulafsm___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->clk));
    bufp->chgBit(oldp+1,(vlSelf->en));
    bufp->chgCData(oldp+2,(vlSelf->dout),8);
    bufp->chgCData(oldp+3,(vlSelf->formulafsm__DOT__num),8);
}

void Vformulafsm___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vformulafsm___024root__trace_cleanup\n"); );
    // Init
    Vformulafsm___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vformulafsm___024root*>(voidSelf);
    Vformulafsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
