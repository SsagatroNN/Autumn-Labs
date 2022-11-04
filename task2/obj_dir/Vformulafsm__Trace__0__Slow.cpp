// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vformulafsm__Syms.h"


VL_ATTR_COLD void Vformulafsm___024root__trace_init_sub__TOP__0(Vformulafsm___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vformulafsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vformulafsm___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBit(c+2,"en", false,-1);
    tracep->declBus(c+3,"dout", false,-1, 7,0);
    tracep->pushNamePrefix("formulafsm ");
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBit(c+2,"en", false,-1);
    tracep->declBus(c+3,"dout", false,-1, 7,0);
    tracep->declBus(c+4,"num", false,-1, 7,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vformulafsm___024root__trace_init_top(Vformulafsm___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vformulafsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vformulafsm___024root__trace_init_top\n"); );
    // Body
    Vformulafsm___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vformulafsm___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vformulafsm___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vformulafsm___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vformulafsm___024root__trace_register(Vformulafsm___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vformulafsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vformulafsm___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vformulafsm___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vformulafsm___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vformulafsm___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vformulafsm___024root__trace_full_sub_0(Vformulafsm___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vformulafsm___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vformulafsm___024root__trace_full_top_0\n"); );
    // Init
    Vformulafsm___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vformulafsm___024root*>(voidSelf);
    Vformulafsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vformulafsm___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vformulafsm___024root__trace_full_sub_0(Vformulafsm___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vformulafsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vformulafsm___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->clk));
    bufp->fullBit(oldp+2,(vlSelf->en));
    bufp->fullCData(oldp+3,(vlSelf->dout),8);
    bufp->fullCData(oldp+4,(vlSelf->formulafsm__DOT__num),8);
}
